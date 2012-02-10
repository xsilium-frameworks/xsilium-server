/*
 * authServer.cpp
 *
 *  Created on: 2 févr. 2012
 *      Author: joda2
 */

#include "AuthServer.h"
//#include "socket/AuthSocket.h"
#include <stdio.h> // Printf
#include <pthread.h>





void authServer::startThread()
{
	printf("Demarrage du thread d'authentification\n");
	pthread_create(&threadSocket,NULL,);
}

authServer::authServer() {
	printf("Lancement du serveur d'authantification de Xsilium\n");
	this->endThread = false ;

}

authServer::~authServer() {
}


void authServer::setEndThread(bool endThread) {
	this->endThread = endThread ;

}

bool authServer::getEndThread() {
	return this->endThread ;
}






