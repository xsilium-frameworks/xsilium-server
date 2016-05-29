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
    KingdomServer(KingdomServer& kingdomServer);
    virtual ~KingdomServer();

    void startServer(std::string configFile);
    void stopThread();
    AuthentificationService*& getAuthentificationService();
    void setAuthentificationService(AuthentificationService*& authentificationService);
    ChatService*& getChatService();
    void setChatService(ChatService*& chatService);
    NetworkManager*& getClientNetwork();
    void setClientNetwork(NetworkManager*& clientNetwork);
    ConfigurationManager*& getConfiguration();
    void setConfiguration(ConfigurationManager*& configuration);
    DatabaseManager*& getDatabaseManager();
    void setDatabaseManager(DatabaseManager*& databaseManager);
    LogManager*& getLog();
    void setLog(LogManager*& log);
    PlayerService*& getPlayerService();
    void setPlayerService(PlayerService*& playerService);
    SchedulingService*& getSchedulingService();
    void setSchedulingService(SchedulingService*& schedulingService);

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
