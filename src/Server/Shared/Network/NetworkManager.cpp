/*
 * \file NetworkManager.cpp
 *
 *  Created on: \date 4 nov. 2014
 *      Author: \author joda
 *  \brief :
 */
#include "NetworkManager.h"

NetworkManager::NetworkManager() {
	enet_initialize();
	server = NULL;
	peer = NULL;
	client = NULL;
	endThread = false;
	isConnectedflag = false;

}

NetworkManager::~NetworkManager() {
	listOfListenner.clear();
	if(server)
		delete server;
	if(client)
		delete client;
	delete peer;
	enet_deinitialize();
}

bool NetworkManager::createConnexion(ENetAddress adresse, int MaxClient) {

	endThread = false;
	server = enet_host_create (&adresse /* the address to bind the server host to */,
			(size_t)MaxClient      /* allow up to 32 clients and/or outgoing connections */,
			2      /* allow up to 2 channels to be used, 0 and 1 */,
			0      /* assume any amount of incoming bandwidth */,
			0      /* assume any amount of outgoing bandwidth */);
	if (server == NULL)
		return false ;

	enet_host_compress_with_range_coder(server);
	thread = boost::thread(&NetworkManager::threadConnexionServer, (void *) this);

	return true ;
}

bool NetworkManager::createConnexion()
{
	client = enet_host_create (NULL /* create a client host */,
			1 /* only allow 1 outgoing connection */,
			2 /* allow up 2 channels to be used, 0 and 1 */,
			57600 / 8 /* 56K modem with 56 Kbps downstream bandwidth */,
			14400 / 8 /* 56K modem with 14 Kbps upstream bandwidth */);
	if ( client != NULL)
	{
		enet_host_compress_with_range_coder(client);
		return true;
	}
	return false;
}

bool NetworkManager::deleteConnexion()
{
	endThread = true;
	thread.join();
	return true;
}

bool NetworkManager::disconnexion()
{
	if(peer != NULL)
	{
		if(isConnectedflag)
		{
			isConnectedflag = false;
		}
		enet_peer_disconnect (peer, 0);
		thread.join();
		enet_peer_reset (peer);
		return true;
	}
	return false;
}

int NetworkManager::connexionToHost(std::string url,int port)
{
	enet_address_set_host (& address,url.c_str());
	address.port = port;
	peer = enet_host_connect (client, & address, 2, 0);
	if (peer == NULL)
	{
		return 1;
	}
	if (enet_host_service (client, &eventClient, 1000) > 0 && eventClient.type == ENET_EVENT_TYPE_CONNECT)
	{
		isConnectedflag = true;
		endThread = false;
		thread = boost::thread(&NetworkManager::threadConnexionClient, (void *) this);
		return 0;
	}
	else
	{
		/* Either the 5 seconds are up or a disconnect event was */
		/* received. Reset the peer in the event the 5 seconds   */
		/* had run out without any significant event.            */
		enet_peer_reset (peer);
		return 2 ;
	}
}

void NetworkManager::sendPacket(ENetHost * host, enet_uint8 channel, MessagePacket * messagePacket)
{
	boost::mutex::scoped_lock lock(mutexSend);

	std::ostringstream archive_stream;
	std::string messageSend;

	boost::archive::text_oarchive archive(archive_stream);
	archive << messagePacket;

	messageSend = archive_stream.str();

	ENetPacket * packet = enet_packet_create (messageSend.c_str(),messageSend.size() + 1,ENET_PACKET_FLAG_RELIABLE);
	enet_host_broadcast (host,channel,packet);
}

void NetworkManager::sendPacket(ENetPeer * peer, enet_uint8 channel, MessagePacket * messagePacket)
{
	boost::mutex::scoped_lock lock(mutexSend);

	std::ostringstream archive_stream;
	std::string messageSend;

	boost::archive::text_oarchive archive(archive_stream);
	archive << messagePacket;

	messageSend = archive_stream.str();

	ENetPacket * packet = enet_packet_create (messageSend.c_str(),messageSend.size() + 1,ENET_PACKET_FLAG_RELIABLE);
	enet_peer_send(peer,channel,packet);
}



void* NetworkManager::threadConnexionServer(void* arguments)
{
	NetworkManager * networkManager = static_cast<NetworkManager*> (arguments) ;

	while ((enet_host_service (networkManager->server,&networkManager->eventServer, 10) >= 0 ) && (networkManager->endThread == false )  )
	{
		switch (networkManager->eventServer.type)
		{
		case ENET_EVENT_TYPE_CONNECT:
			SessionManager::getInstance()->creerSession(networkManager->eventServer.peer);
			break;
		case ENET_EVENT_TYPE_RECEIVE:
		{
			MessagePacket * message = new MessagePacket();

			std::istringstream archive_stream(std::string((char*)networkManager->eventServer.packet->data)) ;
			boost::archive::text_iarchive archive(archive_stream);
			archive >> message;

			networkManager->callBack(message->getOpcode(), SessionManager::getInstance()->trouverSession(networkManager->eventServer.peer->address),message);

			enet_packet_destroy (networkManager->eventServer.packet);
			break;
		}

		case ENET_EVENT_TYPE_DISCONNECT:
			SessionManager::getInstance()->supprimerSession(networkManager->eventServer.peer);
			break;
		default:
			break;
		}
	}
	return NULL;
}

void* NetworkManager::threadConnexionClient(void* arguments)
{
	NetworkManager * networkManager = static_cast<NetworkManager *>(arguments) ;

	while ((enet_host_service (networkManager->client,&networkManager->eventClient, 10) >= 0 ) && (networkManager->endThread == false )  )
	{
		switch (networkManager->eventClient.type)
		{
		case ENET_EVENT_TYPE_CONNECT:
			//networkManager->callback((XSILIUM_ALL * 1000) + ID_CONNEXION);
			break;
		case ENET_EVENT_TYPE_RECEIVE:
		{
			MessagePacket * message = new MessagePacket();

			std::istringstream archive_stream(std::string((char*)networkManager->eventClient.packet->data));
			boost::archive::text_iarchive archive(archive_stream);
			archive >> message;

			networkManager->callback(message->getOpcode(),message);
			break;
		}

		case ENET_EVENT_TYPE_DISCONNECT:
			//networkManager->callback((XSILIUM_ALL * 1000 ) + ID_DECONEXION);
			networkManager->endThread = true;
			break;
		default:
			break;
		}
        enet_packet_destroy (networkManager->eventClient.packet);
	}
	return NULL;
}


void NetworkManager::addListenneur(int identifiant,NetworkListener * networkListener)
{
	listOfListenner[identifiant] = networkListener ;
}

void NetworkManager::removeListenneur(int identifiant)
{
	std::map<int,NetworkListener *>::iterator listenner ;
	listenner = listOfListenner.find(identifiant) ;
	if ( listenner != listOfListenner.end())
	{
		listOfListenner.erase(listenner);
	}
}

void NetworkManager::callBack(int identifiant,Session * session,MessagePacket * messagePacket)
{
	std::map<int,NetworkListener *>::iterator listenner ;
	listenner = listOfListenner.find(identifiant) ;
	if ( listenner != listOfListenner.end())
	{
		listenner->second->setPacket(session,messagePacket);
	}
}


