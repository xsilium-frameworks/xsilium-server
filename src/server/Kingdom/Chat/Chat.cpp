/*
 * \file Chat.cpp
 *
 *  Created on: \date 5 dŽc. 2012
 *      Author: \author joda
 *  \brief :
 */

#include "Chat.h"

Chat::Chat() {
	connexion = Connexion::getInstance();
	pthread_mutex_init(&mutexList,NULL);

	endThread = false;


}

Chat::~Chat() {
	connexion->removelistenneur(XSILIUM_KINGDOM,ID_REC_CHAT);
}

void Chat::setPacket()
{
	pthread_mutex_lock( &mutexList );
	ListOfTchatPacket.push(connexion->getPacket());
	pthread_mutex_unlock( &mutexList );
}

ENetEvent * Chat::getPacket()
{
	pthread_mutex_lock( &mutexList );
	ENetEvent * packet = ListOfTchatPacket.front();
	ListOfTchatPacket.pop();
	return packet;
	pthread_mutex_unlock( &mutexList );
}

void Chat::stopThread()
{
	endThread = true;
	pthread_join(thread,NULL);
}

void Chat::run()
{
	connexion->addlistenneur(XSILIUM_KINGDOM,ID_REC_CHAT,this,&Chat::setPacket );
	pthread_create(&thread,NULL,Chat::threadChat,(void *)this);
}

void* Chat::threadChat(void* arguments)
{
	Chat * chat = (Chat *) arguments ;

	while(chat->endThread == false)
	{
		if(!chat->ListOfTchatPacket.empty())
		{

		}
		else
			sleep(0.1);
	}

	return NULL;
}
