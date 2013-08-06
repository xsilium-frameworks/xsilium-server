/*
 * \file Session.h
 *
 *  Created on: \date 12 janv. 2013
 *      Author: \author joda
 *  \brief :
 */

#ifndef SESSION_H_
#define SESSION_H_

#include "enet/enet.h"
#include "Compte/Compte.h"

#include "Databases/LoginDatabase.h"
#include "Compte/GestionnaireCompte.h"


/*
 *
 */
class Session {
public:
	Session();
	virtual ~Session();

	void setSessionPeer(ENetPeer * peer);
	ENetPeer * getSessionPeer();
	ENetAddress * getSessionID();


	void banIP(time_t unbandate,const char * raison,int bannedby);
	void unbanIP();
	bool isBanned();
	time_t getUnBanDate();

	void ajoutIPTemps();
	void supprimeIPTemps();
	int getNBIPTemps();

	void setCompte(Compte * compte);
	Compte * getCompte();




private:
	ENetPeer * peer;
	time_t unbandate;
	int ipNBEssai;
    LoginDatabase * compteDB ;
    GestionnaireCompte * gestionnaireCompte;
    Compte * compte;
};

#endif /* SESSION_H_ */
