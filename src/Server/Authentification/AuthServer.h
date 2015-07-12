/*
 * \file AuthServer.h
 *
 *  Created on: \date 18 déc. 2014
 *      Author: \author joda
 *  \brief :
 */
#ifndef SRC_SERVER_AUTHENTIFICATION_AUTHSERVER_H_
#define SRC_SERVER_AUTHENTIFICATION_AUTHSERVER_H_

#include <Signal/SignalHandler.h>
#include <unistd.h>
#include <iostream>

#include "Authentification/Service/AuthentificationService.h"
#include "Realm/Service/RealmService.h"

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
	SignalHandler * signalHandler;
	Configuration * configuration;
	Log * log;

	DatabaseManager * databaseManager;
	NetworkManager * networkManager;
	AuthentificationService * authentificationService;
	RealmService * realmService;
};

} /* namespace Auth */

#endif /* SRC_SERVER_AUTHENTIFICATION_AUTHSERVER_H_ */
