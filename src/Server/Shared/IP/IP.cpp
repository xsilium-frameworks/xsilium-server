/*
 * \file IP.cpp
 *
 *  Created on: \date 21 févr. 2015
 *      Author: \author joda
 *  \brief :
 */
#include "IP.h"

IP::IP(char * hostip ) {
	database = DatabaseManager::getInstance();
	unbandate = 0;
	ipNBEssai = 0;
	suffix = "IP";
	this->hostip = hostip;

	database->prepareStatement(suffix + database->ToString(REALMS_DEL_IPTEMPORAIRE_SUPPRLIGNEIP),"DELETE FROM IP.ip_temporaire where ip_temp_ip = $1");
	database->prepareStatement(suffix + database->ToString(REALMS_SEL_IPTEMPORAIRE_LECTURENERREURS),"SELECT ip_temp_nessais FROM IP.ip_temporaire where ip_temp_ip = $1");
	database->prepareStatement(suffix + database->ToString(REALMS_INS_IPTEMPORAIRE_STOCKAGEIPTEMPORAIRE),"INSERT INTO IP.ip_temporaire VALUES (DEFAULT, $1, $2)");
	database->prepareStatement(suffix + database->ToString(REALMS_UPD_IPTEMPORAIRE_MAJIPTEMPORAIRE),"UPDATE IP.ip_temporaire SET ip_temp_nessais = $1 WHERE ip_temp_ip = $2");
	database->prepareStatement(suffix + database->ToString(REALMS_SEL_IPBANNED_INFOSSURIPBANNIES),"SELECT unbandate FROM IP.ip_banned WHERE unbandate > now() and ban_actif = true and ip = $1");
	database->prepareStatement(suffix + database->ToString(REALMS_INS_IPBANNED_BANIP),"INSERT INTO IP.ip_banned VALUES (DEFAULT,$1, now(), to_timestamp($2), $3, $4, true )");
	database->prepareStatement(suffix + database->ToString(REALMS_UPD_IPBANNED_DEBANAUTOIP),"Update IP.ip_banned set ban_actif=false WHERE unbandate <=now() AND ban_actif = true");
	database->prepareStatement(suffix + database->ToString(REALMS_UPD_IPBANNED_DEBANIP),"Update IP.ip_banned set ban_actif=false WHERE ban_actif = true and ip = $1 ");


}

IP::~IP() {
	// TODO Auto-generated destructor stub
}

void IP::banIP(time_t unbandate,const char * raison,int bannedby)
{
	database->executionPrepareStatement(suffix + database->ToString(REALMS_INS_IPBANNED_BANIP),0,4,hostip,database->ToString(unbandate).c_str(),raison,database->ToString(bannedby).c_str());
}
void IP::unbanIP()
{
	database->executionPrepareStatement(suffix + database->ToString(REALMS_UPD_IPBANNED_DEBANIP),0,1,hostip);
}
bool IP::isBanned()
{
	Tokens resultsqlT;
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

time_t IP::getUnBanDate()
{
	return unbandate;
}

int IP::getNBIPTemps()
{
	return ipNBEssai;
}
void IP::ajoutIPTemps()
{
	Tokens resultsqlT;

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

void IP::supprimeIPTemps()
{
	pqxx::result resultsql;
	char hostip[16];

	database->executionPrepareStatement(suffix + database->ToString(REALMS_DEL_IPTEMPORAIRE_SUPPRLIGNEIP),0,1,hostip);
	ipNBEssai = 0;
}
