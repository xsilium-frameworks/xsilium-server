/*
 * DatabaseException.h
 *
 *  Created on: 23 mars 2016
 *      Author: Aeden
 */

#ifndef SRC_SERVER_SHARED_MANAGER_DATABASES_DATABASEEXCEPTION_H_
#define SRC_SERVER_SHARED_MANAGER_DATABASES_DATABASEEXCEPTION_H_

#include <string>

class DatabaseException {
public:
    DatabaseException();
    DatabaseException(int sqlCode, std::string message);
    DatabaseException(std::string message);
    DatabaseException(std::exception e);
    virtual ~DatabaseException();
};

#endif /* SRC_SERVER_SHARED_MANAGER_DATABASES_DATABASEEXCEPTION_H_ */
