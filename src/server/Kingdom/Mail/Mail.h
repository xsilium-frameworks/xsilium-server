/*
 * Mail.h
 *
 *  Created on: 1 mai 2013
 *      Author: kiti
 *      Gestion des mails
 */

#ifndef MAIL_H_
#define MAIL_H_

#include "ModuleActif/ModuleActif.h"
#include "Session/GestionnaireSession.h"
#include "StructurePacket/StructureMail.h"

enum typeMail
{
	MAIL_S = 0,		//Mail simple,sans pièces jointes
	MAIL_PJ = 1,	//Mail avec pièces Jointes
	MAIL_CR = 2,	//Mail Contre remboursement

};


class Mail : public ModuleActif {
public:
	Mail(Connexion * connexion);
	virtual ~Mail();

	void run();

	void stopThread();

	void sendMail(sMailPacket_C  *data); //gerrer la gestion de la suppression des items dans l'inventaire de la source ? via cpp ?

	void messageSimple(sMailPacket_C  *data);
	void messageMailPJ(sMailPacket_C *data);
	void messageMailContreRemb(sMailPacket_C *data);

private:
	static void  threadMail(void * arguments);
	GestionnaireSession * gestionnaireSession ;
};

#endif /* MAIL_H_ */
