/*
 * authServer.h
 *
 *  Created on: 2 févr. 2012
 *      Author: joda2
 */

#ifndef AUTHSERVER_H_
#define AUTHSERVER_H_

#include "RakThread.h"

#include "Authentification/Authentification.h"


class authServer {
public:
	authServer();
	virtual ~authServer();

	void startThread();
	void stopThread();

private:
	bool endThread;

};

#endif /* AUTHSERVER_H_ */
