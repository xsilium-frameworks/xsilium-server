/*
 * WorldManager.cpp
 *
 *  Created on: 13 avr. 2016
 *      Author: joda
 */

#include "WorldManager.h"

namespace Kingdom {

WorldManager::WorldManager() {
    networkManager = new NetworkManager();

}

WorldManager::WorldManager(NetworkManager * networkManager) {
    this->networkManager = networkManager;
}

WorldManager::~WorldManager() {
    // TODO Auto-generated destructor stub
}

void WorldManager::update(int diff) {

}

} /* namespace Kingdom */
