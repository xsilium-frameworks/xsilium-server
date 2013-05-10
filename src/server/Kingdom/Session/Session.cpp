/*
 * \file Session.cpp
 *
 *  Created on: \date 12 janv. 2013
 *      Author: \author joda
 *  \brief :
 */

#include "Session.h"

Session::Session() {
	peer = NULL;

}

Session::~Session() {
	// TODO Auto-generated destructor stub
}

void Session::setSessionPeer(ENetPeer * peer)
{
	this->peer = peer;
}

ENetAddress * Session::getSessionID()
{
	return &peer->address ;
}
