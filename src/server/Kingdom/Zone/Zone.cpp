/*
 * \file Zone.cpp
 *
 *  Created on: \date 7 avr. 2013
 *      Author: \author joda
 *  \brief :
 */

#include "Zone.h"

Zone::Zone() {
	// TODO Auto-generated constructor stub

}

Zone::~Zone() {
	// TODO Auto-generated destructor stub
}

void Zone::setZonePeer(ENetPeer * peer)
{
	this->peer = peer;
}

ENetAddress * Zone::getZoneID()
{
	return &peer->address ;
}
