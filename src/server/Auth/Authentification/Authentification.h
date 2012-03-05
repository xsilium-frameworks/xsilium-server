/*
 * Authentification.h
 *
 *  Created on: 7 févr. 2012
 *      Author: joda2
 */
#ifndef AUTHENTIFICATION_H_
#define AUTHENTIFICATION_H_

#include <stdio.h>
#include <vector>


#include "RakThread.h"
#include "BitStream.h"
#include "RakPeerInterface.h"
#include "MessageIdentifiers.h"
#include "RakSleep.h"


#include "../resource.h"
#include "Databases/LoginDatabase.h"
#include "Structure/Server.h"
#include "Structure/Client.h"

using namespace RakNet;
using namespace std;



class Authentification {
public:
	Authentification();
	virtual ~Authentification();

	bool CreateClient(Packet *packet);
	bool DeleteClient(Packet *packet);
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
