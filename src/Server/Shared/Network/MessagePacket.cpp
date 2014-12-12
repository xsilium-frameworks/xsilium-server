/*
 * \file MessagePacket.cpp
 *
 *  Created on: \date 30 oct. 2014
 *      Author: \author joda
 *  \brief :
 */

#include "MessagePacket.h"

MessagePacket::MessagePacket()
{
	opcode = 0;

}

MessagePacket::~MessagePacket()
{

}

int MessagePacket::getOpcode()
{
	return opcode;
}
