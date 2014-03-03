/*
 * \file StructureChat.h
 *
 *  Created on: \date 18 f�vr. 2013
 *      Author: \author joda
 *  \brief :
 */

#ifndef STRUCTURECHAT_H_
#define STRUCTURECHAT_H_

typedef struct TICKETTYPEPACKET
{
	structure_opcodeT structure_opcode;
    uint8_t           typeTicket;
}ticketTypePacketT;

typedef struct TICKETPACKET_C
{
	ticketTypePacketT charTypePacket;
    char      perso[64];
    int		  idTicket;
    char      message[512];
} sTicketPacket_C;




#endif /* STRUCTURECHAT_H_ */
