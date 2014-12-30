/*
 * \file worldServeur.h
 *
 *  Created on: \date 27 nov. 2012
 *      Author: \author joda
 *  \brief :
 */

#ifndef WORLDSERVEUR_H_
#define WORLDSERVEUR_H_

#include "Config/Configuration.h"
#include "Logging/Log.h"
#include "SignalHandler/SignalHandler.h"
#include "Connexion/Connexion.h"
#include "Chat/Chat.h"
#include "Session/GestionnaireSession.h"
#include "Zone/GestionnaireZone.h"

/*
 *
 */
class worldServeur {
public:
    /*!
     *  \brief WorldServer
     *
     *  Constructeur de la classe worldServeur.
     *  	- Charge les configs (Singleton)
     *  	- Instancie:
     *  			-> les Logs (Singleton)
     *  			-> la gestion de connexion
     *  			-> Gestionnaire de zone (Singleton)
     *  				-->setConnexionClient ( a voir )
     *
     *  \param
     */
	worldServeur();
	/*!
	 *  \brief ~worldServeur
	 * Destructeur de la classe worldServeur
	 *	Supprime :
	 *		->la connexionToClient
	 *		->chat
	 *	Fait appel au destructeur de :
	 *		-> Configuration
	 *		-> Log
	 *		-> GestionnaireSession
	 *		-> GestionnaireZone
	 *  \param
	 */
	virtual ~worldServeur();
	/*!
	 *  \brief run
	 *	Démmarrage du worldServeur (thread):
	 *		-> chargement des config
	 *		-> inscription dans les Logs
	 *		-> démarrage du chat()
	 *  \param
	 */
	void run();

	void stopThread();

private :
	SignalHandler * signalHandler;
	Configuration * config ;
	Log * log;
	ENetAddress adresse;
	Connexion * connexiontToClient;

	//Kingdom principal
	Chat * chat;
	GestionnaireSession * gestionnaireSession ;
	GestionnaireZone * gestionnaireZone ;

};

#endif /* WORLDSERVEUR_H_ */
