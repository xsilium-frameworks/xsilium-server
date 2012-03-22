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

#include "Authentification/Authentification.h"

  /*! \class authServer
   * \brief classe permettant la gestion de l'authentification
   *
   *  La classe gère l'authentification des clients
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

};

#endif /* AUTHSERVER_H_ */
