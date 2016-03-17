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
    requeteSQL += "FROM authentification.ip_banned WHERE unbandate > now() and ip = $1";

    database->prepareStatement(suffix + Utilities::toString(REALMS_SEL_IPBANNED_INFOSSURIPBANNIES),
            requeteSQL.c_str());

    requeteSQL = "INSERT INTO authentification.ip_banned VALUES (DEFAULT,$1, to_timestamp($2),";
    requeteSQL += "to_timestamp($3), $4, $5 )";
    database->prepareStatement(suffix + Utilities::toString(REALMS_INS_IPBANNED_BANIP),
            requeteSQL.c_str());

    requeteSQL =
            "Update authentification.ip_banned set bandate=to_timestamp($1),unbandate=to_timestamp($2),";
    requeteSQL += "raison=$3,bannedby=$4 WHERE id_ip_banned = $5 ";
    database->prepareStatement(suffix + Utilities::toString(REALMS_UPD_IPBANNED_DEBANIP),
            requeteSQL.c_str());

    requeteSQL = "Delete from authentification.ip_banned WHERE id_ip_banned = $1 ";
    database->prepareStatement(suffix + Utilities::toString(REALMS_DEL_IPBANNED_DEBANIP),
            requeteSQL.c_str());

}

IPBanDAO::~IPBanDAO() {
    // TODO Auto-generated destructor stub
}

bool IPBanDAO::create(Model * model, int idTransaction) {
    bool retour;
    Tokens tokens;

    IPBan * ipBan = static_cast<IPBan*>(model);

    retour = database->executionPrepareStatement(
            suffix + Utilities::toString(REALMS_INS_IPBANNED_BANIP), &tokens, idTransaction, 5,
            ipBan->getIp().c_str(), Utilities::toString(ipBan->getBandate()).c_str(),
            Utilities::toString(ipBan->getUnbandate()).c_str(), ipBan->getRaison().c_str(),
            Utilities::toString(ipBan->getBannedby()).c_str());
    read(ipBan, idTransaction);
    return retour;
}
bool IPBanDAO::read(Model * model, int idTransaction) {
    bool retour;
    Tokens resultsqlT;

    IPBan * ipBan = static_cast<IPBan*>(model);

    retour = database->executionPrepareStatement(
            suffix + Utilities::toString(REALMS_SEL_IPBANNED_INFOSSURIPBANNIES), &resultsqlT,
            idTransaction, 1, ipBan->getIp().c_str());

    if (resultsqlT.empty()) {
        retour = false;
    } else {
        Tokens resultatsql;

        resultatsql = Utilities::strSplit(resultsqlT[0], ";");

        ipBan->setIdIpBanned(Utilities::toInt(resultatsql[0]));
        ipBan->setBandate(Utilities::toDate(resultatsql[1]));
        ipBan->setUnbandate(Utilities::toDate(resultatsql[2]));
        ipBan->setRaison(resultatsql[3]);
        ipBan->setBannedby(Utilities::toInt(resultatsql[4]));

        retour = true;
    }

    return retour;

}
bool IPBanDAO::update(Model * model, int idTransaction) {
    Tokens resultsqlT;

    IPBan * ipBan = static_cast<IPBan*>(model);

    return database->executionPrepareStatement(
            suffix + Utilities::toString(REALMS_UPD_IPBANNED_DEBANIP), &resultsqlT, idTransaction,
            5, Utilities::toString(ipBan->getBandate()).c_str(),
            Utilities::toString(ipBan->getUnbandate()).c_str(), ipBan->getRaison().c_str(),
            Utilities::toString(ipBan->getBannedby()).c_str(),
            Utilities::toString(ipBan->getIdIpBanned()).c_str());
}
bool IPBanDAO::suppr(Model * model, int idTransaction) {
    Tokens resultsqlT;

    IPBan * ipBan = static_cast<IPBan*>(model);

    return database->executionPrepareStatement(
            suffix + Utilities::toString(REALMS_DEL_IPBANNED_DEBANIP), &resultsqlT, idTransaction,
            1, Utilities::toString(ipBan->getIdIpBanned()).c_str());
}

