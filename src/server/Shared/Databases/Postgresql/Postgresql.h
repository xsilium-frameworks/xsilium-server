/*
 * \file Postgresql.h
 *
 *  Created on: \date 20 oct. 2014
 *      Author: \author joda
 *  \brief :
 */
#ifndef SRC_SERVER_SHARED_DATABASES_POSTGRESQL_POSTGRESQL_H_
#define SRC_SERVER_SHARED_DATABASES_POSTGRESQL_POSTGRESQL_H_

#include <pqxx/pqxx>
#include <boost/thread.hpp>
#include <iostream>
#include <stdarg.h>

#include "Database.h"

/*
 *
 */
class Postgresql: public Database {
public:
	Postgresql();
	virtual ~Postgresql();

	bool Connection();
	bool Deconnection();
	void Select();
	void Insert();
	void Delete();
	void Update();
	void GetTransaction();
	void Commit();

private:
	pqxx::lazyconnection * conn;


};

#endif /* SRC_SERVER_SHARED_DATABASES_POSTGRESQL_POSTGRESQL_H_ */
