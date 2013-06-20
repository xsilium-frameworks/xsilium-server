/*
 * \file Chat.cpp
 *
 *  Created on: \date 5 dŽc. 2012
 *      Author: \author joda
 *  \brief :
 */

#include "Chat.h"

Chat::Chat(Connexion * connexion) : ModuleActif(connexion) {
	endThread = false;
	gestionnaireSession = GestionnaireSession::getInstance();
	gestionnaireZone = GestionnaireZone::getInstance();
}

Chat::~Chat() {
	connexion->removelistenneur((XSILIUM_KINGDOM * 10 ) + ID_CHAT);
}

void Chat::stopThread()
{
	endThread = true;
	condition_Queue.notify_all();
	groupThread.join_all();
}

void Chat::run()
{
	connexion->addlistenneur((XSILIUM_KINGDOM * 10 )+ ID_CHAT,boost::bind(&Chat::setPacket, this));
	for(uint8_t i = 0;i< NUM_THREAD_MODULE;i++)
	{
		groupThread.add_thread(new boost::thread(&Chat::threadChat, (void *) this) );
	}
}

ENetPacket * Chat::messageToAll(ENetEvent * packet)
{
	if (packet->packet->dataLength >= sizeof(sChatPacket_C))
	{
		Session * session = gestionnaireSession->trouverSession(packet->peer->address) ;


		sChatPacket_C *data = (sChatPacket_C *) packet->packet->data ;
		sChatPacket_C messageData;


		messageData.charTypePacket.structure_opcode.cmd = XSILIUM_KINGDOM ;
		messageData.charTypePacket.structure_opcode.opcode = ID_CHAT ;
		messageData.charTypePacket.typeChat = 0;

		std::strcpy(messageData.perso,data->perso);
		std::strcpy(messageData.message,data->message);

		return enet_packet_create ((const void *)&messageData,sizeof(messageData) + 1,ENET_PACKET_FLAG_RELIABLE);
	}
	else
	{
		return NULL;
	}
}

ENetPacket * Chat::messageToPerso(ENetEvent * packet)
{
	if (packet->packet->dataLength >= sizeof(sChatPacket_C))
	{
		Session * session = gestionnaireSession->trouverSession(packet->peer->address) ;


		sChatPacket_C *data = (sChatPacket_C *) packet->packet->data ;
		sChatPacket_C messageData;


		messageData.charTypePacket.structure_opcode.cmd = XSILIUM_KINGDOM ;
		messageData.charTypePacket.structure_opcode.opcode = ID_CHAT ;
		messageData.charTypePacket.typeChat = 0;

		std::strcpy(messageData.perso,data->perso);
		std::strcpy(messageData.message,data->message);

		return enet_packet_create ((const void *)&messageData,sizeof(messageData) + 1,ENET_PACKET_FLAG_RELIABLE);
	}
	else
	{
		return NULL;
	}
}

void Chat::threadChat(void* arguments)
{
	Chat * chat = (Chat *) arguments ;

	while(!chat->endThread)
	{
		if(!chat->isEmpty())
		{
			ENetEvent packet = chat->getPacket();
			sChatPacket_C *data = (sChatPacket_C *) packet.packet->data ;
			ENetPacket * message = NULL;
			switch(data->typeChat)
			{
			case ALLMESSAGE :
				message = chat->messageToAll(&packet);
				break;
			case PERSOMESSAGE :
				message = chat->messageToPerso(&packet);
				break;
			default:
				break;
			}
			if(message != NULL)
			{
				chat->connexion->sendPacket(chat->connexion->getServer(), 0, message);
			}
			chat->connexion->deletePacket(packet.packet);
		}
	}
}
