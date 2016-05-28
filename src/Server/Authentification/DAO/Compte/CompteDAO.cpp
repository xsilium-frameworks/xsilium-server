/*
 * CompteManager.cpp
 *
 *  Created on: 6 oct. 2015
 *      Author: joda
 */

#include "CompteDAO.h"

CompteDAO::CompteDAO() {
    suffix = "Compte";

    requeteSQL = "SELECT id_account,sha_pass_hash,email,joindate,last_ip,";
    requeteSQL += "locked,last_login,online,locale";
    requeteSQL += " FROM authentification.account where username = $1";
    database->prepareStatement(suffix + Utilities::toString(REALMS_SEL_ACCOUNT),
            requeteSQL.c_str());

    requeteSQL = "UPDATE authentification.account SET sha_pass_hash = $2,email=$3,";
    requeteSQL += "joindate = to_timestamp($4),last_ip = $5,locked = $6,";
    requeteSQL += "last_login = to_timestamp($7),online = $8,locale = $9";
    requeteSQL += " WHERE id_account = $1";
    database->prepareStatement(suffix + Utilities::toString(REALMS_UPD_ACCOUNT),
            requeteSQL.c_str());

    requeteSQL = "INSERT INTO authentification.account VALUES ";
    requeteSQL += "(DEFAULT,$1,$2,$3,to_timestamp($4),$5,$6,";
    requeteSQL += "to_timestamp($7),$8,$9)";
    database->prepareStatement(suffix + Utilities::toString(REALMS_INS_ACCOUNT),
            requeteSQL.c_str());

    requeteSQL = "DELETE FROM authentification.account WHERE id_account = $1";
    database->prepareStatement(suffix + Utilities::toString(REALMS_DEL_ACCOUNT),
            requeteSQL.c_str());

}

CompteDAO::~CompteDAO() {
    // TODO Auto-generated destructor stub
}

bool CompteDAO::create(Model * model, int idTransaction) {
    bool retour = true;
    Tokens tokens;

    Compte * compte = static_cast<Compte*>(model);

    try {
        database->executionPrepareStatement(suffix + Utilities::toString(REALMS_INS_ACCOUNT),
                &tokens, idTransaction, 9, compte->getUsername().c_str(),
                compte->getShaPassHash().c_str(), compte->getEmail().c_str(),
                Utilities::toString(compte->getJoindate()).c_str(), compte->getLastIp().c_str(),
                Utilities::toString(compte->isLocked()).c_str(),
                Utilities::toString(compte->getLastLogin()).c_str(),
                Utilities::toString(compte->isOnline()).c_str(),
                Utilities::toString(compte->getLocale()).c_str());
    } catch (DatabaseException & e) {
        retour = false;
    }
    return retour;
}

bool CompteDAO::update(Model * model, int idTransaction) {
    Tokens resultsqlT;

    bool retour = true;

    Compte * compte = static_cast<Compte*>(model);

    try {
        database->executionPrepareStatement(suffix + Utilities::toString(REALMS_UPD_ACCOUNT),
                &resultsqlT, idTransaction, 9, Utilities::toString(compte->getIdAccount()).c_str(),
                compte->getShaPassHash().c_str(), compte->getEmail().c_str(),
                Utilities::toString(compte->getJoindate()).c_str(), compte->getLastIp().c_str(),
                Utilities::toString(compte->isLocked()).c_str(),
                Utilities::toString(compte->getLastLogin()).c_str(),
                Utilities::toString(compte->isOnline()).c_str(),
                Utilities::toString(compte->getLocale()).c_str());
    } catch (DatabaseException & e) {
        retour = false;
    }

    return retour;

}
bool CompteDAO::read(Model * model, int idTransaction) {
    bool retour = false;
    Tokens resultsqlT;

    Compte * compte = static_cast<Compte*>(model);

    try {
        database->executionPrepareStatement(suffix + Utilities::toString(REALMS_SEL_ACCOUNT),
                &resultsqlT, idTransaction, 1, compte->getUsername().c_str());
    } catch (DatabaseException & e) {
        retour = false;
    }

    if (!resultsqlT.empty()) {
        Tokens resultatsql;

        resultatsql = Utilities::strSplit(resultsqlT[0], ";");

        compte->setIdAccount(Utilities::toInt(resultatsql[0]));
        compte->setShaPassHash(resultatsql[1]);
        compte->setEmail(resultatsql[2]);
        compte->setJoindate(Utilities::toDate(resultatsql[3]));
        compte->setLastIp(resultatsql[4]);
        compte->setLocked(Utilities::toBool(resultatsql[5]));
        compte->setLastLogin(Utilities::toDate(resultatsql[6]));
        compte->setOnline(Utilities::toBool(resultatsql[8]));
        compte->setLocale(Utilities::toInt(resultatsql[8]));

        retour = true;
    }

    return retour;
}
bool CompteDAO::suppr(Model * model, int idTransaction) {
    Tokens resultsqlT;
    bool retour = true;

    Compte * compte = static_cast<Compte*>(model);

    try {
        database->executionPrepareStatement(suffix + Utilities::toString(REALMS_DEL_ACCOUNT),
                &resultsqlT, idTransaction, 1, Utilities::toString(compte->getIdAccount()).c_str());
    } catch (DatabaseException & e) {
        retour = false;
    }
    return retour;
}
