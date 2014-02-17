/*
 * gestionnaireTicket.cpp
 *
 *  Created on: 3 avr. 2013
 *      Author: mathieu
 */



#include "gestionnaireTicket.h"

GestionnaireTicket::gestionnaireTicket(Connexion * connexion) : ModuleActif(connexion) {
	endThread = false;
	gestionnaireSession = GestionnaireSession::getInstance();
}

GestionnaireTicket::~gestionnaireTicket() {
//	connexion->removelistenneur((XSILIUM_KINGDOM * 10 ) + ID_CHAT);
}

void GestionnaireTicket::stopThread()
{
	endThread = true;
	condition_Queue.notify_all();
	groupThread.join_all();
}

void GestionnaireTicket::run()
{
	//connexion->addlistenneur((XSILIUM_KINGDOM * 10 )+ ID_CHAT,boost::bind(&Chat::setPacket, this));
	for(uint8_t i = 0;i< NUM_THREAD_MODULE;i++)
	{
		groupThread.add_thread(new boost::thread(&Chat::threadTicket, (void *) this) );
	}
}

void GestionnaireTicket::threadTicket(void* arguments)
{
	GestionnaireTicket * gestionnaireTicket = (GestionnaireTicket *) arguments ;

	while(!gestionnaireTicket->endThread)
	{
		if(!gestionnaireTicket->isEmpty())
		{
			ENetEvent packet = gestionnaireTicket->getPacket();
			CHATTYPEPACKET *data = (CHATTYPEPACKET *) packet.packet->data ;
			switch(data->typeChat)
			{
			case ALLMESSAGE :
				//gestionnaireTicket->messageToAll(&packet);
				break;
			case PERSOMESSAGE :
				//gestionnaireTicket->messageToPerso(&packet);
				break;
			default:
				break;
			}
			gestionnaireTicket->connexion->deletePacket(packet.packet);
		}
	}
}
