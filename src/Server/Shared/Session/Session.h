/*
 * \file Session.h
 *
 *  Created on: \date 16 déc. 2014
 *      Author: \author joda
 *  \brief :
 */
#ifndef SRC_SERVER_SHARED_SESSION_SESSION_H_
#define SRC_SERVER_SHARED_SESSION_SESSION_H_

#include <enet/enet.h>
#include "Databases/DatabaseManager.h"
#include "Compte/Compte.h"

/*
 *
 */

enum SessionDatabaseStatements {
	REALMS_DEL_IPTEMPORAIRE_SUPPRLIGNEIP,
	REALMS_SEL_IPTEMPORAIRE_LECTURENERREURS,
	REALMS_INS_IPTEMPORAIRE_STOCKAGEIPTEMPORAIRE,
	REALMS_UPD_IPTEMPORAIRE_MAJIPTEMPORAIRE,
	REALMS_SEL_IPBANNED_INFOSSURIPBANNIES,
	REALMS_INS_IPBANNED_BANIP,
	REALMS_UPD_IPBANNED_DEBANAUTOIP,
	REALMS_UPD_IPBANNED_DEBANIP
};

class Session {
public:
	Session();
	virtual ~Session();

	void setSessionPeer(ENetPeer * peer);
	ENetPeer * getSessionPeer();
	ENetAddress * getSessionID();

	void banIP(time_t unbandate, const char * raison, int bannedby);
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
	DatabaseManager * database;
	std::string suffix;

	Compte * compte;


};

#endif /* SRC_SERVER_SHARED_SESSION_SESSION_H_ */
