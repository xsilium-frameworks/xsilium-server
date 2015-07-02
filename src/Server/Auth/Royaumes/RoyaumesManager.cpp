/*
 * \file RoyaumesManager.cpp
 *
 *  Created on: \date 22 févr. 2015
 *      Author: \author joda
 *  \brief :
 */
#include "RoyaumesManager.h"

namespace Auth {

RoyaumesManager::RoyaumesManager(NetworkManager * networkManager) {
	this->networkManager = networkManager;
	log = Log::getInstance();

	m_NextUpdateTime = 0;

}

RoyaumesManager::~RoyaumesManager() {
	networkManager->removeListenneur(ID_ROYAUME);
}

void RoyaumesManager::run()
{
	networkManager->addListenneur(ID_ROYAUME,this);
	NetworkListener::run();

}

void RoyaumesManager::processPacket(MessageNetwork * messageNetwork)
{
	log->write(Log::DEBUG,"Nouveau Packet Royaume");
	MessagePacket * messageRetour = new MessagePacket();
	switch(messageNetwork->messagePacket->getSousOpcode())
	{
	case ID_LIST_ROYAUME :
		HandleReadRoyaumes(messageNetwork,messageRetour);
		break;
	default:
		break;
	}
	networkManager->sendPacket(messageNetwork->session->getSessionPeer(),0,messageRetour);
}

int  RoyaumesManager::HandleReadRoyaumes(MessageNetwork * messageNetwork,MessagePacket * messageRetour)
{
	messageRetour->setOpcode(ID_ROYAUME);
	messageRetour->setSousOpcode(ID_LIST_ROYAUME);

	for (std::map<int,Royaume *>::iterator it=listRoyaume.begin(); it!=listRoyaume.end(); ++it)
	{
		if(it->second != NULL)
			messageRetour->setProperty(it->first,it->second->ToExport());
		else
			listRoyaume.erase(it);

	}

	return ID_NOERROR_R;
}

int  RoyaumesManager::HandleCreateRoyaume(MessageNetwork * messageNetwork,MessagePacket * messageRetour)
{
	return true;
}

} /* namespace Auth */
