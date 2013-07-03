/*
 * AuthServer.h
 *
 *  Created on: 2 f�vr. 2012
 *      Author:
 */


#include "AuthServer.h"

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


		config->Get("LogLevel",logLevel);
		log->Start((Log::Priority)logLevel,"authserver.log");
		log->Write(Log::DEBUG,"Demarrage du serveur d'authentification");

		auth = new Authentification(connexion);

		config->Get("port",serverPort);
		config->Get("clientMax",numClient);
		adresse.host = ENET_HOST_ANY;
		adresse.port  = (enet_uint16) serverPort;

		log->Write(Log::DEBUG,"Demarrage du socket d'authentification");

		if(!connexion->createConnexion(adresse,numClient))
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
	log->Write(Log::DEBUG,"Arret du thread d'authentification");
	log->Stop();
}


authServer::authServer() {
	config = Configuration::getInstance();
	log = Log::getInstance();
	connexion = new Connexion();
	auth = NULL;
	signalHandler = NULL;

}

authServer::~authServer() {
	delete connexion ;
	delete auth;
	Configuration::DestroyInstance();
	Log::DestroyInstance();


}

int main()
{
	authServer * authserver = new authServer();
	authserver->startServer();
	delete authserver;
}
