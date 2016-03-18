/*
 * IPDAO.cpp
 *
 *  Created on: 15 déc. 2015
 *      Author: Aeden
 */

#include "IPDAO.h"

IPDAO::IPDAO() {
    suffix = "IP";

    database->prepareStatement(suffix + Utilities::toString(REALMS_DEL_IPTEMPORAIRE),
            "DELETE FROM authentification.ip_temporaire where id_ip = $1");
    database->prepareStatement(suffix + Utilities::toString(REALMS_SEL_IPTEMPORAIRE),
            "SELECT id_ip,ip_temp_nessais FROM authentification.ip_temporaire where ip_temp_ip = $1");
    database->prepareStatement(suffix + Utilities::toString(REALMS_INS_IPTEMPORAIRE),
            "INSERT INTO authentification.ip_temporaire VALUES (DEFAULT, $1, $2)");
    database->prepareStatement(suffix + Utilities::toString(REALMS_UPD_IPTEMPORAIRE),
            "UPDATE authentification.ip_temporaire SET ip_temp_nessais = $1 WHERE id_ip = $2");

}

IPDAO::~IPDAO() {
    // TODO Auto-generated destructor stub
}

bool IPDAO::create(Model * model, int idTransaction) {
    bool retour;
    Tokens tokens;

    IP * ip = static_cast<IP*>(model);

    retour = database->executionPrepareStatement(
            suffix + Utilities::toString(REALMS_INS_IPTEMPORAIRE), &tokens, idTransaction, 2,
            ip->getIpTempIp().c_str(), Utilities::toString(ip->getIpTempNessais()).c_str());
    read(ip, idTransaction);
    return retour;
}
bool IPDAO::read(Model * model, int idTransaction) {
    bool retour = false;
    Tokens resultsqlT;

    IP * ip = static_cast<IP*>(model);

    retour = database->executionPrepareStatement(
            suffix + Utilities::toString(REALMS_SEL_IPTEMPORAIRE), &resultsqlT, idTransaction, 1,
            ip->getIpTempIp().c_str());

    if (!resultsqlT.empty()) {
        Tokens resultatsql;
        resultatsql = Utilities::strSplit(resultsqlT[0], ";");
        ip->setIdIp(Utilities::toInt(resultatsql[0]));
        ip->setIpTempNessais(Utilities::toInt(resultatsql[1]));
        retour = true;
    }
    return retour;
}
bool IPDAO::update(Model * model, int idTransaction) {
    Tokens resultsqlT;

    IP * ip = static_cast<IP*>(model);

    return database->executionPrepareStatement(
            suffix + Utilities::toString(REALMS_UPD_IPTEMPORAIRE), &resultsqlT, idTransaction, 2,
            Utilities::toString(ip->getIpTempNessais()).c_str(),
            Utilities::toString(ip->getIdIp()).c_str());
}
bool IPDAO::suppr(Model * model, int idTransaction) {
    Tokens resultsqlT;

    IP * ip = static_cast<IP*>(model);

    return database->executionPrepareStatement(
            suffix + Utilities::toString(REALMS_DEL_IPTEMPORAIRE), &resultsqlT, idTransaction, 1,
            Utilities::toString(ip->getIdIp()).c_str());

}
