/*
 * \file authServer.cpp
 *
 *  Created on: \date 2 fŽvr. 2012
 *      Author: \author joda2
 *     \brief :
 */

#include "AuthServer.h"


using namespace RakNet;

RakPeerInterface *peer;



RAK_THREAD_DECLARATION(SocketThread)
{
	bool endthread = *((bool *) arguments);
	Authentification * auth = new Authentification();

	while(!endthread)
	{
		Packet * packet = peer->Receive();
		while (packet)
		{
			switch (packet->data[0])
			{
			case ID_NEW_INCOMING_CONNECTION:
				printf("Nouvelle connexion\n");
				if(!auth->CreateClient(packet))
					printf("Impossible de cree le client\n");
				break;
			case ID_CONNECTION_LOST:
			case ID_DISCONNECTION_NOTIFICATION:
				printf("deconnexion\n");
				if(!auth->DeleteClient(packet))
					printf("Impossible de supprimer le client\n");
				break;
	 		case ID_USER_PACKET_ENUM:
	 			printf("Packet recu\n");
	 			if(!auth->_HandleLogonChallenge(packet))
	 				printf("Impossible d'authentifier le client\n");
	 			break;
	 		default:
	 			break;
			}
			peer->DeallocatePacket(packet);
			packet = peer->Receive();
		}
		RakSleep(30);
	}

	delete auth;


	return false;
}






void authServer::startThread()
{
	printf("Demarrage du thread d'authentification\n");
	SocketDescriptor socketDescriptor;
	socketDescriptor.port=(unsigned short) SERVER_PORT;
	bool b = peer->Startup((unsigned short) NUM_CLIENTS,&socketDescriptor,1)==RAKNET_STARTED;
	RakAssert(b);
	peer->SetMaximumIncomingConnections(NUM_CLIENTS);
	RakThread::Create(&SocketThread, &this->endThread);


}


void authServer::stopThread()
{
	printf("Arret du thread d'authentification\n");
	this->endThread = true ;
}


authServer::authServer() {
	printf("Lancement du serveur d'authantification de Xsilium\n");
	peer = RakNet::RakPeerInterface::GetInstance();
	this->endThread = false ;

}

authServer::~authServer() {
	RakNet::RakPeerInterface::DestroyInstance(peer);

}


