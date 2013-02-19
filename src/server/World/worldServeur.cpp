/*
 * \file worldServeur.cpp
 *
 *  Created on: \date 27 nov. 2012
 *      Author: \author joda
 *  \brief :
 */

#include "worldServeur.h"

worldServeur::worldServeur() {
	config = Configuration::getInstance();
	log = Log::getInstance();
	connexion = new Connexion();
	chat = new Chat();

}

worldServeur::~worldServeur() {
	delete chat;
	Configuration::DestroyInstance();
	Log::DestroyInstance();
	GestionnaireSession::DestroyInstance();
	delete connexion;

}

void worldServeur::run()
{
	int serverPort, numClient ;
	try
		{
			signalHandler->setupSignalHandlers();
			if (!config->Load("../etc/world.config"))
			{
				return;
			}
			int logLevel;

			config->Get("LogLevel",logLevel);
			log->Start((Log::Priority)logLevel,"world.log");
			log->Write(Log::DEBUG,"Demarrage du gestionnaire de royaume");

			config->Get("port",serverPort);
			config->Get("clientMax",numClient);
			adresse.host = ENET_HOST_ANY;
			adresse.port  = (enet_uint16) serverPort;

			if(!connexion->createConnexion(adresse,numClient))
			{
				log->Write(Log::DEBUG,"erreur lors de l'ouverture du socket");
				return ;
			}

			log->Write(Log::DEBUG,"Demarrage du gestionnaire de session");
			gestionnaireSession = GestionnaireSession::getInstance();
			gestionnaireSession->setConnexion(connexion);

			log->Write(Log::DEBUG,"Demarrage du systeme de Tchat");
			chat->setConnexionLogin(connexion);
			chat->run();



			while(!signalHandler->gotExitSignal())
			        sleep(1);

			stopThread();

		}
		catch (SignalException& e)
		{
			std::cerr << "SignalException: " << e.what() << std::endl;
		}
}

void worldServeur::stopThread()
{
	log->Write(Log::DEBUG,"Arret du thread d'authentification");
	chat->stopThread();
	connexion->deleteConnexion();
	log->Stop();
}

int main()
{
	worldServeur  worldserveur ;
	worldserveur.run();
	return true;
}
