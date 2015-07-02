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
	MessagePacket messageRetour;
	switch(messageNetwork->messagePacket->getSousOpcode())
	{
	case ID_CHALLENGE :
		handleLogonChallenge(messageNetwork,&messageRetour);
		break;
	case ID_REPONSE :
		handleLogonProof(messageNetwork,&messageRetour);
		break;
	default:
		break;
	}
	networkManager->sendPacket(messageNetwork->session->getSessionPeer(),0,&messageRetour);
}


int  Authentification::handleLogonChallenge(MessageNetwork * messageNetwork,MessagePacket * messageRetour)
{
	IPBan ipBan(messageNetwork->session->getIP());
	IP ip(messageNetwork->session->getIP());
	int error = ID_NOERROR ;

	try
	{
		// Controle Presence Donnée
		if(!messageNetwork->messagePacket->hasProperty("Build") || messageNetwork->messagePacket->hasProperty("Login"))
			throw ID_ERROR_PACKET_SIZE;

		messageNetwork->session->getSessionListener()->setSessionListenerType(SESSION_COMPTE);

		ip.read();

		if(!ipBan.read())
			throw ID_CONNECTION_BANNED ;

		log->write(Log::INFO,"Nom du client : %s ",messageNetwork->messagePacket->getProperty("Login").c_str());

		Compte * compte = new Compte(messageNetwork->messagePacket->getProperty("Login"));
		if(!compte->read())
		{
			banIP(&ip,&ipBan);
			throw ID_INVALID_ACCOUNT_OR_PASSWORD;
		}

		CompteBan compteBan( compte->getIdAccount());

		if(compteBan.read())
			throw ID_COMPTE_BANNIE;

		messageNetwork->session->setSessionListener(compte);
		messageNetwork->session->setSessionEtape(STEP_REPONSE);
		messageRetour->setOpcode(ID_AUTH);
		messageRetour->setSousOpcode(ID_CHALLENGE);
		messageRetour->setProperty("Key",1234567);

		ip.setIpTempNessais(0);



	}
	catch ( int exceptionError )
	{
		log->write(Log::ERROR,"Erreur d'authentification %d sur l'ip %s",exceptionError,messageNetwork->session->getIP().c_str());
		messageRetour->setOpcode(ID_AUTH);
		messageRetour->setSousOpcode(ID_ERREUR);
		messageRetour->setProperty("ErrorId",exceptionError);
		error = exceptionError;

	}

	int idtransaction = DatabaseManager::getInstance()->createTransaction();
	ip.update(idtransaction);

	if(error == ID_INVALID_ACCOUNT_OR_PASSWORD )
		ipBan.create(idtransaction);

	DatabaseManager::getInstance()->commit(idtransaction);



	return error ;

}

int Authentification::handleLogonProof(MessageNetwork * messageNetwork,MessagePacket * messageRetour)
{

	IPBan ipBan(messageNetwork->session->getIP());
	IP ip(messageNetwork->session->getIP());
	int error = ID_NOERROR ;

	try
	{

		if(!messageNetwork->messagePacket->hasProperty("Password"))
			throw ID_ERROR_PACKET_SIZE;

		if(messageNetwork->session->getSessionListener()->getSessionListenerType() != SESSION_COMPTE)
			throw ID_ERROR_PACKET_SIZE;

		if(messageNetwork->session->getSessionEtape() < STEP_REPONSE)
			throw ID_ERROR_ETAPE;

		Compte * compte = static_cast<Compte*> (messageNetwork->session->getSessionListener()) ;


		if (messageNetwork->messagePacket->getProperty("Password").compare(compte->getShaPassHash()) != 0)
		{
			banIP(&ip , &ipBan);
			throw ID_INVALID_ACCOUNT_OR_PASSWORD;
		}

		log->write(Log::INFO,"Mot de passe valider");

		ip.setIpTempNessais(0);

		messageNetwork->session->setSessionEtape(STEP_REAMSLIST);

		messageRetour->setOpcode(ID_AUTH);
		messageRetour->setSousOpcode(ID_REPONSE);
	}
	catch ( int exceptionError )
	{
		log->write(Log::ERROR,"Erreur d'authentification %d sur l'ip %s",exceptionError,messageNetwork->session->getIP().c_str());
		messageRetour->setOpcode(ID_AUTH);
		messageRetour->setSousOpcode(ID_ERREUR);
		messageRetour->setProperty("ErrorId",exceptionError);
		error = exceptionError;
	}

	int idtransaction = DatabaseManager::getInstance()->createTransaction();
	ip.update(idtransaction);

	if(error == ID_INVALID_ACCOUNT_OR_PASSWORD )
		ipBan.create(idtransaction);

	DatabaseManager::getInstance()->commit(idtransaction);


	return error;
}

void Authentification::banIP(IP * ip , IPBan * ipBan)
{
	int nombreErreurMax,banTime;
	config->get("nombreErreurMax",nombreErreurMax);
	config->get("banTime",banTime);


	ip->setIpTempNessais( ip->getIpTempNessais() + 1 );

	if( ( ip->getIpTempNessais() % nombreErreurMax ) == 0 )
	{
		ipBan->setBandate(time(NULL));
		ipBan->setUnbandate((time(NULL) + (banTime * (ip->getIpTempNessais() / nombreErreurMax ))  *60));
		ipBan->setRaison("autoban");
		ipBan->setBannedby(0);
	}
}


} /* namespace Auth */
