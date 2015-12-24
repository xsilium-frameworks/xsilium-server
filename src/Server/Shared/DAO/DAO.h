/*
 * DAO.h
 *
 *  Created on: 22 déc. 2015
 *      Author: joda
 */

#ifndef SRC_SERVER_SHARED_DAO_DAO_H_
#define SRC_SERVER_SHARED_DAO_DAO_H_

#include <Manager/Databases/DatabaseManager.h>

class DAO {
public:
    DAO();
    virtual ~DAO();

protected:
    std::string suffix;
    DatabaseManager * database;
    std::string requeteSQL;
};

#endif /* SRC_SERVER_SHARED_DAO_DAO_H_ */
