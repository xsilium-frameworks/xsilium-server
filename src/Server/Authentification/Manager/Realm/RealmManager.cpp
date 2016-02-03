/*
 * RealmManager.cpp
 *
 *  Created on: 11 juil. 2015
 *      Author: Skronak
 */

#include "RealmManager.h"

namespace Auth {

RealmManager::RealmManager() {
	realmDAO = new RealmDAO();
}

RealmManager::~RealmManager() {
	delete realmDAO;
}

void RealmManager::createRealm() {

}
void RealmManager::updateRealm() {

}

int RealmManager::checkRealmName(std::string nameRealm) {
	Realm realm(nameRealm);
	if (realmDAO->read(&realm)) {
		return realm.getIdRoyaume();
	} else {
		return 0;
	}
}

bool RealmManager::checkRealmKey(std::string realmKey) {
	std::string configKey;

	configurationManager->get("realmKey", configKey);

	if (configKey.compare(realmKey) != 0) {
		return false;
	} else {
		return true;
	}
}

std::vector<std::string> RealmManager::getRealmsList(int version, int autorisation) {
	std::vector < std::string > retour;
	std::vector<Realm *>::iterator it;

	for (it = listRoyaume.begin(); it != listRoyaume.end(); ++it) {
		if (*it != NULL) {
			if ((*it)->getAutorisationRoyaume() <= autorisation
					&& (*it)->getVersionClientRoyaume() == version)
				retour.push_back((*it)->getUrlRoyaume());
		} else
			listRoyaume.erase(it);
	}
	return retour;
}

void RealmManager::update(int diff)
{
    printf("test realm \n");
}

} /* namespace Auth */
