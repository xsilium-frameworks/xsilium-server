/*
 * \file RoyaumesManager.cpp
 *
 *  Created on: \date 22 févr. 2015
 *      Author: \author joda
 *  \brief :
 */
#include "../Realm/RoyaumesManager.h"

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
		HandleListRoyaume(messageNetwork,messageRetour);
		break;
	default:
		break;
	}
	networkManager->sendPacket(messageNetwork->session->getSessionPeer(),0,messageRetour);
}

int  RoyaumesManager::HandleListRoyaume(MessageNetwork * messageNetwork,MessagePacket * messageRetour)
{
	messageRetour->setOpcode(ID_ROYAUME);
	messageRetour->setSousOpcode(ID_LIST_ROYAUME);

	for (std::map<int,Royaume *>::iterator it=listRoyaume.begin(); it!=listRoyaume.end(); ++it)
	{
		if(it->second != NULL)
			messageRetour->setProperty(it->first,it->second->ToExport());
		else
			it = listRoyaume.erase(it);
	}

	return ID_NOERROR_R;

}

int  RoyaumesManager::HandleUpdateRoyaume(MessageNetwork * messageNetwork,MessagePacket * messageRetour)
{
	std::vector<std::string> tableauData = {"NameRoyaume","Key"};

	// Controle Presence Donnée
	if(! controleData(messageNetwork->messagePacket,&tableauData) )
	{
		log->write(Log::INFO,"Le message venant de %d:%d est illisible ",messageNetwork->session->getSessionID()->host,messageNetwork->session->getSessionID()->port);
		messageRetour->setOpcode(ID_ROYAUME);
		messageRetour->setSousOpcode(ID_ERROR_PACKET_SIZE_R);
		messageRetour->setProperty("ErrorId",ID_ERROR_PACKET_SIZE);
		return ID_ERROR_PACKET_SIZE ;
	}



	Royaume * newRoyaume = new Royaume(messageNetwork->messagePacket->getProperty("NameRoyaume"));

	if(newRoyaume->read())
	{
		tableauData.clear();
		tableauData = {"ID","Key"};
		if(! controleData(messageNetwork->messagePacket,&tableauData) )
		{
			log->write(Log::INFO,"Le message venant de %d:%d est illisible ",messageNetwork->session->getSessionID()->host,messageNetwork->session->getSessionID()->port);
			messageRetour->setOpcode(ID_ROYAUME);
			messageRetour->setSousOpcode(ID_ERROR_PACKET_SIZE_R);
			messageRetour->setProperty("ErrorId",ID_ERROR_PACKET_SIZE);
			return ID_ERROR_PACKET_SIZE ;
		}
	}




	suffix = "Royaume";
	this->idRoyaume = idRoyaume;
	keyRoyaume = "";
	nameRoyaume = "";
	urlRoyaume = "";
	portRoyaume = 0;
	autorisationRoyaume = 0;
	versionClientRoyaume = 0;
	online_royaume = 0;

	messageNetwork->session->getSessionListener()->setSessionListenerType(SESSION_ROYAUME);







	return true;

}

} /* namespace Auth */
