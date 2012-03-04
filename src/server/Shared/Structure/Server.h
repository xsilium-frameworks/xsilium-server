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


/** \struct AUTH_LOGON_PROOF_S
 *
 *
 */
typedef struct AUTH_LOGON_PROOF_S
{
    uint8_t   cmd; /*!< correspond au type de packet que l'on envoi */
    int   error; /*!< correspond a l'erreur qui a ete detecter */
    int   M2[20]; /*      */
} sAuthLogonProof_S;


/** \struct sClient
 *
 *
 */
typedef struct sClient
{
	RakNet::RakNetGUID 	guid; /*!< Numero unique generer lors de la connection au socket  */
	std::string IP ; /*!< L'ip du client       */
    uint8_t idLogin; /*      */
    uint16_t  build; /*      */
    uint8_t   platform[4]; /*      */
    uint8_t   os[4]; /*      */
    uint8_t   country[4]; /*      */
    std::string shaPassHash; /*      */
    bool locked; /*      */
    std::string lastIP; /*!< derniere IP du compte      */
    uint8_t gmlevel[50] ; /*      */
    std::string shaPassHask; /*      */
    int accountUnBanDate ; /*      */
};






#endif /* SERVER_H_ */
