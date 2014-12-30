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
	connexion->removelistenneur((XSILIUM_KINGDOM * 1000 ) + ID_MAIL);
}

void Mail::stopThread()
{
	endThread = true;
	condition_Queue.notify_all();
	groupThread.join_all();
}

void Mail::run()
{
	connexion->addlistenneur((XSILIUM_KINGDOM * 1000 )+ ID_MAIL,boost::bind(&Mail::setPacket, this));
	for(uint8_t i = 0;i< NUM_THREAD_MODULE;i++)
	{
		groupThread.add_thread(new boost::thread(&Mail::threadMail, (void *) this) );
	}
}

void Mail::messageSimple(sMailPacket_C *data)  //Message simple
{
	sMailPacket_C mailData;


	mailData.structure_opcode.cmd = XSILIUM_KINGDOM ;
	mailData.structure_opcode.opcode = ID_MAIL ;
	mailData.typeMail = MAIL_S;

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
	mailData.structure_opcode.opcode = ID_MAIL ;
	mailData.typeMail = MAIL_PJ;

	std::strcpy(mailData.perso_out,data->perso_out);
	std::strcpy(mailData.perso_in,data->perso_in);
	std::strcpy(mailData.objet_mail,data->objet_mail);
	for ( int increment = 0; increment < sizeof(data->item_mail);increment++)
	{
		mailData.item_mail[increment] = data->item_mail[increment];	//Besoin de faire des tests sur la viabilité des objets ? Inventaires toussa toussa
	}

	std::strcpy(mailData.corps_mail,data->corps_mail);

	ENetPacket * message = enet_packet_create ((const void *)&mailData,sizeof(mailData) + 1,ENET_PACKET_FLAG_RELIABLE); // d'où vient message utilité enetpacket ?
	connexion->sendPacket(connexion->getServer(), 0, message);
}

void Mail::messageMailContreRemb(sMailPacket_C *data)  //Message avec pièces jointes faire un héritage mail simple ? Idem mail CR = mail simple + mail PJ
{
	sMailPacket_C mailData;


	mailData.structure_opcode.cmd = XSILIUM_KINGDOM ;
	mailData.structure_opcode.opcode = ID_MAIL ;
	mailData.typeMail = MAIL_CR;

	std::strcpy(mailData.perso_out,data->perso_out);
	std::strcpy(mailData.perso_in,data->perso_in);
	std::strcpy(mailData.objet_mail,data->objet_mail);

	for ( int increment = 0; increment < sizeof(data->item_mail);increment++)
	{
		mailData.item_mail[increment] = data->item_mail[increment];	//Besoin de faire des tests sur la viabilité des objets ? Inventaires toussa toussa
	}

	std::strcpy(mailData.corps_mail,data->corps_mail);
	mailData.contre_remb = data->contre_remb;	//utile ?
	mailData.val_remb = data->val_remb;

	ENetPacket * message = enet_packet_create ((const void *)&mailData,sizeof(mailData) + 1,ENET_PACKET_FLAG_RELIABLE); // d'où vient message utilité enetpacket ?
	connexion->sendPacket(connexion->getServer(), 0, message);
}


void Mail::threadMail(void* arguments)
{
	Mail * mail = static_cast<Mail *> (arguments) ;

	while(!mail->endThread)
	{
		if(!mail->isEmpty())
		{
			ENetEvent packet = mail->getPacket();
			Session * session = mail->gestionnaireSession->trouverSession(packet.peer->address) ;
			sMailPacket_C *data = (sMailPacket_C *) packet.packet->data ;
			switch(data->typeMail)
			{
			case MAIL_S :
				mail->messageSimple(data);
				break;
			case MAIL_PJ :
				mail->messageMailPJ(data);
				break;
			case MAIL_CR :
				mail->messageMailContreRemb(data);
				break;

			default:
				break;
			}
			mail->connexion->deletePacket(packet.packet);
		}
	}
}

