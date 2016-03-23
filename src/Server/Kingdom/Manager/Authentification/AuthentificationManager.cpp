/*
 * AuthentificationManager.cpp
 *
 *  Created on: 19 mars 2016
 *      Author: joda
 */

#include "AuthentificationManager.h"

namespace Kingdom {

AuthentificationManager::AuthentificationManager() {
    authNetwork = new NetworkManager();
    init();
}

AuthentificationManager::AuthentificationManager(NetworkManager * authNetwork) {
    this->authNetwork = authNetwork;
    init();
}

AuthentificationManager::~AuthentificationManager() {
    disconnexion();
    delete authNetwork;
}

void AuthentificationManager::init() {
    int portAuth;
    std::string urlAuth;

    configurationManager->get("portAuth", portAuth);
    configurationManager->get("urlAuth", urlAuth);

    authNetwork->createConnexion();
    authNetwork->connexionToHost(urlAuth, portAuth);
}

void AuthentificationManager::disconnexion() {
    authNetwork->disconnexion();
}

bool AuthentificationManager::checkAccount(int idAccount) {
    return true;
}

bool AuthentificationManager::registerRealm() {
    return true;
}

} /* namespace Kingdom */
