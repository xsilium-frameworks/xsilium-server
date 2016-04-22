/*
 * \file KingdomServer.h
 *
 *  Created on: \date 1 janv. 2015
 *      Author: \author joda
 *  \brief :
 */
#ifndef SRC_SERVER_KINGDOM_KINGDOMSERVER_H_
#define SRC_SERVER_KINGDOM_KINGDOMSERVER_H_

#include <unistd.h>
#include <iostream>
#include <Manager/Databases/DatabaseManager.h>
#include <Service/scheduling/SchedulingService.h>
#include <Service/Chat/ChatService.h>
#include <Service/Player/PlayerService.h>
#include <Service/Authentification/AuthentificationService.h>

namespace Kingdom {

/*
 *
 */
class KingdomServer {
public:
    KingdomServer();
    KingdomServer(ConfigurationManager * configuration, LogManager * log,
            DatabaseManager * databaseManager, NetworkManager * networkManager,
            SchedulingService * schedulingService, ChatService * chatService,
            PlayerService * playerService);
    virtual ~KingdomServer();

    void startServer();
    void stopThread();

private:
    ConfigurationManager * configuration;
    LogManager * log;

    DatabaseManager * databaseManager;
    NetworkManager * clientNetwork;

    SchedulingService * schedulingService;
    ChatService * chatService;
    PlayerService * playerService;
    AuthentificationService * authentificationService;

};

} /* namespace Kingdom */

#endif /* SRC_SERVER_KINGDOM_KINGDOMSERVER_H_ */
