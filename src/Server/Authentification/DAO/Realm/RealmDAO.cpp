/*
 * RealmDAO.cpp
 *
 *  Created on: 11 juil. 2015
 *      Author: Skronak
 */

#include "RealmDAO.h"

namespace Auth {

RealmDAO::RealmDAO() {
    suffix = "Royaume";

    database->prepareStatement(suffix + Utilities::toString(REALMS_SEL_LISTESROYAUMES),
            "SELECT id_royaume,key_royaume,url_royaume,port_royaume,autorisation_royaume,version_client_royaume,online_royaume FROM authentification.liste_royaume where name_royaume = $1");
    database->prepareStatement(suffix + Utilities::toString(REALMS_UPD_LISTESROYAUMES),
            "UPDATE authentification.liste_royaume SET "
                    "keyRoyaume = $2,nameRoyaume=$3,urlRoyaume = $4,portRoyaume=$5,autorisationRoyaume=$6,versionClientRoyaume=$7,online_royaume = $8 WHERE idRoyaume = $1");
    database->prepareStatement(suffix + Utilities::toString(REALMS_INS_LISTESROYAUMES),
            "INSERT INTO authentification.liste_royaume VALUES (DEFAULT,$1,$2,$3,$4,$5,$6,$7)");
    database->prepareStatement(suffix + Utilities::toString(REALMS_DEL_LISTESROYAUMES),
            "DELETE FROM authentification.liste_royaume WHERE id_royaume = $1");

}

RealmDAO::~RealmDAO() {
    // TODO Auto-generated destructor stub
}

bool RealmDAO::create(Model * model, int idTransaction) {
    bool retour;
    Tokens tokens;

    Realm * realm = static_cast<Realm*>(model);

    retour = database->executionPrepareStatement(
            suffix + Utilities::toString(REALMS_INS_LISTESROYAUMES), &tokens, idTransaction, 7,
            realm->getKeyRoyaume().c_str(), realm->getNameRoyaume().c_str(),
            realm->getUrlRoyaume().c_str(), Utilities::toString(realm->getPortRoyaume()).c_str(),
            Utilities::toString(realm->getAutorisationRoyaume()).c_str(),
            Utilities::toString(realm->getVersionClientRoyaume()).c_str(),
            Utilities::toString(realm->isOnlineRoyaume()).c_str());
    retour = read(realm);
    return retour;
}
bool RealmDAO::read(Model * model, int idTransaction) {
    bool retour;
    Tokens resultsqlT;

    Realm * realm = static_cast<Realm*>(model);

    retour = database->executionPrepareStatement(
            suffix + Utilities::toString(REALMS_SEL_LISTESROYAUMES), &resultsqlT, idTransaction, 1,
            realm->getNameRoyaume().c_str());

    if (resultsqlT.empty()) {
        retour = false;
    } else {
        Tokens resultatsql;
        resultatsql = Utilities::strSplit(resultsqlT[0], ";");

        realm->setNameRoyaume(resultatsql[0]);
        realm->setKeyRoyaume(resultatsql[1]);
        realm->setUrlRoyaume(resultatsql[2]);
        realm->setPortRoyaume(Utilities::toInt(resultatsql[3]));
        realm->setAutorisationRoyaume(Utilities::toInt(resultatsql[4]));
        realm->setVersionClientRoyaume(Utilities::toInt(resultatsql[5]));
        realm->setOnlineRoyaume(Utilities::toBool(resultatsql[6]));

        retour = true;

    }

    return retour;

}
bool RealmDAO::update(Model * model, int idTransaction) {
    Tokens resultsqlT;

    Realm * realm = static_cast<Realm*>(model);

    return database->executionPrepareStatement(
            suffix + Utilities::toString(REALMS_UPD_LISTESROYAUMES), &resultsqlT, idTransaction, 8,
            Utilities::toString(realm->getIdRoyaume()).c_str(), realm->getKeyRoyaume().c_str(),
            realm->getNameRoyaume().c_str(), realm->getUrlRoyaume().c_str(),
            Utilities::toString(realm->getPortRoyaume()).c_str(),
            Utilities::toString(realm->getAutorisationRoyaume()).c_str(),
            Utilities::toString(realm->getVersionClientRoyaume()).c_str(),
            Utilities::toString(realm->isOnlineRoyaume()).c_str());

}
bool RealmDAO::suppr(Model * model, int idTransaction) {
    Tokens resultsqlT;

    Realm * realm = static_cast<Realm*>(model);

    return database->executionPrepareStatement(
            suffix + Utilities::toString(REALMS_DEL_LISTESROYAUMES), &resultsqlT, idTransaction, 1,
            Utilities::toString(realm->getIdRoyaume()).c_str());

}

} /* namespace Auth */
