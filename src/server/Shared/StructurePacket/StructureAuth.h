/*
 * \file StructureAuth.h
 *
 *  Created on: \date 20 juil. 2013
 *      Author: \author joda
 *  \brief :
 */

#ifndef STRUCTUREAUTH_H_
#define STRUCTUREAUTH_H_

#include "StructurePacket/StructureGeneral.h"

struct AUTHPACKET_TYPE
{
	structure_opcodeT structure_opcode;
	uint8_t           typeAuth;
};

/*!
 *  \brief structure AUTHPACKET_LC_CLIENT
 *
 *  structure de AUTH_LOGON_CHALLENGE_C
 *
 *  \param
 */

struct AUTHPACKET_LC_C
{
	AUTHPACKET_TYPE authTypePacket;
	uint16_t  build;
	uint8_t   platform[4];
	uint8_t   os[4];
	uint8_t   country[4];
	uint8_t   login_len;
	char   login[64];
};

struct AUTHPACKET_ERROR
{
	AUTHPACKET_TYPE authTypePacket;
	uint8_t   errorID; /*!< correspond a l'erreur qui a ete detecter */
};


struct AUTHPACKET_LC_S
{
	AUTHPACKET_TYPE authTypePacket;
	uint32_t	key;
	uint32_t	key2;
};

struct AUTHPACKET_P_C
{
	AUTHPACKET_TYPE authTypePacket;
	uint8_t   A[1];

};

struct AUTHPACKET_P_S
{
	AUTHPACKET_TYPE authTypePacket;
	uint8_t   Key[20];
};

struct AUTHPACKET_LS_C
{
	AUTHPACKET_TYPE authTypePacket;
	uint32_t  iD;
	uint32_t  version;
};

struct AUTHPACKET_LS_S
{
	AUTHPACKET_TYPE authTypePacket;
	char address[255];
	uint32_t port;
	char name[255];
	char type[255];
	uint32_t NBJoueur;
	bool online;
};



#endif /* STRUCTUREAUTH_H_ */
