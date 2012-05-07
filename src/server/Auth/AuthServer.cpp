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
	Log *log = Log::getInstance();

	while(!endthread)
	{
		Packet * packet = peer->Receive();
		while (packet)
		{
			switch (packet->data[0])
			{
			case ID_NEW_INCOMING_CONNECTION:
				log->Write(Log::DEBUG,"Nouvelle connexion");
				if(!auth->CreateClient(packet))
					log->Write(Log::ERROR,"Impossible de cree le client");
				break;
			case ID_CONNECTION_LOST:
			case ID_DISCONNECTION_NOTIFICATION:
				log->Write(Log::DEBUG,"deconnexion");
				if(!auth->DeleteClient(packet))
					log->Write(Log::ERROR,"Impossible de supprimer le client");
				break;
	 		case ID_USER_PACKET_ENUM:
	 			log->Write(Log::DEBUG,"Packet recu");
	 			if(!auth->_HandleLogonChallenge(packet))
	 				log->Write(Log::ERROR,"Impossible d'authentifier le client");
	 			break;
	 		default:
	 			break;
			}
			peer->DeallocatePacket(packet);
			packet = peer->Receive();
		}
		//log->Write(Log::DEBUG,"attente de 0,003s");
		RakSleep(30);
	}

	delete auth;


	return false;
}






void authServer::startThread()
{
	if (!config->Load("/Users/joda/workspace/xsilium/Debug/auth.config"))
	{}
	int logLevel;
	config->Get("LogLevel",logLevel);
	log->Start((Log::Priority)logLevel,"");
	log->Write(Log::DEBUG,"Demarrage du thread d'authentification");

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
	log->Write(Log::DEBUG,"Arret du thread d'authentification");
	log->Stop();
	this->endThread = true ;
}


authServer::authServer() {
	peer = RakPeerInterface::GetInstance();
	config = Configuration::getInstance();
	log = Log::getInstance();

	this->endThread = false ;

}

authServer::~authServer() {
	RakPeerInterface::DestroyInstance(peer);
	Configuration::DestroyInstance();
	Log::DestroyInstance();

}


