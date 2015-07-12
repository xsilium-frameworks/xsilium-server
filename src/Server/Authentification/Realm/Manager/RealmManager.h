/*
 * RealmManager.h
 *
 *  Created on: 11 juil. 2015
 *      Author: Skronak
 */

#ifndef SRC_SERVER_AUTHENTIFICATION_REALM_SERVICE_REALMMANAGER_H_
#define SRC_SERVER_AUTHENTIFICATION_REALM_SERVICE_REALMMANAGER_H_

#include "Realm/DAO/RealmDAO.h"
#include <Configuration/Configuration.h>
#include <vector>

namespace Auth {

class RealmManager : public Singleton<RealmManager> {
public:
	RealmManager();
	virtual ~RealmManager();

	void createRealm();
	void updateRealm();
	/*!
	 * Methode de verification de l'existence d'un realm par son nom
	 * @param nameRoyaume
	 * @return idRealm ou 0 si non trouv�
	 */
	int checkRealmName(std::string nameRealm);
	/*!
	 * Methode de verification de la cl� d'un realm
	 * @param nameRoyaume
	 * @return bool
	 */
	bool checkRealmKey(std::string keyRealm);

	std::vector<std::string> getRealmsList();


private:
	std::vector<RealmDAO *> listRoyaume;
	Configuration * configuration;
};

} /* namespace Auth */

#endif /* SRC_SERVER_AUTHENTIFICATION_REALM_SERVICE_REALMMANAGER_H_ */
