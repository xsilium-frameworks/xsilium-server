/*!
 * \file AuthServer.h
 * \date 18 déc. 2014
 * \author xsilium-frameworks team
 * \author joda
 * \brief : Basic authentification server
 */
#ifndef SRC_SERVER_AUTH_AUTHSERVER_H_
#define SRC_SERVER_AUTH_AUTHSERVER_H_

#include <Signal/SignalHandler.h>
#include <unistd.h>
#include <iostream>

#include "Authentification/Authentification.h"

#include "Royaumes/RoyaumesManager.h"

/*!
 * \namespace Auth
 *
 * namespace that contain authentification's stuff.
 */
namespace Auth {

/*!
 * \class AuthServer
 * \brief Class that manage the authentification server.
 */
class AuthServer {
public:
	/*!
	 * \brief Constructor
	 * 
	 * Constructor of the AuthServer class.
	 */
	AuthServer();
	/*!
	 * \brief Destructor
	 *
	 * Destructor of the AuthServer class.
	 */
	virtual ~AuthServer();
	/*!
	 * \brief Start
	 * 
	 * Start the authentification server.
	 */
	void startServer();
	/*!
	 * \brief Stop
	 * 
	 * Stop the authentification server.
	 */
	void stopThread(); /*! Should change to stopServer() ? */


private:
	/*!
	 * \param signalHandler a constant constructor pointer.
	 */
	SignalHandler * signalHandler;
	Configuration * configuration;
	Log * log;

	DatabaseManager * databaseManager;
	NetworkManager * networkManager;
	Authentification * authentification;
	RoyaumesManager * royaumesManager;
};

} /* namespace Auth */

#endif /* SRC_SERVER_AUTH_AUTHSERVER_H_ */
