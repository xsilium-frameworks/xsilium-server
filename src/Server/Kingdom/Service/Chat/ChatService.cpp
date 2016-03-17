/*
 * ChatService.cpp
 *
 *  Created on: 11 juil. 2015
 *      Author: Skronak
 */

#include "ChatService.h"

namespace Kingdom {

ChatService::ChatService(NetworkManager * networkManager) {
    this->networkManager = networkManager;

}

ChatService::~ChatService() {
}

void ChatService::run() {
    networkManager->addListenneur(ID_CHAT, this);
    Service::run();

}

void ChatService::processPacket(MessageNetwork * messageNetwork) {
    log->write(LogManager::DEBUG, "Nouveau Packet Authentification");
    MessageNetwork * messageRetour = new MessageNetwork();
    switch (messageNetwork->messagePacket->getSousOpcode()) {
    case ID_KINGDOM:
        handleChatKingdom(messageNetwork, messageRetour);
        break;
    case ID_AREA:
        handleChatArea(messageNetwork, messageRetour);
        break;
    case ID_PRIVATE:
        handleChatPrivate(messageNetwork, messageRetour);
        break;
    case ID_COMMUNITY:
        handleChatCommunity(messageNetwork, messageRetour);
        break;
    default:
        break;
    }
    networkManager->sendPacket(messageRetour);
}

void ChatService::handleChatKingdom(MessageNetwork * messageNetwork,
        MessageNetwork * messageRetour) {

    messageRetour->messagePacket = new MessagePacket();

    // Controle presence proprietes du message
    if (!messageNetwork->messagePacket->hasProperty("Canal")
            || !messageNetwork->messagePacket->hasProperty("Text")) {
        log->write(LogManager::INFO, "Le message venant de %d:%d est illisible ",
                messageNetwork->session->getSessionID()->host,
                messageNetwork->session->getSessionID()->port);

        sendErrorPacket(messageNetwork, messageRetour, ID_ERROR_PACKET_SIZE);
        return;
    }
    messageRetour->messagePacket->setOpcode(ID_CHAT);
    messageRetour->messagePacket->setSousOpcode(ID_KINGDOM);
    messageRetour->messagePacket->setProperty("Perso",
            messageNetwork->messagePacket->getProperty("Perso"));
    messageRetour->messagePacket->setProperty("Canal",
            messageNetwork->messagePacket->getProperty("Canal"));
    messageRetour->messagePacket->setProperty("Text",
            messageNetwork->messagePacket->getProperty("Text"));

    messageRetour->session->setSessionHost(networkManager->getHost());

}

void ChatService::handleChatPrivate(MessageNetwork * messageNetwork,
        MessageNetwork * messageRetour) {

    messageRetour->messagePacket = new MessagePacket();

    // Controle presence proprietes du message
    if (!messageNetwork->messagePacket->hasProperty("name_dest")
            || !messageNetwork->messagePacket->hasProperty("text")) {
        log->write(LogManager::INFO, "Le message venant de %d:%d est illisible ",
                messageNetwork->session->getSessionID()->host,
                messageNetwork->session->getSessionID()->port);

        sendErrorPacket(messageNetwork, messageRetour, ID_ERROR_PACKET_SIZE);
        return;
    }

    messageRetour->session->setSessionPeer(messageNetwork->session->getSessionPeer());
}

void ChatService::handleChatArea(MessageNetwork * messageNetwork, MessageNetwork * messageRetour) {

    messageRetour->messagePacket = new MessagePacket();

    // Controle presence proprietes du message
    if (!messageNetwork->messagePacket->hasProperty("id_area")
            || !messageNetwork->messagePacket->hasProperty("text")) {
        log->write(LogManager::INFO, "Le message venant de %d:%d est illisible ",
                messageNetwork->session->getSessionID()->host,
                messageNetwork->session->getSessionID()->port);

        sendErrorPacket(messageNetwork, messageRetour, ID_ERROR_PACKET_SIZE);
        return;
    }
    messageRetour->messagePacket->setOpcode(ID_CHAT);
    messageRetour->messagePacket->setSousOpcode(ID_PRIVATE);
    messageRetour->session->setSessionPeer(messageNetwork->session->getSessionPeer());
}

void ChatService::handleChatCommunity(MessageNetwork * messageNetwork,
        MessageNetwork * messageRetour) {

    messageRetour->messagePacket = new MessagePacket();

    // Controle presence proprietes du message
    if (!messageNetwork->messagePacket->hasProperty("id_community")
            || !messageNetwork->messagePacket->hasProperty("text")) {
        log->write(LogManager::INFO, "Le message venant de %d:%d est illisible ",
                messageNetwork->session->getSessionID()->host,
                messageNetwork->session->getSessionID()->port);
        sendErrorPacket(messageNetwork, messageRetour, ID_ERROR_PACKET_SIZE);
        return;
    }
    messageRetour->messagePacket->setOpcode(ID_CHAT);
    messageRetour->messagePacket->setSousOpcode(ID_COMMUNITY);
    messageRetour->session->setSessionPeer(messageNetwork->session->getSessionPeer());
}
//TODO Implementation SpamDetector
bool ChatService::spamDetector(MessageNetwork * messageNetwork, MessagePacket * messageRetour) {
    messageRetour->setOpcode(ID_CHAT);
    messageRetour->setSousOpcode(ID_ERREUR);
    messageRetour->setProperty("ErrorId", ID_SPAM);

    return false;
}

void ChatService::sendErrorPacket(MessageNetwork * messageNetwork, MessageNetwork * messageRetour,
        int typeErreur) {
    messageRetour->session->setSessionPeer(messageNetwork->session->getSessionPeer());
    messageRetour->messagePacket->setOpcode(ID_CHAT);
    messageRetour->messagePacket->setSousOpcode(ID_ERREUR);
    messageRetour->messagePacket->setProperty("ErrorId", typeErreur);
}

} /* namespace Auth */
