/*
 * Client.h
 *
 *  Created on: 2 mars 2012
 *      Author: joda2
 */

#ifndef CLIENT_H_
#define CLIENT_H_


typedef struct AUTH_LOGON_CHALLENGE_C
{
    uint8_t   cmd;
    uint8_t   error;
    uint16_t  size;
    uint8_t   version1;
    uint16_t  build;
    uint8_t   platform[4];
    uint8_t   os[4];
    uint8_t   country[4];
    uint32_t  timezone_bias;
    uint8_t   login_len;
    uint8_t   login[1];
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






#endif /* CLIENT_H_ */
