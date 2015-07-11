/*
 * AuthentificationService.h
 *
 *  Created on: 11 juil. 2015
 *      Author: Skronak
 */

#ifndef SRC_SERVER_AUTHENTIFICATION_AUTHENTIFICATION_SERVICE_AUTHENTIFICATIONSERVICE_H_
#define SRC_SERVER_AUTHENTIFICATION_AUTHENTIFICATION_SERVICE_AUTHENTIFICATIONSERVICE_H_

#include <Network/NetworkManager.h>

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
	void sendErrorPacket(MessagePacket * messageRetour, typeForAuth type);

private:
	NetworkManager * networkManager;
	Log * log;
};

} /* namespace Auth */

#endif /* SRC_SERVER_AUTHENTIFICATION_AUTHENTIFICATION_SERVICE_AUTHENTIFICATIONSERVICE_H_ */
