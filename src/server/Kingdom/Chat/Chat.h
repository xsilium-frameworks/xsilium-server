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

#include "StructurePacket/StructureChat.h"


/*
 *
 */
class Chat : public ModuleActif {
public:
	Chat(Connexion * connexion);
	virtual ~Chat();

	void run();

	void stopThread();

private:
	static void  threadChat(void * arguments);
	GestionnaireSession * gestionnaireSession ;
};

#endif /* CHAT_H_ */
