/*
 * \file AuthServer.h
 *
 *  Created on: \date 18 déc. 2014
 *      Author: \author joda
 *  \brief :
 */
#ifndef SRC_SERVER_AUTHENTIFICATION_AUTHSERVER_H_
#define SRC_SERVER_AUTHENTIFICATION_AUTHSERVER_H_

#include <Manager/Signal/SignalHandler.h>
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
	virtual ~AuthServer();

	void startServer();
	void stopThread();


private:
	ConfigurationManager * configuration;
	LogManager * log;

	DatabaseManager * databaseManager;
	NetworkManager * networkManager;
	AuthentificationService * authentificationService;
	RealmService * realmService;
	SchedulingService * schedulingService ;
};

} /* namespace Auth */

#endif /* SRC_SERVER_AUTHENTIFICATION_AUTHSERVER_H_ */
