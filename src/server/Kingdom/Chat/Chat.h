/*
 * \file Chat.h
 *
 *  Created on: \date 5 déc. 2012
 *      Author: \author joda
 *  \brief :
 */

#ifndef CHAT_H_
#define CHAT_H_

#include "ModuleActif/ModuleActif.h"

#include "Session/GestionnaireSession.h"
#include "Zone/GestionnaireZone.h"

#include "StructurePacket/StructureChat.h"

enum typeFormessage
{
	ALLMESSAGE = 0,
	ZONEMESSAGE,
	GUILDMESSAGE,
	GROUPEMESSAGE,
	PERSOMESSAGE

};


/*
 *
 */
class Chat : public ModuleActif {
public:
	Chat(Connexion * connexion);
	virtual ~Chat();

	void run();

	void stopThread();


	bool messageToAll(ENetEvent * packet, bool cppUnit = false);
	bool messageToPerso(ENetEvent * packet, bool cppUnit = false);

private:
	static void  threadChat(void * arguments);
	GestionnaireSession * gestionnaireSession ;
	GestionnaireZone * gestionnaireZone ;
};

#endif /* CHAT_H_ */
