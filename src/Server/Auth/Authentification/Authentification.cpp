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
		HandleLogonChallenge(messageNetwork,messageRetour);
		break;
	case ID_REPONSE :
		HandleLogonProof(messageNetwork,messageRetour);
		break;
	default:
		break;
	}
	networkManager->sendPacket(messageNetwork->session->getSessionPeer(),0,messageRetour);
}


int  Authentification::HandleLogonChallenge(MessageNetwork * messageNetwork,MessagePacket * messageRetour)
{
	// Controle Presence Donnée
	if(!messageNetwork->messagePacket->hasProperty("Build"))
	{
		log->write(Log::INFO,"Le message venant de %d:%d est illisible ",messageNetwork->session->getSessionID()->host,messageNetwork->session->getSessionID()->port);
		messageRetour->setOpcode(ID_AUTH);
		messageRetour->setSousOpcode(ID_ERREUR);
		messageRetour->setProperty("ErrorId",ID_ERROR_PACKET_SIZE);
		return ID_ERROR_PACKET_SIZE ;

	}

	if(!messageNetwork->messagePacket->hasProperty("Login"))
	{
		log->write(Log::INFO,"Le message venant de %d:%d est illisible ",messageNetwork->session->getSessionID()->host,messageNetwork->session->getSessionID()->port);
		messageRetour->setOpcode(ID_AUTH);
		messageRetour->setSousOpcode(ID_ERREUR);
		messageRetour->setProperty("ErrorId",ID_ERROR_PACKET_SIZE);
		return ID_ERROR_PACKET_SIZE ;

	}

	/*if(messageNetwork->session->getSessionType() != SESSION_CLIENT)
	{
		log->write(Log::INFO,"Le message venant de %d:%d est illisible ",messageNetwork->session->getSessionID()->host,messageNetwork->session->getSessionID()->port);
		messageRetour->setOpcode(ID_AUTH);
		messageRetour->setSousOpcode(ID_ERREUR);
		messageRetour->setProperty("ErrorId",ID_ERROR_PACKET_SIZE);
		return ID_ERROR_PACKET_SIZE ;

	}*/

	messageNetwork->session->setSessionType(SESSION_CLIENT);

	IP ipTemp(messageNetwork->session->getIP());

	if(ipTemp.isBanned())
	{
		log->write(Log::INFO,"[AuthChallenge] L'ip %d est bannie !",messageNetwork->session->getSessionID()->host);
		messageRetour->setOpcode(ID_AUTH);
		messageRetour->setSousOpcode(ID_ERREUR);
		messageRetour->setProperty("ErrorId",ID_CONNECTION_BANNED);
		return ID_CONNECTION_BANNED ;
	}

	ipTemp.ajoutIPTemps();

	log->write(Log::INFO,"Nom du client : %s ",messageNetwork->messagePacket->getProperty("Login").c_str());

	Compte * compte = new Compte();
	if(!compte->chargementCompte(messageNetwork->messagePacket->getProperty("Login")))
	{
		int nombreErreurMax,banTime;
		config->get("nombreErreurMax",nombreErreurMax);
		config->get("banTime",banTime);

		if( ( ipTemp.getNBIPTemps() % nombreErreurMax ) == 0 )
		{
			ipTemp.banIP( (time(NULL) + (banTime * (ipTemp.getNBIPTemps() / nombreErreurMax ))  *60),"autoban", 0 );
		}
		log->write(Log::INFO,"[AuthChallenge] Le compte %s n'existe pas",messageNetwork->messagePacket->getProperty("Login").c_str());
		messageRetour->setOpcode(ID_AUTH);
		messageRetour->setSousOpcode(ID_ERREUR);
		messageRetour->setProperty("ErrorId",ID_INVALID_ACCOUNT_OR_PASSWORD);
		return ID_INVALID_ACCOUNT_OR_PASSWORD;
	}


	messageNetwork->session->setCompte(compte);

	if(compte->isBanned())
	{
		log->write(Log::INFO,"[AuthChallenge] Le compte %s est banni jusqu'au %s",messageNetwork->messagePacket->getProperty("Login").c_str(),ctime(compte->getAccountUnBanDate()));
		messageRetour->setOpcode(ID_AUTH);
		messageRetour->setSousOpcode(ID_ERREUR);
		messageRetour->setProperty("ErrorId",ID_COMPTE_BANNIE);
		return ID_COMPTE_BANNIE;
	}

	if(compte->islocked())
	{
		log->write(Log::INFO,"[AuthChallenge] Le compte %s est lier a l'IP %s ",compte->getNomCompte()->c_str(),compte->getLastIP()->c_str());
		log->write(Log::INFO,"[AuthChallenge] Le client a pour l'IP : %s ",messageNetwork->session->getIP());

		if(messageNetwork->session->getIP() != compte->getLastIP()->c_str())
		{
			log->write(Log::INFO,"[AuthChallenge] L'IP %s ne correspond pas a la derniere IP %s ",messageNetwork->session->getIP(),compte->getLastIP()->c_str());
			messageRetour->setOpcode(ID_AUTH);
			messageRetour->setSousOpcode(ID_ERREUR);
			messageRetour->setProperty("ErrorId",ID_INVALID_IP);
			return ID_INVALID_IP;

		}
		else
			log->write(Log::INFO,"[AuthChallenge] Les IPs correspondent ");
	}

	ipTemp.supprimeIPTemps();
	compte->setEtapeConnexion(2);
	messageRetour->setOpcode(ID_AUTH);
	messageRetour->setSousOpcode(ID_CHALLENGE);
	messageRetour->setProperty("Key",1234567);
	return ID_NOERROR;
}

int Authentification::HandleLogonProof(MessageNetwork * messageNetwork,MessagePacket * messageRetour)
{

	if(!messageNetwork->messagePacket->hasProperty("Password"))
	{
		log->write(Log::INFO,"Le message venant de %d:%d est illisible ",messageNetwork->session->getSessionID()->host,messageNetwork->session->getSessionID()->port);
		messageRetour->setOpcode(ID_AUTH);
		messageRetour->setSousOpcode(ID_ERREUR);
		messageRetour->setProperty("ErrorId",ID_ERROR_PACKET_SIZE);
		return ID_ERROR_PACKET_SIZE ;

	}

	if(messageNetwork->session->getSessionType() != SESSION_CLIENT)
	{
		log->write(Log::INFO,"Le message venant de %d:%d est illisible ",messageNetwork->session->getSessionID()->host,messageNetwork->session->getSessionID()->port);
		messageRetour->setOpcode(ID_AUTH);
		messageRetour->setSousOpcode(ID_ERREUR);
		messageRetour->setProperty("ErrorId",ID_ERROR_PACKET_SIZE);
		return ID_ERROR_PACKET_SIZE ;

	}

	if(messageNetwork->session->getCompte()->getEtapeConnextion() < 2)
	{
		log->write(Log::INFO,"Le client n'est pas a la bonne etape ");
		messageRetour->setOpcode(ID_AUTH);
		messageRetour->setSousOpcode(ID_ERREUR);
		messageRetour->setProperty("ErrorId",ID_ERROR_ETAPE);
		return ID_ERROR_ETAPE;
	}

	IP ipTemp(messageNetwork->session->getIP());


	ipTemp.ajoutIPTemps();

	log->write(Log::INFO,"nombre de passage %d",messageNetwork->session->getCompte()->getNombreEssai());

	if (messageNetwork->messagePacket->getProperty("Password").compare(*messageNetwork->session->getCompte()->getMDPSHA()) != 0)
	{
		int nombreErreurMDPMax,banTime;
		log->write(Log::INFO,"Erreur de mot de passe");

		config->get("nombreErreurMDP",nombreErreurMDPMax);
		config->get("banTime",banTime);

		messageNetwork->session->getCompte()->setNombreEssai(messageNetwork->session->getCompte()->getNombreEssai() + 1);

		if( (messageNetwork->session->getCompte()->getNombreEssai() % nombreErreurMDPMax ) == 0 )
		{
			messageNetwork->session->getCompte()->banCompte((time(NULL) + banTime  *60),"autoban", 0);
			log->write(Log::INFO,"[AuthChallenge] Le compte %s est banni jusqu'au %s",messageNetwork->session->getCompte()->getNomCompte()->c_str(),ctime(messageNetwork->session->getCompte()->getAccountUnBanDate()));
			messageRetour->setOpcode(ID_AUTH);
			messageRetour->setSousOpcode(ID_ERREUR);
			messageRetour->setProperty("ErrorId",ID_COMPTE_BANNIE);
			return ID_COMPTE_BANNIE;

		}

		messageRetour->setOpcode(ID_AUTH);
		messageRetour->setSousOpcode(ID_ERREUR);
		messageRetour->setProperty("ErrorId",ID_INVALID_ACCOUNT_OR_PASSWORD);
		return ID_INVALID_ACCOUNT_OR_PASSWORD;


	}

	log->write(Log::INFO,"Mot de passe valider");

	messageNetwork->session->getCompte()->setNombreEssai(0);
	messageNetwork->session->getCompte()->setEtapeConnexion(3);

	messageRetour->setOpcode(ID_AUTH);
	messageRetour->setSousOpcode(ID_REPONSE);

	return ID_NOERROR;
}

int Authentification::HandleRealmList(MessageNetwork * messageNetwork,MessagePacket * messageRetour)
{
	/*	for (ListeServeur::const_iterator serveur= listServeur->getListServeur().begin(); serveur!=listServeur->getListServeur().end(); ++serveur)
	{

	}

	return true; */

	return ID_NOERROR;
}



/// %Realm List command handler
/*bool Authentification::_HandleRealmList()
{
    sLog.outStaticDebug("Entering _HandleRealmList");
    if (socket().recv_len() < 5)
        return false;

    socket().recv_skip(5);

    ///- Get the user id (else close the connection)
    // No SQL injection (prepared statement)
//changement car normalisation nom requete -- nico le 18-11-2012
PreparedStatement* stmt = LoginDatabase.GetPreparedStatement(REALMS_SEL_ACCOUNT_RECUPINFOSCOMPTE);
    //PreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_GET_ACCIDBYNAME);
    stmt->setString(0, _login);
    PreparedQueryResult result = LoginDatabase.Query(stmt);
    if (!result)
    {
        sLog.outError("[ERROR] user %s tried to login and we cannot find him in the database.", _login.c_str());
        socket().shutdown();
        return false;
    }

    uint32 id = result->GetUInt32(0);

    ///- Update realm list if need
    sRealmList->UpdateIfNeed();

    ///- Circle through realms in the RealmList and construct the return packet (including # of user characters in each realm)
    ByteBuffer pkt;

    size_t RealmListSize = 0;
    for (RealmList::RealmMap::const_iterator i = sRealmList->begin(); i != sRealmList->end(); ++i)
    {
        // don't work with realms which not compatible with the client
        if (_expversion & POST_BC_EXP_FLAG) // 2.4.3 and 3.1.3 cliens
        {
            if (i->second.gamebuild != _build)
                continue;
        }
        else if (_expversion & PRE_BC_EXP_FLAG) // 1.12.1 and 1.12.2 clients are compatible with eachother
        {
            if (!AuthHelper::IsPreBCAcceptedClientBuild(i->second.gamebuild))
                continue;
        }

        uint8 AmountOfCharacters;

        // No SQL injection. id of realm is controlled by the database.
        stmt = LoginDatabase.GetPreparedStatement(LOGIN_GET_NUMCHARSONREALM);
        stmt->setUInt32(0, i->second.m_ID);
        stmt->setUInt32(1, id);
        result = LoginDatabase.Query(stmt);
        if (result)
            AmountOfCharacters = result->GetUInt8(0);
        else
            AmountOfCharacters = 0;

        uint8 lock = (i->second.allowedSecurityLevel > _accountSecurityLevel) ? 1 : 0;

        pkt << i->second.icon;                             // realm type
        if ( _expversion & POST_BC_EXP_FLAG )//only 2.4.3 and 3.1.3 cliens
            pkt << lock;                                       // if 1, then realm locked
        pkt << i->second.color;                            // if 2, then realm is offline
        pkt << i->first;
        pkt << i->second.address;
        pkt << i->second.populationLevel;
        pkt << AmountOfCharacters;
        pkt << i->second.timezone;                          // realm category
        if ( _expversion & POST_BC_EXP_FLAG )//2.4.3 and 3.1.3 clients
            pkt << (uint8) 0x2C;                                // unk, may be realm number/id?
        else
            pkt << (uint8) 0x0; //1.12.1 and 1.12.2 clients

        ++RealmListSize;
    }

    if ( _expversion & POST_BC_EXP_FLAG )//2.4.3 and 3.1.3 cliens
    {
        pkt << (uint8) 0x10;
        pkt << (uint8) 0x00;
    }else{//1.12.1 and 1.12.2 clients
        pkt << (uint8) 0x00;
        pkt << (uint8) 0x02;
    }

    // make a ByteBuffer which stores the RealmList's size
    ByteBuffer RealmListSizeBuffer;
    RealmListSizeBuffer << (uint32)0;
    if (_expversion & POST_BC_EXP_FLAG) // only 2.4.3 and 3.1.3 cliens
        RealmListSizeBuffer << (uint16)RealmListSize;
    else
        RealmListSizeBuffer << (uint32)RealmListSize;

    ByteBuffer hdr;
    hdr << (uint8) REALM_LIST;
    hdr << (uint16)(pkt.size() + RealmListSizeBuffer.size());
    hdr.append(RealmListSizeBuffer);    // append RealmList's size buffer
    hdr.append(pkt);                    // append realms in the realmlist

    socket().send((char const*)hdr.contents(), hdr.size());

    return true;
}*/


} /* namespace Auth */
