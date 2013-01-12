/*
 * \file Session.cpp
 *
 *  Created on: \date 12 janv. 2013
 *      Author: \author joda
 *  \brief :
 */

#include "Session.h"

Session::Session() {
	// TODO Auto-generated constructor stub

}

Session::~Session() {
	// TODO Auto-generated destructor stub
}

void Session::setSessionID(ENetAddress * adresseID)
{
	this->adresseID = adresseID;
}

ENetAddress * Session::getSessionID()
{
	return adresseID ;
}
