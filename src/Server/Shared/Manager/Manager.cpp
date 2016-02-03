/*
 * Manager.cpp
 *
 *  Created on: 22 déc. 2015
 *      Author: joda
 */

#include "Manager.h"

std::vector<Manager *> Manager::listOfManager ;

Manager::Manager() {
    logManager = LogManager::getInstance();
    configurationManager = ConfigurationManager::getInstance();
    addManager(this);
}

Manager::~Manager() {
}

void Manager::addManager(Manager * manager)
{
    Manager::listOfManager.push_back(manager);
}

