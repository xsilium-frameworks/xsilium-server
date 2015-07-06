/*
 * TicketManager.cpp
 *
 *  Created on: 27 juin 2015
 *      Author: Skronak
 */

#include "TicketManager.h"

namespace Kingdom {

TicketManager::TicketManager(NetworkManager * networkManager) {
	this->networkManager = networkManager;
	config = Configuration::getInstance();
	log = Log::getInstance();
}

TicketManager::~TicketManager() {
	networkManager->removeListenneur(ID_TICKET);
}

void TicketManager::run()
{
	networkManager->addListenneur(ID_TICKET,this);
	NetworkListener::run();
}

void TicketManager::processPacket(MessageNetwork * messageNetwork)
{
	log->write(Log::DEBUG,"Nouveau Packet de ticket");
	MessagePacket messageRetour ;
	Ticket ticket;

	switch(messageNetwork->messagePacket->getSousOpcode())
	{
	case ID_CREATE :
		handleTicketCreate(messageNetwork,&messageRetour);
		createTicket(messageNetwork,&messageRetour);
		break;
	case ID_EDIT :
		handleTicketEdit(messageNetwork,&messageRetour);
		//editTicket();
		break;
	case ID_SHOW :
		handleTicketRead(messageNetwork,&messageRetour);
		//readTicket();
		break;
	case ID_DELETE :
		handleTicketSuppr(messageNetwork,&messageRetour);
		//deleteTicket();
		break;
	}
	networkManager->sendPacket(messageNetwork->session->getSessionPeer(),0,&messageRetour);
}

int  TicketManager::handleTicketCreate(MessageNetwork * messageNetwork,MessagePacket * messageRetour)
{
	// Controle Presence Donnee
	if(!messageNetwork->messagePacket->hasProperty("text")||!messageNetwork->messagePacket->hasProperty("title")||!messageNetwork->messagePacket->hasProperty("coord") || !messageNetwork->messagePacket->hasProperty("category")|| !messageNetwork->messagePacket->hasProperty("subCategory")||!messageNetwork->messagePacket->hasProperty("idReporter") )
	{
		log->write(Log::INFO,"Le message venant de %d:%d est illisible ",messageNetwork->session->getSessionID()->host,messageNetwork->session->getSessionID()->port);
		messageRetour->setOpcode(ID_TICKET);
		messageRetour->setSousOpcode(ID_ERREUR);
		messageRetour->setProperty("ErrorId",ID_ERROR_PACKET_SIZE);
		return ID_ERROR_PACKET_SIZE ;
	}
	return 0;
}

void TicketManager::createTicket(MessageNetwork * messageNetwork, MessagePacket * messageRetour) {
	Ticket ticket;
	ticket.setTitle(messageNetwork->messagePacket->getProperty("title"));
	ticket.setText(messageNetwork->messagePacket->getProperty("text"));
	ticket.setCategory(messageNetwork->messagePacket->getProperty("category"));
	ticket.setSubCategory(messageNetwork->messagePacket->getProperty("subCategory"));
	//ticket.setCoord();  TODO: recuperation des coordonnees du joueur
	//ticket.setIdReporter(messageNetwork->messagePacket->getProperty("idReporter").);

	if (ticket.create()) {
		messageRetour->setOpcode(ID_TICKET);
		messageRetour->setSousOpcode(ID_ERREUR);
		messageRetour->setProperty("ErrorId",ID_ERROR_DB);
	}
}

} /* namespace Kingdom */
