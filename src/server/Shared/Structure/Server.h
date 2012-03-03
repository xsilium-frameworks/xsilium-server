/*
 * Server.h
 *
 *  Created on: 2 mars 2012
 *      Author: joda2
 */

#ifndef SERVER_H_
#define SERVER_H_

#include <string>;
#include <gmp.h>
#include "RakPeerInterface.h"

typedef struct AUTH_LOGON_PROOF_S
{
    int   cmd;
    int   error;
    int   M2[20];
} sAuthLogonProof_S;


typedef struct sClient
{
	RakNet::RakNetGUID 	guid;
	std::string IP ;
    uint8_t idLogin;
    uint16_t  build;
    uint8_t   platform[4];
    uint8_t   os[4];
    uint8_t   country[4];
    std::string shaPassHash;
    bool locked;
    std::string lastIP;
    uint8_t gmlevel[50] ;
    std::string shaPassHask;
    int accountUnBanDate ;
};






#endif /* SERVER_H_ */
