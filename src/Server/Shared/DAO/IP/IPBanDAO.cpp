/*
 * IPBanDAO.cpp
 *
 *  Created on: 15 déc. 2015
 *      Author: Aeden
 */

#include "IPBanDAO.h"

IPBanDAO::IPBanDAO() {
	suffix = "IPBAN";
	requeteSQL = "SELECT id_ip_banned,bandate,unbandate,raison,bannedby ";
	requeteSQL += "FROM IP.ip_banned WHERE unbandate > now() and ip = $1";

	database->prepareStatement(suffix + database->ToString(REALMS_SEL_IPBANNED_INFOSSURIPBANNIES),
			requeteSQL.c_str());

	requeteSQL = "INSERT INTO IP.ip_banned VALUES (DEFAULT,$1, to_timestamp($2),";
	requeteSQL += "to_timestamp($3), $4, $5 )";
	database->prepareStatement(suffix + database->ToString(REALMS_INS_IPBANNED_BANIP),
			requeteSQL.c_str());

	requeteSQL = "Update IP.ip_banned set bandate=to_timestamp($1),unbandate=to_timestamp($2),";
	requeteSQL += "raison=$3,bannedby=$4 WHERE id_ip_banned = $5 ";
	database->prepareStatement(suffix + database->ToString(REALMS_UPD_IPBANNED_DEBANIP),
			requeteSQL.c_str());

	requeteSQL = "Delete from IP.ip_banned WHERE id_ip_banned = $1 ";
	database->prepareStatement(suffix + database->ToString(REALMS_DEL_IPBANNED_DEBANIP),
			requeteSQL.c_str());

}

IPBanDAO::~IPBanDAO() {
	// TODO Auto-generated destructor stub
}

bool IPBanDAO::create(IPBan * ipBan, int idTransaction) {
	bool retour;
	Tokens tokens;
	retour = database->executionPrepareStatement(
			suffix + database->ToString(REALMS_INS_IPBANNED_BANIP), &tokens, idTransaction, 5,
			ipBan->getIp().c_str(), database->ToString(ipBan->getBandate()).c_str(),
			database->ToString(ipBan->getUnbandate()).c_str(), ipBan->getRaison().c_str(),
			database->ToString(ipBan->getBannedby()).c_str());
	read(ipBan, idTransaction);
	return retour;
}
bool IPBanDAO::read(IPBan * ipBan, int idTransaction) {
	bool retour;
	Tokens resultsqlT;
	retour = database->executionPrepareStatement(
			suffix + database->ToString(REALMS_SEL_IPBANNED_INFOSSURIPBANNIES), &resultsqlT,
			idTransaction, 1, ipBan->getIp().c_str());

	if (resultsqlT.empty()) {
		retour = false;
	} else {
		Tokens resultatsql;

		resultatsql = database->strSplit(resultsqlT[0], ";");

		ipBan->setIdIpBanned(database->ToInt(resultatsql[0]));
		ipBan->setBandate(database->ToDate(resultatsql[1]));
		ipBan->setUnbandate(database->ToDate(resultatsql[2]));
		ipBan->setRaison(resultatsql[3]);
		ipBan->setBannedby(database->ToInt(resultatsql[4]));

		retour = true;
	}

	return retour;

}
bool IPBanDAO::update(IPBan * ipBan, int idTransaction) {
	Tokens resultsqlT;
	return database->executionPrepareStatement(
			suffix + database->ToString(REALMS_UPD_IPBANNED_DEBANIP), &resultsqlT, idTransaction, 5,
			database->ToString(ipBan->getBandate()).c_str(),
			database->ToString(ipBan->getUnbandate()).c_str(), ipBan->getRaison().c_str(),
			database->ToString(ipBan->getBannedby()).c_str(),
			database->ToString(ipBan->getIdIpBanned()).c_str());
}
bool IPBanDAO::suppr(IPBan * ipBan, int idTransaction) {
	Tokens resultsqlT;
	return database->executionPrepareStatement(
			suffix + database->ToString(REALMS_DEL_IPBANNED_DEBANIP), &resultsqlT, idTransaction, 1,
			database->ToString(ipBan->getIdIpBanned()).c_str());
}

