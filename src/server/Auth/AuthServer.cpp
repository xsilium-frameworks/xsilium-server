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
	RakPeerInterface *peer = RakPeerInterface::GetInstance();
	Authentification * auth = new Authentification(peer);
	Log *log = Log::getInstance();
	Configuration *config = Configuration::getInstance();
	SocketDescriptor socketDescriptor;
	int serverPort , numClient ;
	config->Get("port",serverPort);
	config->Get("clientMax",numClient);
	socketDescriptor.port=(unsigned short) serverPort;
	bool b = peer->Startup((unsigned short) numClient,&socketDescriptor,1)==RAKNET_STARTED;
	if (b == false)
	{
		log->Write(Log::ERROR,"Impossible d'ouvrir le socket");
		endthread = false;

	}
	RakAssert(b);
	peer->SetMaximumIncomingConnections(numClient);

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
	 		case ID_SEND_USER:
	 			log->Write(Log::DEBUG,"Packet recu");
	 			if(!auth->_HandleLogonChallenge(packet))
	 				log->Write(Log::ERROR,"Impossible d'authentifier le client");
	 			break;
	 		case ID_SEND_REPONSE:
	 			log->Write(Log::DEBUG,"Packet de reponse recu");
	 			if(!auth->_HandleLogonProof(packet))
	 				log->Write(Log::ERROR,"Mauvaise reponse, impossible d'authentifier le client");
	 			break;
	 		case ID_GET_ROYAUME:
	 			log->Write(Log::DEBUG,"Packet demande de royaume");
	 			// if(!auth->_HandleLogonChallenge(packet))
	 				log->Write(Log::ERROR,"Impossible d'envoyer le royaume");
	 			break;
			}
			peer->DeallocatePacket(packet);
			packet = peer->Receive();
		}
		RakSleep(30);
	}

	delete auth;
	RakPeerInterface::DestroyInstance(peer);


	return false;
}






void authServer::startServer()
{
	try
	{
		signalHandler->setupSignalHandlers();
		if (!config->Load("/home/mathieu/git/xsilium-server/Debug/auth.config"))
		{}
		int logLevel;
		config->Get("LogLevel",logLevel);
		log->Start((Log::Priority)logLevel,"");
		log->Write(Log::DEBUG,"Demarrage du thread d'authentification");
		RakThread::Create(&SocketThread, &this->endThread);

		while(!signalHandler->gotExitSignal())
		        sleep(1);

		stopThread();
	}
	catch (SignalException& e)
	{
		std::cerr << "SignalException: " << e.what() << std::endl;
	}
}


void authServer::stopThread()
{
	log->Write(Log::DEBUG,"Arret du thread d'authentification");
	log->Stop();
	this->endThread = true ;
}


authServer::authServer() {
	config = Configuration::getInstance();
	log = Log::getInstance();
	this->endThread = false ;

}

authServer::~authServer() {
	Configuration::DestroyInstance();
	Log::DestroyInstance();

}

int main()
{
	    authServer * authserver = new authServer();
	    authserver->startServer();
	    delete authserver;
}
