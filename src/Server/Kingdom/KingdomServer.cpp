/*
 * \file KingdomServer.cpp
 *
 *  Created on: \date 1 janv. 2015
 *      Author: \author joda
 *  \brief :
 */
#include "KingdomServer.h"

namespace Kingdom {

KingdomServer::KingdomServer() {
	signalHandler = 0;
	networkManager = new NetworkManager(NETWORK_TYPE_SERVER);
	configuration = Configuration::getInstance();
	log = Log::getInstance();
	databaseManager = DatabaseManager::getInstance();
	chatManager = 0;

}

KingdomServer::~KingdomServer() {
	delete chatManager;
	delete networkManager;
	DatabaseManager::DestroyInstance();
	Configuration::DestroyInstance();
	Log::DestroyInstance();
}

void KingdomServer::startServer()
{
	try {

		int logLevel,typeDatabase,serverPort,numClient;
		std::string infoDB;
		ENetAddress adresse;

		signalHandler->setupSignalHandlers();
		if (!configuration->load("../etc/Kingdom.config"))
			return;


		configuration->get("LogLevel",logLevel);
		log->start((Log::Priority)logLevel,"kingdomServer.log");
		log->activationFile();

		log->write(Log::DEBUG,"Demarrage de la connexion SQL (loginDB) ");
		configuration->get("typeDatabase",typeDatabase);
		configuration->get("databaseInfo",infoDB);

		databaseManager->createServer(typeDatabase);
		databaseManager->connection(infoDB);

		log->write(Log::DEBUG,"Demarrage du module de Chat");
		chatManager = new ChatManager(networkManager);
		chatManager->run();

		configuration->get("portClient",serverPort);
		configuration->get("clientMax",numClient);
		adresse.host = ENET_HOST_ANY;
		adresse.port  = (enet_uint16) serverPort;

		log->write(Log::DEBUG,"Demarrage du socket Kingdom");

		if(!networkManager->createConnexion(adresse,numClient))
		{
			log->write(Log::DEBUG,"Impossible d'ouvrir la connexion ");
			return;
		}

		while(!signalHandler->gotExitSignal())
			sleep(1);

		stopThread();

	}
	catch (SignalException& e) {
		std::cerr << "SignalException: " << e.what() << std::endl;
	}
}
void KingdomServer::stopThread()
{
	log->write(Log::DEBUG,"Extinction du serveur ");
	networkManager->disconnexion();
	chatManager->stopThread();
	databaseManager->deconnection();
}

} /* namespace Kingdom */

int main()
{
	Kingdom::KingdomServer * kingdomServer = new Kingdom::KingdomServer();
	kingdomServer->startServer();
	delete kingdomServer;
}
