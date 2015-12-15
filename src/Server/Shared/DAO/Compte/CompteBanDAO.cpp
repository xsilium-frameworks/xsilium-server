/*
 * CompteBanDAO.cpp
 *
 *  Created on: 15 déc. 2015
 *      Author: Aeden
 */

#include "CompteBanDAO.h"

CompteBanDAO::CompteBanDAO() {
	suffix = "COMPTEBAN";

	database->prepareStatement(
			suffix + database->ToString(REALMS_SEL_ACCOUNTBANNED),
			"SELECT id_account_banned,bandate,unbandate,raison,bannedby "
					+ "FROM compte.account_banned "
					+ "WHERE unbandate>now() and id_account=$1");
	database->prepareStatement(
			suffix + database->ToString(REALMS_INS_ACCOUNTBANNED),
			"INSERT INTO compte.account_banned VALUES "
					+ "(DEFAULT,$1,to_timestamp($2),to_timestamp($3),"
					+ "'AutoBan erreur authentification',$4)");
	database->prepareStatement(
			suffix + database->ToString(REALMS_UPD_ACCOUNTBANNED),
			"UPDATE compte.account_banned SET "
					+ "bandate=to_timestamp($1),unbandate=to_timestamp($2),"
					+ "raison=$3,bannedby=$4 WHERE id_account_banned=$5");
	database->prepareStatement(
			suffix + database->ToString(REALMS_DEL_ACCOUNTBANNED),
			"DELETE FROM compte.account_banned WHERE id_account_banned=$1");

}

CompteBanDAO::~CompteBanDAO() {
	// TODO Auto-generated destructor stub
}

bool CompteBanDAO::create(CompteBan * compteBan, int idTransaction) {
	bool retour;
	Tokens tokens;
	retour = database->executionPrepareStatement(
			suffix + database->ToString(REALMS_INS_ACCOUNTBANNED), &tokens,
			idTransaction, 5,
			database->ToString(compteBan->getIdAccount()).c_str(),
			database->ToString(compteBan->getBandate()).c_str(),
			database->ToString(compteBan->getUnbandate()).c_str(),
			compteBan->getRaison().c_str(),
			database->ToString(compteBan->getBannedby()).c_str());
	read(compteBan, idTransaction);
	return retour;
}
bool CompteBanDAO::update(CompteBan * compteBan, int idTransaction) {
	Tokens resultsqlT;
	return database->executionPrepareStatement(
			suffix + database->ToString(REALMS_UPD_ACCOUNTBANNED), &resultsqlT,
			idTransaction, 5,
			database->ToString(compteBan->getBandate()).c_str(),
			database->ToString(compteBan->getUnbandate()).c_str(),
			compteBan->getRaison().c_str(),
			database->ToString(compteBan->getBannedby()).c_str(),
			database->ToString(compteBan->getIdAccountBanned()).c_str());
}
bool CompteBanDAO::read(CompteBan * compteBan, int idTransaction) {
	bool retour;
	Tokens resultsqlT;
	retour = database->executionPrepareStatement(
			suffix + database->ToString(REALMS_SEL_ACCOUNTBANNED), &resultsqlT,
			idTransaction, 1,
			database->ToString(compteBan->getIdAccount()).c_str());

	if (resultsqlT.empty()) {
		retour = false;
	} else {
		Tokens resultatsql;

		resultatsql = database->strSplit(resultsqlT[0], ";");

		compteBan->setIdAccountBanned(database->ToInt(resultatsql[0]));
		compteBan->setBandate(database->ToDate(resultatsql[1]));
		compteBan->setUnbandate(database->ToDate(resultatsql[2]));
		compteBan->setRaison(resultatsql[3]);
		compteBan->setBannedby(database->ToInt(resultatsql[4]));
		retour = true;
	}

	return retour;
}
bool CompteBanDAO::suppr(CompteBan * compteBan, int idTransaction) {
	Tokens resultsqlT;
	return database->executionPrepareStatement(
			suffix + database->ToString(REALMS_DEL_ACCOUNTBANNED), &resultsqlT,
			idTransaction, 1,
			database->ToString(compteBan->getIdAccountBanned()).c_str());
}

