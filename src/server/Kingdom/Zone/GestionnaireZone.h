/*
 * \file GestionnaireZone.h
 *
 *  Created on: \date 7 avr. 2013
 *      Author: \author joda
 *  \brief :
 */

#ifndef GESTIONNAIREZONE_H_
#define GESTIONNAIREZONE_H_

#include <stdio.h>
#include <vector>

#include "Singleton/Singleton.h"
#include "Config/Configuration.h"
#include "Connexion/Connexion.h"

#include "Zone/Zone.h"


/*
 *
 */
class GestionnaireZone : public Singleton<GestionnaireZone>
{
	friend class Singleton<GestionnaireZone>;

public:
	GestionnaireZone(Connexion * connexionToClient);
	virtual ~GestionnaireZone();

	bool run ();
	void stop();


	void creeZone();
	Zone * trouveZone(ENetAddress address);
	void supprimerZone();

	void sendToZone(Zone * zone, ENetPacket * packet);


private:
	std::vector<Zone *> listOfZone ;
	std::vector<Zone *>::iterator zone ;

	Configuration * config ;


	Connexion * connexionToClient;
	Connexion * connexionToZone;

	boost::mutex mutexZone;



};

#endif /* GESTIONNAIREZONE_H_ */
