/*
 * \file Model.cpp
 *
 *  Created on: \date 25 mai 2015
 *      Author: \author joda
 *  \brief :
 */
#include "Model.h"

Model::Model() {
	sessionListenerType = 0;
	updateData = false;

}

Model::~Model() {
	// TODO Auto-generated destructor stub
}

int Model::getSessionListenerType() const {
	return sessionListenerType;
}

void Model::setSessionListenerType(int sessionListenerType) {
	this->sessionListenerType = sessionListenerType;
}
