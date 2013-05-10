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
	connexiontToClient = new Connexion();
	chat = new Chat(connexiontToClient);
	gestionnaireZone = GestionnaireZone::getInstance();
	gestionnaireZone->setConnexionClient(connexiontToClient);

	gestionnaireSession = NULL;
	signalHandler = NULL;

}

worldServeur::~worldServeur() {
	delete chat;
	Configuration::DestroyInstance();
	Log::DestroyInstance();
	GestionnaireSession::DestroyInstance();
	GestionnaireZone::DestroyInstance();
	delete connexiontToClient;

}

void worldServeur::run()
{
	int serverPort, numClient ;
	try
		{
			signalHandler->setupSignalHandlers();
			if (!config->Load("../etc/Kingdom.config"))
			{
				return;
			}
			int logLevel;

			config->Get("LogLevel",logLevel);
			log->Start((Log::Priority)logLevel,"Kingdom.log");
			log->Write(Log::DEBUG,"Demarrage du gestionnaire de royaume");

			log->Write(Log::DEBUG,"Demarrage du gestionnaire de session");
			gestionnaireSession = GestionnaireSession::getInstance();
			gestionnaireSession->setConnexion(connexiontToClient);

			log->Write(Log::DEBUG,"Demarrage du systeme de Tchat");
			chat->run();

			log->Write(Log::DEBUG,"Demarrage du systeme de Zone");
			if(!gestionnaireZone->run())
			{
				log->Write(Log::DEBUG,"erreur lors de l'ouverture du socket pour les zones");
				return ;
			}



			config->Get("portClient",serverPort);
			config->Get("clientMax",numClient);
			adresse.host = ENET_HOST_ANY;
			adresse.port  = (enet_uint16) serverPort;

			log->Write(Log::DEBUG,"Demarrage du la connexionToClient");
			if(!connexiontToClient->createConnexion(adresse,numClient))
			{
				log->Write(Log::DEBUG,"erreur lors de l'ouverture du socket pour les clients");
				return ;
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

void worldServeur::stopThread()
{
	log->Write(Log::DEBUG,"Arret du thread d'authentification");
	chat->stopThread();
	gestionnaireZone->stop();
	connexiontToClient->deleteConnexion();
	log->Stop();
}

int main()
{
	worldServeur  worldserveur ;
	worldserveur.run();
	return true;
}
