/*
 * AuthentificationManager.h
 *
 *  Created on: 11 juil. 2015
 *      Author: Skronak
 */

#ifndef SRC_SERVER_AUTHENTIFICATION_AUTHENTIFICATION_MANAGER_AUTHENTIFICATIONMANAGER_H_
#define SRC_SERVER_AUTHENTIFICATION_AUTHENTIFICATION_MANAGER_AUTHENTIFICATIONMANAGER_H_
#include <Configuration/Configuration.h>
#include <IP/IPBan.h>
#include <IP/IP.h>
#include <Compte/Compte.h>
#include <Compte/CompteBan.h>

namespace Auth {

enum erreurOfAuth
{
	ID_NOERROR = 0,
	ID_ERROR_PACKET_SIZE,
	ID_CONNECTION_BANNED,
	ID_INVALID_ACCOUNT_OR_PASSWORD,
	ID_COMPTE_BANNIE,
	ID_INVALID_IP,
	ID_ERROR_ETAPE
};

enum stepOfAuth
{
	STEP_CHALLENGE = 0,
	STEP_REPONSE,
	STEP_REAMSLIST

};

class AuthentificationManager {
public:

	/*!
	 *  \brief Constructeur de la classe AuthentificationManager
	 */
	AuthentificationManager();
	/*!
	 *  \brief Destructeur de la classe AuthentificationManager
	 */
	virtual ~AuthentificationManager();

	int checkIp(std::string ip);
};

} /* namespace Auth */

#endif /* SRC_SERVER_AUTHENTIFICATION_AUTHENTIFICATION_MANAGER_AUTHENTIFICATIONMANAGER_H_ */
