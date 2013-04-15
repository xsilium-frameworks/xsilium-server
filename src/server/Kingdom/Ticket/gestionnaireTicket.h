/*
 * gestionnaireTicket.h
 *
 *  Created on: 3 avr. 2013
 *      Author: mathieu
 */

#ifndef GESTIONNAIRETICKET_H_
#define GESTIONNAIRETICKET_H_

#include "ModuleActif/ModuleActif.h"

#include "Session/GestionnaireSession.h"

#include "StructurePacket/StructureTicket.h"


class gestionnaireTicket {
public:
	gestionnaireTicket();
	virtual ~gestionnaireTicket();
	void ajouterTicket();

	ENetEvent getPacket();

private:

	static void  threadTicket(void * arguments);
	GestionnaireSession * gestionnaireSession ;
};

#endif /* GESTIONNAIRETICKET_H_ */
