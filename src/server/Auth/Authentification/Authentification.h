/*
 * Authentification.h
 *
 *  Created on: 7 f�vr. 2012
 *      Author: joda2
 */

/*!
 * \file Authentification.h
 * \brief authentication
 * \author joda2
 *
 */


#ifndef AUTHENTIFICATION_H_
#define AUTHENTIFICATION_H_

#include <stdio.h>
#include <vector>


#include "BitStream.h"
#include "MessageIdentifiers.h"
#include "RakSleep.h"


#include "../resource.h"
#include "Databases/LoginDatabase.h"
#include "Structure/Client.h"
#include "Logging/Log.h"
#include "Config/Configuration.h"

using namespace RakNet;
using namespace std;



class Authentification {
public:


    /*!
     *  \brief Constructeur
     *
     *  Constructeur de la classe Authentification
     *	Et se connecte a la DB
     *  \param
     */

	Authentification(RakPeerInterface *peer);

    /*!
     *  \brief Constructeur
     *
     *  Destructeur de la classe Authentification
     *  Et se déconnecte de la DB
     *  \param
     */

	virtual ~Authentification();

    /*!
     *  \brief CreateClient
     *
     *  creation d'une variable de type client que l'on va mettre
     *  dans le vector "listofclient" afin d'identifier et d'utiliser
     *  les meme donner d'une etape a une autre
     *
     *  \param
     */

	bool CreateClient(Packet *packet);

    /*!
     *  \brief DeleteClient
     *
     *  Supression de la variable de type client que l'on a mis
     *  dans le vector "listofclient"
     *
     *  \param
     */

	bool DeleteClient(Packet *packet);

    /*!
     *  \brief FindClient
     *
     *  Recherche d'une variable de type client que l'on a mis
     *  dans le vector "listofclient"
     *
     *  \param
     */

	bool FindClient(RakNetGUID guid);

    /*!
     *  \brief _HandleLogonChallenge
     *
     *  Vérifie la l'existance du client ainsi que son status
     *  banni ou non et génère les defis
     *
     *  \param
     */

	void ConnexionDB();

    bool _HandleLogonChallenge( RakNet::Packet *packet);
    bool _HandleLogonProof();
    bool _HandleReconnectChallenge();
    bool _HandleReconnectProof();
    bool _HandleRealmList();

private:

    vector<sClient> listOfClient ;
    vector<sClient>::iterator client ;
    LoginDatabase * realms ;
    Log * log;
    Configuration * config ;
    RakPeerInterface *peer2;


     string connectionString;

    bool isDBConnect ;


};

#endif /* AUTHENTIFICATION_H_ */
