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
	GestionnaireSession::DestroyInstance();
	GestionnaireZone::DestroyInstance();
	delete connexiontToClient;
	Configuration::DestroyInstance();
	Log::DestroyInstance();
}

void worldServeur::run()
{
	int serverPort, numClient ;
	try
		{
			signalHandler->setupSignalHandlers();
			//Si chargement ne se fait pas correctement return null.
			if (!config->Load("../etc/Kingdom.config"))
			{
				return;
			}
			int logLevel;

			//Récupère le niveau de log :ERROR, WARNING, INFO, CONFIG, DEBUG
			config->Get("LogLevel",logLevel);

			//Démarre les logs avec les priorité et écrit dans le fichier Kingdom
			log->Start((Log::Priority)logLevel,"Kingdom.log");

			/**Puis inscrit le message suivant : "Demarrage du gestionnaire de royaume"
			 * log->Write => Inscrit | Log::DEBUG => type dd'information | "[Le message]"
			**/
			log->Write(Log::DEBUG,"Demarrage du gestionnaire de royaume");

			log->Write(Log::DEBUG,"Demarrage du gestionnaire de session");

			//Récupère l'instanciation du GestionnaireSession
			gestionnaireSession = GestionnaireSession::getInstance();
			//?? A voir
			gestionnaireSession->setConnexion(connexiontToClient);

			log->Write(Log::DEBUG,"Demarrage du systeme de Tchat");
			//Démarrage du chat
			chat->run();

			log->Write(Log::DEBUG,"Demarrage du systeme de Zone");

			//si le gestionnaireZone ne démarre pas correctement
			//Inscrit dans les log puis on return null.
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
