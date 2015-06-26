/*
 * \file ChatManager.cpp
 *
 *  Created on: \date 3 janv. 2015
 *      Author: \author joda
 *  \brief :
 */
#include "ChatManager.h"

namespace Kingdom {

ChatManager::ChatManager(NetworkManager * networkManager) {
	this->networkManager = networkManager;
	config = Configuration::getInstance();
	log = Log::getInstance();
}

ChatManager::~ChatManager() {
	networkManager->removeListenneur(ID_CHAT);
}

void ChatManager::run()
{
	networkManager->addListenneur(ID_CHAT,this);
	NetworkListener::run();
}

void ChatManager::ProcessPacket(MessageNetwork * messageNetwork)
{
	log->write(Log::DEBUG,"Nouveau Packet de Chat");
	MessagePacket * messageRetour = new MessagePacket();

	// En cas de spam le message n'est pas envoye
	switch(messageNetwork->messagePacket->getSousOpcode())
	{
	case ID_KINGDOM :
		HandleChatKingdom(messageNetwork, messageRetour);
		SendPacketChat(messageNetwork, messageRetour, ID_KINGDOM);
		networkManager->sendPacket(networkManager->getHost(),0,messageRetour);
		break;
	case ID_AREA :
		HandleChatArea(messageNetwork, messageRetour);
		SendPacketChat(messageNetwork, messageRetour, ID_AREA);
		break;
	case ID_PRIVATE :
		HandleChatPrivate(messageNetwork, messageRetour);
		SendPacketChat(messageNetwork, messageRetour, ID_PRIVATE);
		break;
	case ID_COMMUNITY :
		HandleChatCommunity(messageNetwork, messageRetour);
		SendPacketChat(messageNetwork, messageRetour, ID_COMMUNITY);
		break;
	default:
		break;
	}
}

int  ChatManager::HandleChatKingdom(MessageNetwork * messageNetwork,MessagePacket * messageRetour)
{
	// Controle presence proprietes du message
	if(!messageNetwork->messagePacket->hasProperty("canal")||!messageNetwork->messagePacket->hasProperty("text"))
	{
		log->write(Log::INFO,"Le message venant de %d:%d est illisible ",messageNetwork->session->getSessionID()->host,messageNetwork->session->getSessionID()->port);
		messageRetour->setOpcode(ID_CHAT);
		messageRetour->setSousOpcode(ID_ERREUR);
		messageRetour->setProperty("ErrorId",ID_ERROR_PACKET_SIZE);
		return ID_ERROR_PACKET_SIZE ;
	}
	messageRetour->setOpcode(ID_CHAT);
	messageRetour->setSousOpcode(ID_PRIVATE);

	return ID_NOERROR;
}

int  ChatManager::HandleChatPrivate(MessageNetwork * messageNetwork,MessagePacket * messageRetour)
{
	// Controle presence proprietes du message
	if(!messageNetwork->messagePacket->hasProperty("name_dest")||!messageNetwork->messagePacket->hasProperty("text"))
	{
		log->write(Log::INFO,"Le message venant de %d:%d est illisible ",messageNetwork->session->getSessionID()->host,messageNetwork->session->getSessionID()->port);
		messageRetour->setOpcode(ID_CHAT);
		messageRetour->setSousOpcode(ID_ERREUR);
		messageRetour->setProperty("ErrorId",ID_ERROR_PACKET_SIZE);
		return ID_ERROR_PACKET_SIZE ;
	}
}

int  ChatManager::HandleChatArea(MessageNetwork * messageNetwork,MessagePacket * messageRetour)
{
	// Controle presence proprietes du message
	if(!messageNetwork->messagePacket->hasProperty("id_area")||!messageNetwork->messagePacket->hasProperty("text"))
	{
		log->write(Log::INFO,"Le message venant de %d:%d est illisible ",messageNetwork->session->getSessionID()->host,messageNetwork->session->getSessionID()->port);
		messageRetour->setOpcode(ID_CHAT);
		messageRetour->setSousOpcode(ID_ERREUR);
		messageRetour->setProperty("ErrorId",ID_ERROR_PACKET_SIZE);

		return ID_ERROR_PACKET_SIZE ;
	}
	messageRetour->setOpcode(ID_CHAT);
	messageRetour->setSousOpcode(ID_PRIVATE);

	return ID_NOERROR;
}

int  ChatManager::HandleChatCommunity(MessageNetwork * messageNetwork,MessagePacket * messageRetour)
{
	// Controle presence proprietes du message
	if(!messageNetwork->messagePacket->hasProperty("id_community")||!messageNetwork->messagePacket->hasProperty("text"))
	{
		log->write(Log::INFO,"Le message venant de %d:%d est illisible ",messageNetwork->session->getSessionID()->host,messageNetwork->session->getSessionID()->port);
		messageRetour->setOpcode(ID_CHAT);
		messageRetour->setSousOpcode(ID_ERREUR);
		messageRetour->setProperty("ErrorId",ID_ERROR_PACKET_SIZE);

		return ID_ERROR_PACKET_SIZE ;
	}
	messageRetour->setOpcode(ID_CHAT);
	messageRetour->setSousOpcode(ID_COMMUNITY);

	return ID_NOERROR;
}
//TODO Implementation SpamDetector
bool ChatManager::SpamDetector(MessageNetwork * messageNetwork,MessagePacket * messageRetour)
{
	messageRetour->setOpcode(ID_CHAT);
	messageRetour->setSousOpcode(ID_ERREUR);
	messageRetour->setProperty("ErrorId",ID_SPAM);

	return false;
}

void ChatManager::SendPacketChat(MessageNetwork * messageNetwork,MessagePacket * messageRetour, int typeForChat) {
	if (messageRetour->getSousOpcode() == ID_ERREUR)
	{
		networkManager->sendPacket(messageNetwork->session->getSessionPeer(),0,messageRetour);
	} else {

		switch(typeForChat)
			{
			case ID_KINGDOM :
				networkManager->sendPacket(networkManager->getHost(),0,messageRetour);
				break;
			case ID_AREA :
				// envoie au joueurs de la zone uniquement
				break;
			case ID_PRIVATE :
				// envoi a un joueur spécifique
				break;
			case ID_COMMUNITY :
				// envoie a une liste de joueur
				break;
			}
	}
}

}/* namespace Kingdom */
