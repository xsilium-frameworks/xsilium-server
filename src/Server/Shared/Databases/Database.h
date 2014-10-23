/*
 * \file Database.h
 *
 *  Created on: \date 20 oct. 2014
 *      Author: \author joda
 *  \brief :
 */
#ifndef SRC_SERVER_SHARED_DATABASES_DATABASE_H_
#define SRC_SERVER_SHARED_DATABASES_DATABASE_H_

#include <string>
#include <iostream>
#include <stdarg.h>
#include <vector>

typedef std::vector<std::string> Tokens;

class Database {
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

	Tokens strSplit(const std::string &src, const std::string &sep) {
		Tokens r;
		std::string s;
		for (std::string::const_iterator i = src.begin(); i != src.end(); ++i) {
			if (sep.find(*i) != std::string::npos) {
				if (s.length())
					r.push_back(s);
				s = "";
			} else {
				s += *i;
			}
		}
		if (s.length())
			r.push_back(s);
		return r;
	}
	;
};

#endif /* SRC_SERVER_SHARED_DATABASES_DATABASE_H_ */
