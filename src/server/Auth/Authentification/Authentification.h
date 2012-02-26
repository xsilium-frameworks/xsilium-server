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
#include <gmp.h>
#include <string>


#include "RakThread.h"
#include "BitStream.h"
#include "RakPeerInterface.h"
#include "MessageIdentifiers.h"
#include "RakSleep.h"


#include "../resource.h"
#include "../../Shared/Databases/LoginDatabase.h"

using namespace RakNet;
using namespace std;

typedef struct
{
	RakNetGUID 	guid;
	string IP ;
    string login;
    uint16_t  build;
    uint8_t   platform[4];
    uint8_t   os[4];
    uint8_t   country[4];
} sClient;


class Authentification {
public:
	Authentification();
	virtual ~Authentification();

	bool CreateClient(Packet *packet);
	bool DeleteClient(Packet *packet);
	bool FindClient(RakNet::RakNetGUID guid);

    bool _HandleLogonChallenge( RakNet::Packet *packet);
    bool _HandleLogonProof();
    bool _HandleReconnectChallenge();
    bool _HandleReconnectProof();
    bool _HandleRealmList();

private:

    vector<sClient> listOfClient ;
    vector<sClient>::iterator client ;
    LoginDatabase * realms ;
    char connectionString[256];

    bool isDBConnect ;


};

#endif /* AUTHENTIFICATION_H_ */
