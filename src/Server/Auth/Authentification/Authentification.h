/*
 * \file Authentification.h
 *
 *  Created on: \date 24 déc. 2014
 *      Author: \author joda
 *  \brief :
 */
#ifndef SRC_SERVER_AUTH_AUTHENTIFICATION_AUTHENTIFICATION_H_
#define SRC_SERVER_AUTH_AUTHENTIFICATION_AUTHENTIFICATION_H_

#include <Network/NetworkManager.h>
#include <Configuration/Configuration.h>
#include <IP/IPBan.h>
#include <IP/IP.h>
#include <Compte/Compte.h>
#include <Compte/CompteBan.h>

namespace Auth {

enum stepOfAuth
{
	STEP_CHALLENGE = 0,
	STEP_REPONSE,
	STEP_REAMSLIST

};

enum typeForAuth
{
	ID_CHALLENGE = 0,
	ID_REPONSE,
	ID_SEND_CANCEL,
	ID_ERREUR
};

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

/*
 *
 */
class Authentification : public NetworkListener {
public:
	/*!
	 *  \brief Constructeur
	 *
	 *  Constructeur de la classe Authentification
	 *	Et se connecte a la DB
	 *  \param
	 */

	Authentification(NetworkManager * networkManager);

	/*!
	 *  \brief Constructeur
	 *
	 *  Destructeur de la classe Authentification
	 *  Et se déconnecte de la DB
	 *  \param
	 */

	virtual ~Authentification();


	void run();

	/*!
	 *  \brief _HandleLogonChallenge
	 *
	 *  Vérifie la l'existance du client ainsi que son status
	 *  banni ou non et génère les defis
	 *
	 *  \param
	 */

	int  handleLogonChallenge(MessageNetwork * messageNetwork,MessagePacket * messageRetour);
	int  handleLogonProof(MessageNetwork * messageNetwork,MessagePacket * messageRetour);

	void processPacket(MessageNetwork * messageNetwork);


private:

	void banIP(IP * ip , IPBan * ipBan);

	Log * log;
	Configuration * config ;
	NetworkManager * networkManager;

};

} /* namespace Auth */

#endif /* SRC_SERVER_AUTH_AUTHENTIFICATION_AUTHENTIFICATION_H_ */
