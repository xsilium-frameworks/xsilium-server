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

#include "RakThread.h"
#include "Config/Configuration.h"
#include "Logging/Log.h"

#include "Authentification/Authentification.h"

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
     *  \brief StartThread
     *
     *  Launches starThread
     */

	void startThread();

    /*!
     *  \brief StopThread
     *
     *  Kill the Tread
     */

	void stopThread();

private:
	bool endThread;

	RakPeerInterface *peer;
	Configuration * config ;
	Log * log;

};

#endif /* AUTHSERVER_H_ */
