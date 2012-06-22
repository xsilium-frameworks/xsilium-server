/*
 * Authentification.cpp
 *
 *  Created on: 7 f�vr. 2012
 *      Author: joda2
 */

#include "Authentification.h"

Authentification::Authentification() {
	realms = new LoginDatabase();
	config = Configuration::getInstance();
	log = Log::getInstance();
	this->ConnexionDB();

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
			  return true;
		  }
	  }
	}

	return false;
}

void Authentification::ConnexionDB()
{
	string host,port,dbname,user,password;
	config->Get("postgresHost",host);
	config->Get("postgresPort",port);
	config->Get("postgresDBname",dbname);
	config->Get("postgresUser",user);
	config->Get("postgresPassword",password);
	connectionString = "host=" + host + " port=" + port + " dbname=" + dbname + " user=" + user + " password=" + password;
	//isDBConnect = realms->Connect(connectionString.c_str());


}


bool Authentification::CreateClient(ENetEvent *packet)
{
	sClient clientTemp ;
	clientTemp.IP = packet->peer->address.host ;
	clientTemp.port = packet->peer->address.port ;
	listOfClient.push_back(clientTemp);

	return true;
}

bool Authentification::DeleteClient(ENetEvent *packet)
{
	FindClient(packet->peer->address);

	listOfClient.erase(client);
	return true;
}



bool Authentification::_HandleLogonChallenge( ENetEvent *packet)
{
	//if (packet->packet->dataLength < sizeof(sAuthLogonChallenge_C))
	//	return false;

	FindClient(packet->peer->address);

	sAuthLogonChallenge_C *data = (sAuthLogonChallenge_C *) packet->packet->data ;

	string login = (const char *) data->login ;
	if (data->login_len != strlen(login.c_str()))
		printf("erreur avec le nom\n");


	client->build = data->build;

	printf("Nom du client : %s\n",login.c_str());

	AUTH_LOGON_PROOF_S error;
	/*RakNet::BitStream * sendMessage;

	bool resultsGetBan;
	realms->setIPBan();
	client->IP = packet->systemAddress.ToString(false);
	if(realms->getIPBan(&client->IP,&resultsGetBan))
	{
		if(resultsGetBan)
		{
			error.typeId = ID_CONNECTION_BANNED ;
			error.error = 1;
			printf("[AuthChallenge] L'ip %s est bannie !\n",client->IP.c_str());

			sendMessage->Write(error);
			this->peer->Send(sendMessage,HIGH_PRIORITY,RELIABLE_ORDERED,0,packet->systemAddress,true);

			return false;
		}

		if (realms->selectAccount(login.c_str(),client.base()))
		{
			if(client->idLogin == 0)
			{
				error.typeId = ID_INVALID_PASSWORD ;
				error.error = 1;
				printf("[AuthChallenge] Le compte %s n'existe pas \n",login.c_str());
				return false;
			}
			if(client->locked)
			{
				printf("[AuthChallenge] Le compte %s est lier a l'IP %s \n",login.c_str(),client->lastIP.c_str());
				printf("[AuthChallenge] Le client � pour l'IP %s \n",client->IP.c_str());

				if(client->IP != client->lastIP)
				{
					printf("[AuthChallenge] L'IP %s ne correspond pas � la derniere IP %s \n",client->IP.c_str(),client->lastIP.c_str());
					return false;
				}
				else
					printf("[AuthChallenge] Les IPs correspondent \n");
			}

		}


	}*/
	return true;
}


bool Authentification::_HandleLogonProof(ENetEvent *packet)
{
	/*FindClient(packet->peer->address);
	client->passage +=1;
	AUTH_LOGON_PROOF_C *data = (AUTH_LOGON_PROOF_C *) &packet->data ;
	if (strcmp(data->A.c_str()  , client->shaPassHash.c_str()) == 1)
	{
		log->Write(Log::INFO,"Erreur de mot de passe");
		if(client->passage == 3)
		{
			//Bannir le client

		}
	}
	else
	{
		log->Write(Log::INFO,"Mot de passe valider");
		client->passage = 0;
	}
	*/
	return true;

}

/*/// Logon Challenge command handler
bool Authentification::_HandleLogonChallenge()
{
    sLog.outStaticDebug("Entering _HandleLogonChallenge");
    if (socket().recv_len() < sizeof(sAuthLogonChallenge_C))
        return false;

    ///- Read the first 4 bytes (header) to get the length of the remaining of the packet
    std::vector<uint8> buf;
    buf.resize(4);

    socket().recv((char *)&buf[0], 4);

    EndianConvert(*((uint16*)(buf[0])));
    uint16 remaining = ((sAuthLogonChallenge_C *)&buf[0])->size;
    sLog.outStaticDebug("[AuthChallenge] got header, body is %#04x bytes", remaining);

    if ((remaining < sizeof(sAuthLogonChallenge_C) - buf.size()) || (socket().recv_len() < remaining))
        return false;

    //No big fear of memory outage (size is int16, i.e. < 65536)
    buf.resize(remaining + buf.size() + 1);
    buf[buf.size() - 1] = 0;
    sAuthLogonChallenge_C *ch = (sAuthLogonChallenge_C*)&buf[0];

    ///- Read the remaining of the packet
    socket().recv((char *)&buf[4], remaining);
    sLog.outStaticDebug("[AuthChallenge] got full packet, %#04x bytes", ch->size);
    sLog.outStaticDebug("[AuthChallenge] name(%d): '%s'", ch->I_len, ch->I);


    return true;
}

/// Logon Proof command handler
bool Authentification::_HandleLogonProof()
{
    sLog.outStaticDebug("Entering _HandleLogonProof");
    ///- Read the packet
    sAuthLogonProof_C lp;

    if (!socket().recv((char *)&lp, sizeof(sAuthLogonProof_C)))
        return false;

    /// <ul><li> If the client has no valid version
    if (_expversion == NO_VALID_EXP_FLAG)
    {
        ///- Check if we have the appropriate patch on the disk

        sLog.outDebug("Client with invalid version, patching is not implemented");
        socket().shutdown();
        return true;
    }
    /// </ul>

    ///- Continue the SRP6 calculation based on data received from the client
    BigNumber A;

    A.SetBinary(lp.A, 32);

    // SRP safeguard: abort if A==0
    if (A.isZero())
    {
        socket().shutdown();
        return true;
    }

    SHA1Hash sha;
    sha.UpdateBigNumbers(&A, &B, NULL);
    sha.Finalize();
    BigNumber u;
    u.SetBinary(sha.GetDigest(), 20);
    BigNumber S = (A * (v.ModExp(u, N))).ModExp(b, N);

    uint8 t[32];
    uint8 t1[16];
    uint8 vK[40];
    memcpy(t, S.AsByteArray(32), 32);
    for (int i = 0; i < 16; ++i)
    {
        t1[i] = t[i * 2];
    }
    sha.Initialize();
    sha.UpdateData(t1, 16);
    sha.Finalize();
    for (int i = 0; i < 20; ++i)
    {
        vK[i * 2] = sha.GetDigest()[i];
    }
    for (int i = 0; i < 16; ++i)
    {
        t1[i] = t[i * 2 + 1];
    }
    sha.Initialize();
    sha.UpdateData(t1, 16);
    sha.Finalize();
    for (int i = 0; i < 20; ++i)
    {
        vK[i * 2 + 1] = sha.GetDigest()[i];
    }
    K.SetBinary(vK, 40);

    uint8 hash[20];

    sha.Initialize();
    sha.UpdateBigNumbers(&N, NULL);
    sha.Finalize();
    memcpy(hash, sha.GetDigest(), 20);
    sha.Initialize();
    sha.UpdateBigNumbers(&g, NULL);
    sha.Finalize();
    for (int i = 0; i < 20; ++i)
    {
        hash[i] ^= sha.GetDigest()[i];
    }
    BigNumber t3;
    t3.SetBinary(hash, 20);

    sha.Initialize();
    sha.UpdateData(_login);
    sha.Finalize();
    uint8 t4[SHA_DIGEST_LENGTH];
    memcpy(t4, sha.GetDigest(), SHA_DIGEST_LENGTH);

    sha.Initialize();
    sha.UpdateBigNumbers(&t3, NULL);
    sha.UpdateData(t4, SHA_DIGEST_LENGTH);
    sha.UpdateBigNumbers(&s, &A, &B, &K, NULL);
    sha.Finalize();
    BigNumber M;
    M.SetBinary(sha.GetDigest(), 20);

    ///- Check if SRP6 results match (password is correct), else send an error
    if (!memcmp(M.AsByteArray(), lp.M1, 20))
    {
        sLog.outBasic("User '%s' successfully authenticated", _login.c_str());

        ///- Update the sessionkey, last_ip, last login time and reset number of failed logins in the account table for this account
        // No SQL injection (escaped user name) and IP address as received by socket
        const char* K_hex = K.AsHexStr();

        PreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_SET_LOGONPROOF);
        stmt->setString(0, K_hex);
        stmt->setString(1, socket().get_remote_address().c_str());
        stmt->setUInt32(2, GetLocaleByName(_localizationName));
        stmt->setString(3, _login);
        LoginDatabase.Execute(stmt);

        OPENSSL_free((void*)K_hex);

        ///- Finish SRP6 and send the final result to the client
        sha.Initialize();
        sha.UpdateBigNumbers(&A, &M, &K, NULL);
        sha.Finalize();

        if (_expversion & POST_BC_EXP_FLAG)//2.4.3 and 3.1.3 clients (10146 is Chinese build for 3.1.3)
        {
            sAuthLogonProof_S proof;
            memcpy(proof.M2, sha.GetDigest(), 20);
            proof.cmd = AUTH_LOGON_PROOF;
            proof.error = 0;
            proof.unk1 = 0x00800000;
            proof.unk2 = 0x00;
            proof.unk3 = 0x00;
            socket().send((char *)&proof, sizeof(proof));
        }
        else
        {
            sAuthLogonProof_S_Old proof;
            memcpy(proof.M2, sha.GetDigest(), 20);
            proof.cmd = AUTH_LOGON_PROOF;
            proof.error = 0;
            //proof.unk1 = 0x00800000;
            proof.unk2 = 0x00;
            //proof.unk3 = 0x00;
            socket().send((char *)&proof, sizeof(proof));
        }

        ///- Set _authed to true!
        _authed = true;
    }
    else
    {
        char data[4]= { AUTH_LOGON_PROOF, WOW_FAIL_INCORRECT_PASSWORD, 3, 0};
        socket().send(data, sizeof(data));
        sLog.outBasic("[AuthChallenge] account %s tried to login with wrong password!",_login.c_str ());

        uint32 MaxWrongPassCount = sConfig.GetIntDefault("WrongPass.MaxCount", 0);
        if (MaxWrongPassCount > 0)
        {
            //Increment number of failed logins by one and if it reaches the limit temporarily ban that account or IP
            PreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_SET_FAILEDLOGINS);
            stmt->setString(0, _login);
            LoginDatabase.Execute(stmt);

            stmt = LoginDatabase.GetPreparedStatement(LOGIN_GET_FAILEDLOGINS);
            stmt->setString(0, _login);

            if (PreparedQueryResult loginfail = LoginDatabase.Query(stmt))
            {
                uint32 failed_logins = loginfail->GetUInt32(1);

                if (failed_logins >= MaxWrongPassCount)
                {
                    uint32 WrongPassBanTime = sConfig.GetIntDefault("WrongPass.BanTime", 600);
                    bool WrongPassBanType = sConfig.GetBoolDefault("WrongPass.BanType", false);

                    if (WrongPassBanType)
                    {
                        uint32 acc_id = loginfail->GetUInt32(0);
                        stmt = LoginDatabase.GetPreparedStatement(LOGIN_SET_ACCAUTOBANNED);
                        stmt->setUInt32(0, acc_id);
                        stmt->setUInt32(1, WrongPassBanTime);
                        LoginDatabase.Execute(stmt);

                        sLog.outBasic("[AuthChallenge] account %s got banned for '%u' seconds because it failed to authenticate '%u' times",
                            _login.c_str(), WrongPassBanTime, failed_logins);
                    }
                    else
                    {
                        stmt = LoginDatabase.GetPreparedStatement(LOGIN_SET_IPAUTOBANNED);
                        stmt->setString(0, socket().get_remote_address());
                        stmt->setUInt32(1, WrongPassBanTime);
                        LoginDatabase.Execute(stmt);

                        sLog.outBasic("[AuthChallenge] IP %s got banned for '%u' seconds because account %s failed to authenticate '%u' times",
                            socket().get_remote_address().c_str(), WrongPassBanTime, _login.c_str(), failed_logins);
                    }
                }
            }
        }
    }

    return true;
}

/// Reconnect Challenge command handler
bool Authentification::_HandleReconnectChallenge()
{
    sLog.outStaticDebug("Entering _HandleReconnectChallenge");
    if (socket().recv_len() < sizeof(sAuthLogonChallenge_C))
        return false;

    ///- Read the first 4 bytes (header) to get the length of the remaining of the packet
    std::vector<uint8> buf;
    buf.resize(4);

    socket().recv((char *)&buf[0], 4);

    EndianConvert(*((uint16*)(buf[0])));
    uint16 remaining = ((sAuthLogonChallenge_C *)&buf[0])->size;
    sLog.outStaticDebug("[ReconnectChallenge] got header, body is %#04x bytes", remaining);

    if ((remaining < sizeof(sAuthLogonChallenge_C) - buf.size()) || (socket().recv_len() < remaining))
        return false;

    //No big fear of memory outage (size is int16, i.e. < 65536)
    buf.resize(remaining + buf.size() + 1);
    buf[buf.size() - 1] = 0;
    sAuthLogonChallenge_C *ch = (sAuthLogonChallenge_C*)&buf[0];

    ///- Read the remaining of the packet
    socket().recv((char *)&buf[4], remaining);
    sLog.outStaticDebug("[ReconnectChallenge] got full packet, %#04x bytes", ch->size);
    sLog.outStaticDebug("[ReconnectChallenge] name(%d): '%s'", ch->I_len, ch->I);

    _login = (const char*)ch->I;

    PreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_GET_SESSIONKEY);
    stmt->setString(0, _login);
    PreparedQueryResult result = LoginDatabase.Query(stmt);

    // Stop if the account is not found
    if (!result)
    {
        sLog.outError("[ERROR] user %s tried to login and we cannot find his session key in the database.", _login.c_str());
        socket().shutdown();
        return false;
    }

    K.SetHexStr (result->GetCString(0));

    ///- Sending response
    ByteBuffer pkt;
    pkt << (uint8)  AUTH_RECONNECT_CHALLENGE;
    pkt << (uint8)  0x00;
    _reconnectProof.SetRand(16 * 8);
    pkt.append(_reconnectProof.AsByteArray(16), 16);             // 16 bytes random
    pkt << (uint64) 0x00 << (uint64) 0x00;                  // 16 bytes zeros
    socket().send((char const*)pkt.contents(), pkt.size());
    return true;
}

/// Reconnect Proof command handler
bool Authentification::_HandleReconnectProof()
{
    sLog.outStaticDebug("Entering _HandleReconnectProof");
    ///- Read the packet
    sAuthReconnectProof_C lp;
    if (!socket().recv((char *)&lp, sizeof(sAuthReconnectProof_C)))
        return false;

    if (_login.empty() || !_reconnectProof.GetNumBytes() || !K.GetNumBytes())
        return false;

    BigNumber t1;
    t1.SetBinary(lp.R1, 16);

    SHA1Hash sha;
    sha.Initialize();
    sha.UpdateData(_login);
    sha.UpdateBigNumbers(&t1, &_reconnectProof, &K, NULL);
    sha.Finalize();

    if (!memcmp(sha.GetDigest(), lp.R2, SHA_DIGEST_LENGTH))
    {
        ///- Sending response
        ByteBuffer pkt;
        pkt << (uint8)  AUTH_RECONNECT_PROOF;
        pkt << (uint8)  0x00;
        pkt << (uint16) 0x00;                               // 2 bytes zeros
        socket().send((char const*)pkt.contents(), pkt.size());

        ///- Set _authed to true!
        _authed = true;

        return true;
    }
    else
    {
        sLog.outError("[ERROR] user %s tried to login, but session invalid.", _login.c_str());
        socket().shutdown();
        return false;
    }
}

/// %Realm List command handler
bool Authentification::_HandleRealmList()
{
    sLog.outStaticDebug("Entering _HandleRealmList");
    if (socket().recv_len() < 5)
        return false;

    socket().recv_skip(5);

    ///- Get the user id (else close the connection)
    // No SQL injection (prepared statement)

    PreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_GET_ACCIDBYNAME);
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
