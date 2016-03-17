/*
 * AuthentificationManager.h
 *
 *  Created on: 11 juil. 2015
 *      Author: Skronak
 */

#ifndef SRC_SERVER_AUTHENTIFICATION_AUTHENTIFICATION_MANAGER_AUTHENTIFICATIONMANAGER_H_
#define SRC_SERVER_AUTHENTIFICATION_AUTHENTIFICATION_MANAGER_AUTHENTIFICATIONMANAGER_H_

#include <Manager/Manager.h>
#include <map>

#include <DAO/IP/IPBanDAO.h>
#include <DAO/IP/IPDAO.h>
#include <DAO/Compte/CompteDAO.h>
#include <DAO/Compte/CompteBanDAO.h>

namespace Auth {

class AuthentificationManager: public Manager, public Singleton<AuthentificationManager> {
public:

    /*!
     *  \brief Constructeur de la classe AuthentificationManager
     */
    AuthentificationManager();
    /*!
     *  \brief Constructeur de la classe AuthentificationManager
     */
    AuthentificationManager(DAO* compteBanDao, DAO* compteDao, DAO* ipBanDao, DAO* ipDao);

    /*!
     *  \brief Destructeur de la classe AuthentificationManager
     */
    virtual ~AuthentificationManager();

    bool checkIp(std::string ip);

    Compte * getAccount(int idCompte);

    int checkAccount(std::string username);

    void resetIpTemp(std::string ip);

    void banIP(std::string ip);

    void update(int diff);

private:
    DAO * ipBanDAO;
    DAO * ipDAO;
    DAO * compteDAO;
    DAO * compteBanDAO;

    std::map<int, Compte*> listOfCompte;
};

} /* namespace Auth */

#endif /* SRC_SERVER_AUTHENTIFICATION_AUTHENTIFICATION_MANAGER_AUTHENTIFICATIONMANAGER_H_ */
