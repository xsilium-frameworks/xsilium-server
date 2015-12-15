/*
 * CompteManager.cpp
 *
 *  Created on: 6 oct. 2015
 *      Author: joda
 */

#include "CompteDAO.h"

CompteDAO::CompteDAO() {
	suffix = "Compte";

	database->prepareStatement(suffix + database->ToString(REALMS_SEL_ACCOUNT),
			"SELECT id_account,sha_pass_hash,email,joindate,last_ip,locked,last_login,online,locale "
					+ "FROM compte.account where username = $1 ");
	database->prepareStatement(suffix + database->ToString(REALMS_UPD_ACCOUNT),
			"UPDATE compte.account SET sha_pass_hash = $2,email=$3,joindate = to_timestamp($4),"
					+ "last_ip = $5,locked = $6,last_login = to_timestamp($7),online = $8,locale = $9 "
					+ "WHERE id_account = $1");
	database->prepareStatement(suffix + database->ToString(REALMS_INS_ACCOUNT),
			"INSERT INTO compte.account VALUES "
					+ "(DEFAULT,$1,$2,$3,to_timestamp($4),$5,$6,to_timestamp($7),$8,$9)");
	database->prepareStatement(suffix + database->ToString(REALMS_DEL_ACCOUNT),
			"DELETE FROM compte.account WHERE id_account = $1");

}

CompteDAO::~CompteDAO() {
	// TODO Auto-generated destructor stub
}

bool CompteDAO::create(Compte * compte, int idTransaction) {
	bool retour;
	Tokens tokens;
	retour = database->executionPrepareStatement(
			suffix + database->ToString(REALMS_INS_ACCOUNT), &tokens,
			idTransaction, 9, compte->getUsername().c_str(),
			compte->getShaPassHash().c_str(), compte->getEmail().c_str(),
			database->ToString(compte->getJoindate()).c_str(),
			compte->getLastIp().c_str(),
			database->ToString(compte->isLocked()).c_str(),
			database->ToString(compte->getLastLogin()).c_str(),
			database->ToString(compte->isOnline()).c_str(),
			database->ToString(compte->getLocale()).c_str());
	return retour;
}
bool CompteDAO::update(Compte * compte, int idTransaction) {
	Tokens resultsqlT;
	return database->executionPrepareStatement(
			suffix + database->ToString(REALMS_UPD_ACCOUNT), &resultsqlT,
			idTransaction, 9,
			database->ToString(compte->getIdAccount()).c_str(),
			compte->getShaPassHash().c_str(), compte->getEmail().c_str(),
			database->ToString(compte->getJoindate()).c_str(),
			compte->getLastIp().c_str(),
			database->ToString(compte->isLocked()).c_str(),
			database->ToString(compte->getLastLogin()).c_str(),
			database->ToString(compte->isOnline()).c_str(),
			database->ToString(compte->getLocale()).c_str());

}
bool CompteDAO::read(Compte * compte, int idTransaction) {
	bool retour;
	Tokens resultsqlT;
	retour = database->executionPrepareStatement(
			suffix + database->ToString(REALMS_SEL_ACCOUNT), &resultsqlT,
			idTransaction, 1, compte->getUsername().c_str());

	if (resultsqlT.empty()) {
		retour = false;
	} else {
		Tokens resultatsql;

		resultatsql = database->strSplit(resultsqlT[0], ";");

		compte->setIdAccount(database->ToInt(resultatsql[0]));
		compte->setShaPassHash(resultatsql[1]);
		compte->setEmail(resultatsql[2]);
		compte->setJoindate(database->ToDate(resultatsql[3]));
		compte->setLastIp(resultatsql[4]);
		compte->setLocked(database->ToBool(resultatsql[5]));
		compte->setLastLogin(database->ToDate(resultatsql[6]));
		compte->setOnline(database->ToBool(resultatsql[8]));
		compte->setLocale(database->ToInt(resultatsql[8]));

		retour = true;
	}

	return retour;
}
bool CompteDAO::suppr(Compte * compte, int idTransaction) {
	Tokens resultsqlT;
	return database->executionPrepareStatement(
			suffix + database->ToString(REALMS_DEL_ACCOUNT), &resultsqlT,
			idTransaction, 1,
			database->ToString(compte->getIdAccount()).c_str());
}
