/*
 * \file Authentification.cpp
 *
 *  Created on: \date 24 déc. 2014
 *      Author: \author joda
 *  \brief :
 */
#include "Authentification.h"

namespace Auth {

Authentification::Authentification(NetworkManager * networkManager) {
	this->networkManager = networkManager;
	config = Configuration::getInstance();
	log = Log::getInstance();

}

Authentification::~Authentification() {
	networkManager->removeListenneur(ID_AUTH);
}

void Authentification::run()
{
	networkManager->addListenneur(ID_AUTH,this);
	NetworkListener::run();

}

void Authentification::processPacket(MessageNetwork * messageNetwork)
{
	log->write(Log::DEBUG,"Nouveau Packet Authentification");
	MessagePacket * messageRetour = new MessagePacket();
	switch(messageNetwork->messagePacket->getSousOpcode())
	{
	case ID_CHALLENGE :
		handleLogonChallenge(messageNetwork,messageRetour);
		break;
	case ID_REPONSE :
		handleLogonProof(messageNetwork,messageRetour);
		break;
	default:
		break;
	}
	networkManager->sendPacket(messageNetwork->session->getSessionPeer(),0,messageRetour);
}


int  Authentification::handleLogonChallenge(MessageNetwork * messageNetwork,MessagePacket * messageRetour)
{
	std::vector<std::string> tableauData ;
	tableauData.push_back("Build");
	tableauData.push_back("Login");


	// Controle Presence Donnée
	if(! controleData(messageNetwork->messagePacket,&tableauData) )
	{
		log->write(Log::INFO,"Le message venant de %d:%d est illisible ",messageNetwork->session->getSessionID()->host,messageNetwork->session->getSessionID()->port);
		messageRetour->setOpcode(ID_AUTH);
		messageRetour->setSousOpcode(ID_ERREUR);
		messageRetour->setProperty("ErrorId",ID_ERROR_PACKET_SIZE);
		return ID_ERROR_PACKET_SIZE ;

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
		messageRetour->setOpcode(ID_AUTH);
		messageRetour->setSousOpcode(ID_ERREUR);
		messageRetour->setProperty("ErrorId",ID_CONNECTION_BANNED);
		return ID_CONNECTION_BANNED ;
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
		messageRetour->setOpcode(ID_AUTH);
		messageRetour->setSousOpcode(ID_ERREUR);
		messageRetour->setProperty("ErrorId",ID_INVALID_ACCOUNT_OR_PASSWORD);
		return ID_INVALID_ACCOUNT_OR_PASSWORD;
	}


	messageNetwork->session->setSessionListener(compte);
	CompteBan compteBan( compte->getIdAccount());


	if(compteBan.read())
	{
		time_t unbandate = compteBan.getUnbandate() ;
		log->write(Log::INFO,"[AuthChallenge] Le compte %s est banni jusqu'au %s",messageNetwork->messagePacket->getProperty("Login").c_str(),ctime(&unbandate));
		messageRetour->setOpcode(ID_AUTH);
		messageRetour->setSousOpcode(ID_ERREUR);
		messageRetour->setProperty("ErrorId",ID_COMPTE_BANNIE);
		return ID_COMPTE_BANNIE;
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
			messageRetour->setOpcode(ID_AUTH);
			messageRetour->setSousOpcode(ID_ERREUR);
			messageRetour->setProperty("ErrorId",ID_INVALID_IP);
			return ID_INVALID_IP;

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
	return ID_NOERROR;
}

int Authentification::handleLogonProof(MessageNetwork * messageNetwork,MessagePacket * messageRetour)
{
	std::vector<std::string> tableauData;
	tableauData.push_back("Password");

	// Controle Presence Donnée
	if(! controleData(messageNetwork->messagePacket,&tableauData) )
	{
		log->write(Log::INFO,"Le message venant de %d:%d est illisible ",messageNetwork->session->getSessionID()->host,messageNetwork->session->getSessionID()->port);
		messageRetour->setOpcode(ID_AUTH);
		messageRetour->setSousOpcode(ID_ERREUR);
		messageRetour->setProperty("ErrorId",ID_ERROR_PACKET_SIZE);
		return ID_ERROR_PACKET_SIZE ;

	}

	if(messageNetwork->session->getSessionListener()->getSessionListenerType() != SESSION_COMPTE)
	{
		log->write(Log::INFO,"Le message venant de %d:%d est illisible ",messageNetwork->session->getSessionID()->host,messageNetwork->session->getSessionID()->port);
		messageRetour->setOpcode(ID_AUTH);
		messageRetour->setSousOpcode(ID_ERREUR);
		messageRetour->setProperty("ErrorId",ID_ERROR_PACKET_SIZE);
		return ID_ERROR_PACKET_SIZE ;

	}

	Compte * compte = static_cast<Compte*> (messageNetwork->session->getSessionListener()) ;

	if(messageNetwork->session->getSessionEtape() < STEP_REPONSE)
	{
		log->write(Log::INFO,"Le client n'est pas a la bonne etape ");
		messageRetour->setOpcode(ID_AUTH);
		messageRetour->setSousOpcode(ID_ERREUR);
		messageRetour->setProperty("ErrorId",ID_ERROR_ETAPE);
		return ID_ERROR_ETAPE;
	}

	IP ip(messageNetwork->session->getIP());

	if (messageNetwork->messagePacket->getProperty("Password").compare(compte->getShaPassHash()) != 0)
	{
		/*int nombreErreurMDPMax,banTime;
		log->write(Log::INFO,"Erreur de mot de passe");

		config->get("nombreErreurMDP",nombreErreurMDPMax);
		config->get("banTime",banTime);

		compte->setNombreEssai(compte->getNombreEssai() + 1);

		if( (compte->getNombreEssai() % nombreErreurMDPMax ) == 0 )
		{
			compte->banCompte((time(NULL) + banTime  *60),"autoban", 0);
			log->write(Log::INFO,"[AuthChallenge] Le compte %s est banni jusqu'au %s",compte->getNomCompte()->c_str(),ctime(compte->getAccountUnBanDate()));
			messageRetour->setOpcode(ID_AUTH);
			messageRetour->setSousOpcode(ID_ERREUR);
			messageRetour->setProperty("ErrorId",ID_COMPTE_BANNIE);
			return ID_COMPTE_BANNIE;

		} */

		messageRetour->setOpcode(ID_AUTH);
		messageRetour->setSousOpcode(ID_ERREUR);
		messageRetour->setProperty("ErrorId",ID_INVALID_ACCOUNT_OR_PASSWORD);
		return ID_INVALID_ACCOUNT_OR_PASSWORD;


	}

	log->write(Log::INFO,"Mot de passe valider");

	ip.setIpTempNessais(0);
	ip.update();

	messageNetwork->session->setSessionEtape(STEP_REAMSLIST);

	messageRetour->setOpcode(ID_AUTH);
	messageRetour->setSousOpcode(ID_REPONSE);

	return ID_NOERROR;
}


} /* namespace Auth */
