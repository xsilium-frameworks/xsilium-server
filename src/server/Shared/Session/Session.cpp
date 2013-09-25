/*
 * \file Session.cpp
 *
 *  Created on: \date 12 janv. 2013
 *      Author: \author joda
 *  \brief :
 */

#include "Session.h"

Session::Session() {
	peer = NULL;
	compteDB = LoginDatabase::getInstance();
	unbandate = 0;
	ipNBEssai = 0;
	compte = NULL;

}

Session::~Session() {
}

void Session::setSessionPeer(ENetPeer * peer)
{
	this->peer = peer;
}

ENetPeer * Session::getSessionPeer()
{
	return peer;
}

ENetAddress * Session::getSessionID()
{
	return &peer->address ;
}


void Session::banIP(time_t unbandate,const char * raison,int bannedby)
{
	char hostip[16];

	enet_address_get_host_ip(&peer->address,hostip,sizeof(hostip));
	compteDB->executionPrepareStatement(REALMS_INS_IPBANNED_BANIP,4,hostip,ToString(unbandate).c_str(),raison,ToString(bannedby).c_str());
}
void Session::unbanIP()
{
	char hostip[16];

	enet_address_get_host_ip(&peer->address,hostip,sizeof(hostip));
	compteDB->executionPrepareStatement(REALMS_UPD_IPBANNED_DEBANIP,1,hostip);
}
bool Session::isBanned()
{
	pqxx::result resultsql;
	char hostip[16];

	enet_address_get_host_ip(&peer->address,hostip,sizeof(hostip));
	compteDB->executionPrepareStatement(REALMS_UPD_IPBANNED_DEBANAUTOIP);
	resultsql = compteDB->executionPrepareStatement(REALMS_SEL_IPBANNED_INFOSSURIPBANNIES,1,hostip);

	if(resultsql.empty())
	{
		unbandate = 0;
		return false;
	}
	else
	{
		struct tm tm;
		strptime((resultsql[0][0].as<std::string>()).c_str(), "%Y-%m-%d %H:%M:%S", &tm);
		unbandate = mktime(&tm);
		return true;
	}

}

time_t Session::getUnBanDate()
{
	return unbandate;
}

int Session::getNBIPTemps()
{
	return ipNBEssai;
}
void Session::ajoutIPTemps()
{
	pqxx::result resultsql;
	char hostip[16];

	enet_address_get_host_ip(&peer->address,hostip,sizeof(hostip));
	resultsql = compteDB->executionPrepareStatement(REALMS_SEL_IPTEMPORAIRE_LECTURENERREURS,1,hostip);

	if(resultsql.empty())
	{
		ipNBEssai = 1;
		compteDB->executionPrepareStatement(REALMS_INS_IPTEMPORAIRE_STOCKAGEIPTEMPORAIRE,2,hostip,ToString(1).c_str());
	}
	else
	{
		ipNBEssai = resultsql[0][0].as<int>() + 1;
		compteDB->executionPrepareStatement(REALMS_UPD_IPTEMPORAIRE_MAJIPTEMPORAIRE,2,ToString(ipNBEssai).c_str(),hostip);
	}

}

void Session::supprimeIPTemps()
{
	pqxx::result resultsql;
	char hostip[16];

	enet_address_get_host_ip(&peer->address,hostip,sizeof(hostip));
	compteDB->executionPrepareStatement(REALMS_DEL_IPTEMPORAIRE_SUPPRLIGNEIP,1,hostip);

}

void Session::setCompte(Compte * compte)
{
	this->compte = compte;
}

Compte * Session::getCompte()
{
	return compte;
}


