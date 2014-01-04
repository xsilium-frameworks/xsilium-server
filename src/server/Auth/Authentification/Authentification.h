/*
 * Authentification.h
 *
 *  Created on: 7 f�vr. 2012
 *      Author: joda2
 */

/*!
 * \file Authentification.h
 * \brief authentication
 * \author joda
 *
 */


#ifndef AUTHENTIFICATION_H_
#define AUTHENTIFICATION_H_

#include "StructurePacket/StructureAuth.h"
#include "Config/Configuration.h"
#include "Connexion/Connexion.h"
#include "ListServeur/ListServeur.h"
#include "Session/GestionnaireSession.h"

#include "ModuleActif/ModuleActif.h"

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


class Authentification : public ModuleActif {
public:


	/*!
	 *  \brief Constructeur
	 *
	 *  Constructeur de la classe Authentification
	 *	Et se connecte a la DB
	 *  \param
	 */

	Authentification(Connexion * connexion);

	/*!
	 *  \brief Constructeur
	 *
	 *  Destructeur de la classe Authentification
	 *  Et se déconnecte de la DB
	 *  \param
	 */

	virtual ~Authentification();


	void run();

	void stopThread();

	/*!
	 *  \brief _HandleLogonChallenge
	 *
	 *  Vérifie la l'existance du client ainsi que son status
	 *  banni ou non et génère les defis
	 *
	 *  \param
	 */

	int  HandleLogonChallenge(ENetEvent * packet,bool cppUnit = false);
	int  HandleLogonProof(ENetEvent * packet,bool cppUnit = false);
	int  HandleRealmList(ENetEvent * packet,bool cppUnit = false);

private:

	static void  threadAuthentification(void * arguments);

	GestionnaireSession * gestionnaireSession ;
	GestionnaireCompte * gestionnaireCompte ;
	LoginDatabase * realms ;
	Log * log;
	Configuration * config ;
	Connexion * connexion;
	ListServeur * listServeur;


};

#endif /* AUTHENTIFICATION_H_ */
