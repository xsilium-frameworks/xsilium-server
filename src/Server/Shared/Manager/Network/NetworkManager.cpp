/*
 * \file NetworkManager.cpp
 *
 *  Created on: \date 4 nov. 2014
 *      Author: \author joda
 *  \brief :
 */
#include "NetworkManager.h"

NetworkManager::NetworkManager(int typeConnexion) {
	enet_initialize();
	host = 0;
	peer = 0;
	endThread = false;
	isConnectedflag = false;
	this->typeConnexion = typeConnexion ;

}

NetworkManager::~NetworkManager() {
	listOfListenner.clear();
	enet_host_destroy(host);
	enet_deinitialize();
}

ENetHost * NetworkManager::getHost()
{
	return host;
}
ENetPeer * NetworkManager::getPeer()
{
	return peer;
}

bool NetworkManager::createConnexion(ENetAddress adresse, int MaxClient) {

	endThread = false;

	if (!host)
	{
		if(typeConnexion == NETWORK_TYPE_SERVER)
		{

			host = enet_host_create (&adresse /* the address to bind the server host to */,
					(size_t)MaxClient      /* allow up to 32 clients and/or outgoing connections */,
					2      /* allow up to 2 channels to be used, 0 and 1 */,
					0      /* assume any amount of incoming bandwidth */,
					0      /* assume any amount of outgoing bandwidth */);
			if (host == NULL)
				return false ;
			enet_host_compress_with_range_coder(host);
			thread = boost::thread(&NetworkManager::threadConnexion, (void *) this);

		}
		else
		{
			host = enet_host_create (NULL /* create a client host */,
					1 /* only allow 1 outgoing connection */,
					2 /* allow up 2 channels to be used, 0 and 1 */,
					57600 / 8 /* 56K modem with 56 Kbps downstream bandwidth */,
					14400 / 8 /* 56K modem with 14 Kbps upstream bandwidth */);
			if ( host == NULL)
				return false;
			enet_host_compress_with_range_coder(host);
		}
	}
	else
		return false;
	return true ;
}

int NetworkManager::connexionToHost(std::string url,int port)
{
	ENetAddress address;
	enet_address_set_host (&address,url.c_str());
	address.port = port;
	peer = enet_host_connect (host, & address, 2, 0);
	if (peer == NULL)
	{
		return 1;
	}
	if (enet_host_service (host, &event, 1000) > 0 && event.type == ENET_EVENT_TYPE_CONNECT)
	{
		isConnectedflag = true;
		endThread = false;
		thread = boost::thread(&NetworkManager::threadConnexion, (void *) this);
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

bool NetworkManager::disconnexion()
{
	if(typeConnexion == NETWORK_TYPE_SERVER)
	{
		endThread = true;
		thread.join();
		return true;
	}
	else
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



void* NetworkManager::threadConnexion(void* arguments)
{
	NetworkManager * networkManager = static_cast<NetworkManager*> (arguments) ;

	while ((enet_host_service (networkManager->host,&networkManager->event, 10) >= 0 ) && (networkManager->endThread == false )  )
	{
		switch (networkManager->event.type)
		{
		case ENET_EVENT_TYPE_CONNECT:
			if(networkManager->typeConnexion == NETWORK_TYPE_SERVER)
			{
				SessionManager::getInstance()->creerSession(networkManager->event.peer);
			}
			break;
		case ENET_EVENT_TYPE_RECEIVE:
		{
			MessagePacket * message = new MessagePacket();

			std::istringstream archive_stream(std::string((char*)networkManager->event.packet->data)) ;
			boost::archive::text_iarchive archive(archive_stream);
			archive >> message;

			networkManager->callBack(message->getOpcode(), SessionManager::getInstance()->trouverSession(networkManager->event.peer->address),message);

			enet_packet_destroy (networkManager->event.packet);
			break;
		}

		case ENET_EVENT_TYPE_DISCONNECT:
			if(networkManager->typeConnexion == NETWORK_TYPE_SERVER)
			{
				SessionManager::getInstance()->supprimerSession(networkManager->event.peer);
			}
			else
			{
				networkManager->endThread = true;
			}
			break;
		default:
			break;
		}
	}
	return NULL;
}


void NetworkManager::addListenneur(int identifiant,Service * service)
{
	listOfListenner[identifiant] = service ;
}

void NetworkManager::removeListenneur(int identifiant)
{
	std::map<int,Service *>::iterator listenner ;
	listenner = listOfListenner.find(identifiant) ;
	if ( listenner != listOfListenner.end())
	{
		listOfListenner.erase(listenner);
	}
}

void NetworkManager::callBack(int identifiant,Session * session,MessagePacket * messagePacket)
{
	std::map<int,Service *>::iterator listenner ;
	listenner = listOfListenner.find(identifiant) ;
	if ( listenner != listOfListenner.end())
	{
		listenner->second->setPacket(session,messagePacket);
	}
}


