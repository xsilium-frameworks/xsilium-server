/*
 * AuthServer.h
 *
 *  Created on: 2 f�vr. 2012
 *      Author:
 */


#include "AuthServer.h"


void* threadConnexion(void* arguments)
{
	bool endthread = *((bool *) arguments);
	if ( enet_initialize() != 0)
	    {
	        fprintf (stderr, "An error occurred while initializing ENet.\n");
	        return false;
	    }
	ENetAddress address;
	ENetHost * server;
	ENetEvent eventServer;
	int serverPort, numClient ;
	Configuration *config = Configuration::getInstance();
	Log *log = Log::getInstance();
	Authentification * auth = new Authentification();

	config->Get("port",serverPort);
	config->Get("clientMax",numClient);
	address.host = ENET_HOST_ANY;
	address.port  = (enet_uint16) serverPort;

	server = enet_host_create (& address /* the address to bind the server host to */,
								32      /* allow up to 32 clients and/or outgoing connections */,
	                                  2      /* allow up to 2 channels to be used, 0 and 1 */,
	                                  0      /* assume any amount of incoming bandwidth */,
	                                  0      /* assume any amount of outgoing bandwidth */);
	if (server == NULL)
	    {
	        fprintf (stderr,
	                 "An error occurred while trying to create an ENet server host.\n");
	        exit (EXIT_FAILURE);
	    }

		/* Wait up to 1000 milliseconds for an event. */
		while ((enet_host_service (server, & eventServer, 1000) >= 0 ) && (endthread == false )  )
		{
			switch (eventServer.type)
			{
				case ENET_EVENT_TYPE_CONNECT:
					log->Write(Log::DEBUG,"Nouvelle connexion");
					if(!auth->CreateClient(&eventServer))
						log->Write(Log::ERROR,"Impossible de cree le client");
			            break;

			        case ENET_EVENT_TYPE_RECEIVE:

			        	char dudul ;
			        	dudul = eventServer.packet -> data[0];

			        	switch(atoi(&dudul))
			        	{
			        		case ID_SEND_USER:
			        			log->Write(Log::DEBUG,"Packet recu");
			        			if(!auth->_HandleLogonChallenge(&eventServer))
			        				log->Write(Log::ERROR,"Impossible d'authentifier le client");
			        			break;
			        		 	case ID_SEND_REPONSE:
			        		 		log->Write(Log::DEBUG,"Packet de reponse recu");
			        		 		if(!auth->_HandleLogonProof(&eventServer))
			        		 			log->Write(Log::ERROR,"Mauvaise reponse, impossible d'authentifier le client");
			        		 		break;
			        			case ID_GET_ROYAUME:
			        	 			log->Write(Log::DEBUG,"Packet demande de royaume");
			       		 			// if(!auth->_HandleLogonChallenge(&eventServer))
			       		 				log->Write(Log::ERROR,"Impossible d'envoyer le royaume");
			       		 			break;
			        	}

			    	    /* One could just use enet_host_service() instead. */
			    	    enet_host_flush (server);
			            /* Clean up the packet now that we're done using it. */
			            enet_packet_destroy (eventServer.packet);

			            break;

			        case ENET_EVENT_TYPE_DISCONNECT:
			        	log->Write(Log::DEBUG,"deconnexion");
			        	if(!auth->DeleteClient(&eventServer))
			        		log->Write(Log::ERROR,"Impossible de supprimer le client");
			        	break;
			        default:
			        	break;
			}
		}


	delete auth;
	atexit (enet_deinitialize);


	return NULL;
}






void authServer::startServer()
{
	try
	{
		signalHandler->setupSignalHandlers();
		if (!config->Load("Debug/auth.config"))
		{}
		int logLevel;
		config->Get("LogLevel",logLevel);
		log->Start((Log::Priority)logLevel,"authserver.log");
		log->Write(Log::DEBUG,"Demarrage du thread d'authentification");
		pthread_create(&thread,NULL,threadConnexion,&this->endThread);

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
