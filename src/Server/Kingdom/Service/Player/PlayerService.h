/*
 * PlayerService.h
 *
 *  Created on: 23 mars 2016
 *      Author: joda
 */

#ifndef SRC_SERVER_KINGDOM_SERVICE_PLAYER_PLAYERSERVICE_H_
#define SRC_SERVER_KINGDOM_SERVICE_PLAYER_PLAYERSERVICE_H_

#include <Manager/Network/NetworkManager.h>

namespace Kingdom {

class PlayerService: public Service {

    /*! Enumeration des types de message disponibles */
    enum typeForPlayer {
        ID_SHIFTING, /*!< Message de deplacement du joueur  */
        ID_ERROR /*!< Message de retour en cas d'anomalie*/
    };

    /*! Enumeration des types de retour possibles */
    enum erreurOfPlayer {
        ID_SHIFTING_ERROR_PLAYER = Service::ID_OTHER_ERROR
    };

public:
    PlayerService(NetworkManager * networkManager);
    virtual ~PlayerService();

    /*!
     * methode de lancement du thread
     */
    void run();

    void processPacket(MessageNetwork * messageNetwork);

private:
    NetworkManager * networkManager;
};

} /* namespace Kingdom */

#endif /* SRC_SERVER_KINGDOM_SERVICE_PLAYER_PLAYERSERVICE_H_ */
