/*
 * \file Model.cpp
 *
 *  Created on: \date 25 mai 2015
 *      Author: \author joda
 *  \brief :
 */
#include "Model.h"

Model::Model() {
	updateData = false;
	online = true;

}

Model::~Model() {
	// TODO Auto-generated destructor stub
}

std::string Model::getTypeModel() const {
	return std::string(typeid(this).name());
}


void Model::setOnline(bool online)
{
    this->online = true;
}

bool Model::isOnline() const {
    return online;
}
