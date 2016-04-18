/*
 * WorldManager.h
 *
 *  Created on: 13 avr. 2016
 *      Author: joda
 */

#ifndef SRC_SERVER_KINGDOM_MANAGER_WORLD_WORLDMANAGER_H_
#define SRC_SERVER_KINGDOM_MANAGER_WORLD_WORLDMANAGER_H_

#include <Manager/Network/NetworkManager.h>
#include <Manager/Manager.h>

namespace Kingdom {

class WorldManager: public Manager, public Singleton<WorldManager> {

public:
    WorldManager();
    WorldManager(NetworkManager * networkManager);
    virtual ~WorldManager();

    void update(int diff);

private:
    NetworkManager * networkManager;
};

}
/* namespace Kingdom */

#endif /* SRC_SERVER_KINGDOM_MANAGER_WORLD_WORLDMANAGER_H_ */
