/*
 * \file Session.cpp
 *
 *  Created on: \date 16 déc. 2014
 *      Author: \author joda
 *  \brief :
 */
#include "Session.h"

Session::Session() {
	peer = NULL;
	database = DatabaseManager::getInstance();
	unbandate = 0;
	ipNBEssai = 0;
	suffix = "Session";
	compte = 0;

	database->prepareStatement(suffix + database->ToString(REALMS_DEL_IPTEMPORAIRE_SUPPRLIGNEIP),"DELETE FROM compte.ip_temporaire where ip_temp_ip = $1");
	database->prepareStatement(suffix + database->ToString(REALMS_SEL_IPTEMPORAIRE_LECTURENERREURS),"SELECT ip_temp_nessais FROM compte.ip_temporaire where ip_temp_ip = $1");
	database->prepareStatement(suffix + database->ToString(REALMS_INS_IPTEMPORAIRE_STOCKAGEIPTEMPORAIRE),"INSERT INTO compte.ip_temporaire VALUES (DEFAULT, $1, $2)");
	database->prepareStatement(suffix + database->ToString(REALMS_UPD_IPTEMPORAIRE_MAJIPTEMPORAIRE),"UPDATE compte.ip_temporaire SET ip_temp_nessais = $1 WHERE ip_temp_ip = $2");
	database->prepareStatement(suffix + database->ToString(REALMS_SEL_IPBANNED_INFOSSURIPBANNIES),"SELECT unbandate FROM compte.ip_banned WHERE unbandate > now() and ban_actif = true and ip = $1");
	database->prepareStatement(suffix + database->ToString(REALMS_INS_IPBANNED_BANIP),"INSERT INTO compte.ip_banned VALUES (DEFAULT,$1, now(), to_timestamp($2), $3, $4, true )");
	database->prepareStatement(suffix + database->ToString(REALMS_UPD_IPBANNED_DEBANAUTOIP),"Update compte.ip_banned set ban_actif=false WHERE unbandate <=now() AND ban_actif = true");
	database->prepareStatement(suffix + database->ToString(REALMS_UPD_IPBANNED_DEBANIP),"Update compte.ip_banned set ban_actif=false WHERE ban_actif = true and ip = $1 ");

}

Session::~Session() {
	if(compte)
		delete compte;
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
	database->executionPrepareStatement(suffix + database->ToString(REALMS_INS_IPBANNED_BANIP),0,4,hostip,database->ToString(unbandate).c_str(),raison,database->ToString(bannedby).c_str());
}
void Session::unbanIP()
{
	char hostip[16];

	enet_address_get_host_ip(&peer->address,hostip,sizeof(hostip));
	database->executionPrepareStatement(suffix + database->ToString(REALMS_UPD_IPBANNED_DEBANIP),0,1,hostip);
}
bool Session::isBanned()
{
	Tokens resultsqlT;
	char hostip[16];

	enet_address_get_host_ip(&peer->address,hostip,sizeof(hostip));
	database->executionPrepareStatement(suffix + database->ToString(REALMS_UPD_IPBANNED_DEBANAUTOIP));
	resultsqlT = database->executionPrepareStatement(suffix + database->ToString(REALMS_SEL_IPBANNED_INFOSSURIPBANNIES),0,1,hostip);

	if(resultsqlT.empty())
	{
		unbandate = 0;
		return false;
	}
	else
	{
		Tokens resultatsql;

		resultatsql = database->strSplit( resultsqlT[0] ,";");

		struct tm tm;
		strptime(resultatsql[0].c_str(), "%Y-%m-%d %H:%M:%S", &tm);
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
	Tokens resultsqlT;
	char hostip[16];

	enet_address_get_host_ip(&peer->address,hostip,sizeof(hostip));
	resultsqlT = database->executionPrepareStatement(suffix + database->ToString(REALMS_SEL_IPTEMPORAIRE_LECTURENERREURS),0,1,hostip);

	if(resultsqlT.empty())
	{
		ipNBEssai = 1;
		database->executionPrepareStatement(suffix + database->ToString(REALMS_INS_IPTEMPORAIRE_STOCKAGEIPTEMPORAIRE),0,2,hostip,database->ToString(1).c_str());
	}
	else
	{
		Tokens resultatsql;
		resultatsql = database->strSplit( resultsqlT[0] ,";");

		ipNBEssai = database->ToInt(resultatsql[0]) + 1;
		database->executionPrepareStatement(suffix + database->ToString(REALMS_UPD_IPTEMPORAIRE_MAJIPTEMPORAIRE),0,2,database->ToString(ipNBEssai).c_str(),hostip);
	}

}

void Session::supprimeIPTemps()
{
	pqxx::result resultsql;
	char hostip[16];

	enet_address_get_host_ip(&peer->address,hostip,sizeof(hostip));
	database->executionPrepareStatement(suffix + database->ToString(REALMS_DEL_IPTEMPORAIRE_SUPPRLIGNEIP),0,1,hostip);
	ipNBEssai = 0;
}

void Session::setCompte(Compte * compte)
{
	this->compte = compte;
}

Compte * Session::getCompte()
{
	return compte;
}
