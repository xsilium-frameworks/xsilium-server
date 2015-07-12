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
#include <IP/IPBan.h>
#include <IP/IP.h>
#include <Compte/Compte.h>
#include <Compte/CompteBan.h>

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
