/*
 * \file Chat.cpp
 *
 *  Created on: \date 3 janv. 2015
 *      Author: \author joda
 *  \brief :
 */
#include "Chat.h"

namespace Kingdom {

Chat::Chat(NetworkManager * networkManager) {
	this->networkManager = networkManager;
	config = Configuration::getInstance();
	log = Log::getInstance();
}

Chat::~Chat() {
	networkManager->removeListenneur(ID_CHAT);
}

void Chat::run()
{
	networkManager->addListenneur(ID_CHAT,this);
	NetworkListener::run();
}

void Chat::processPacket(MessageNetwork * messageNetwork)
{
	log->write(Log::DEBUG,"Nouveau Packet de Chat");
	MessagePacket * messageRetour = new MessagePacket();
	switch(messageNetwork->messagePacket->getSousOpcode())
	{
	case ID_WORLD :
		HandleChatWorld(messageNetwork,messageRetour);
		break;
	case ID_AREA :
		HandleChatArea(messageNetwork,messageRetour);
		break;
	case ID_TRADE :
		HandleChatTrade(messageNetwork,messageRetour);
		break;
	case ID_PRIVATE :
		HandleChatPrivate(messageNetwork,messageRetour);
		break;
	default:
		break;
	}
	networkManager->sendPacket(messageNetwork->session->getSessionPeer(),0,messageRetour);
}

int  Chat::HandleChatPrivate(MessageNetwork * messageNetwork,MessagePacket * messageRetour)
{
	// Controle presence donnée identifiant du destinataire
	if(!messageNetwork->messagePacket->hasProperty("id_dest"))
	{
		log->write(Log::INFO,"Le message venant de %d:%d est illisible ",messageNetwork->session->getSessionID()->host,messageNetwork->session->getSessionID()->port);
		messageRetour->setOpcode(ID_AUTH);
		messageRetour->setSousOpcode(ID_ERREUR);
		messageRetour->setProperty("ErrorId",ID_ERROR_PACKET_SIZE);
		return ID_ERROR_PACKET_SIZE ;
	}

	messageRetour->setOpcode(ID_CHAT);
	messageRetour->setSousOpcode(ID_PRIVATE);
	messageRetour->setProperty("Key",1234567);

	return ID_NOERROR;
}

// envoi à cette personne



















}
/* namespace Kingdom */
