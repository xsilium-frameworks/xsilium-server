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
	worldServeur();
	virtual ~worldServeur();
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
