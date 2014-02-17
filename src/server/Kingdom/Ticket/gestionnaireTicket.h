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


class GestionnaireTicket : public ModuleActif {

public:
	GestionnaireTicket(Connexion * connexion);
	virtual ~GestionnaireTicket();

	void run();

	void stopThread();

	bool ajouterTicket(ENetEvent * packet, bool cppUnit = false);
	bool supprimerTicket(ENetEvent * packet, bool cppUnit = false);

private:

	static void  threadTicket(void * arguments);
	GestionnaireSession * gestionnaireSession ;
};

#endif /* GESTIONNAIRETICKET_H_ */
