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
#include <map>
#include <time.h>

#include <Databases/Database.h>

/*
 *
 */
class Postgresql: public Database {
public:
	Postgresql();
	virtual ~Postgresql();

	bool connection(std::string infoConnection);
	bool deconnection();
	void prepareStatement(std::string index,const char * sql);
	bool executionPrepareStatement(std::string index,Tokens * resultat, int idTransaction = 0,int nombreArgument = 0,va_list listOfArgument = 0);
	int  createTransaction();
	void commit(int idTransaction);

private:
	pqxx::lazyconnection * connexion;
	std::map<int,pqxx::work *> listOfTransaction;
	time_t timer;
	boost::mutex mutex1;

	bool conversionRetour(pqxx::result resultat,Tokens * resultatToken);



};

#endif /* SRC_SERVER_SHARED_DATABASES_POSTGRESQL_POSTGRESQL_H_ */
