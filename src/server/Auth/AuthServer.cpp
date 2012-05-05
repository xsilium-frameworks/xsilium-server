/*
 * AuthServer.h
 *
 *  Created on: 2 f�vr. 2012
 *      Author:
 */


#include "AuthServer.h"


using namespace RakNet; // a commenter





RAK_THREAD_DECLARATION(SocketThread)
{

	bool endthread = *((bool *) arguments);
	Authentification * auth = new Authentification();
	RakPeerInterface *peer = RakPeerInterface::GetInstance();

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
	if (!config->Load("/Users/joda/workspace/xsilium/Debug/auth.config"))
	{

	}
	SocketDescriptor socketDescriptor;
	int serverPort , numClient ;
	config->Get("port",serverPort);
	config->Get("clientMax",numClient);
	socketDescriptor.port=(unsigned short) serverPort;
	bool b = peer->Startup((unsigned short) numClient,&socketDescriptor,1)==RAKNET_STARTED;
	RakAssert(b);
	peer->SetMaximumIncomingConnections(numClient);
	RakThread::Create(&SocketThread, &this->endThread);


}


void authServer::stopThread()
{
	printf("Arret du thread d'authentification\n");
	this->endThread = true ;
}


authServer::authServer() {
	peer = RakPeerInterface::GetInstance();
	config = Configuration::getInstance();
	log = Log::getInstance();
	int logLevel;
	config->Get("LogLevel",logLevel);
	log->Start((Log::Priority)logLevel,"");
	log->Write(Log::DEBUG,"Lancement du serveur d'authantification de Xsilium");
	this->endThread = false ;

}

authServer::~authServer() {
	RakPeerInterface::DestroyInstance(peer);
	Configuration::DestroyInstance();
	Log::DestroyInstance();

}


