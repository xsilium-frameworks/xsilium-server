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
	log = Log::getInstance();
}


AuthentificationService::~AuthentificationService() {
	// TODO Auto-generated destructor stub
}

void AuthentificationService::run()
{
	networkManager->addListenneur(ID_AUTH,this);
	NetworkListener::run();

}

void AuthentificationService::processPacket(MessageNetwork * messageNetwork)
{
	log->write(Log::DEBUG,"Nouveau Packet Authentification");
	MessagePacket * messageRetour = new MessagePacket();
	switch(messageNetwork->messagePacket->getSousOpcode())
	{
	case ID_CHALLENGE :
//		handleLogonChallenge(messageNetwork,messageRetour);
		break;
	case ID_REPONSE :
//		handleLogonProof(messageNetwork,messageRetour);
		break;
	default:
		break;
	}
	networkManager->sendPacket(messageNetwork->session->getSessionPeer(),0,messageRetour);
}

void  Authentification::handleLogonChallenge(MessageNetwork * messageNetwork,MessagePacket * messageRetour)
{
	std::vector<std::string> tableauData ;
	tableauData.push_back("Build");
	tableauData.push_back("Login");


	// Controle Presence Donneee
	if(! controleData(messageNetwork->messagePacket,&tableauData) )
	{
		log->write(Log::INFO,"Le message venant de %d:%d est illisible ",messageNetwork->session->getSessionID()->host,messageNetwork->session->getSessionID()->port);
		sendErrorPacket(messageRetour, ID_ERROR_PACKET_SIZE);
		return;
	}

	messageNetwork->session->getSessionListener()->setSessionListenerType(SESSION_COMPTE);

	IPBan ipBan(messageNetwork->session->getIP());
	IP ip(messageNetwork->session->getIP());
	ip.read();

	if(ip.getIdIp() == 0)
		ip.create();

	if(ipBan.read())
	{
		log->write(Log::INFO,"[AuthChallenge] L'ip %d est bannie !",messageNetwork->session->getSessionID()->host);
		sendErrorPacket(messageRetour, ID_CONNECTION_BANNED);
	}

	log->write(Log::INFO,"Nom du client : %s ",messageNetwork->messagePacket->getProperty("Login").c_str());

	Compte * compte = new Compte(messageNetwork->messagePacket->getProperty("Login"));
	if(!compte->read())
	{

		ip.setIpTempNessais( ip.getIpTempNessais() + 1 );

		int nombreErreurMax,banTime;
		config->get("nombreErreurMax",nombreErreurMax);
		config->get("banTime",banTime);

		if( ( ip.getIpTempNessais() % nombreErreurMax ) == 0 )
		{
			ipBan.setBandate(time(NULL));
			ipBan.setUnbandate((time(NULL) + (banTime * (ip.getIpTempNessais() / nombreErreurMax ))  *60));
			ipBan.setRaison("autoban");
			ipBan.setBannedby(0);
			ipBan.create();
		}
		ip.update();

		log->write(Log::INFO,"[AuthChallenge] Le compte %s n'existe pas",messageNetwork->messagePacket->getProperty("Login").c_str());
		sendErrorPacket(messageRetour, ID_INVALID_ACCOUNT_OR_PASSWORD);
	}


	messageNetwork->session->setSessionListener(compte);
	CompteBan compteBan( compte->getIdAccount());


	if(compteBan.read())
	{
		time_t unbandate = compteBan.getUnbandate() ;
		log->write(Log::INFO,"[AuthChallenge] Le compte %s est banni jusqu'au %s",messageNetwork->messagePacket->getProperty("Login").c_str(),ctime(&unbandate));
		sendErrorPacket(messageRetour, ID_COMPTE_BANNIE);
	}

	if(compte->isLocked())
	{
		log->write(Log::INFO,"[AuthChallenge] Le compte %s est lier a l'IP %s ",compte->getUsername().c_str(),compte->getLastIp().c_str());
		log->write(Log::INFO,"[AuthChallenge] Le client a pour l'IP : %s ",messageNetwork->session->getIP().c_str());

		if(messageNetwork->session->getIP().compare(compte->getLastIp()) != 0 )
		{

			ip.setIpTempNessais( ip.getIpTempNessais() + 1 );

			int nombreErreurMax,banTime;
			config->get("nombreErreurMax",nombreErreurMax);
			config->get("banTime",banTime);

			if( ( ip.getIpTempNessais() % nombreErreurMax ) == 0 )
			{
				ipBan.setBandate(time(NULL));
				ipBan.setUnbandate((time(NULL) + (banTime * (ip.getIpTempNessais() / nombreErreurMax ))  *60));
				ipBan.setRaison("autoban");
				ipBan.setBannedby(0);
				ipBan.create();
			}
			ip.update();

			log->write(Log::INFO,"[AuthChallenge] L'IP %s ne correspond pas a la derniere IP %s ",messageNetwork->session->getIP().c_str(),compte->getLastIp().c_str());
			sendErrorPacket(messageRetour, ID_INVALID_IP);
		}
		else
			log->write(Log::INFO,"[AuthChallenge] Les IPs correspondent ");
	}

	ip.setIpTempNessais(0);
	ip.update();

	messageNetwork->session->setSessionEtape(STEP_REPONSE);

	messageRetour->setOpcode(ID_AUTH);
	messageRetour->setSousOpcode(ID_CHALLENGE);
	messageRetour->setProperty("Key",1234567);
}

void Authentification::handleLogonProof(MessageNetwork * messageNetwork,MessagePacket * messageRetour)
{
	std::vector<std::string> tableauData;
	tableauData.push_back("Password");

	// Controle Presence Donnee
	if(! controleData(messageNetwork->messagePacket,&tableauData) )
	{
		log->write(Log::INFO,"Le message venant de %d:%d est illisible ",messageNetwork->session->getSessionID()->host,messageNetwork->session->getSessionID()->port);
		sendErrorPacket(messageRetour, ID_ERROR_PACKET_SIZE);
	}

	if(messageNetwork->session->getSessionListener()->getSessionListenerType() != SESSION_COMPTE)
	{
		log->write(Log::INFO,"Le message venant de %d:%d est illisible ",messageNetwork->session->getSessionID()->host,messageNetwork->session->getSessionID()->port);
		sendErrorPacket(messageRetour, ID_ERROR_PACKET_SIZE);
	}

	Compte * compte = static_cast<Compte*> (messageNetwork->session->getSessionListener()) ;

	if(messageNetwork->session->getSessionEtape() < STEP_REPONSE)
	{
		log->write(Log::INFO,"Le client n'est pas a la bonne etape ");
		sendErrorPacket(messageRetour, ID_ERROR_ETAPE);
	}

	IP ip(messageNetwork->session->getIP());

	if (messageNetwork->messagePacket->getProperty("Password").compare(compte->getShaPassHash()) != 0)
	{
		sendErrorPacket(messageRetour, ID_INVALID_ACCOUNT_OR_PASSWORD);
	}

	log->write(Log::INFO,"Mot de passe valider");

	ip.setIpTempNessais(0);
	ip.update();

	messageNetwork->session->setSessionEtape(STEP_REAMSLIST);

	messageRetour->setOpcode(ID_AUTH);
	messageRetour->setSousOpcode(ID_REPONSE);
}

void AuthentificationService::sendErrorPacket(MessagePacket * messageRetour, typeForAuth type) {
	messageRetour->setOpcode(ID_AUTH);
	messageRetour->setSousOpcode(ID_ERREUR);
	messageRetour->setProperty("ErrorId",type);
}

} /* namespace Auth */
