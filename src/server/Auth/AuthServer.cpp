/*
 * authServer.cpp
 *
 *  Created on: 2 févr. 2012
 *      Author: joda2
 */

#include "AuthServer.h"
#include "socket/AuthSocket.h"
#include <stdio.h> // Printf

#include "RakPeerInterface.h"
#include "RakThread.h"
#include "RakSleep.h"


using namespace RakNet;

RAK_THREAD_DECLARATION(authThread)
{
	int endThread = *((int *) arguments);
	AuthSocket * authSocket = new AuthSocket();
	authSocket->Start();
	printf("update\n");
	while ( endThread  == false )
	{
		printf("update\n");
		authSocket->Update();
		RakSleep(1000);
	}
	return false;
}


void authServer::startThread()
{
	printf("Demarrage du thread d'authentification\n");
	RakThread::Create(&authThread,&this->endThread);

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






