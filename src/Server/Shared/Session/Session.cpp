/*
 * \file Session.cpp
 *
 *  Created on: \date 16 déc. 2014
 *      Author: \author joda
 *  \brief :
 */
#include "Session.h"

Session::Session() {
	peer = NULL;
	compte = 0;
	sessionType = SESSION_NONE;

}

Session::~Session() {
	if(compte)
		delete compte;
}

void Session::setSessionPeer(ENetPeer * peer)
{
	this->peer = peer;
}

ENetPeer * Session::getSessionPeer()
{
	return peer;
}

ENetAddress * Session::getSessionID()
{
	return &peer->address ;
}

void Session::setCompte(Compte * compte)
{
	this->compte = compte;
}

Compte * Session::getCompte()
{
	return compte;
}

void Session::setSessionType(SessionType sessionType)
{
	this->sessionType = sessionType;
}

SessionType Session::getSessionType()
{
	return sessionType;
}

char * Session::getIP()
{
	char * buffer = new char[16];
	enet_address_get_host_ip(&peer->address,buffer,sizeof(buffer));
	return buffer;
}
