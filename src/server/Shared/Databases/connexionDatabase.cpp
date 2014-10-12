/*
 * connexionDatabase.cpp
 *
 *  Created on: 29 juin 2012
 *      Author: mathieu
 */

#include "connexionDatabase.h"



ConnexionDatabase::ConnexionDatabase() {
	conn = NULL;
}

ConnexionDatabase::~ConnexionDatabase() {
	delete conn;
}

void ConnexionDatabase::ConnexionDB(std::string infoString)
{

	//if (!conn->is_open())
	//{
	    boost::mutex::scoped_lock lock(mutex1);
		Tokens tokens = utils.StrSplit(infoString, ";");
		Tokens::iterator iter;
		std::string host, port_or_socket, user, password , database ,connectionString ;

		iter = tokens.begin();

		if (iter != tokens.end())
			host = *iter++;
		if (iter != tokens.end())
			port_or_socket = *iter++;
		if (iter != tokens.end())
			user = *iter++;
		if (iter != tokens.end())
			password = *iter++;
	    if (iter != tokens.end())
	        database = *iter++;

		connectionString = "host=" + host + " port=" + port_or_socket + " user=" + user + " password=" + password + " dbname=" + database;
		conn = new pqxx::lazyconnection(connectionString.c_str());
	//}





}

void ConnexionDatabase::DeconnexionDB()
{
	conn->deactivate();
}


void ConnexionDatabase::PrepareStatement(int index, const char* sql)
{
	boost::mutex::scoped_lock lock(mutex1);

	std::ostringstream oss;
	oss << index;
	std::string indexDB = suffix + oss.str() ;

	conn->prepare(indexDB.c_str(), sql);

}

pqxx::result ConnexionDatabase::ExecutionPrepareStatement(int index,pqxx::work * transaction,int nombreArgument,...)
{
	bool autoCommit;
	boost::mutex::scoped_lock lock(mutex1);

	std::ostringstream oss;
	oss << index;
	std::string indexDB = suffix + oss.str() ;

	pqxx::result resultat;
	char * argument;

	if(transaction == NULL)
	{
		transaction = new pqxx::work(*conn);
		autoCommit = true;
	}
	va_list  listOfArgument;
	va_start(listOfArgument, nombreArgument);
	try{
		conn->activate();
		if(transaction->prepared(indexDB.c_str()).exists())
		{
			pqxx::prepare::invocation invoc =  transaction->prepared(indexDB.c_str());

			for (int i = 0 ;i < nombreArgument ; i++ )
			{
				argument = va_arg(listOfArgument,char*);
				invoc(argument);
			}
			resultat = invoc.exec();
			if(autoCommit)
				transaction->commit();
		}

		conn->deactivate();
	}
    catch (const std::exception &e)
       {
    	txn->abort();
         std::cerr << e.what() << std::endl;
       }
	va_end(listOfArgument);

	if(autoCommit)
		delete transaction;

    return resultat;

}
