/*
 * \file IP.h
 *
 *  Created on: \date 21 févr. 2015
 *      Author: \author joda
 *  \brief :
 */
#ifndef SRC_SERVER_SHARED_IP_IP_H_
#define SRC_SERVER_SHARED_IP_IP_H_

#include <Databases/DatabaseManager.h>

enum IPDatabaseStatements {
	REALMS_DEL_IPTEMPORAIRE_SUPPRLIGNEIP,
	REALMS_SEL_IPTEMPORAIRE_LECTURENERREURS,
	REALMS_INS_IPTEMPORAIRE_STOCKAGEIPTEMPORAIRE,
	REALMS_UPD_IPTEMPORAIRE_MAJIPTEMPORAIRE,
	REALMS_SEL_IPBANNED_INFOSSURIPBANNIES,
	REALMS_INS_IPBANNED_BANIP,
	REALMS_UPD_IPBANNED_DEBANAUTOIP,
	REALMS_UPD_IPBANNED_DEBANIP
};

/*
 *
 */
class IP {
public:
	IP(char * hostip );
	virtual ~IP();

	void banIP(time_t unbandate, const char * raison, int bannedby);
	void unbanIP();
	bool isBanned();
	time_t getUnBanDate();

	void ajoutIPTemps();
	void supprimeIPTemps();
	int getNBIPTemps();

private:
	time_t unbandate;
	int ipNBEssai;
	DatabaseManager * database;
	std::string suffix;
	char * hostip;
};

#endif /* SRC_SERVER_SHARED_IP_IP_H_ */
