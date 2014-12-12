/*
 * \file Database.h
 *
 *  Created on: \date 20 oct. 2014
 *      Author: \author joda
 *  \brief :
 */
#ifndef SRC_SERVER_SHARED_DATABASES_DATABASE_H_
#define SRC_SERVER_SHARED_DATABASES_DATABASE_H_

#include <iostream>
#include <stdarg.h>
#include <vector>
#include "Utilities/Utilities.h"

class Database : public Utilities {
public:
	Database(){};
	virtual ~Database(){};

	virtual bool connection(std::string infoConnection) = 0;
	virtual bool deconnection() = 0;
	virtual void prepareStatement(std::string index, const char * sql) = 0;
	virtual Tokens executionPrepareStatement(std::string index,
			int idTransaction = 0, int nombreArgument = 0,
			va_list listOfArgument = 0) = 0;
	virtual int createTransaction() = 0;
	virtual void commit(int idTransaction) = 0;
};

#endif /* SRC_SERVER_SHARED_DATABASES_DATABASE_H_ */
