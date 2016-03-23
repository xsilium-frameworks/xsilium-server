/*
 * PlayerService.cpp
 *
 *  Created on: 23 mars 2016
 *      Author: joda
 */

#include "PlayerService.h"

namespace Kingdom {

PlayerService::PlayerService(NetworkManager * networkManager) {
    this->networkManager = networkManager;

}

PlayerService::~PlayerService() {
    // TODO Auto-generated destructor stub
}

void PlayerService::run() {
    networkManager->addListenneur(ID_CHAT, this);
    Service::run();

}

void PlayerService::processPacket(MessageNetwork * messageNetwork) {
    log->write(LogManager::DEBUG, "Nouveau Packet Authentification");
    MessageNetwork * messageRetour = new MessageNetwork();
    switch (messageNetwork->messagePacket->getSousOpcode()) {
    default:
        break;
    }
    networkManager->sendPacket(messageRetour);
}

} /* namespace Kingdom */
