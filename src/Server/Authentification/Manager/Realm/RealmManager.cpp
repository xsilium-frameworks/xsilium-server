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

std::vector<Realm*> RealmManager::getRealmsList(int version, int autorisation) {
    std::vector<Realm*> retour;
    std::map<const char *, Realm*>::iterator itListRoyaume = listRoyaume.begin();

    while (itListRoyaume != listRoyaume.end()) {
        if (itListRoyaume->second->getAutorisationRoyaume() <= autorisation
                && itListRoyaume->second->getVersionClientRoyaume() == version) {
            retour.push_back(itListRoyaume->second);
        }
    }
    return retour;
}

void RealmManager::update(int diff) {
    std::map<const char *, Realm*>::iterator it = listRoyaume.begin();

    while (it != listRoyaume.end()) {
        if (it->second->isUpdate()) {
            realmDAO->update(it->second);
        }

        if (!it->second->isOnline()) {
            realmDAO->update(it->second);
            listRoyaume.erase(it++);
        } else {
            ++it;
        }
    }
}

} /* namespace Auth */
