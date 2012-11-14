/*
 * AuthCodes.h
 *
 *  Created on: 24 févr. 2012
 *      Author: joda2
 */

#ifndef AUTHCODES_H_
#define AUTHCODES_H_

enum Opcode
{
	ID_CONNEXION = 0,
	ID_DECONEXION,
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
    ID_ERROR
};

enum typerequete
{
   XSILIUM_AUTH = 0
};

#endif /* AUTHCODES_H_ */
