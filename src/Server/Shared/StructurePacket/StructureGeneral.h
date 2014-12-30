/*
 * Packet.h
 *
 *  Created on: 2 mars 2012
 *      Author: joda2
 */

#ifndef PACKET_H_
#define PACKET_H_

#include <stdint.h>

    /*!
     *  \brief structure AUTH_LOGON_CHALLENGE_C
     *
     *  structure de AUTH_LOGON_CHALLENGE_C
     *
     *  \param
     */
typedef struct structure_opcode
{
	uint8_t   cmd;
	uint8_t   opcode;
} structure_opcodeT ;

typedef struct structure_erreur
{
	structure_opcodeT structure_opcode;
    int   error; /*!< correspond a l'erreur qui a ete detecter */
}structure_erreurT;




#endif /* PACKET_H_ */
