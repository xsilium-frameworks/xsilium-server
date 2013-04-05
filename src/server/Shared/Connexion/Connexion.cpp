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
}

Connexion::~Connexion()
{
	delete server;
	delete peer;
	enet_deinitialize();
}

bool Connexion::createConnexion(ENetAddress adresse,int MaxClient)
{
	endThread = false;
	server = enet_host_create (&adresse /* the address to bind the server host to */,
			(size_t)MaxClient      /* allow up to 32 clients and/or outgoing connections */,
			2      /* allow up to 2 channels to be used, 0 and 1 */,
			0      /* assume any amount of incoming bandwidth */,
			0      /* assume any amount of outgoing bandwidth */);
	if (server == NULL)
		return false ;

	thread = boost::thread(&Connexion::threadConnexion, (void *) this);

	return true ;
}


void* Connexion::threadConnexion(void* arguments)
{
	Connexion * connexion = (Connexion *) arguments ;
	connexion->packet = &connexion->eventServer;

	while ((enet_host_service (connexion->server,&connexion->eventServer, 10) >= 0 ) && (connexion->endThread == false )  )
	{
		switch (connexion->eventServer.type)
		{
		case ENET_EVENT_TYPE_CONNECT:
			connexion->callback((XSILIUM_ALL * 10) + ID_CONNEXION);
			break;
		case ENET_EVENT_TYPE_RECEIVE:
		{
			structure_opcodeT * typePacket = (structure_opcodeT *) connexion->eventServer.packet->data ;

			connexion->callback( (typePacket->cmd * 10 ) +  (typePacket->opcode ));

			break;
		}

		case ENET_EVENT_TYPE_DISCONNECT:
			connexion->callback((XSILIUM_ALL * 10 ) + ID_DECONEXION);
			break;
		default:
			break;
		}
	}
	return NULL;
}


bool Connexion::deleteConnexion()
{
	endThread = true;
	thread.join();
	return true;

}

ENetEvent * Connexion::getPacket()
{
	return packet;
}

ENetHost * Connexion::getServer()
{
	return server ;
}

void Connexion::deletePacket(ENetPacket * packet)
{
	boost::mutex::scoped_lock lock(mutexDelete);
	/* Clean up the packet now that we're done using it. */
	enet_packet_destroy (packet);
}

void Connexion::sendPacket(ENetHost * host, enet_uint8 channel, ENetPacket * packet)
{
	boost::mutex::scoped_lock lock(mutexSend);
	enet_host_broadcast (host,channel,packet);
}

void Connexion::sendPacket(ENetPeer * peer, enet_uint8 channel, ENetPacket * packet)
{
	boost::mutex::scoped_lock lock(mutexSend);
	enet_peer_send(peer,channel,packet);
}
