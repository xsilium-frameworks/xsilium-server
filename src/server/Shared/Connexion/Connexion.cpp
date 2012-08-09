/*
 * \file Connexion.cpp
 *
 *  Created on: \date 8 aožt 2012
 *      Author: \author joda
 *  \brief :
 */

#include "Connexion.h"

Connexion::Connexion() {
enet_initialize();
endThread = false;
}

Connexion::~Connexion()
{
	for (listenner=listOfListenner.begin() ; listenner!=listOfListenner.end() ; ++listenner)
		{
			delete listenner->callback;
		}
		delete server;
		delete peer;
}

bool Connexion::createConnexion(ENetAddress adresse,int MaxClient)
{
	server = enet_host_create (&adresse /* the address to bind the server host to */,
							   (size_t)MaxClient      /* allow up to 32 clients and/or outgoing connections */,
	                                  2      /* allow up to 2 channels to be used, 0 and 1 */,
	                                  0      /* assume any amount of incoming bandwidth */,
	                                  0      /* assume any amount of outgoing bandwidth */);
	if (server == NULL)
		return false ;

	pthread_create(&thread,NULL,Connexion::threadConnexion,(void *)this);

	return true ;
}


void* Connexion::threadConnexion(void* arguments)
{
	Connexion * connexion = (Connexion *) arguments ;
	connexion->packet = &connexion->eventServer;

	while ((enet_host_service (connexion->server,&connexion->eventServer, 1000) >= 0 ) && (connexion->endThread == false )  )
	{
		switch (connexion->eventServer.type)
		{
			case ENET_EVENT_TYPE_CONNECT:
				connexion->callback(XSILIUM_AUTH,ID_CONNEXION);
		        break;
		    case ENET_EVENT_TYPE_RECEIVE:

		    	//connexion->callback(connexion->eventServer.packet->data[0],connexion->eventServer.packet->data[1]);
		    	connexion->callback(XSILIUM_AUTH,ID_SEND_USER);

		        	//switch(atoi(&dudul))
		        	//{
		        	//	case ID_SEND_USER:
		        	//		log->Write(Log::DEBUG,"Packet recu");
		        	//		if(!auth->_HandleLogonChallenge(&eventServer))
		        	//			log->Write(Log::ERROR,"Impossible d'authentifier le client");
		        	//		break;
		        	//	 	case ID_SEND_REPONSE:
		        	//	 		log->Write(Log::DEBUG,"Packet de reponse recu");
		        	//	 		if(!auth->_HandleLogonProof(&eventServer))
		        	//	 			log->Write(Log::ERROR,"Mauvaise reponse, impossible d'authentifier le client");
		        	//	 		break;
		        	//		case ID_GET_ROYAUME:
		        	// 			log->Write(Log::DEBUG,"Packet demande de royaume");
		       		 			// if(!auth->_HandleLogonChallenge(&eventServer))
		       		// 				log->Write(Log::ERROR,"Impossible d'envoyer le royaume");
		       		// 			break;
		        	//}

		    	    /* One could just use enet_host_service() instead. */
		    	    //enet_host_flush (server);
		            /* Clean up the packet now that we're done using it. */
		            enet_packet_destroy (connexion->eventServer.packet);

		        break;

		    case ENET_EVENT_TYPE_DISCONNECT:
		    	connexion->callback(XSILIUM_AUTH,ID_DECONEXION);
		        break;
		    default:
		        break;
		}
	}
	return NULL;
}


bool Connexion::deleteConnexion()
{
	enet_deinitialize();
	return true;

}

ENetEvent * Connexion::getPacket()
{
	return packet;
}

void Connexion::callback(typerequete requete, Opcode opcode)
{
	for (listenner=listOfListenner.begin() ; listenner!=listOfListenner.end() ; ++listenner)
	{
		if (listenner->requete == requete )
		{
			if(listenner->opcode == opcode)
			{
				listenner->callback->Call();
			}
		}
	}
}

