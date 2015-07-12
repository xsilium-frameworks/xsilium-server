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

	realmManager = RealmManager::getInstance();

}

RealmService::~RealmService() {
	networkManager->removeListenneur(ID_REALM);
	RealmManager::DestroyInstance();
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
	case ID_REGISTER_REALM :
		handleRegisterRealm(messageNetwork,messageRetour);
		break;
	default:
		break;
	}
	networkManager->sendPacket(messageNetwork->session->getSessionPeer(),0,messageRetour);
}

void  RealmService::handleRegisterRealm(MessageNetwork * messageNetwork,MessagePacket * messageRetour)
{
	messageNetwork->session->getSessionListener()->setSessionListenerType(SESSION_REALM);
}

void RealmService::sendErrorPacket(MessagePacket * messageRetour, int typeError) {
	messageRetour->setOpcode(ID_REALM);
	messageRetour->setSousOpcode(ID_ERREUR_REALM);
	messageRetour->setProperty("ErrorId",typeError);
}

} /* namespace Auth */
