/*
 * AuthCodes.h
 *
 *  Created on: 24 févr. 2012
 *      Author: joda2
 */

#ifndef AUTHCODES_H_
#define AUTHCODES_H_

enum loginopcode
{
   ID_SEND_USER = 0,
   ID_SEND_CHALLENGE,
   ID_SEND_REPONSE,
   ID_SEND_VALIDATION,
   ID_GET_ROYAUME,
   ID_SEND_ROYAUME,
   ID_CONNECTION_BANNED,
   ID_INVALID_PASSWORD,
   ID_COMPTE_BANNIE
};

#endif /* AUTHCODES_H_ */
