/*
 * \file KingdomServer.h
 *
 *  Created on: \date 1 janv. 2015
 *      Author: \author joda
 *  \brief :
 */
#ifndef SRC_SERVER_KINGDOM_KINGDOMSERVER_H_
#define SRC_SERVER_KINGDOM_KINGDOMSERVER_H_

#include <Manager/Signal/SignalHandler.h>
#include <unistd.h>
#include <iostream>
#include <Manager/Databases/DatabaseManager.h>
#include <Manager/Configuration/ConfiguratioNManager.h>
#include <Manager/Log/LogManager.h>
#include <Manager/Network/NetworkManager.h>

namespace Kingdom {

/*
 *
 */
class KingdomServer {
public:
    KingdomServer();
    virtual ~KingdomServer();

    void startServer();
    void stopThread();

private:
    SignalHandler * signalHandler;
    ConfigurationManager * configuration;
    LogManager * log;

    DatabaseManager * databaseManager;
    NetworkManager * networkManager;

};

} /* namespace Kingdom */

#endif /* SRC_SERVER_KINGDOM_KINGDOMSERVER_H_ */
