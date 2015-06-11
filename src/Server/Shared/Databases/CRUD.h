/*
 * \file CRUD.h
 *
 *  Created on: \date 27 mai 2015
 *      Author: \author joda
 *  \brief :
 */
#ifndef SRC_SERVER_SHARED_DATABASES_CRUD_H_
#define SRC_SERVER_SHARED_DATABASES_CRUD_H_

#include <Databases/DatabaseManager.h>

class CRUD {
public:
	CRUD()
	{
		database = DatabaseManager::getInstance();
	};
	virtual ~CRUD(){};

	virtual bool create(int idTransaction) = 0;
	virtual bool read(int idTransaction) = 0 ;
	virtual bool update(int idTransaction) = 0;
	virtual bool suppr(int idTransaction) = 0;

protected:
	std::string suffix;
	DatabaseManager * database;
};



#endif /* SRC_SERVER_SHARED_DATABASES_CRUD_H_ */
