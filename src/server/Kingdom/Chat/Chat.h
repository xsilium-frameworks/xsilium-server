/*
 * \file Chat.h
 *
 *  Created on: \date 5 déc. 2012
 *      Author: \author joda
 *  \brief :
 */

#ifndef CHAT_H_
#define CHAT_H_

#include "Connexion/Connexion.h"

#include "Opcode/Opcode.h"

#include <queue>
#include <boost/thread.hpp>

#include "Session/GestionnaireSession.h"

#include "StructurePacket/StructureChat.h"


/*
 *
 */
class Chat {
public:
	Chat();
	virtual ~Chat();

	void run();

	void stopThread();

	void setPacket();
	ENetEvent getPacket();

	void setConnexionLogin(Connexion * connexion );

private:

	static void  threadChat(void * arguments);

	bool endThread;

	Connexion * connexion;
	boost::thread thread[4];
	std::queue<ENetEvent> ListOfTchatPacket;
	boost::mutex mutexList;
	boost::condition_variable condition_Queue;

	GestionnaireSession * gestionnaireSession ;
};

#endif /* CHAT_H_ */
