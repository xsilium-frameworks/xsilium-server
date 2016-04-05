/*
 * \file DatabaseManager.h
 *
 *  Created on: \date 23 oct. 2014
 *      Author: \author joda
 *  \brief :
 */
#ifndef SRC_SERVER_SHARED_DATABASES_DATABASEMANAGER_H_
#define SRC_SERVER_SHARED_DATABASES_DATABASEMANAGER_H_

#include <Manager/Databases/Postgresql/Postgresql.h>
#include <Singleton/Singleton.h>
#include <boost/thread.hpp>


enum ServerDB
{
	POSTGRESQL = 0
};


/*
 *
 */
class DatabaseManager : public Singleton<DatabaseManager> {

public:
	DatabaseManager();
	virtual ~DatabaseManager();

	void createServer(int choixServerDB);

	bool connection(std::string infoConnection);
	void deconnection();
	void prepareStatement(std::string index, const char * sql);
	void executionPrepareStatement(std::string index,Tokens * resultat, int idTransaction = 0,
			int nombreArgument = 0, ...);
	int createTransaction();
	void commit(int idTransaction);

private:

	boost::mutex mutex1 ;

	Database * database;


};

#endif /* SRC_SERVER_SHARED_DATABASES_DATABASEMANAGER_H_ */
