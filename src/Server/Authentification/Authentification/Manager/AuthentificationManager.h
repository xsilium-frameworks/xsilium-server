/*
 * AuthentificationManager.h
 *
 *  Created on: 11 juil. 2015
 *      Author: Skronak
 */

#ifndef SRC_SERVER_AUTHENTIFICATION_AUTHENTIFICATION_MANAGER_AUTHENTIFICATIONMANAGER_H_
#define SRC_SERVER_AUTHENTIFICATION_AUTHENTIFICATION_MANAGER_AUTHENTIFICATIONMANAGER_H_
#include <Log/Log.h>
#include <Configuration/Configuration.h>
#include <Model/IP/IPBan.h>
#include <Model/IP/IP.h>
#include <Model/Compte/Compte.h>
#include <Model/Compte/CompteBan.h>
#include <DAO/IP/IPBanDAO.h>
#include <DAO/IP/IPDAO.h>
#include <DAO/Compte/CompteDAO.h>
#include <DAO/Compte/CompteBanDAO.h>

namespace Auth {

class AuthentificationManager : public Singleton<AuthentificationManager> {
public:

	/*!
	 *  \brief Constructeur de la classe AuthentificationManager
	 */
	AuthentificationManager();
	/*!
	 *  \brief Destructeur de la classe AuthentificationManager
	 */
	virtual ~AuthentificationManager();

	bool checkIp(std::string ip);

	Compte * isAccountExist(std::string Username,std::string ip);

	bool checkAccount(int idAccount);

	void resetIpTemp(std::string ip);

	void banIP(std::string ip);

private:

	Log * log;
	Configuration * config ;
};

} /* namespace Auth */

#endif /* SRC_SERVER_AUTHENTIFICATION_AUTHENTIFICATION_MANAGER_AUTHENTIFICATIONMANAGER_H_ */
