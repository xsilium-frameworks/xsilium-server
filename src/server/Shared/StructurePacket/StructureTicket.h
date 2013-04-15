/*
 * \file StructureChat.h
 *
 *  Created on: \date 18 f�vr. 2013
 *      Author: \author joda
 *  \brief :
 */

#ifndef STRUCTURECHAT_H_
#define STRUCTURECHAT_H_


typedef struct TicketPACKET_C
{
	structure_opcodeT structure_opcode;
    uint8_t           typeTicket;
    char      perso[64];
    int		  idTicket;
    char      message[512];
} sTicketPACKET_C;



#endif /* STRUCTURECHAT_H_ */
