/*
 * AuthentificationService.h
 *
 *  Created on: 11 juil. 2015
 *      Author: Skronak
 */

#ifndef SRC_SERVER_AUTHENTIFICATION_AUTHENTIFICATION_SERVICE_AUTHENTIFICATIONSERVICE_H_
#define SRC_SERVER_AUTHENTIFICATION_AUTHENTIFICATION_SERVICE_AUTHENTIFICATIONSERVICE_H_

#include <Network/NetworkManager.h>
#include "Authentification/Manager/AuthentificationManager.h"

namespace Auth {

/*!
 * \enum typeForAuth
 * Enumeration des OPcodes
 */
enum typeForAuth
{
	ID_CHALLENGE = 0,//!< ID_CHALLENGE
	ID_REPONSE,      //!< ID_REPONSE
	ID_SEND_CANCEL,  //!< ID_SEND_CANCEL
	ID_ERREUR        //!< ID_ERREUR
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

enum stepOfAuth
{
	STEP_CHALLENGE = 0,
	STEP_REPONSE,
	STEP_REAMSLIST

};


class AuthentificationService : public NetworkListener  {
public:

	/*!
	 *  \brief Constructeur de la classe Authentification et se connecte a la DB
	 *  \param networkManager
	 */
	AuthentificationService(NetworkManager * networkManager);
	virtual ~AuthentificationService();

	/*!
	 * methode de lancement du thread
	 */
	void run();

	void processPacket(MessageNetwork * messageNetwork);
	/*!
	 *  \brief _HandleLogonChallenge
	 *
	 *  Verifie la l'existence du client ainsi que son statut
	 *  banni ou non et genere le defi
	 *  \param
	 */
	void handleLogonChallenge(MessageNetwork * messageNetwork, MessagePacket * messageRetour);
	void handleLogonProof(MessageNetwork * messageNetwork, MessagePacket * messageRetour);

	/*!
	 * Alimentation des erreurs d'un packets
	 * @param messageRetour
	 * @param typeForAuth : type d'erreur
	 */
	void sendErrorPacket(MessagePacket * messageRetour, int typeErreur);

private:
	NetworkManager * networkManager;
	Log * log;

	AuthentificationManager * authentificationManager ;
};

} /* namespace Auth */

#endif /* SRC_SERVER_AUTHENTIFICATION_AUTHENTIFICATION_SERVICE_AUTHENTIFICATIONSERVICE_H_ */
