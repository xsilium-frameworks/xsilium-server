/*
 * \file AuthServer.h
 *
 *  Created on: \date 18 déc. 2014
 *      Author: \author joda
 *  \brief :
 */
#ifndef SRC_SERVER_AUTH_AUTHSERVER_H_
#define SRC_SERVER_AUTH_AUTHSERVER_H_

#include <Signal/SignalHandler.h>
#include <unistd.h>
#include <iostream>

#include "Authentification/Authentification.h"

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
	Authentification * authentification;
};

} /* namespace Auth */

#endif /* SRC_SERVER_AUTH_AUTHSERVER_H_ */
