/*
 * \file AuthServer.cpp
 *
 *  Created on: \date 18 déc. 2014
 *      Author: \author joda
 *  \brief :
 */
#include "AuthServer.h"

namespace Auth {

AuthServer::AuthServer() {
	signalHandler = 0;
	authentification = 0;
	royaumesManager = 0;
	networkManager = new NetworkManager();
	configuration = Configuration::getInstance();
	log = Log::getInstance();
	databaseManager = DatabaseManager::getInstance();

}

AuthServer::~AuthServer() {
	delete authentification;
	delete royaumesManager;
	delete networkManager;
	DatabaseManager::DestroyInstance();
	Configuration::DestroyInstance();
	Log::DestroyInstance();
}

void AuthServer::startServer()
{
	try {

		int logLevel,typeDatabase,serverPort,numClient;
		std::string infoDB;
		ENetAddress adresse;

		signalHandler->setupSignalHandlers();
		if (!configuration->load("../etc/auth.config"))
			return;


		configuration->get("LogLevel",logLevel);
		log->start((Log::Priority)logLevel,"authserver.log");
		log->activationFile();

		log->write(Log::DEBUG,"Demarrage de la connexion SQL (loginDB) ");
		configuration->get("typeDatabase",typeDatabase);
		configuration->get("databaseInfo",infoDB);

		databaseManager->createServer(typeDatabase);
		databaseManager->connection(infoDB);

		log->write(Log::DEBUG,"Demarrage du serveur d'authentification");
		authentification = new Authentification(networkManager);
		authentification->run();

		log->write(Log::DEBUG,"Demarrage du serveur de Royaume");
		royaumesManager = new RoyaumesManager(networkManager);
		royaumesManager->run();

		configuration->get("port",serverPort);
		configuration->get("clientMax",numClient);
		adresse.host = ENET_HOST_ANY;
		adresse.port  = (enet_uint16) serverPort;

		log->write(Log::DEBUG,"Demarrage du socket d'authentification");

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

void AuthServer::stopThread()
{
	log->write(Log::DEBUG,"Extinction du serveur ");
	networkManager->deleteConnexion();
	authentification->stopThread();
	databaseManager->deconnection();

}


} /* namespace Auth */


int main()
{
	Auth::AuthServer * authserver = new Auth::AuthServer();
	authserver->startServer();
	delete authserver;
}
