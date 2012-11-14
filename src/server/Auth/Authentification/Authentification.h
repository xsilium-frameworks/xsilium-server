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

#include <enet/enet.h>


#include "../resource.h"
#include "Databases/LoginDatabase.h"
#include "Structure/Client.h"
#include "Logging/Log.h"
#include "Config/Configuration.h"
#include "Opcode/Opcode.h"
#include "Connexion/Connexion.h"


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

	Authentification();

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

	void CreateClient();

    /*!
     *  \brief DeleteClient
     *
     *  Supression de la variable de type client que l'on a mis
     *  dans le vector "listofclient"
     *
     *  \param
     */

	void DeleteClient();

    /*!
     *  \brief FindClient
     *
     *  Recherche d'une variable de type client que l'on a mis
     *  dans le vector "listofclient"
     *
     *  \param
     */

	bool FindClient(ENetAddress guid);

    /*!
     *  \brief _HandleLogonChallenge
     *
     *  Vérifie la l'existance du client ainsi que son status
     *  banni ou non et génère les defis
     *
     *  \param
     */

	void HandleLogonChallenge();
	void HandleLogonProof();
	void HandleRealmList();

private:

    vector<sClient> listOfClient ;
    vector<sClient>::iterator client ;
    LoginDatabase * realms ;
    Log * log;
    Configuration * config ;
    Connexion * connexion;


     string connectionString;

    bool isDBConnect ;


};

#endif /* AUTHENTIFICATION_H_ */
