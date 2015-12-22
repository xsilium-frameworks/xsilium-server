/*
 * CompteBanDAO.cpp
 *
 *  Created on: 15 déc. 2015
 *      Author: Aeden
 */

#include "CompteBanDAO.h"

CompteBanDAO::CompteBanDAO() {
	suffix = "COMPTEBAN";

	requeteSQL = "SELECT id_account_banned,bandate,unbandate,raison,bannedby ";
	requeteSQL += "FROM compte.account_banned WHERE unbandate>now() and id_account=$1";
	database->prepareStatement(suffix + Utilities::toString(REALMS_SEL_ACCOUNTBANNED),
			requeteSQL.c_str());

	requeteSQL = "INSERT INTO compte.account_banned VALUES ";
	requeteSQL += "(DEFAULT,$1,to_timestamp($2),to_timestamp($3),";
	requeteSQL += "'AutoBan erreur authentification',$4)";
	database->prepareStatement(suffix + Utilities::toString(REALMS_INS_ACCOUNTBANNED),
			requeteSQL.c_str());

	requeteSQL = "UPDATE compte.account_banned SET ";
	requeteSQL += "bandate=to_timestamp($1),unbandate=to_timestamp($2),";
	requeteSQL += "raison=$3,bannedby=$4 WHERE id_account_banned=$5";
	database->prepareStatement(suffix + Utilities::toString(REALMS_UPD_ACCOUNTBANNED),
			requeteSQL.c_str());

	requeteSQL = "DELETE FROM compte.account_banned WHERE id_account_banned=$1";
	database->prepareStatement(suffix + Utilities::toString(REALMS_DEL_ACCOUNTBANNED),
			requeteSQL.c_str());

}

CompteBanDAO::~CompteBanDAO() {
	// TODO Auto-generated destructor stub
}

bool CompteBanDAO::create(CompteBan * compteBan, int idTransaction) {
	bool retour;
	Tokens tokens;
	retour = database->executionPrepareStatement(
			suffix + Utilities::toString(REALMS_INS_ACCOUNTBANNED), &tokens, idTransaction, 5,
			Utilities::toString(compteBan->getIdAccount()).c_str(),
			Utilities::toString(compteBan->getBandate()).c_str(),
			Utilities::toString(compteBan->getUnbandate()).c_str(), compteBan->getRaison().c_str(),
			Utilities::toString(compteBan->getBannedby()).c_str());
	read(compteBan, idTransaction);
	return retour;
}
bool CompteBanDAO::update(CompteBan * compteBan, int idTransaction) {
	Tokens resultsqlT;
	return database->executionPrepareStatement(
			suffix + Utilities::toString(REALMS_UPD_ACCOUNTBANNED), &resultsqlT, idTransaction, 5,
			Utilities::toString(compteBan->getBandate()).c_str(),
			Utilities::toString(compteBan->getUnbandate()).c_str(), compteBan->getRaison().c_str(),
			Utilities::toString(compteBan->getBannedby()).c_str(),
			Utilities::toString(compteBan->getIdAccountBanned()).c_str());
}
bool CompteBanDAO::read(CompteBan * compteBan, int idTransaction) {
	bool retour;
	Tokens resultsqlT;
	retour = database->executionPrepareStatement(
			suffix + Utilities::toString(REALMS_SEL_ACCOUNTBANNED), &resultsqlT, idTransaction, 1,
			Utilities::toString(compteBan->getIdAccount()).c_str());

	if (resultsqlT.empty()) {
		retour = false;
	} else {
		Tokens resultatsql;

		resultatsql = Utilities::strSplit(resultsqlT[0], ";");

		compteBan->setIdAccountBanned(Utilities::toInt(resultatsql[0]));
		compteBan->setBandate(Utilities::toDate(resultatsql[1]));
		compteBan->setUnbandate(Utilities::toDate(resultatsql[2]));
		compteBan->setRaison(resultatsql[3]);
		compteBan->setBannedby(Utilities::toInt(resultatsql[4]));
		retour = true;
	}

	return retour;
}
bool CompteBanDAO::suppr(CompteBan * compteBan, int idTransaction) {
	Tokens resultsqlT;
	return database->executionPrepareStatement(
			suffix + Utilities::toString(REALMS_DEL_ACCOUNTBANNED), &resultsqlT, idTransaction, 1,
			Utilities::toString(compteBan->getIdAccountBanned()).c_str());
}

