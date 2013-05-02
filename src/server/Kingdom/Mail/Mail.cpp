/*
 * Mail.cpp
 *
 *  Created on: 1 mai 2013
 *      Author: kiti
 */

#include "Mail.h"

Mail::Mail(Connexion * connexion) : ModuleActif(connexion) {
	endThread = false;
	gestionnaireSession = GestionnaireSession::getInstance();
}

Mail::~Mail() {
	connexion->removelistenneur((XSILIUM_KINGDOM * 10 ) + ID_Mail);
}

void Mail::stopThread()
{
	endThread = true;
	condition_Queue.notify_all();
	groupThread.join_all();
}

void Mail::run()
{
	connexion->addlistenneur((XSILIUM_KINGDOM * 10 )+ ID_Mail,boost::bind(&Mail::setPacket, this));
	for(uint8_t i = 0;i< NUM_THREAD_MODULE;i++)
	{
		groupThread.add_thread(new boost::thread(&Mail::threadMail, (void *) this) );
	}
}

void Mail::messageSimple(sMailPacket_C *data)  //Message simple
{
	sMailPacket_C mailData;


	mailData.structure_opcode.cmd = XSILIUM_KINGDOM ;
	mailData.structure_opcode.opcode = ID_Mail ;
	mailData.typeMail = 0;

	std::strcpy(mailData.perso_out,data->perso_out);
	std::strcpy(mailData.perso_in,data->perso_in);
	std::strcpy(mailData.corps_mail,data->corps_mail);

	ENetPacket * message = enet_packet_create ((const void *)&mailData,sizeof(mailData) + 1,ENET_PACKET_FLAG_RELIABLE); // d'où vient message utilité enetpacket ?
	connexion->sendPacket(connexion->getServer(), 0, message);
}


void Mail::messageMailPJ(sMailPacket_C *data)  //Message avec pièces jointes faire un héritage mail simple ? Idem mail CR = mail simple + mail PJ
{
	sMailPacket_C mailData;


	mailData.structure_opcode.cmd = XSILIUM_KINGDOM ;
	mailData.structure_opcode.opcode = ID_Mail ;
	mailData.typeMail = 1;

	std::strcpy(mailData.perso_out,data->perso_out);
	std::strcpy(mailData.perso_in,data->perso_in);
	std::strcpy(mailData.objet_mail,data->objet_mail);
	std::strcpy(mailData.item1_mail,data->item1_mail);	//Besoin de faire des tests sur la viabilité des objets ? Inventaires toussa toussa
	std::strcpy(mailData.item2_mail,data->item2_mail);
	std::strcpy(mailData.item3_mail,data->item3_mail);
	std::strcpy(mailData.item4_mail,data->item4_mail);
	std::strcpy(mailData.item5_mail,data->item5_mail);	// Peos (idem item)
	std::strcpy(mailData.corps_mail,data->corps_mail);

	ENetPacket * message = enet_packet_create ((const void *)&mailData,sizeof(mailData) + 1,ENET_PACKET_FLAG_RELIABLE); // d'où vient message utilité enetpacket ?
	connexion->sendPacket(connexion->getServer(), 0, message);
}

void Mail::messageMailContreRemb(sMailPacket_C *data)  //Message avec pièces jointes faire un héritage mail simple ? Idem mail CR = mail simple + mail PJ
{
	sMailPacket_C mailData;


	mailData.structure_opcode.cmd = XSILIUM_KINGDOM ;
	mailData.structure_opcode.opcode = ID_Mail ;
	mailData.typeMail = 2;

	std::strcpy(mailData.perso_out,data->perso_out);
	std::strcpy(mailData.perso_in,data->perso_in);
	std::strcpy(mailData.objet_mail,data->objet_mail);
	std::strcpy(mailData.item1_mail,data->item1_mail);	//Besoin de faire des tests sur la viabilité des objets ? Inventaires toussa toussa
	std::strcpy(mailData.item2_mail,data->item2_mail);
	std::strcpy(mailData.item3_mail,data->item3_mail);
	std::strcpy(mailData.item4_mail,data->item4_mail);
	std::strcpy(mailData.item5_mail,data->item5_mail);	// Peos (idem item)
	std::strcpy(mailData.corps_mail,data->corps_mail);
	std::strcpy(mailData.contre_remb,data->contre_remb);	//utile ?
	std::strcpy(mailData.val_remb,data->val_remb);

	ENetPacket * message = enet_packet_create ((const void *)&mailData,sizeof(mailData) + 1,ENET_PACKET_FLAG_RELIABLE); // d'où vient message utilité enetpacket ?
	connexion->sendPacket(connexion->getServer(), 0, message);
}


void Mail::threadMail(void* arguments)
{
	Mail * mail = (Mail *) arguments ;

	while(!Mail->endThread)
	{
		if(!Mail->isEmpty())
		{
			ENetEvent packet = Mail->getPacket();
			Session * session = Mail->gestionnaireSession->trouverSession(packet.peer->address) ;
			sMailPacket_C *data = (sMailPacket_C *) packet.packet->data ;
			switch(data->typeMail)
			{
			case MAIL_S :
				Mail->messageSimple(data);
				break;
			case MAIL_PJ :
				Mail->messageMailPJ(data);
				break;
			case MAIL_CR :
				Mail->messageMailContreRemb(data);
				break;

			default:
				break;
			}
			Mail->connexion->deletePacket(packet.packet);
		}
	}
}

