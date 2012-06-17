/*
 * authServer.h
 *
 *  Created on: 2 f�vr. 2012
 *      Author:
 */

/*!
 * \file authServer.h
 * \brief authentication server
 * \author joda2
 *
 */

#ifndef AUTHSERVER_H_
#define AUTHSERVER_H_

#include <pthread.h>
#include "Config/Configuration.h"
#include "Logging/Log.h"
#include "SignalHandler/SignalHandler.h"

#include "Authentification/Authentification.h"
#include "AuthCodes/AuthCodes.h"

  /*! \class authServer
   * \brief Permet de faire la liaison entre la reception des packets
   * et le traitement des données
   */

class authServer {
public:

    /*!
     *  \brief Constructeur
     *
     *  Constructeur de la classe authServer
     *
     *  \param
     */

	authServer();

    /*!
     *  \brief Destructeur
     *
     *  Destructeur de la classe ~authServer
     */

	virtual ~authServer();

    /*!
     *  \brief StartServer
     *
     *  Launches startServer
     */

	void startServer();

    /*!
     *  \brief StopThread
     *
     *  Kill the Tread
     */

	void stopThread();

private:
	bool endThread;

	SignalHandler * signalHandler;
	Configuration * config ;
	Log * log;
	pthread_t thread;

};

#endif /* AUTHSERVER_H_ */
