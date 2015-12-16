/*
 * \file CRUD.h
 *
 *  Created on: \date 27 mai 2015
 *      Author: \author joda
 *  \brief :
 */
#ifndef SRC_SERVER_SHARED_DATABASES_CRUD_H_
#define SRC_SERVER_SHARED_DATABASES_CRUD_H_

#include <Manager/Databases/DatabaseManager.h>
#include <Model/Model.h>

class CRUD {
public:
	CRUD()
	{
		database = DatabaseManager::getInstance();
	};
	virtual ~CRUD(){};

	virtual bool create(Model * model , int idTransaction = 0) = 0;
	virtual bool read(Model * model , int idTransaction = 0) = 0 ;
	virtual bool update(Model * model , int idTransaction = 0) = 0;
	virtual bool suppr(Model * model , int idTransaction = 0) = 0;

protected:
	std::string suffix;
	DatabaseManager * database;
	std::string requeteSQL;
};



#endif /* SRC_SERVER_SHARED_DATABASES_CRUD_H_ */
