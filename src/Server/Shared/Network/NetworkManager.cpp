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
	endThread = false;

}

NetworkManager::~NetworkManager() {
	std::map<int,NetworkListener *>::iterator listenner ;
	for (listenner=listOfListenner.begin(); listenner !=listOfListenner.end(); ++listenner)
	{
		delete listenner->second;
	}
	listOfListenner.clear();

	delete server;
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
	thread = boost::thread(&NetworkManager::threadConnexion, (void *) this);

	return true ;
}

bool NetworkManager::deleteConnexion()
{
	endThread = true;
	thread.join();
	return true;
}

void NetworkManager::sendPacket(ENetHost * host, enet_uint8 channel, MessagePacket * messagePacket)
{
	boost::mutex::scoped_lock lock(mutexSend);

	std::ostringstream archive_stream;
	boost::archive::text_oarchive archive(archive_stream);
	archive << messagePacket;

	ENetPacket * packet = enet_packet_create ((const void *)&archive_stream,sizeof(archive_stream) + 1,ENET_PACKET_FLAG_RELIABLE);
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

	ENetPacket * packet = enet_packet_create (messageSend.c_str(),sizeof(messageSend) + 1,ENET_PACKET_FLAG_RELIABLE);
	enet_peer_send(peer,channel,packet);
}



void* NetworkManager::threadConnexion(void* arguments)
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

			networkManager->callback(message->getOpcode(), SessionManager::getInstance()->trouverSession(networkManager->eventServer.peer->address),message);

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


void NetworkManager::addlistenneur(int identifiant,NetworkListener * networkListener)
{
	listOfListenner[identifiant] = networkListener ;
}

void NetworkManager::removelistenneur(int identifiant)
{
	std::map<int,NetworkListener *>::iterator listenner ;
	listenner = listOfListenner.find(identifiant) ;
	if ( listenner == listOfListenner.end())
	{
		listOfListenner.erase(listenner);
	}
}

void NetworkManager::callback(int identifiant,Session * session,MessagePacket * messagePacket)
{
	std::map<int,NetworkListener *>::iterator listenner ;
	listenner = listOfListenner.find(identifiant) ;
	if ( listenner != listOfListenner.end())
	{
		listenner->second->setPacket(session,messagePacket);
	}
}


