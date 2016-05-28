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

void AuthentificationManager::update(int diff) {

}

void AuthentificationManager::connexionToRealm() {
    MessageNetwork * messageRetour = new MessageNetwork();
    messageRetour->session = new Session();
    messageRetour->messagePacket = new MessagePacket();
    messageRetour->session->setSessionPeer(authNetwork->getPeer());
    messageRetour->messagePacket->setOpcode(ID_REALM);
    messageRetour->messagePacket->setSousOpcode(ID_REGISTER_REALM);
    messageRetour->messagePacket->setProperty("Name", "serveur 1");
    messageRetour->messagePacket->setProperty("Key", "123456789");
    messageRetour->messagePacket->setProperty("Port", "60001");
    messageRetour->messagePacket->setProperty("URL", "127.0.0.1");
    messageRetour->messagePacket->setProperty("Version", "1");
    authNetwork->sendPacket(messageRetour);
}

} /* namespace Kingdom */
