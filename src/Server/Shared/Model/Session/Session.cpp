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
	model = 0;
	sessionEtape = 0;
}

Session::~Session() {
	if(model)
	{
	    model->setOnline(false);
	}
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

void Session::setSessionListener(Model * model)
{
	this->model = model;
}

Model * Session::getSessionListener()
{
	return model;
}

std::string Session::getIP()
{
	char * buffer = new char[16];
	enet_address_get_host_ip(&peer->address,buffer,sizeof(buffer));
	return std::string(buffer);
}

int Session::getSessionEtape() const {
	return sessionEtape;
}

void Session::setSessionEtape(int sessionEtape) {
	this->sessionEtape = sessionEtape;
}
