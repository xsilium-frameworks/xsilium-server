/*
 * AuthServer.h
 *
 *  Created on: 2 f�vr. 2012
 *      Author:
 */


#include "AuthServer.h"

authServer::authServer() {
	config = Configuration::getInstance();
	log = Log::getInstance();
	connexiontToClient = new Connexion();
	auth = NULL;
	signalHandler = NULL;
	gestionnaireSession = NULL;
	gestionnaireCompte = NULL;
	connexionSQLRealms = NULL;

}

authServer::~authServer() {
	delete auth;
	delete connexiontToClient ;
	LoginDatabase::DestroyInstance();
	Configuration::DestroyInstance();
	GestionnaireSession::DestroyInstance();
	GestionnaireCompte::DestroyInstance();
	Log::DestroyInstance();


}

void authServer::startServer()
{
	try
	{
		signalHandler->setupSignalHandlers();
		if (!config->Load("../etc/auth.config"))
		{
			return ;
		}
		int logLevel,serverPort,numClient;
		std::string infoDB;


		config->Get("LogLevel",logLevel);
		log->Start((Log::Priority)logLevel,"authserver.log");


		log->Write(Log::DEBUG,"Demarrage de la connexion SQL (loginDB) ");
		config->Get("LoginDatabaseInfo",infoDB);
		connexionSQLRealms = LoginDatabase::getInstance();
		connexionSQLRealms->connexionDB(infoDB);

		log->Write(Log::DEBUG,"Demarrage du gestionnaire de compte");
		gestionnaireCompte = GestionnaireCompte::getInstance();

		log->Write(Log::DEBUG,"Demarrage du gestionnaire de session");
		gestionnaireSession = GestionnaireSession::getInstance();
		gestionnaireSession->setConnexion(connexiontToClient);


		log->Write(Log::DEBUG,"Demarrage du serveur d'authentification");
		auth = new Authentification(connexiontToClient);
		auth->run();

		config->Get("port",serverPort);
		config->Get("clientMax",numClient);
		adresse.host = ENET_HOST_ANY;
		adresse.port  = (enet_uint16) serverPort;

		log->Write(Log::DEBUG,"Demarrage du socket d'authentification");

		if(!connexiontToClient->createConnexion(adresse,numClient))
		{
			log->Write(Log::DEBUG,"Impossible d'ouvrir la connexion ");
			return;
		}

		while(!signalHandler->gotExitSignal())
			sleep(1);

		stopThread();

	}
	catch (SignalException& e)
	{
		std::cerr << "SignalException: " << e.what() << std::endl;
	}
}


void authServer::stopThread()
{
	log->Write(Log::DEBUG,"Arret du socket de connexion");
	connexiontToClient->deleteConnexion();
	log->Write(Log::DEBUG,"Arret du serveur d'authentification");
	auth->stopThread();
	log->Write(Log::DEBUG,"Arret de la connexion SQL (loginDB)");
	connexionSQLRealms->deconnexionDB();
	log->Write(Log::DEBUG,"Arret du thread d'authentification");
	log->Stop();
}

int main()
{
	authServer * authserver = new authServer();
	authserver->startServer();
	delete authserver;
}
