/*
 * AuthCodes.h
 *
 *  Created on: 24 f�vr. 2012
 *      Author: joda2
 */

#ifndef AUTHCODES_H_
#define AUTHCODES_H_

    /*!
     *  \brief Opcode
     *
     *  Declaration des Opcode pour chaque cas d'une connexion
     *  \param
     */

enum Opcode
{
	// partie generique
	ID_CONNEXION = 0,
	ID_DECONEXION,

	// partie authentification
    ID_SEND_USER,
    ID_SEND_CHALLENGE,
    ID_SEND_REPONSE,
    ID_SEND_VALIDATION,
    ID_GET_ROYAUME,
    ID_SEND_ROYAUME,
    ID_CONNECTION_BANNED,
    ID_INVALID_ACCOUNT_OR_PASSWORD,
    ID_COMPTE_BANNIE,
    ID_SEND_CANCEL,
    ID_INVALID_IP,
    ID_ERROR,

    //partie royaume
    ID_CHAT,

    //partie ticket
    ID__TICKET,

    //Partie message
    ID_MAIL
};

enum typerequete
{
   XSILIUM_AUTH = 0,
   XSILIUM_KINGDOM,
   XSILIUM_ALL
};

#endif /* AUTHCODES_H_ */
