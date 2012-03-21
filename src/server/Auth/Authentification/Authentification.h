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
     *  Prend le client et le met dans la pile
     *  gestion de la pile FIFO
     *  Et l'integre dans la DB
     *
     *  \param
     */

	bool CreateClient(Packet *packet);

    /*!
     *  \brief DeleteClient
     *
     *  Prend le client et le met dans la pile
     *  gestion de la pile FIFO
     *  Et supprime de la DB
     *
     *  \param
     */

	bool DeleteClient(Packet *packet);

    /*!
     *  \brief FindClient
     *
     *  Recherche le client dans la DB
     *
     *  \param
     */

	bool FindClient(RakNetGUID guid);

    bool _HandleLogonChallenge( RakNet::Packet *packet);
    bool _HandleLogonProof();
    bool _HandleReconnectChallenge();
    bool _HandleReconnectProof();
    bool _HandleRealmList();

private:

    vector<sClient> listOfClient ;
    vector<sClient>::iterator client ;
    LoginDatabase * realms ;
    const char * connectionString;

    bool isDBConnect ;


};

#endif /* AUTHENTIFICATION_H_ */
