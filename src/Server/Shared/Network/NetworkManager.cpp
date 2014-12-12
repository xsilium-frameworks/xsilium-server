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
	boost::archive::text_oarchive archive(archive_stream);
	archive << messagePacket;

	ENetPacket * packet = enet_packet_create ((const void *)&archive_stream,sizeof(archive_stream) + 1,ENET_PACKET_FLAG_RELIABLE);
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
			//networkManager->callback((XSILIUM_ALL * 1000) + ID_CONNEXION);
			break;
		case ENET_EVENT_TYPE_RECEIVE:
		{
		/*	structure_opcodeT * typePacket = (structure_opcodeT *) connexion->eventServer.packet->data ;

			connexion->callback( (typePacket->cmd * 1000 ) +  (typePacket->opcode ));
*/
			break;
		}

		case ENET_EVENT_TYPE_DISCONNECT:
			//connexion->callback((XSILIUM_ALL * 1000 ) + ID_DECONEXION);
			break;
		default:
			break;
		}
	}
	return NULL;
}




