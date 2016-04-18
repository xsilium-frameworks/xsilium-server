/*
 * AuthentificationService.h
 *
 *  Created on: 14 avr. 2016
 *      Author: joda
 */

#ifndef SRC_SERVER_KINGDOM_SERVICE_AUTHENTIFICATION_AUTHENTIFICATIONSERVICE_H_
#define SRC_SERVER_KINGDOM_SERVICE_AUTHENTIFICATION_AUTHENTIFICATIONSERVICE_H_

#include <Service/Service.h>
#include <Manager/Network/NetworkManager.h>
#include "Manager/Authentification/AuthentificationManager.h"

namespace Kingdom {

class AuthentificationService: public Service {
public:
    AuthentificationService(NetworkManager * networkManager);
    virtual ~AuthentificationService();

    /*!
     * methode de lancement du thread
     */
    void run();

    void processPacket(MessageNetwork * messageNetwork);

private:
    NetworkManager * networkManager;
    AuthentificationManager * authentificationManager;
};

} /* namespace Kingdom */

#endif /* SRC_SERVER_KINGDOM_SERVICE_AUTHENTIFICATION_AUTHENTIFICATIONSERVICE_H_ */
