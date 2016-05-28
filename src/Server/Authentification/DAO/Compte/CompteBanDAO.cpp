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
    requeteSQL += "FROM authentification.account_banned WHERE unbandate>now() and id_account=$1";
    database->prepareStatement(suffix + Utilities::toString(REALMS_SEL_ACCOUNTBANNED),
            requeteSQL.c_str());

    requeteSQL = "INSERT INTO authentification.account_banned VALUES ";
    requeteSQL += "(DEFAULT,$1,to_timestamp($2),to_timestamp($3),";
    requeteSQL += "'AutoBan erreur authentification',$4)";
    database->prepareStatement(suffix + Utilities::toString(REALMS_INS_ACCOUNTBANNED),
            requeteSQL.c_str());

    requeteSQL = "UPDATE authentification.account_banned SET ";
    requeteSQL += "bandate=to_timestamp($1),unbandate=to_timestamp($2),";
    requeteSQL += "raison=$3,bannedby=$4 WHERE id_account_banned=$5";
    database->prepareStatement(suffix + Utilities::toString(REALMS_UPD_ACCOUNTBANNED),
            requeteSQL.c_str());

    requeteSQL = "DELETE FROM authentification.account_banned WHERE id_account_banned=$1";
    database->prepareStatement(suffix + Utilities::toString(REALMS_DEL_ACCOUNTBANNED),
            requeteSQL.c_str());

}

CompteBanDAO::~CompteBanDAO() {
    // TODO Auto-generated destructor stub
}

bool CompteBanDAO::create(Model * model, int idTransaction) {
    bool retour = true;
    Tokens tokens;

    CompteBan * compteBan = static_cast<CompteBan*>(model);

    try {
        database->executionPrepareStatement(suffix + Utilities::toString(REALMS_INS_ACCOUNTBANNED),
                &tokens, idTransaction, 5, Utilities::toString(compteBan->getIdAccount()).c_str(),
                Utilities::toString(compteBan->getBandate()).c_str(),
                Utilities::toString(compteBan->getUnbandate()).c_str(),
                compteBan->getRaison().c_str(),
                Utilities::toString(compteBan->getBannedby()).c_str());
    } catch (DatabaseException & e) {
        retour = false;
    }
    read(compteBan, idTransaction);
    return retour;
}
bool CompteBanDAO::update(Model * model, int idTransaction) {
    bool retour = true;
    Tokens resultsqlT;
    CompteBan * compteBan = static_cast<CompteBan*>(model);

    try {
        database->executionPrepareStatement(suffix + Utilities::toString(REALMS_UPD_ACCOUNTBANNED),
                &resultsqlT, idTransaction, 5, Utilities::toString(compteBan->getBandate()).c_str(),
                Utilities::toString(compteBan->getUnbandate()).c_str(),
                compteBan->getRaison().c_str(),
                Utilities::toString(compteBan->getBannedby()).c_str(),
                Utilities::toString(compteBan->getIdAccountBanned()).c_str());
    } catch (DatabaseException & e) {
        retour = false;
    }
    return retour;
}
bool CompteBanDAO::read(Model * model, int idTransaction) {
    bool retour = false;
    Tokens resultsqlT;
    CompteBan * compteBan = static_cast<CompteBan*>(model);
    try {
        database->executionPrepareStatement(suffix + Utilities::toString(REALMS_SEL_ACCOUNTBANNED),
                &resultsqlT, idTransaction, 1,
                Utilities::toString(compteBan->getIdAccount()).c_str());
    } catch (DatabaseException & e) {
        retour = false;
    }

    if (!resultsqlT.empty()) {
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
bool CompteBanDAO::suppr(Model * model, int idTransaction) {
    bool retour = true;
    Tokens resultsqlT;
    CompteBan * compteBan = static_cast<CompteBan*>(model);
    try {
        database->executionPrepareStatement(suffix + Utilities::toString(REALMS_DEL_ACCOUNTBANNED),
                &resultsqlT, idTransaction, 1,
                Utilities::toString(compteBan->getIdAccountBanned()).c_str());
    } catch (DatabaseException & e) {
        retour = false;
    }
    return retour;
}

