/*
 * AuthentificationService.cpp
 *
 *  Created on: 14 avr. 2016
 *      Author: joda
 */

#include "AuthentificationService.h"

namespace Kingdom {

AuthentificationService::AuthentificationService(NetworkManager * networkManager) {
    this->networkManager = networkManager;
    authentificationManager = 0;
}

AuthentificationService::~AuthentificationService() {
    networkManager->removeListenneur(ID_AUTH);
}

void AuthentificationService::run() {
    authentificationManager = AuthentificationManager::getInstance();
    authentificationManager->connexionToRealm();
    networkManager->addListenneur(ID_AUTH, this);
    Service::run();

}

void AuthentificationService::processPacket(MessageNetwork * messageNetwork) {
}

} /* namespace Kingdom */
