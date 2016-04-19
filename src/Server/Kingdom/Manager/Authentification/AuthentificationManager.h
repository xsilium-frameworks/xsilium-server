/*
 * AuthentificationManager.h
 *
 *  Created on: 19 mars 2016
 *      Author: joda
 */

#ifndef SRC_SERVER_KINGDOM_MANAGER_AUTHENTIFICATION_AUTHENTIFICATIONMANAGER_H_
#define SRC_SERVER_KINGDOM_MANAGER_AUTHENTIFICATION_AUTHENTIFICATIONMANAGER_H_

#include <Manager/Manager.h>
#include <Manager/Network/NetworkManager.h>

namespace Kingdom {

class AuthentificationManager: public Manager, public Singleton<AuthentificationManager> {
public:
    AuthentificationManager();
    AuthentificationManager(NetworkManager * authNetwork);
    virtual ~AuthentificationManager();

    bool checkAccount(int idAccount);

    bool registerRealm();

    void update(int diff);

private:
    void init();
    void disconnexion();
    NetworkManager * authNetwork;
};

} /* namespace Kingdom */

#endif /* SRC_SERVER_KINGDOM_MANAGER_AUTHENTIFICATION_AUTHENTIFICATIONMANAGER_H_ */
