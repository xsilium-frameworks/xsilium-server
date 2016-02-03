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
#include <vector>

class Manager {
public:
    Manager();
    virtual ~Manager();

    virtual void update(int diff) = 0;

    static std::vector<Manager *> listOfManager;

protected:

    static void addManager(Manager * manager);

    LogManager * logManager;
    ConfigurationManager * configurationManager ;

};

#endif /* SRC_SERVER_SHARED_MANAGER_MANAGER_H_ */
