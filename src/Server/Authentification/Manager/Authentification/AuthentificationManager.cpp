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

Compte * AuthentificationManager::getAccount(int idCompte) {

    Compte * compte = NULL;
    std::map<int, Compte*>::iterator it;

    it = listOfCompte.find(idCompte);

    if (it != listOfCompte.end()) {
        compte = it->second;
    }

    return compte;
}

int AuthentificationManager::checkAccount(std::string username) {
    int idCompte = 0;
    Compte * compte = new Compte(username);

    if (compteDAO->read(compte)) {
        idCompte = compte->getIdAccount();
        compte->setOnline(true);
        listOfCompte[idCompte] = compte;
        CompteBan * compteBan = new CompteBan(compte->getIdAccount());
        if (compteBanDAO->read(compteBan)) {
            compte->setCompteBan(compteBan);
        }
    }

    return idCompte;
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
    std::map<int, Compte*>::iterator it = listOfCompte.begin();

    if (!listOfCompte.empty()) {
        while (it != listOfCompte.end()) {
            if (it->second->isUpdate()) {
                if (!compteDAO->update(it->second)) {
                    logManager->write(LogManager::ERROR, "Update du compte %s est en erreur.",
                            it->second->getUsername().c_str());
                } else {
                    it->second->setUpdate(false);
                }
            }
            if (!it->second->isOnline()) {
                compteDAO->update(it->second);
                logManager->write(LogManager::DEBUG, "Delete du compte : %s",
                        it->second->getUsername().c_str());
                listOfCompte.erase(it++);
            } else {
                ++it;
            }

        }
    }

}

} /* namespace Auth */
