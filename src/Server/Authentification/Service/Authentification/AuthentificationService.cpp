/*
 * AuthentificationService.cpp
 *
 *  Created on: 11 juil. 2015
 *      Author: Skronak
 */

#include "AuthentificationService.h"

namespace Auth {

AuthentificationService::AuthentificationService(NetworkManager * networkManager) {
    this->networkManager = networkManager;
    authentificationManager = AuthentificationManager::getInstance();
    realmManager = RealmManager::getInstance();
}

AuthentificationService::~AuthentificationService() {
    networkManager->removeListenneur(ID_AUTH);
    AuthentificationManager::DestroyInstance();
    RealmManager::DestroyInstance();
}

void AuthentificationService::run() {
    networkManager->addListenneur(ID_AUTH, this);
    Service::run();

}

void AuthentificationService::processPacket(MessageNetwork * messageNetwork) {
    log->write(LogManager::DEBUG, "Nouveau Packet Authentification");
    MessageNetwork * messageRetour = new MessageNetwork();
    messageRetour->messagePacket = new MessagePacket();
    messageRetour->session = new Session ();
    
    switch (messageNetwork->messagePacket->getSousOpcode()) {
    case ID_CHALLENGE:
        handleLogonChallenge(messageNetwork, messageRetour);
        break;
    case ID_REPONSE:
        handleLogonProof(messageNetwork, messageRetour);
        break;
    case ID_REALMSLIST:
        handleRealmsList(messageNetwork, messageRetour);
    default:
        break;
    }
    networkManager->sendPacket(messageRetour);

}

void AuthentificationService::handleLogonChallenge(MessageNetwork * messageNetwork,
        MessageNetwork * messageRetour) {
    std::vector < std::string > tableauData;
    

    tableauData.push_back("Build");
    tableauData.push_back("Login");

    // Controle Presence Donneee
    if (!controleData(messageNetwork->messagePacket, &tableauData)) {
        log->write(LogManager::INFO, "Le message venant de %d:%d est illisible ",
                messageNetwork->session->getSessionID()->host,
                messageNetwork->session->getSessionID()->port);
        sendErrorPacket(messageNetwork, messageRetour, ID_ERROR_PACKET_SIZE);
        return;
    }

    if (!authentificationManager->checkIp(messageNetwork->session->getIP())) {
        log->write(LogManager::INFO, "[AuthChallenge] L'ip %s est bannie !",
                messageNetwork->session->getIP().c_str());
        sendErrorPacket(messageNetwork, messageRetour, ID_CONNECTION_BANNED);
        return;
    }

    log->write(LogManager::INFO, "Nom du client : %s ",
            messageNetwork->messagePacket->getProperty("Login").c_str());

    int idCompte = authentificationManager->checkAccount(
            messageNetwork->messagePacket->getProperty("Login"));

    if (idCompte == 0) {
        log->write(LogManager::INFO, "[AuthChallenge] Le compte %s n'existe pas",
                messageNetwork->messagePacket->getProperty("Login").c_str());
        authentificationManager->banIP(messageNetwork->session->getIP());
        sendErrorPacket(messageNetwork, messageRetour, ID_INVALID_ACCOUNT_OR_PASSWORD);
        return;
    }

    Compte * compte = authentificationManager->getAccount(idCompte);

    if (compte == NULL || compte->getCompteBan() != 0) {

        time_t unbandate = compte->getCompteBan()->getUnbandate();
        log->write(LogManager::INFO, "[AuthChallenge] Le compte %s est banni jusqu'au %s",
                compte->getUsername().c_str(), ctime(&unbandate));
        sendErrorPacket(messageNetwork, messageRetour, ID_COMPTE_BANNIE);
        return;
    }

    messageNetwork->session->setSessionListener(compte);
    messageNetwork->session->setSessionEtape(STEP_REPONSE);

    messageRetour->messagePacket->setOpcode(ID_AUTH);
    messageRetour->messagePacket->setSousOpcode(ID_CHALLENGE);
    messageRetour->messagePacket->setProperty("Key", 1234567);
    messageRetour->session->setSessionPeer(messageNetwork->session->getSessionPeer());

}

void AuthentificationService::handleLogonProof(MessageNetwork * messageNetwork,
        MessageNetwork * messageRetour) {
    std::vector < std::string > tableauData;

    tableauData.push_back("Password");

// Controle Presence Donnee
    if (!controleData(messageNetwork->messagePacket, &tableauData)) {
        log->write(LogManager::INFO, "Le message venant de %d:%d est illisible ",
                messageNetwork->session->getSessionID()->host,
                messageNetwork->session->getSessionID()->port);
        sendErrorPacket(messageNetwork, messageRetour, ID_ERROR_PACKET_SIZE);
        return;
    }

    if (messageNetwork->session->getSessionListener()->getTypeModel().compare("Compte") == 0) {
        log->write(LogManager::INFO, "Le message venant de %d:%d est illisible ",
                messageNetwork->session->getSessionID()->host,
                messageNetwork->session->getSessionID()->port);
        sendErrorPacket(messageNetwork, messageRetour, ID_ERROR_PACKET_SIZE);
        return;
    }

    if (messageNetwork->session->getSessionEtape() < STEP_REPONSE) {
        log->write(LogManager::INFO, "Le client n'est pas a la bonne etape ");
        sendErrorPacket(messageNetwork, messageRetour, ID_ERROR_ETAPE);
        return;
    }

    Compte * compte = static_cast<Compte*>(messageNetwork->session->getSessionListener());

    if (messageNetwork->messagePacket->getProperty("Password").compare(compte->getShaPassHash())
            != 0) {
        authentificationManager->banIP(messageNetwork->session->getIP());
        sendErrorPacket(messageNetwork, messageRetour, ID_INVALID_ACCOUNT_OR_PASSWORD);
        return;
    }

    log->write(LogManager::INFO, "Mot de passe valider");

    authentificationManager->resetIpTemp(messageNetwork->session->getIP());

    messageNetwork->session->setSessionEtape(STEP_REAMSLIST);

    messageRetour->messagePacket->setOpcode(ID_AUTH);
    messageRetour->messagePacket->setSousOpcode(ID_REPONSE);
    messageRetour->session->setSessionPeer(messageNetwork->session->getSessionPeer());
}

void AuthentificationService::handleRealmsList(MessageNetwork * messageNetwork,
        MessageNetwork * messageRetour) {
    std::vector < std::string > tableauData;
    tableauData.push_back("versionClient");

// Controle Presence Donnee
    if (!controleData(messageNetwork->messagePacket, &tableauData)) {
        log->write(LogManager::INFO, "Le message venant de %d:%d est illisible ",
                messageNetwork->session->getSessionID()->host,
                messageNetwork->session->getSessionID()->port);
        sendErrorPacket(messageNetwork, messageRetour, ID_ERROR_PACKET_SIZE);
        return;
    }

    if (messageNetwork->session->getSessionEtape() < STEP_REAMSLIST) {
        log->write(LogManager::INFO, "Le client n'est pas a la bonne etape ");
        sendErrorPacket(messageNetwork, messageRetour, ID_ERROR_ETAPE);
        return;
    }

    std::vector<Realm*> listOfRealms = realmManager->getRealmsList(
            Utilities::toInt(messageNetwork->messagePacket->getProperty("versionClient")), 1);

    for (int increment = 0; increment < listOfRealms.size(); ++increment) {
        messageRetour->messagePacket->setProperty("realm" + Utilities::toString(increment),
                listOfRealms[increment]->toString());
    }

    messageRetour->messagePacket->setOpcode(ID_AUTH);
    messageRetour->messagePacket->setSousOpcode(ID_REALMSLIST);
    messageRetour->session->setSessionPeer(messageNetwork->session->getSessionPeer());

}

void AuthentificationService::sendErrorPacket(MessageNetwork * messageNetwork,
        MessageNetwork * messageRetour, int typeErreur) {

    messageRetour->session->setSessionPeer(messageNetwork->session->getSessionPeer());
    messageRetour->messagePacket->setOpcode(ID_AUTH);
    messageRetour->messagePacket->setSousOpcode(ID_ERROR);
    messageRetour->messagePacket->setProperty("ErrorId", typeErreur);
}

} /* namespace Auth */
