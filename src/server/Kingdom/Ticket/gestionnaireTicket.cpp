/*
 * gestionnaireTicket.cpp
 *
 *  Created on: 3 avr. 2013
 *      Author: mathieu
 */



#include "gestionnaireTicket.h"

gestionnaireTicket::gestionnaireTicket() {
	// TODO Auto-generated constructor stub
	endThread = false;
	gestionnaireSession = GestionnaireSession::getInstance();
}

gestionnaireTicket::~gestionnaireTicket() {
	// TODO Auto-generated destructor stub
}


/*Pour recevoir les tickets*/
ENetEvent  gestionnaireTicket::getPacket()
{
	ENetEvent  packet = ListOfTicketPacket.front();
	ListOfTicketPacket.pop();
	return packet;
}

void gestionnaireTicket::ajouterTicket()
{


}

void gestionnaireTicket::threadTicket(void* arguments)
{
	gestionnaireTicket * ticket = (gestionnaireTicket *) arguments ;

	while(!gestionnaireTicket->endThread)
	{
		/*boost::mutex::scoped_lock lock(gestionnaireTicket->mutexList);
		if(gestionnaireTicket->ListOfTicketPacket.empty())
		{
			gestionnaireTicket->condition_Queue.wait(lock);
		}
		else
		{
			ENetEvent packet = gestionnaireTicket->getPacket();
			lock.unlock();
			Session * session = gestionnaireTicket->gestionnaireSession->trouverSession(packet.peer->address) ;
			sTicketPACKET_C_C *data = (sTicketPACKET_C *) packet.packet->data ;
			*/
		if(gestionnaireTicket->isEmpty())
		{
			ENetEvent packet = gestionnaireTicket->getPacket();
			Session * session = gestionnaireTicket->gestionnaireSession->trouverSession(packet.peer->address) ;
			sTicketPACKET_C *data = (sTicketPACKET_C *) packet.packet->data ;


			switch(data->typeTicket)
			{
				case 0:
				{
					//reçois un ticcket et l'envoi en DB
					sTicketPACKET_C messageData;

					messageData.structure_opcode.opcode = ID_TICKET ;
					messageData.typeTicket = 0;

					std::strcpy(messageData.perso,data->perso);
					std::strcpy(messageData.message,data->message);

					// appelle de ajouterTicket
				}
				case 1:
				{
					//reçois la demander d'un ticket
					sTicketPACKET_C messageData;

					messageData.structure_opcode.opcode = ID_TICKET ;
					messageData.typeTicket = 1;
					//J'ai modifié StructureTicket.h
					std::strcpy(messageData.perso,data->perso);
					std::strcpy(messageData.idTicket,data->idTicket);

				}
				case 2:
				{
					//envoi la liste des ticket enfonction de: perso
					sTicketPACKET_C messageData;

					messageData.structure_opcode.opcode = ID_TICKET ;
					messageData.typeTicket = 2;
				}
				case 3:
				{
					//reçois ordre de suppression de ticket
					sTicketPACKET_C messageData;

					messageData.structure_opcode.opcode = ID_TICKET ;
					messageData.typeTicket = 3;
					std::strcpy(messageData.perso,data->perso);
					std::strcpy(messageData.idTicket,data->idTicket);
				}

			}
			gestionnaireTicket->connexion->deletePacket(packet.packet);
		}

	}
}
