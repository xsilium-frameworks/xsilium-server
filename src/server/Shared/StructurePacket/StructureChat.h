/*
 * \file StructureChat.h
 *
 *  Created on: \date 18 févr. 2013
 *      Author: \author joda
 *  \brief :
 */

#ifndef STRUCTURECHAT_H_
#define STRUCTURECHAT_H_


typedef struct CHATPACKET_C
{
	structure_opcodeT structure_opcode;
    uint8_t           typeChat;
    char     perso[64];
    char      message[512];
} sChatPacket_C;



#endif /* STRUCTURECHAT_H_ */
