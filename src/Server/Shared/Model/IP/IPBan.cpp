/*
 * \file IPBan.cpp
 *
 *  Created on: \date 30 mai 2015
 *      Author: \author joda
 *  \brief :
 */
#include "IPBan.h"

IPBan::IPBan(std::string ip) {
	suffix = "IPBAN";
	this->ip = ip;
	id_ip_banned = 0;
	bandate = 0;
	unbandate = 0;
	raison = "";
	bannedby = 0;

	database->prepareStatement(suffix + database->ToString(REALMS_SEL_IPBANNED_INFOSSURIPBANNIES),"SELECT id_ip_banned,bandate,unbandate,raison,bannedby FROM IP.ip_banned WHERE unbandate > now() and ip = $1");
	database->prepareStatement(suffix + database->ToString(REALMS_INS_IPBANNED_BANIP),"INSERT INTO IP.ip_banned VALUES (DEFAULT,$1, to_timestamp($2), to_timestamp($3), $4, $5 )");
	database->prepareStatement(suffix + database->ToString(REALMS_UPD_IPBANNED_DEBANIP),"Update IP.ip_banned set bandate=to_timestamp($1),unbandate=to_timestamp($2),raison=$3,bannedby=$4 WHERE id_ip_banned = $5 ");
	database->prepareStatement(suffix + database->ToString(REALMS_DEL_IPBANNED_DEBANIP),"Delete from IP.ip_banned WHERE id_ip_banned = $1 ");


}

IPBan::~IPBan() {
	// TODO Auto-generated destructor stub
}

bool IPBan::create(int idTransaction)
{
	bool retour;
	Tokens tokens;
	retour = database->executionPrepareStatement(suffix + database->ToString(REALMS_INS_IPBANNED_BANIP),&tokens,idTransaction,5,ip.c_str(),database->ToString(bandate).c_str(),database->ToString(unbandate).c_str(),raison.c_str(),database->ToString(bannedby).c_str());
	read();
	return retour;
}
bool IPBan::read(int idTransaction)
{
	bool retour;
	Tokens resultsqlT;
	retour = database->executionPrepareStatement(suffix + database->ToString(REALMS_SEL_IPBANNED_INFOSSURIPBANNIES),&resultsqlT,idTransaction,1,ip.c_str());

	if(resultsqlT.empty())
	{
		retour = false;
	}
	else
	{
		Tokens resultatsql;

		resultatsql = database->strSplit( resultsqlT[0] ,";");

		id_ip_banned = database->ToInt(resultatsql[0]);
		bandate = database->ToDate(resultatsql[1]);
		unbandate = database->ToDate(resultatsql[2]);
		raison = resultatsql[3];
		bannedby = database->ToInt(resultatsql[4]);

		retour = true;
	}

	return retour;

}
bool IPBan::update(int idTransaction)
{
	Tokens resultsqlT;
	return database->executionPrepareStatement(suffix + database->ToString(REALMS_UPD_IPBANNED_DEBANIP),&resultsqlT,idTransaction,5,database->ToString(bandate).c_str(),database->ToString(unbandate).c_str(),raison.c_str(),database->ToString(bannedby).c_str(),database->ToString(id_ip_banned).c_str());
}
bool IPBan::suppr(int idTransaction)
{
	Tokens resultsqlT;
	return  database->executionPrepareStatement(suffix + database->ToString(REALMS_DEL_IPBANNED_DEBANIP),&resultsqlT,idTransaction,1,database->ToString(id_ip_banned).c_str());
}


time_t IPBan::getBandate() const {
	return bandate;
}

void IPBan::setBandate(time_t bandate) {
	this->bandate = bandate;
}

int IPBan::getBannedby() const {
	return bannedby;
}

void IPBan::setBannedby(int bannedby) {
	this->bannedby = bannedby;
}

int IPBan::getIdIpBanned() const {
	return id_ip_banned;
}

void IPBan::setIdIpBanned(int idIpBanned) {
	id_ip_banned = idIpBanned;
}

const std::string& IPBan::getIp() const {
	return ip;
}

void IPBan::setIp(const std::string& ip) {
	this->ip = ip;
}

const std::string& IPBan::getRaison() const {
	return raison;
}

void IPBan::setRaison(const std::string& raison) {
	this->raison = raison;
}

time_t IPBan::getUnbandate() const {
	return unbandate;
}

void IPBan::setUnbandate(time_t unbandate) {
	this->unbandate = unbandate;
}
