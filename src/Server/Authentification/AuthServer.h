/*
 * \file AuthServer.h
 *
 *  Created on: \date 18 déc. 2014
 *      Author: \author joda
 *  \brief :
 */
#ifndef SRC_SERVER_AUTHENTIFICATION_AUTHSERVER_H_
#define SRC_SERVER_AUTHENTIFICATION_AUTHSERVER_H_

#include <unistd.h>
#include <iostream>

#include "Service/scheduling/SchedulingService.h"
#include "Service/Authentification/AuthentificationService.h"
#include "Service/Realm/RealmService.h"

namespace Auth {

/*
 *
 */
class AuthServer {
public:
    AuthServer();
    AuthServer(AuthServer & authServer);
    virtual ~AuthServer();

    void startServer(std::string configFile);
    void stopThread();

    AuthentificationService*& getAuthentificationService();
    void setAuthentificationService(AuthentificationService*& authentificationService);
    ConfigurationManager*& getConfiguration();
    void setConfiguration(ConfigurationManager*& configuration);
    DatabaseManager*& getDatabaseManager();
    void setDatabaseManager(DatabaseManager*& databaseManager);
    LogManager*& getLog();
    void setLog(LogManager*& log);
    NetworkManager*& getNetworkManager();
    void setNetworkManager(NetworkManager*& networkManager);
    RealmService*& getRealmService();
    void setRealmService(RealmService*& realmService);
    SchedulingService*& getSchedulingService();
    void setSchedulingService(SchedulingService*& schedulingService);

private:
    ConfigurationManager * configuration;
    LogManager * log;

    DatabaseManager * databaseManager;
    NetworkManager * networkManager;
    AuthentificationService * authentificationService;
    RealmService * realmService;
    SchedulingService * schedulingService;
};

} /* namespace Auth */

#endif /* SRC_SERVER_AUTHENTIFICATION_AUTHSERVER_H_ */
