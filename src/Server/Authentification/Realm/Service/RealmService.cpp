/*
 * RealmService.cpp
 *
 *  Created on: 11 juil. 2015
 *      Author: Skronak
 */

#include "RealmService.h"

namespace Auth {

RealmService::RealmService(NetworkManager * networkManager) {
	this->networkManager = networkManager;
	log = Log::getInstance();

	m_NextUpdateTime = 0;

}

RealmService::~RealmService() {
	networkManager->removeListenneur(ID_REALM);
}


void RealmService::run()
{
	networkManager->addListenneur(ID_REALM,this);
	NetworkListener::run();
}

void RealmService::processPacket(MessageNetwork * messageNetwork)
{
	log->write(Log::DEBUG,"Nouveau Packet Realm");
	MessagePacket * messageRetour = new MessagePacket();
	switch(messageNetwork->messagePacket->getSousOpcode())
	{
	case ID_LIST_REALM :
		handleListRealm(messageNetwork,messageRetour);
		break;
	default:
		break;
	}
	networkManager->sendPacket(messageNetwork->session->getSessionPeer(),0,messageRetour);
}

int  RealmService::handleListRealm(MessageNetwork * messageNetwork,MessagePacket * messageRetour)
{
	messageRetour->setOpcode(ID_REALM);
	messageRetour->setSousOpcode(ID_LIST_REALM);

	for (std::map<int,Realm *>::iterator it=listRealm.begin(); it!=listRealm.end(); ++it)
	{
		if(it->second != NULL)
			messageRetour->setProperty(it->first,it->second->ToExport());
		else
			it = listRealm.erase(it);
	}

	return ID_NOERROR_R;

}

int  RealmService::handleCreateRealm(MessageNetwork * messageNetwork,MessagePacket * messageRetour)
{
	std::vector<std::string> tableauData = {"NameRealm","Key"};

	// Controle Presence Donnée
	if(! controleData(messageNetwork->messagePacket,&tableauData) )
	{
		log->write(Log::INFO,"Le message venant de %d:%d est illisible ",messageNetwork->session->getSessionID()->host,messageNetwork->session->getSessionID()->port);
		sendErrorPacket(messageRetour, ID_ERROR_PACKET_SIZE);
	}



	Realm * newRealm = new Realm(messageNetwork->messagePacket->getProperty("NameRealm"));

	if(newRealm->read())
	{
		tableauData.clear();
		tableauData = {"ID","Key"};
		if(! controleData(messageNetwork->messagePacket,&tableauData) )
		{
			log->write(Log::INFO,"Le message venant de %d:%d est illisible ",messageNetwork->session->getSessionID()->host,messageNetwork->session->getSessionID()->port);
			sendErrorPacket(MessagePacket * messageRetour, ID_ERROR_PACKET_SIZE);
		}
	}




	suffix = "Realm";
	this->idRealm = idRealm;
	keyRealm = "";
	nameRealm = "";
	urlRealm = "";
	portRealm = 0;
	autorisationRealm = 0;
	versionClientRealm = 0;
	online_Realm = 0;

	messageNetwork->session->getSessionListener()->setSessionListenerType(SESSION_REALM);
	return true;
}

void RealmService::sendErrorPacket(MessagePacket * messageRetour, erreurOfRealm type) {
	messageRetour->setOpcode(ID_REALM);
	messageRetour->setSousOpcode(ID_ERREUR);
	messageRetour->setProperty("ErrorId",type);
}

} /* namespace Auth */
