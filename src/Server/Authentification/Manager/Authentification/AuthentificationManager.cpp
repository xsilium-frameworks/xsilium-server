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

AuthentificationManager::AuthentificationManager(DAO* compteBanDao,DAO* compteDao,DAO* ipBanDao,DAO* ipDao) {

    this->ipBanDAO = ipBanDao;
    this->ipDAO = ipDao;
    this->compteDAO = compteDao;
    this->compteBanDAO = compteBanDao;
}

AuthentificationManager::~AuthentificationManager() {
    delete ipBanDAO ;
    delete ipDAO ;
    delete compteDAO;
    delete compteBanDAO ;
}

bool AuthentificationManager::checkIp(std::string ip){

    IPBan ipBan(ip);
    IP ipTemp(ip);


    if(ipBanDAO->read(&ipBan))
        return false;


    if(ipDAO->read(&ipTemp))
        ipDAO->create(&ipTemp);

    return true ;
}

Compte * AuthentificationManager::isAccountExist(std::string Username,std::string ip)
{
    Compte * compte = new Compte(Username);

    if(!compteDAO->read(compte))
    {
        banIP(ip);
        return 0;
    }

    return compte;
}

bool AuthentificationManager::checkAccount(int idAccount)
{
    CompteBan compteBan( idAccount);

    if(compteBanDAO->read(&compteBan))
        return false;

    return true;

}

void AuthentificationManager::banIP(std::string ip)
{
    int nombreErreurMax,banTime;
    int idTransaction = 0;
    IP ipTemp(ip);
    IPBan ipBan(ip);

    ipDAO->read(&ipTemp);
    ipTemp.setIpTempNessais(ipTemp.getIpTempNessais() + 1);

    configurationManager->get("nombreErreurMax",nombreErreurMax);
    configurationManager->get("banTime",banTime);

    if( ( ipTemp.getIpTempNessais() % nombreErreurMax ) == 0 )
    {

        idTransaction = DatabaseManager::getInstance()->createTransaction();

        ipBan.setBandate(time(NULL));
        ipBan.setUnbandate((time(NULL) + (banTime * (ipTemp.getIpTempNessais() / nombreErreurMax ))  *60));
        ipBan.setRaison("autoban");
        ipBan.setBannedby(0);
        ipBanDAO->create(&ipBan,idTransaction);
    }
    ipDAO->update(&ipTemp,idTransaction);
}

void AuthentificationManager::resetIpTemp(std::string ip)
{
    IP ipTemp(ip);
    ipDAO->read(&ipTemp);
    ipTemp.setIpTempNessais(0);
    ipDAO->update(&ipTemp);
}

void AuthentificationManager::update(int diff)
{
    printf("test auth \n");
}

} /* namespace Auth */
