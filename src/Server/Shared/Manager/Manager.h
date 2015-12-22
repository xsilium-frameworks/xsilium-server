/*
 * Manager.h
 *
 *  Created on: 22 déc. 2015
 *      Author: joda
 */

#ifndef SRC_SERVER_SHARED_MANAGER_MANAGER_H_
#define SRC_SERVER_SHARED_MANAGER_MANAGER_H_

#include <Manager/Configuration/ConfigurationManager.h>
#include <Manager/Log/LogManager.h>

class Manager {
public:
    Manager();
    virtual ~Manager();

protected:
    LogManager * logManager;
    ConfigurationManager * configurationManager ;
};

#endif /* SRC_SERVER_SHARED_MANAGER_MANAGER_H_ */
