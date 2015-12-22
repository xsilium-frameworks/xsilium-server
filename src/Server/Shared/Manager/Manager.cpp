/*
 * Manager.cpp
 *
 *  Created on: 22 déc. 2015
 *      Author: joda
 */

#include "Manager.h"

Manager::Manager() {
    logManager = LogManager::getInstance();
    configurationManager = ConfigurationManager::getInstance();

}

Manager::~Manager() {
    // TODO Auto-generated destructor stub
}

