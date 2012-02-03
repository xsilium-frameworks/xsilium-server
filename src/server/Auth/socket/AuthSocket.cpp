/*
 * AuthSocket.cpp
 *
 *  Created on: 3 févr. 2012
 *      Author: joda2
 */

#include "AuthSocket.h"
#include "../resource.h"

#include "BitStream.h"
#include <stdlib.h> // For atoi
#include <cstring> // For strlen
#include "Rand.h"
#include "RakNetStatistics.h"
#include "MessageIdentifiers.h"
#include <stdio.h>
#include "Kbhit.h"
#include "GetTime.h"
#include "RakAssert.h"
#include "RakSleep.h"
#include "Gets.h"
#include <unistd.h> // usleep
#include <cstdio>
#include "Getche.h"


using namespace RakNet;



AuthSocket::AuthSocket() {
	peer = RakNet::RakPeerInterface::GetInstance();

}

AuthSocket::~AuthSocket() {
	RakNet::RakPeerInterface::DestroyInstance(peer);
}

void AuthSocket::Start(void)
{
	RakNet::SocketDescriptor socketDescriptor;
	socketDescriptor.port=(unsigned short) SERVER_PORT;
	bool b = peer->Startup((unsigned short) 600,&socketDescriptor,1)==RakNet::RAKNET_STARTED;
	RakAssert(b);
	peer->SetMaximumIncomingConnections(600);
}

unsigned AuthSocket::ConnectionCount(void) const
	{
		unsigned short numberOfSystems;
		peer->GetConnectionList(0,&numberOfSystems);
		return numberOfSystems;
	}
void AuthSocket::Update()
{
	Packet *p = peer->Receive();
	while (p)
	{
		switch (p->data[0])
		{
		case ID_CONNECTION_LOST:
		case ID_DISCONNECTION_NOTIFICATION:
		case ID_NEW_INCOMING_CONNECTION:
			printf("Connections = %i\n", ConnectionCount());
			break;
 		case ID_USER_PACKET_ENUM:
 			break;

		}
		peer->DeallocatePacket(p);
		p = peer->Receive();
	}
}




