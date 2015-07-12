/*
 * RealmManager.h
 *
 *  Created on: 11 juil. 2015
 *      Author: Skronak
 */

#ifndef SRC_SERVER_AUTHENTIFICATION_REALM_SERVICE_REALMMANAGER_H_
#define SRC_SERVER_AUTHENTIFICATION_REALM_SERVICE_REALMMANAGER_H_

#include "Realm/DAO/RealmDAO.h"
#include <vector>

namespace Auth {

class RealmManager : public Singleton<RealmManager> {
public:
	RealmManager();
	virtual ~RealmManager();

	void createRealm();
	void updateRealm();

	std::vector<std::string> getRealmsList();


private:
	std::vector<RealmDAO *> listRoyaume;
};

} /* namespace Auth */

#endif /* SRC_SERVER_AUTHENTIFICATION_REALM_SERVICE_REALMMANAGER_H_ */
