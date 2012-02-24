/*
 * resource.h
 *
 *  Created on: 3 févr. 2012
 *      Author: joda2
 */

#ifndef RESOURCE_H_
#define RESOURCE_H_

static const int NUM_CLIENTS=100;
#define SERVER_PORT 1234



typedef struct AUTH_LOGON_CHALLENGE_C
{
    int   cmd;
    int   error;
    char   version;
    int   platform[4];
    int   os[4];
    int   country[4];
    int   loginLen;
    char   login;
} sAuthLogonChallenge_C;

typedef struct AUTH_LOGON_PROOF_C
{
    int   cmd;
    int   A[32];
    int   M1[20];
    int   crc_hash[20];
    int   number_of_keys;
    int   securityFlags;                                  // 0x00-0x04
} sAuthLogonProof_C;

typedef struct AUTH_LOGON_PROOF_S
{
    int   cmd;
    int   error;
    int   M2[20];
} sAuthLogonProof_S;






#endif /* RESOURCE_H_ */
