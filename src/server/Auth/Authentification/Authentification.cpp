/*
 * Authentification.cpp
 *
 *  Created on: 7 f�vr. 2012
 *      Author: joda2
 */

#include "Authentification.h"

Authentification::Authentification() {
	config = Configuration::getInstance();
	log = Log::getInstance();
	connexion = Connexion::getInstance();

	connexion->addlistenneur(XSILIUM_AUTH,ID_CONNEXION,this,&Authentification::CreateClient );
	connexion->addlistenneur(XSILIUM_AUTH,ID_DECONEXION,this,&Authentification::DeleteClient );
	connexion->addlistenneur(XSILIUM_AUTH,ID_SEND_USER,this,&Authentification::HandleLogonChallenge );
	connexion->addlistenneur(XSILIUM_AUTH,ID_SEND_REPONSE,this,&Authentification::HandleLogonProof );
	connexion->addlistenneur(XSILIUM_AUTH,ID_GET_ROYAUME,this,&Authentification::HandleRealmList );

	string infoDB;
	config->Get("LoginDatabaseInfo",infoDB);
	realms = LoginDatabase::getInstance();
	realms->connexionDB(infoDB);

	listServeur = new ListServeur();
	listServeur->Initialize(30);
}

Authentification::~Authentification() {
	delete this->realms ;
}

bool Authentification::FindClient(ENetAddress address)
{

	for (client=listOfClient.begin() ; client!=listOfClient.end() ; ++client)
	{
	  if ( client->IP == address.host )
	  {
		  if(client->port == address.port)
		  {
			  log->Write(Log::INFO,"Le client avec l'IP : %d, Port : %d a ete trouv� ",client->IP,client->port);
			  return true;
		  }
	  }
	}
	log->Write(Log::INFO,"Le client avec l'IP : %d, Port : %d n'a pas �t� trouv� ",client->IP,client->port);
	return false;
}

void Authentification::CreateClient()
{
	sClient clientTemp ;
	ENetEvent * packet;
	packet = connexion->getPacket();

	clientTemp.IP = packet->peer->address.host ;
	clientTemp.port = packet->peer->address.port ;
	clientTemp.etape = 1;

	log->Write(Log::INFO,"Creation d'un nouveaux client avec IP : %d , Port: %d",clientTemp.IP,clientTemp.port);
	listOfClient.push_back(clientTemp);

}

void Authentification::DeleteClient()
{

	ENetEvent * packet;
	packet = connexion->getPacket();


	if (FindClient(packet->peer->address))
	{
		log->Write(Log::INFO,"deconnexion du client IP : %d, Port : %d ",client->IP,client->port);
		listOfClient.erase(client);
	}
	else
		log->Write(Log::INFO,"Le client avec IP : %d et Port : %d",packet->peer->address.host,packet->peer->address.port);
}



void Authentification::HandleLogonChallenge()
{
	ENetEvent * packet;
	uint8_t ipNBEssai;
	packet = connexion->getPacket();

	if (packet->packet->dataLength < sizeof(sAuthLogonChallenge_C))
	{
		AUTH_LOGON_ERROR error;
		error.cmd = XSILIUM_AUTH;
		error.opcode = ID_ERROR ;
		error.error = 1;
		log->Write(Log::INFO,"Le message venant de %d:%d est illisible ",packet->peer->address.host,packet->peer->address.port);

		ENetPacket * message = enet_packet_create ((const char *)&error,sizeof(error) + 1,ENET_PACKET_FLAG_RELIABLE);
		enet_peer_send (packet->peer, 0, message);
		return;
	}

	if (!FindClient(packet->peer->address))
	{
		return ;
	}

	sAuthLogonChallenge_C *data = (sAuthLogonChallenge_C *) packet->packet->data ;

	string login = (const char *) data->login ;
	if (data->login_len != strlen(login.c_str()))
	log->Write(Log::ERROR,"erreur avec le nom \n");


	client->build = data->build;
	char hostip[16];

	log->Write(Log::INFO,"Nom du client : %s ",login.c_str());
	enet_address_get_host_ip(&packet->peer->address,hostip,sizeof(hostip));
	log->Write(Log::INFO,"adresse client et port : %s:%i",hostip,packet->peer->address.port);


	pqxx::result resultsql;
	realms->executionPrepareStatement(REALMS_DEL_IPTEMPORAIRE_SUPPRLIGNEIP);
	resultsql = realms->executionPrepareStatement(REALMS_SEL_IPTEMPORAIRE_LECTURENERREURS,1,hostip);
	if(resultsql.empty())
		ipNBEssai = 0;
	else
		ipNBEssai = resultsql[0][0].as<int>();


	//changement car normalisation nom requete nico le 18-11-2012
	realms->executionPrepareStatement(REALMS_UPD_IPBANNED_DEBANAUTOIP);
	//realms->executionPrepareStatement(LOGIN_SET_EXPIREDIPBANS);
	//changement car normalisation nom requete nico le 18-11-2012
	resultsql = realms->executionPrepareStatement(REALMS_SEL_IPBANNED_INFOSSURIPBANNIES,1,hostip);
	//resultsql = realms->executionPrepareStatement(LOGIN_GET_IPBANNED,1,hostip);
	if(!resultsql.empty())
		{
			AUTH_LOGON_ERROR error;
			error.cmd = XSILIUM_AUTH;
			error.opcode = ID_CONNECTION_BANNED ;
			error.error = 0;
			log->Write(Log::INFO,"[AuthChallenge] L'ip %s est bannie !",hostip);

			ENetPacket * message = enet_packet_create ((const char *)&error,sizeof(error) + 1,ENET_PACKET_FLAG_RELIABLE);
		    enet_peer_send (packet->peer, 0, message);
		    return;
		}
	//changement car normalisation nom requete nico le 18-11-2012
	realms->executionPrepareStatement(REALMS_UPD_ACCOUNTBANNED_DEBANAUTOCOMPTE);
	//realms->executionPrepareStatement(LOGIN_SET_EXPIREDACCBANS);
	//changement car normalisation nom requete nico le 18-11-2012
	resultsql = realms->executionPrepareStatement(REALMS_SEL_ACCOUNT_RECUPINFOSCOMPTE,1,login.c_str());
	//resultsql = realms->executionPrepareStatement(LOGIN_GET_ACCIDBYNAME,1,login.c_str());
	if(resultsql.empty())
		{
			if(ipNBEssai == 0 )
				realms->executionPrepareStatement(REALMS_INS_IPTEMPORAIRE_STOCKAGEIPTEMPORAIRE,1,hostip);
			else if (ipNBEssai == 8 )
			{
				realms->executionPrepareStatement(REALMS_UPD_IPTEMPORAIRE_MAJIPTEMPORAIRE,2,hostip,0);
				realms->executionPrepareStatement(REALMS_INS_BANIP_BANAUTOIP,2,hostip,0);
			}
			else
			{
				realms->executionPrepareStatement(REALMS_UPD_IPTEMPORAIRE_MAJIPTEMPORAIRE,2,hostip,(ipNBEssai + 1));
			}


			AUTH_LOGON_ERROR error;
			error.cmd = XSILIUM_AUTH;
			error.opcode = ID_INVALID_ACCOUNT_OR_PASSWORD ;
			error.error = 0;
			log->Write(Log::INFO,"[AuthChallenge] Le compte %s n'existe pas",login.c_str());

			ENetPacket * message = enet_packet_create ((const char *)&error,sizeof(error) + 1,ENET_PACKET_FLAG_RELIABLE);
		    enet_peer_send (packet->peer, 0, message);
			return;
		}
	client->shaPassHash = resultsql[0][0].as<std::string>();
	client->idLogin = resultsql[0][1].as<int>();
	client->locked = resultsql[0][2].as<bool>();
	client->lastIP = resultsql[0][3].as<std::string>();
	client->nbPassage = resultsql[0][4].as<int>();

	resultsql = realms->executionPrepareStatement(REALMS_SEL_ACCOUNTBANNED_RECUPDATEFINBANCOMPTE,1,ToString((int)client->idLogin).c_str());
	if(resultsql.empty())
	{
		client->accountUnBanDate = 0;
	}
	else
	{

		struct tm tm;
		strptime((resultsql[0][0].as<std::string>()).c_str(), "%Y-%m-%d %H:%M:%S", &tm);

		client->accountUnBanDate = mktime(&tm);
	}

	if(client->accountUnBanDate > time(0) )
	{
		AUTH_LOGON_ERROR error;
		error.cmd = XSILIUM_AUTH;
		error.opcode = ID_COMPTE_BANNIE ;
		error.error = 1;
		log->Write(Log::INFO,"[AuthChallenge] Le compte %s est banni jusqu'au %s ",login.c_str(),(resultsql[0][0].as<std::string>()).c_str());

		ENetPacket * message = enet_packet_create ((const char *)&error,sizeof(error) + 1,ENET_PACKET_FLAG_RELIABLE);
		enet_peer_send (packet->peer, 0, message);
		return;
	}

	if(client->locked)
		{
		log->Write(Log::INFO,"[AuthChallenge] Le compte %s est lier a l'IP %s ",login.c_str(),client->lastIP.c_str());
		log->Write(Log::INFO,"[AuthChallenge] Le client a pour l'IP : %s ",hostip);

		if(hostip != client->lastIP.c_str())
			{
				log->Write(Log::INFO,"[AuthChallenge] L'IP %s ne correspond pas a la derniere IP %s ",hostip,client->lastIP.c_str());
				AUTH_LOGON_ERROR error;
				error.cmd = XSILIUM_AUTH;
				error.opcode = ID_INVALID_IP ;
				error.error = 1;
				ENetPacket * message = enet_packet_create ((const char *)&error,sizeof(error) + 1,ENET_PACKET_FLAG_RELIABLE);
				enet_peer_send (packet->peer, 0, message);
				return;

			}
			else
				log->Write(Log::INFO,"[AuthChallenge] Les IPs correspondent ");
		}
	if(ipNBEssai > 0)
		realms->executionPrepareStatement(REALMS_UPD_IPTEMPORAIRE_MAJIPTEMPORAIRE,2,hostip,0);

	client->etape = 2;
	AUTH_LOGON_CHALLENGE messageRetour;
	messageRetour.cmd = XSILIUM_AUTH;
	messageRetour.opcode = ID_SEND_CHALLENGE;
	messageRetour.key = 1234567;

	ENetPacket * message = enet_packet_create ((const char *)&messageRetour,sizeof(messageRetour) + 1,ENET_PACKET_FLAG_RELIABLE);
	enet_peer_send (packet->peer, 0, message);



}


void Authentification::HandleLogonProof()
{

	ENetEvent * packet;
	packet = connexion->getPacket();

	if (packet->packet->dataLength < sizeof(sAuthLogonChallenge_C))
	{
		AUTH_LOGON_ERROR error;
		error.cmd = XSILIUM_AUTH;
		error.opcode = ID_ERROR ;
		error.error = 1;
		log->Write(Log::INFO,"Le message venant de %d:%d est illisible ",packet->peer->address.host,packet->peer->address.port);

		ENetPacket * message = enet_packet_create ((const char *)&error,sizeof(error) + 1,ENET_PACKET_FLAG_RELIABLE);
		enet_peer_send (packet->peer, 0, message);
		return;
	}


	if(FindClient(packet->peer->address))
	{
		if(client->etape < 2 )
		{
			AUTH_LOGON_ERROR msg_error;
			msg_error.cmd = XSILIUM_AUTH;
			msg_error.opcode = ID_ERROR ;
			msg_error.error = 1;

			ENetPacket * message = enet_packet_create ((const char *)&msg_error,sizeof(msg_error) + 1,ENET_PACKET_FLAG_RELIABLE);
			enet_peer_send (packet->peer, 0, message);

			return;
		}

		client->nbPassage +=1;
		AUTH_LOGON_PROOF_C *data = (AUTH_LOGON_PROOF_C *) packet->packet->data ;

		log->Write(Log::INFO,"packet recu %s",packet->packet->data);

		log->Write(Log::INFO,"nombre de passage %d",client->nbPassage);

		string keyPWD = (const char *) data->A ;

		if (keyPWD.compare(client->shaPassHash) != 0)
		{
//changement car normalisation nom requete --nico le 18-11-2012
realms->executionPrepareStatement(REALMS_UPD_ACCOUNT_MAJERREURSAUTH,2,ToString((int)client->idLogin).c_str(),ToString((int)client->nbPassage).c_str());
//realms->executionPrepareStatement(LOGIN_SET_FAILEDLOGINS,2,ToString((int)client->idLogin).c_str(),ToString((int)client->nbPassage).c_str());

			log->Write(Log::INFO,"Erreur de mot de passe");
			if(client->nbPassage % 3 == 0)
			{
//changement car normalisation nom requete -- nico le 18-11-2012				
realms->executionPrepareStatement(REALMS_INS_ACCOUNTBANNED_AUTOBANCOMPTEAUTH,1,ToString((int)client->idLogin).c_str());
				//realms->executionPrepareStatement(LOGIN_SET_ACCAUTOBANNED,1,ToString((int)client->idLogin).c_str());


				//Bannir le client
				AUTH_LOGON_ERROR msg_error;
				msg_error.cmd = XSILIUM_AUTH;
				msg_error.opcode =ID_COMPTE_BANNIE;
				msg_error.error = 1;
				ENetPacket * message = enet_packet_create ((const char *)&msg_error,sizeof(msg_error) + 1,ENET_PACKET_FLAG_RELIABLE);
				enet_peer_send (packet->peer, 0, message);
				return;

			}

			AUTH_LOGON_ERROR error;
			error.cmd = XSILIUM_AUTH;
			error.opcode = ID_INVALID_ACCOUNT_OR_PASSWORD ;
			error.error = 0;

			ENetPacket * message = enet_packet_create ((const char *)&error,sizeof(error) + 1,ENET_PACKET_FLAG_RELIABLE);
		    enet_peer_send (packet->peer, 0, message);

		}
		else
		{
			log->Write(Log::INFO,"Mot de passe valider");
			client->nbPassage = 0;
			client->etape = 3 ;
//changement car normalisation nom requete -- nico le 18-11-2012
			realms->executionPrepareStatement(REALMS_UPD_ACCOUNT_MAJERREURSAUTH,2,ToString((int)client->idLogin).c_str(),"0");
			//realms->executionPrepareStatement(LOGIN_SET_FAILEDLOGINS,2,ToString((int)client->idLogin).c_str(),"0");

			AUTH_LOGON_PROOF messageValidation;
			messageValidation.cmd = XSILIUM_AUTH;
			messageValidation.opcode = ID_SEND_VALIDATION ;

			ENetPacket * message = enet_packet_create ((const char *)&messageValidation,sizeof(messageValidation) + 1,ENET_PACKET_FLAG_RELIABLE);
		    enet_peer_send (packet->peer, 0, message);


		}
	}

}

void Authentification::HandleRealmList()
{
	listServeur->UpdateIfNeed();
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
