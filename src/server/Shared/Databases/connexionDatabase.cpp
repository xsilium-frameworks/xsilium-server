/*
 * connexionDatabase.cpp
 *
 *  Created on: 29 juin 2012
 *      Author: mathieu
 */

#include "connexionDatabase.h"
#include <pqxx/pqxx>


connexionDatabase::connexionDatabase( ) {
	// TODO Auto-generated constructor stub

}

connexionDatabase::~connexionDatabase() {
	// TODO Auto-generated destructor stub
}

connexionDatabase::connexionDB()
{
	pqxx::connection c("dbname=company user=accounting");
	pqxx::work txn(c);
}

connexionDatabase::connexionDB()
{
	pqxx::connectionpolicy::do_disconnect();
}

connexionDatabase::executionDB();
{
	PGresult *PQexecParams(PGconn *conn,
	                       const char *command,
	                       int nParams,
	                       const Oid *paramTypes,
	                       const char * const *paramValues,
	                       const int *paramLengths,
	                       const int *paramFormats,
	                       int resultFormat);
}
