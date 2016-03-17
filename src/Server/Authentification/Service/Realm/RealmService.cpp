/*
 * RealmService.cpp
 *
 *  Created on: 11 juil. 2015
 *      Author: Skronak
 */

#include "RealmService.h"

namespace Auth {

RealmService::RealmService(NetworkManager * networkManager) {
    this->networkManager = networkManager;

    realmManager = RealmManager::getInstance();

}

RealmService::~RealmService() {
    networkManager->removeListenneur(ID_REALM);
    RealmManager::DestroyInstance();
}

void RealmService::run() {
    networkManager->addListenneur(ID_REALM, this);
    Service::run();
}

void RealmService::processPacket(MessageNetwork * messageNetwork) {
    log->write(LogManager::DEBUG, "Nouveau Packet Realm");
    MessageNetwork * messageRetour = new MessageNetwork();
    switch (messageNetwork->messagePacket->getSousOpcode()) {
    case ID_REGISTER_REALM:
        handleRegisterRealm(messageNetwork, messageRetour);
        break;
    default:
        break;
    }
    networkManager->sendPacket(messageRetour);
}

void RealmService::handleRegisterRealm(MessageNetwork * messageNetwork,
        MessageNetwork * messageRetour) {

    messageRetour->messagePacket = new MessagePacket();

    std::vector < std::string > tableauData;
    tableauData.push_back("Name");
    tableauData.push_back("Key");
    tableauData.push_back("Port");
    tableauData.push_back("URL");
    tableauData.push_back("Version");

    // Controle Presence Donneee
    if (!controleData(messageNetwork->messagePacket, &tableauData)) {
        log->write(LogManager::INFO, "Le message venant de %d:%d est illisible ",
                messageNetwork->session->getSessionID()->host,
                messageNetwork->session->getSessionID()->port);
        sendErrorPacket(messageNetwork, messageRetour, ID_ERROR_PACKET_SIZE_R);
        return;
    }

    // Verification de la cl�
    if (!realmManager->checkRealmKey(messageNetwork->messagePacket->getProperty("Key"))) {
        log->write(LogManager::INFO, "Le message venant de %d:%d est illisible ",
                messageNetwork->session->getSessionID()->host,
                messageNetwork->session->getSessionID()->port);
        sendErrorPacket(messageNetwork, messageRetour, ID_ERROR_KEY);
    }

    // R�cup�ration du Realm et mise � jour
    idRealm = realmManager->checkRealmName(messageNetwork->messagePacket->getProperty("Name"));

    if (idRealm) {
        realmManager->createRealm();
    } else {
        realmManager->updateRealm();
    }

    messageRetour->session->setSessionPeer(messageNetwork->session->getSessionPeer());
}

void RealmService::sendErrorPacket(MessageNetwork * messageNetwork, MessageNetwork * messageRetour,
        int typeError) {
    messageRetour->session->setSessionPeer(messageNetwork->session->getSessionPeer());
    messageRetour->messagePacket->setOpcode(ID_REALM);
    messageRetour->messagePacket->setSousOpcode(ID_ERREUR_REALM);
    messageRetour->messagePacket->setProperty("ErrorId", typeError);
}

} /* namespace Auth */
