/*
 * DAO.h
 *
 *  Created on: 22 déc. 2015
 *      Author: joda
 */

#ifndef SRC_SERVER_SHARED_DAO_DAO_H_
#define SRC_SERVER_SHARED_DAO_DAO_H_

#include <Manager/Databases/DatabaseManager.h>
#include <Model/Model.h>

class DAO {
public:
    DAO();
    virtual ~DAO();

    virtual bool create(Model * model, int idTransaction = 0) = 0;
    virtual bool update(Model * model, int idTransaction = 0) = 0;
    virtual bool read(Model * model, int idTransaction = 0) = 0;
    virtual bool suppr(Model * model, int idTransaction = 0) = 0;

protected:
    std::string suffix;
    DatabaseManager * database;
    std::string requeteSQL;
};

#endif /* SRC_SERVER_SHARED_DAO_DAO_H_ */
