/*
 * AuthentificationService.cpp
 *
 *  Created on: 11 juil. 2015
 *      Author: Skronak
 */

#include "AuthentificationService.h"

namespace Auth {

AuthentificationService::AuthentificationService(NetworkManager * networkManager) {
	this->networkManager = networkManager;
	log = LogManager::getInstance();
	authentificationManager = AuthentificationManager::getInstance();
	realmManager = RealmManager::getInstance();
}

AuthentificationService::~AuthentificationService() {
	AuthentificationManager::DestroyInstance();
	RealmManager::DestroyInstance();
}

void AuthentificationService::run() {
	networkManager->addListenneur(ID_AUTH, this);
	Service::run();

}

void AuthentificationService::processPacket(MessageNetwork * messageNetwork) {
	log->write(LogManager::DEBUG, "Nouveau Packet Authentification");
	MessagePacket * messageRetour = new MessagePacket();
	switch (messageNetwork->messagePacket->getSousOpcode()) {
	case ID_CHALLENGE:
		handleLogonChallenge(messageNetwork, messageRetour);
		break;
	case ID_REPONSE:
		handleLogonProof(messageNetwork, messageRetour);
		break;
	case ID_REALMSLIST:
		handleRealmsList(messageNetwork, messageRetour);
	default:
		break;
	}
	networkManager->sendPacket(messageNetwork->session->getSessionPeer(), 0, messageRetour);
}

void AuthentificationService::handleLogonChallenge(MessageNetwork * messageNetwork,
		MessagePacket * messageRetour) {
	std::vector < std::string > tableauData;
	tableauData.push_back("Build");
	tableauData.push_back("Login");

	// Controle Presence Donneee
	if (!controleData(messageNetwork->messagePacket, &tableauData)) {
		log->write(LogManager::INFO, "Le message venant de %d:%d est illisible ",
				messageNetwork->session->getSessionID()->host,
				messageNetwork->session->getSessionID()->port);
		sendErrorPacket(messageRetour, ID_ERROR_PACKET_SIZE);
		return;
	}

	if (!authentificationManager->checkIp(messageNetwork->session->getIP())) {
		log->write(LogManager::INFO, "[AuthChallenge] L'ip %s est bannie !",
				messageNetwork->session->getIP().c_str());
		sendErrorPacket(messageRetour, ID_CONNECTION_BANNED);
		return;
	}

	log->write(LogManager::INFO, "Nom du client : %s ",
			messageNetwork->messagePacket->getProperty("Login").c_str());

	messageNetwork->session->setSessionListener(
			authentificationManager->isAccountExist(
					messageNetwork->messagePacket->getProperty("Login"),
					messageNetwork->session->getIP()));

	if (!messageNetwork->session->getSessionListener()) {
		log->write(LogManager::INFO, "[AuthChallenge] Le compte %s n'existe pas",
				messageNetwork->messagePacket->getProperty("Login").c_str());
		sendErrorPacket(messageRetour, ID_INVALID_ACCOUNT_OR_PASSWORD);
		return;
	}

	if (!authentificationManager->checkAccount(
			static_cast<Compte*>(messageNetwork->session->getSessionListener())->getIdAccount())) {
		//time_t unbandate = compteBan.getUnbandate() ;
		//log->write(Log::INFO,"[AuthChallenge] Le compte %s est banni jusqu'au %s",messageNetwork->messagePacket->getProperty("Login").c_str(),ctime(&unbandate));
		sendErrorPacket(messageRetour, ID_COMPTE_BANNIE);
		return;
	}

	messageNetwork->session->setSessionEtape(STEP_REPONSE);

	messageRetour->setOpcode(ID_AUTH);
	messageRetour->setSousOpcode(ID_CHALLENGE);
	messageRetour->setProperty("Key", 1234567);
}

void AuthentificationService::handleLogonProof(MessageNetwork * messageNetwork,
		MessagePacket * messageRetour) {
	std::vector < std::string > tableauData;
	tableauData.push_back("Password");

	// Controle Presence Donnee
	if (!controleData(messageNetwork->messagePacket, &tableauData)) {
		log->write(LogManager::INFO, "Le message venant de %d:%d est illisible ",
				messageNetwork->session->getSessionID()->host,
				messageNetwork->session->getSessionID()->port);
		sendErrorPacket(messageRetour, ID_ERROR_PACKET_SIZE);
	}

	if (messageNetwork->session->getSessionListener()->getTypeModel().compare("Compte") == 0   ) {
		log->write(LogManager::INFO, "Le message venant de %d:%d est illisible ",
				messageNetwork->session->getSessionID()->host,
				messageNetwork->session->getSessionID()->port);
		sendErrorPacket(messageRetour, ID_ERROR_PACKET_SIZE);
	}

	if (messageNetwork->session->getSessionEtape() < STEP_REPONSE) {
		log->write(LogManager::INFO, "Le client n'est pas a la bonne etape ");
		sendErrorPacket(messageRetour, ID_ERROR_ETAPE);
	}

	Compte * compte = static_cast<Compte*>(messageNetwork->session->getSessionListener());

	if (messageNetwork->messagePacket->getProperty("Password").compare(compte->getShaPassHash())
			!= 0) {
		authentificationManager->banIP(messageNetwork->session->getIP());
		sendErrorPacket(messageRetour, ID_INVALID_ACCOUNT_OR_PASSWORD);
	}

	log->write(LogManager::INFO, "Mot de passe valider");

	authentificationManager->resetIpTemp(messageNetwork->session->getIP());

	messageNetwork->session->setSessionEtape(STEP_REAMSLIST);

	messageRetour->setOpcode(ID_AUTH);
	messageRetour->setSousOpcode(ID_REPONSE);
}

void AuthentificationService::handleRealmsList(MessageNetwork * messageNetwork,
		MessagePacket * messageRetour) {
	std::vector < std::string > tableauData;
	tableauData.push_back("versionClient");

	// Controle Presence Donnee
	if (!controleData(messageNetwork->messagePacket, &tableauData)) {
		log->write(LogManager::INFO, "Le message venant de %d:%d est illisible ",
				messageNetwork->session->getSessionID()->host,
				messageNetwork->session->getSessionID()->port);
		sendErrorPacket(messageRetour, ID_ERROR_PACKET_SIZE);
	}

	if (messageNetwork->session->getSessionEtape() < STEP_REAMSLIST) {
		log->write(LogManager::INFO, "Le client n'est pas a la bonne etape ");
		sendErrorPacket(messageRetour, ID_ERROR_ETAPE);
	}

	std::vector < std::string > listOfRealms = realmManager->getRealmsList(
			Utilities::toInt(messageNetwork->messagePacket->getProperty("versionClient")), 1);

	for (int increment = 0; increment < listOfRealms.size(); ++increment) {
		messageRetour->setProperty("realm" + Utilities::toString(increment),
				listOfRealms[increment]);
	}

	messageRetour->setOpcode(ID_AUTH);
	messageRetour->setSousOpcode(ID_REALMSLIST);

}

void AuthentificationService::sendErrorPacket(MessagePacket * messageRetour, int typeErreur) {
	messageRetour->setOpcode(ID_AUTH);
	messageRetour->setSousOpcode(ID_ERREUR);
	messageRetour->setProperty("ErrorId", typeErreur);
}

} /* namespace Auth */
