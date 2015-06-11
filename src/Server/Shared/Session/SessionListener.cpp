/*
 * \file SessionListener.cpp
 *
 *  Created on: \date 25 mai 2015
 *      Author: \author joda
 *  \brief :
 */
#include "SessionListener.h"

SessionListener::SessionListener() {
	sessionListenerType = 0;

}

SessionListener::~SessionListener() {
	// TODO Auto-generated destructor stub
}

int SessionListener::getSessionListenerType() const {
	return sessionListenerType;
}

void SessionListener::setSessionListenerType(int sessionListenerType) {
	this->sessionListenerType = sessionListenerType;
}
