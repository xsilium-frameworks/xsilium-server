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


		config->Get("LogLevel",logLevel);
		log->Start((Log::Priority)logLevel,"authserver.log");
		log->Write(Log::DEBUG,"Demarrage du serveur d'authentification");

		auth = new Authentification();

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
	auth = NULL;
	signalHandler = NULL;

}

authServer::~authServer() {
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
