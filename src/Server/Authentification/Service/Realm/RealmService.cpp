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
	log = LogManager::getInstance();

	realmManager = RealmManager::getInstance();

}

RealmService::~RealmService() {
	networkManager->removeListenneur(ID_REALM);
	RealmManager::DestroyInstance();
}

void RealmService::run() {
	networkManager->addListenneur(ID_REALM, this);
	Service::run();
}

void RealmService::processPacket(MessageNetwork * messageNetwork) {
	log->write(LogManager::DEBUG, "Nouveau Packet Realm");
	MessagePacket * messageRetour = new MessagePacket();
	switch (messageNetwork->messagePacket->getSousOpcode()) {
	case ID_REGISTER_REALM:
		handleRegisterRealm(messageNetwork, messageRetour);
		break;
	default:
		break;
	}
	networkManager->sendPacket(messageNetwork->session->getSessionPeer(), 0, messageRetour);
}

void RealmService::handleRegisterRealm(MessageNetwork * messageNetwork,
		MessagePacket * messageRetour) {
	std::vector < std::string > tableauData;
	tableauData.push_back("Name");
	tableauData.push_back("Key");
	tableauData.push_back("Port");
	tableauData.push_back("URL");
	tableauData.push_back("Version");

	messageNetwork->session->getSessionListener()->setSessionListenerType(SESSION_REALM);

	// Controle Presence Donneee
	if (!controleData(messageNetwork->messagePacket, &tableauData)) {
		log->write(LogManager::INFO, "Le message venant de %d:%d est illisible ",
				messageNetwork->session->getSessionID()->host,
				messageNetwork->session->getSessionID()->port);
		sendErrorPacket(messageRetour, ID_ERROR_PACKET_SIZE_R);
		return;
	}

	// Verification de la cl�
	if (!realmManager->checkRealmKey(messageNetwork->messagePacket->getProperty("Key"))) {
		log->write(LogManager::INFO, "Le message venant de %d:%d est illisible ",
				messageNetwork->session->getSessionID()->host,
				messageNetwork->session->getSessionID()->port);
		sendErrorPacket(messageRetour, ID_ERROR_KEY);
	}

	// R�cup�ration du Realm et mise � jour
	idRealm = realmManager->checkRealmName(messageNetwork->messagePacket->getProperty("Name"));

	if (idRealm) {
		realmManager->createRealm();
	} else {
		realmManager->updateRealm();
	}
}

void RealmService::sendErrorPacket(MessagePacket * messageRetour, int typeError) {
	messageRetour->setOpcode(ID_REALM);
	messageRetour->setSousOpcode(ID_ERREUR_REALM);
	messageRetour->setProperty("ErrorId", typeError);
}

} /* namespace Auth */
