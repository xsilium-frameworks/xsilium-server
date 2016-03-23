/*
 * RealmService.h
 *
 *  Created on: 11 juil. 2015
 *      Author: Skronak
 */

#ifndef SRC_SERVER_AUTHENTIFICATION_REALM_SERVICE_REALMSERVICE_H_
#define SRC_SERVER_AUTHENTIFICATION_REALM_SERVICE_REALMSERVICE_H_
#include <Manager/Network/NetworkManager.h>
#include "Manager/Realm/RealmManager.h"

namespace Auth {

class RealmService: public Service {

    enum erreurOfRealm {
        ID_ERROR_KEY = Service::ID_OTHER_ERROR
    };

    enum typeForRealm {
        ID_REGISTER_REALM, ID_ERROR

    };

public:
    RealmService(NetworkManager * networkManager);
    virtual ~RealmService();

    void run();
    void processPacket(MessageNetwork * messageNetwork);

    void handleRegisterRealm(MessageNetwork * messageNetwork, MessageNetwork * messageRetour);
    /*!
     * Alimentation des erreurs d'un packets
     * @param messageRetour
     * @param typeForAuth : type d'erreur
     */
    void sendErrorPacket(MessageNetwork * messageNetwork, MessageNetwork * messageRetour,
            int typeError);

private:
    NetworkManager * networkManager;
    RealmManager * realmManager;

};

} /* namespace Auth */

#endif /* SRC_SERVER_AUTHENTIFICATION_REALM_SERVICE_REALMSERVICE_H_ */
