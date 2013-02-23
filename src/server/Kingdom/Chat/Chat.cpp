/*
 * \file Chat.cpp
 *
 *  Created on: \date 5 dŽc. 2012
 *      Author: \author joda
 *  \brief :
 */

#include "Chat.h"

Chat::Chat() {
	endThread = false;
	gestionnaireSession = GestionnaireSession::getInstance();
}

Chat::~Chat() {
	connexion->removelistenneur(XSILIUM_KINGDOM,ID_CHAT);
}

void Chat::setConnexionLogin(Connexion * connexion )
{
	this->connexion = connexion ;
}

void Chat::setPacket()
{
	boost::mutex::scoped_lock lock(mutexList);

	ListOfTchatPacket.push(*(connexion->getPacket()));
	lock.unlock();
	condition_Queue.notify_one();
}

ENetEvent  Chat::getPacket()
{
	ENetEvent  packet = ListOfTchatPacket.front();
	ListOfTchatPacket.pop();
	return packet;
}

void Chat::stopThread()
{
	endThread = true;
	for(uint8_t i = 0;i< 4;i++)
	{
		condition_Queue.notify_one();
	}
}

void Chat::run()
{
	connexion->addlistenneur(XSILIUM_KINGDOM,ID_CHAT,this,&Chat::setPacket );
	for(uint8_t i = 0;i< 4;i++)
	{
		thread[i] = boost::thread(&Chat::threadChat, (void *) this);
	}
}

void Chat::threadChat(void* arguments)
{
	Chat * chat = (Chat *) arguments ;

	while(!chat->endThread)
	{
		boost::mutex::scoped_lock lock(chat->mutexList);

		if(chat->ListOfTchatPacket.empty())
		{
			chat->condition_Queue.wait(lock);
		}
		else
		{
			ENetEvent packet = chat->getPacket();
			Session * session = chat->gestionnaireSession->trouverSession(packet.peer->address) ;
			sChatPacket_C *data = (sChatPacket_C *) packet.packet->data ;

			if( data->typeChat == 0)
			{
				sChatPacket_C messageData;


				messageData.structure_opcode.cmd = XSILIUM_KINGDOM ;
				messageData.structure_opcode.opcode = ID_CHAT ;
				messageData.typeChat = 0;

				std::strcpy(messageData.perso,data->perso);
				std::strcpy(messageData.message,data->message);

				ENetPacket * message = enet_packet_create ((const void *)&messageData,sizeof(messageData) + 1,ENET_PACKET_FLAG_RELIABLE);
				enet_host_broadcast (chat->connexion->getServer(), 0, message);
				chat->connexion->deletePacket(packet.packet);
			}

		}
		lock.unlock();
	}
}
