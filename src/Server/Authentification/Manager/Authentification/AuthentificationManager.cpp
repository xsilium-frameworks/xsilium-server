/*
 * AuthentificationManager.cpp
 *
 *  Created on: 11 juil. 2015
 *      Author: Skronak
 */

#include "AuthentificationManager.h"

namespace Auth {

AuthentificationManager::AuthentificationManager() {

    ipBanDAO = new IPBanDAO();
    ipDAO = new IPDAO();
    compteDAO = new CompteDAO();
    compteBanDAO = new CompteBanDAO();
}

AuthentificationManager::AuthentificationManager(DAO* compteBanDao, DAO* compteDao, DAO* ipBanDao,
        DAO* ipDao) {

    this->ipBanDAO = ipBanDao;
    this->ipDAO = ipDao;
    this->compteDAO = compteDao;
    this->compteBanDAO = compteBanDao;
}

AuthentificationManager::~AuthentificationManager() {
    delete ipBanDAO;
    delete ipDAO;
    delete compteDAO;
    delete compteBanDAO;
}

bool AuthentificationManager::checkIp(std::string ip) {

    IPBan ipBan(ip);
    IP ipTemp(ip);

    if (ipBanDAO->read(&ipBan))
        return false;

    if (ipDAO->read(&ipTemp))
        ipDAO->create(&ipTemp);

    return true;
}

Compte * AuthentificationManager::getAccount(std::string Username) {
    return listOfCompte.find(Username.c_str())->second;
}

bool AuthentificationManager::checkAccount(std::string Username) {
    bool resultat = false;
    Compte * compte = new Compte(Username);

    if (compteDAO->read(compte)) {
        resultat = true;
        listOfCompte.insert(std::pair<const char *, Compte*>(Username.c_str(), compte));
        CompteBan * compteBan = new CompteBan(compte->getIdAccount());
        if (compteBanDAO->read(compteBan)) {
            compte->setCompteBan(compteBan);
        }
    }

    return resultat;
}

void AuthentificationManager::banIP(std::string ip) {
    int nombreErreurMax, banTime;
    int idTransaction = 0;
    IP ipTemp(ip);
    IPBan ipBan(ip);

    ipDAO->read(&ipTemp);
    ipTemp.setIpTempNessais(ipTemp.getIpTempNessais() + 1);

    configurationManager->get("nombreErreurMax", nombreErreurMax);
    configurationManager->get("banTime", banTime);

    if ((ipTemp.getIpTempNessais() % nombreErreurMax) == 0) {

        idTransaction = DatabaseManager::getInstance()->createTransaction();

        ipBan.setBandate(time(NULL));
        ipBan.setUnbandate(
                (time(NULL) + (banTime * (ipTemp.getIpTempNessais() / nombreErreurMax)) * 60));
        ipBan.setRaison("autoban");
        ipBan.setBannedby(0);
        ipBanDAO->create(&ipBan, idTransaction);
    }
    ipDAO->update(&ipTemp, idTransaction);
}

void AuthentificationManager::resetIpTemp(std::string ip) {
    IP ipTemp(ip);
    ipDAO->read(&ipTemp);
    ipTemp.setIpTempNessais(0);
    ipDAO->update(&ipTemp);
}

void AuthentificationManager::update(int diff) {
    std::map<const char *, Compte*>::iterator it = listOfCompte.begin();

    while (it != listOfCompte.end()) {
        if (it->second->isUpdate()) {
            compteDAO->update(it->second);
        }

        if (!it->second->isOnline()) {
            compteDAO->update(it->second);
            listOfCompte.erase(it++);
        } else {
            ++it;
        }
    }
}

} /* namespace Auth */
