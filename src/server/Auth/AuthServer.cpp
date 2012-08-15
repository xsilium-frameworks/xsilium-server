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
		{}
		int logLevel;
		auth = new Authentification();


		config->Get("LogLevel",logLevel);
		log->Start((Log::Priority)logLevel,"authserver.log");
		log->Write(Log::DEBUG,"Demarrage du serveur d'authentification");

		int serverPort, numClient ;

		config->Get("port",serverPort);
		config->Get("clientMax",numClient);
		adresse.host = ENET_HOST_ANY;
		adresse.port  = (enet_uint16) serverPort;

		if(!connexion->createConnexion(adresse,numClient))
		{
			//erreur
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
	connexion = Connexion::getInstance();

}

authServer::~authServer() {
	Configuration::DestroyInstance();
	Log::DestroyInstance();
	Connexion::DestroyInstance();
	delete auth;

}

int main()
{
	    authServer * authserver = new authServer();
	    authserver->startServer();
	    delete authserver;
}
