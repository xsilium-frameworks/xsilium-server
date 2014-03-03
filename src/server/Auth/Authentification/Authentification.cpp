/*
 * Authentification.cpp
 *
 *  Created on: 7 f�vr. 2012
 *      Author: joda2
 */

#include "Authentification.h"

Authentification::Authentification(Connexion * connexion) : ModuleActif(connexion) {
	config = Configuration::getInstance();
	log = Log::getInstance();
	gestionnaireSession = GestionnaireSession::getInstance();
	gestionnaireCompte = GestionnaireCompte::getInstance();
	this->connexion = connexion;
	realms = LoginDatabase::getInstance();

	listServeur = new ListServeur();
	listServeur->Initialize(30);
}

Authentification::~Authentification() {
	connexion->removelistenneur((XSILIUM_AUTH * 1000) + ID_AUTH);
	delete this->realms ;
}

void Authentification::stopThread()
{
	endThread = true;
	condition_Queue.notify_all();
	groupThread.join_all();
}

void Authentification::run()
{
	connexion->addlistenneur((XSILIUM_AUTH * 1000 )+ ID_AUTH,boost::bind(&Authentification::setPacket, this));
	for(uint8_t i = 0;i< NUM_THREAD_MODULE;i++)
	{
		groupThread.add_thread(new boost::thread(&Authentification::threadAuthentification, (void *) this) );
	}
}

void Authentification::threadAuthentification(void * arguments)
{
	Authentification * authentification = (Authentification *) arguments ;

	while(!authentification->endThread)
	{
		if(!authentification->isEmpty())
		{
			ENetEvent packet = authentification->getPacket();
			AUTHPACKET_TYPE *data = (AUTHPACKET_TYPE *) packet.packet->data ;
			switch(data->typeAuth)
			{
			case ID_CHALLENGE :
				authentification->HandleLogonChallenge(&packet);
				break;
			case ID_REPONSE :
				authentification->HandleLogonProof(&packet);
				break;
			default:
				break;
			}
			authentification->connexion->deletePacket(packet.packet);
		}
	}
}


int  Authentification::HandleLogonChallenge(ENetEvent * packet,bool cppUnit)
{
	if (packet->packet->dataLength < sizeof(AUTHPACKET_LC_C))
	{
		AUTHPACKET_ERROR messageErreur;
		messageErreur.authTypePacket.structure_opcode.cmd = XSILIUM_AUTH;
		messageErreur.authTypePacket.structure_opcode.opcode = ID_AUTH;
		messageErreur.authTypePacket.typeAuth = ID_ERREUR ;
		messageErreur.errorID = ID_ERROR_PACKET_SIZE;

		log->Write(Log::INFO,"Le message venant de %d:%d est illisible ",packet->peer->address.host,packet->peer->address.port);
		if(!cppUnit)
		{
			ENetPacket * message = enet_packet_create ((const void *)&messageErreur,sizeof(messageErreur) + 1,ENET_PACKET_FLAG_RELIABLE);
			connexion->sendPacket (packet->peer, 0, message);
		}
		return ID_ERROR_PACKET_SIZE;
	}
	Session * session = gestionnaireSession->trouverSession(packet->peer->address) ;
	AUTHPACKET_LC_C * data = (AUTHPACKET_LC_C *) packet->packet->data ;

	if(session->isBanned())
	{
		AUTHPACKET_ERROR messageErreur;
		messageErreur.authTypePacket.structure_opcode.cmd = XSILIUM_AUTH;
		messageErreur.authTypePacket.structure_opcode.opcode = ID_AUTH;
		messageErreur.authTypePacket.typeAuth = ID_ERREUR ;
		messageErreur.errorID = ID_CONNECTION_BANNED;

		log->Write(Log::INFO,"[AuthChallenge] L'ip %d est bannie !",session->getSessionID()->host);
		if(!cppUnit)
		{
			ENetPacket * message = enet_packet_create ((const void *)&messageErreur,sizeof(messageErreur) + 1,ENET_PACKET_FLAG_RELIABLE);
			connexion->sendPacket (session->getSessionPeer(), 0, message);
		}
		return ID_CONNECTION_BANNED;
	}

	session->ajoutIPTemps();

	string login = (const char *) data->login ;
	if (data->login_len != strlen(login.c_str()))
	{
		log->Write(Log::ERROR,"Le nom ne n'a pas la meme longueur que login_len");

		AUTHPACKET_ERROR messageErreur;
		messageErreur.authTypePacket.structure_opcode.cmd = XSILIUM_AUTH;
		messageErreur.authTypePacket.structure_opcode.opcode = ID_AUTH;
		messageErreur.authTypePacket.typeAuth = ID_ERREUR ;
		messageErreur.errorID = ID_ERROR_PACKET_SIZE;

		log->Write(Log::INFO,"Le message venant de %d:%d est illisible ",packet->peer->address.host,packet->peer->address.port);
		if(!cppUnit)
		{
			ENetPacket * message = enet_packet_create ((const void *)&messageErreur,sizeof(messageErreur) + 1,ENET_PACKET_FLAG_RELIABLE);
			connexion->sendPacket (packet->peer, 0, message);
		}
		return ID_ERROR_PACKET_SIZE;
	}

	log->Write(Log::INFO,"Nom du client : %s ",login.c_str());

	if(!gestionnaireCompte->creerCompte(login.c_str()))
	{
		int nombreErreurMax,banTime;
		config->Get("nombreErreurMax",nombreErreurMax);
		config->Get("banTime",banTime);

		if( ( session->getNBIPTemps() % nombreErreurMax ) == 0 )
		{
			session->banIP( (time(NULL) + (banTime * (session->getNBIPTemps() / nombreErreurMax ))  *60),"autoban", 0 );
		}


		AUTHPACKET_ERROR messageErreur;
		messageErreur.authTypePacket.structure_opcode.cmd = XSILIUM_AUTH;
		messageErreur.authTypePacket.structure_opcode.opcode = ID_AUTH;
		messageErreur.authTypePacket.typeAuth = ID_ERREUR ;
		messageErreur.errorID = ID_INVALID_ACCOUNT_OR_PASSWORD;
		log->Write(Log::INFO,"[AuthChallenge] Le compte %s n'existe pas",login.c_str());
		if(!cppUnit)
		{
			ENetPacket * message = enet_packet_create ((const void *)&messageErreur,sizeof(messageErreur) + 1,ENET_PACKET_FLAG_RELIABLE);
			connexion->sendPacket (packet->peer, 0, message);
		}
		return ID_INVALID_ACCOUNT_OR_PASSWORD;
	}

	Compte * compte = gestionnaireCompte->trouverCompte(login.c_str());
	session->setCompte(compte);

	if(compte->isBanned())
	{
		AUTHPACKET_ERROR messageErreur;
		messageErreur.authTypePacket.structure_opcode.cmd = XSILIUM_AUTH;
		messageErreur.authTypePacket.structure_opcode.opcode = ID_AUTH;
		messageErreur.authTypePacket.typeAuth = ID_ERREUR ;
		messageErreur.errorID = ID_COMPTE_BANNIE;
		log->Write(Log::INFO,"[AuthChallenge] Le compte %s est banni jusqu'au %s",login.c_str(),ctime(compte->getAccountUnBanDate()));
		if(!cppUnit)
		{
			ENetPacket * message = enet_packet_create ((const void *)&messageErreur,sizeof(messageErreur) + 1,ENET_PACKET_FLAG_RELIABLE);
			connexion->sendPacket (packet->peer, 0, message);
		}
		return ID_COMPTE_BANNIE;
	}

	if(compte->islocked())
	{
		char hostip[16];

		enet_address_get_host_ip(session->getSessionID(),hostip,sizeof(hostip));
		log->Write(Log::INFO,"[AuthChallenge] Le compte %s est lier a l'IP %s ",compte->getNomCompte()->c_str(),compte->getLastIP()->c_str());
		log->Write(Log::INFO,"[AuthChallenge] Le client a pour l'IP : %s ",hostip);

		if(hostip != compte->getLastIP()->c_str())
		{
			log->Write(Log::INFO,"[AuthChallenge] L'IP %s ne correspond pas a la derniere IP %s ",hostip,compte->getLastIP()->c_str());
			AUTHPACKET_ERROR messageErreur;
			messageErreur.authTypePacket.structure_opcode.cmd = XSILIUM_AUTH;
			messageErreur.authTypePacket.structure_opcode.opcode = ID_AUTH;
			messageErreur.authTypePacket.typeAuth = ID_ERREUR ;
			messageErreur.errorID = ID_INVALID_IP;
			if(!cppUnit)
			{
				ENetPacket * message = enet_packet_create ((const void *)&messageErreur,sizeof(messageErreur) + 1,ENET_PACKET_FLAG_RELIABLE);
				connexion->sendPacket (packet->peer, 0, message);
			}
			return ID_INVALID_IP;

		}
		else
			log->Write(Log::INFO,"[AuthChallenge] Les IPs correspondent ");
	}

	session->supprimeIPTemps();
	compte->setEtapeConnexion(2);

	AUTHPACKET_LC_S messageRetour;
	messageRetour.authTypePacket.structure_opcode.cmd = XSILIUM_AUTH;
	messageRetour.authTypePacket.structure_opcode.opcode = ID_AUTH;
	messageRetour.authTypePacket.typeAuth = ID_CHALLENGE ;
	messageRetour.key = 1234567;
	if(!cppUnit)
	{
		ENetPacket * message = enet_packet_create ((const void *)&messageRetour,sizeof(messageRetour) + 1,ENET_PACKET_FLAG_RELIABLE);
		connexion->sendPacket (packet->peer, 0, message);
	}
	return ID_NOERROR;
}

int Authentification::HandleLogonProof(ENetEvent * packet,bool cppUnit)
{
	if (packet->packet->dataLength < sizeof(AUTHPACKET_P_S))
	{
		AUTHPACKET_ERROR messageErreur;
		messageErreur.authTypePacket.structure_opcode.cmd = XSILIUM_AUTH;
		messageErreur.authTypePacket.structure_opcode.opcode = ID_AUTH;
		messageErreur.authTypePacket.typeAuth = ID_ERREUR ;
		messageErreur.errorID = ID_ERROR_PACKET_SIZE;

		log->Write(Log::INFO,"Le message venant de %d:%d est illisible ",packet->peer->address.host,packet->peer->address.port);
		if(!cppUnit)
		{
			ENetPacket * message = enet_packet_create ((const void *)&messageErreur,sizeof(messageErreur) + 1,ENET_PACKET_FLAG_RELIABLE);
			connexion->sendPacket (packet->peer, 0, message);
		}
		return ID_ERROR_PACKET_SIZE;
	}

	Session * session = gestionnaireSession->trouverSession(packet->peer->address) ;

	if(session->getCompte()->getEtapeConnextion() < 2)
	{
		AUTHPACKET_ERROR messageErreur;
		messageErreur.authTypePacket.structure_opcode.cmd = XSILIUM_AUTH;
		messageErreur.authTypePacket.structure_opcode.opcode = ID_AUTH;
		messageErreur.authTypePacket.typeAuth = ID_ERREUR ;
		messageErreur.errorID = ID_ERROR_ETAPE;

		log->Write(Log::INFO,"Le client n'est pas a la bonne etape ");
		if(!cppUnit)
		{
			ENetPacket * message = enet_packet_create ((const void *)&messageErreur,sizeof(messageErreur) + 1,ENET_PACKET_FLAG_RELIABLE);
			connexion->sendPacket (packet->peer, 0, message);
		}
		return ID_ERROR_ETAPE;
	}
	session->ajoutIPTemps();

	AUTHPACKET_P_S *data = (AUTHPACKET_P_S *) packet->packet->data ;
	log->Write(Log::INFO,"packet recu %s",packet->packet->data);

	log->Write(Log::INFO,"nombre de passage %d",session->getCompte()->getNombreEssai());

	string keyPWD = (const char *) data->A ;

	if (keyPWD.compare(*session->getCompte()->getMDPSHA()) != 0)
	{
		int nombreErreurMDPMax,banTime;
		log->Write(Log::INFO,"Erreur de mot de passe");

		config->Get("nombreErreurMDP",nombreErreurMDPMax);
		config->Get("banTime",banTime);

		session->getCompte()->setNombreEssai(session->getCompte()->getNombreEssai() + 1);

		if( (session->getCompte()->getNombreEssai() % nombreErreurMDPMax ) == 0 )
		{
			session->getCompte()->banCompte((time(NULL) + banTime  *60),"autoban", 0);
			AUTHPACKET_ERROR messageErreur;
			messageErreur.authTypePacket.structure_opcode.cmd = XSILIUM_AUTH;
			messageErreur.authTypePacket.structure_opcode.opcode = ID_AUTH;
			messageErreur.authTypePacket.typeAuth = ID_ERREUR ;
			messageErreur.errorID = ID_COMPTE_BANNIE;
			log->Write(Log::INFO,"[AuthChallenge] Le compte %s est banni jusqu'au %s",session->getCompte()->getNomCompte()->c_str(),ctime(session->getCompte()->getAccountUnBanDate()));
			if(!cppUnit)
			{
				ENetPacket * message = enet_packet_create ((const void *)&messageErreur,sizeof(messageErreur) + 1,ENET_PACKET_FLAG_RELIABLE);
				connexion->sendPacket (packet->peer, 0, message);
			}
			return ID_COMPTE_BANNIE;

		}

		AUTHPACKET_ERROR messageErreur;
		messageErreur.authTypePacket.structure_opcode.cmd = XSILIUM_AUTH;
		messageErreur.authTypePacket.structure_opcode.opcode = ID_AUTH;
		messageErreur.authTypePacket.typeAuth = ID_ERREUR ;
		messageErreur.errorID = ID_INVALID_ACCOUNT_OR_PASSWORD;
		if(!cppUnit)
		{
			ENetPacket * message = enet_packet_create ((const void *)&messageErreur,sizeof(messageErreur) + 1,ENET_PACKET_FLAG_RELIABLE);
			connexion->sendPacket (packet->peer, 0, message);
		}
		return ID_INVALID_ACCOUNT_OR_PASSWORD;


	}

	log->Write(Log::INFO,"Mot de passe valider");

	session->getCompte()->setNombreEssai(0);
	session->getCompte()->setEtapeConnexion(3);

	AUTHPACKET_P_C messageValidation;
	messageValidation.authTypePacket.structure_opcode.cmd = XSILIUM_AUTH;
	messageValidation.authTypePacket.structure_opcode.opcode = ID_AUTH ;
	messageValidation.authTypePacket.typeAuth = ID_REPONSE;
	if(!cppUnit)
	{
		ENetPacket * message = enet_packet_create ((const void *)&messageValidation,sizeof(messageValidation) + 1,ENET_PACKET_FLAG_RELIABLE);
		connexion->sendPacket (packet->peer, 0, message);
	}

	return ID_NOERROR;
}

int Authentification::HandleRealmList(ENetEvent * packet,bool cppUnit)
{
	listServeur->UpdateIfNeed();

	ListeServeur::const_iterator test;

	return true;
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
