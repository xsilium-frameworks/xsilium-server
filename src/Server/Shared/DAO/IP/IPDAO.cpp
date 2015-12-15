/*
 * IPDAO.cpp
 *
 *  Created on: 15 déc. 2015
 *      Author: Aeden
 */

#include "IPDAO.h"

IPDAO::IPDAO() {
	suffix = "IP";

	database->prepareStatement(
			suffix + database->ToString(REALMS_DEL_IPTEMPORAIRE),
			"DELETE FROM IP.ip_temporaire where id_ip = $1");
	database->prepareStatement(
			suffix + database->ToString(REALMS_SEL_IPTEMPORAIRE),
			"SELECT id_ip,ip_temp_nessais FROM IP.ip_temporaire where ip_temp_ip = $1");
	database->prepareStatement(
			suffix + database->ToString(REALMS_INS_IPTEMPORAIRE),
			"INSERT INTO IP.ip_temporaire VALUES (DEFAULT, $1, $2)");
	database->prepareStatement(
			suffix + database->ToString(REALMS_UPD_IPTEMPORAIRE),
			"UPDATE IP.ip_temporaire SET ip_temp_nessais = $1 WHERE id_ip = $2");

}

IPDAO::~IPDAO() {
	// TODO Auto-generated destructor stub
}

bool IPDAO::create(IP * ip, int idTransaction) {
	bool retour;
	Tokens tokens;
	retour = database->executionPrepareStatement(
			suffix + database->ToString(REALMS_INS_IPTEMPORAIRE), &tokens,
			idTransaction, 2, ip->getIpTempIp().c_str(),
			database->ToString(ip->getIpTempNessais()).c_str());
	read(ip, idTransaction);
	return retour;
}
bool IPDAO::read(IP * ip, int idTransaction) {
	bool retour;
	Tokens resultsqlT;

	retour = database->executionPrepareStatement(
			suffix + database->ToString(REALMS_SEL_IPTEMPORAIRE), &resultsqlT,
			idTransaction, 1, ip->getIpTempIp().c_str());

	if (resultsqlT.empty()) {
		retour = false;
	} else {
		Tokens resultatsql;
		resultatsql = database->strSplit(resultsqlT[0], ";");
		ip->setIdIp(database->ToInt(resultatsql[0]));
		ip->setIpTempNessais(database->ToInt(resultatsql[1]));
		retour = true;
	}
	return retour;
}
bool IPDAO::update(IP * ip, int idTransaction) {
	Tokens resultsqlT;
	return database->executionPrepareStatement(
			suffix + database->ToString(REALMS_UPD_IPTEMPORAIRE), &resultsqlT,
			idTransaction, 2, database->ToString(ip->getIpTempNessais()).c_str(),
			database->ToString(ip->getIdIp()).c_str());
}
bool IPDAO::suppr(IP * ip, int idTransaction) {
	Tokens resultsqlT;
	return database->executionPrepareStatement(
			suffix + database->ToString(REALMS_DEL_IPTEMPORAIRE), &resultsqlT,
			idTransaction, 1, database->ToString(ip->getIdIp()).c_str());

}
