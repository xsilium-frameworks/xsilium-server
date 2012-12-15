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
#include <pthread.h>


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
	ENetEvent * getPacket();

private:

	static void * threadChat(void * arguments);

	bool endThread;

	Connexion * connexion;
	pthread_t thread;
	std::queue<ENetEvent *> ListOfTchatPacket;
	pthread_mutex_t mutexList;
};

#endif /* CHAT_H_ */
