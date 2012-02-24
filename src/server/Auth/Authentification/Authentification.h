/*
 * Authentification.h
 *
 *  Created on: 7 févr. 2012
 *      Author: joda2
 */
#ifndef AUTHENTIFICATION_H_
#define AUTHENTIFICATION_H_

#include <stdio.h>
#include <stdint.h>
#include <vector>


#include "RakThread.h"
#include "BitStream.h"
#include "RakPeerInterface.h"
#include "MessageIdentifiers.h"
#include "RakSleep.h"
#include "../resource.h"


using namespace RakNet;

typedef struct
{
	RakNet::RakNetGUID 	guid;
    char   login;
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

    std::vector<sClient> listOfClient ;
    std::vector<sClient>::iterator client ;

};

#endif /* AUTHENTIFICATION_H_ */
