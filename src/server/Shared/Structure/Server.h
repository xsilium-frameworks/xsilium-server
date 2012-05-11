/*
 * Server.h
 *
 *  Created on: 2 mars 2012
 *      Author: joda2
 */

#ifndef SERVER_H_
#define SERVER_H_

#include <string>
#include "RakPeerInterface.h"


    /*!
     *  \brief struct AUTH_LOGON_PROOF_S
     *
     *  structure de AUTH_LOGON_PROOF_S
     *
     *  \param
     */
struct AUTH_LOGON_PROOF_S
{
	unsigned char typeId;  /*!< correspond au type de packet que l'on envoi */
    int   error; /*!< correspond a l'erreur qui a ete detecter */
};


/*!
 *  \brief struct sClient
 *
 *  structure de sClient
 *
 *  \param
 */
struct sClient
{
	RakNet::RakNetGUID 	guid; /*!< Numero unique generer lors de la connection au socket  */
	std::string IP ; /*!< L'ip du client       */
    uint8_t idLogin; /*!< numero unique du compte dans la base de donn�e      */
    uint16_t  build; /*!< version du client      */
    uint8_t   platform[4]; /*!< la platform du client      */
    uint8_t   os[4]; /*      */
    uint8_t   country[4]; /*!< le pays du client      */
    std::string shaPassHash; /*!< Le mot de passe crypter */
    bool locked; /*!< Si le client lock sont compte sur l'ip*/
    std::string lastIP; /*!< derniere IP du compte  */
    uint8_t gmlevel[50] ; /*!<Niveau de MJ*/
    int accountUnBanDate ; /*!<si le compte est bannie date de debanne du compte*/
};





#endif /* SERVER_H_ */
