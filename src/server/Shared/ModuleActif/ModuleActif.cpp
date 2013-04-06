/*
 * \file ModuleActif.cpp
 *
 *  Created on: \date 6 avr. 2013
 *      Author: \author joda
 *  \brief :
 */

#include "ModuleActif.h"

ModuleActif::ModuleActif(Connexion * connexion) {
	this->connexion = connexion ;
}

ModuleActif::~ModuleActif() {

	while(ListOfTchatPacket.size() != 0 )
		ListOfTchatPacket.pop();
}

ENetEvent ModuleActif::getPacket()
{
	ENetEvent  packet = ListOfTchatPacket.front();
	ListOfTchatPacket.pop();
	return packet;
}

void ModuleActif::setPacket()
{
	boost::mutex::scoped_lock lock(mutexList);

	ListOfTchatPacket.push(*(connexion->getPacket()));
	lock.unlock();
	condition_Queue.notify_one();
}

bool ModuleActif::isEmpty()
{
	boost::mutex::scoped_lock lock(mutexList);
	if(ListOfTchatPacket.empty())
	{
		condition_Queue.wait(lock);
		return false;
	}
	else
		return true;
}
