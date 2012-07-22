/*
 * connexionDatabase.cpp
 *
 *  Created on: 29 juin 2012
 *      Author: mathieu
 */

#include "connexionDatabase.h"



connexionDatabase::connexionDatabase() {
	//mutex1 = PTHREAD_MUTEX_INITIALIZER;

}

connexionDatabase::~connexionDatabase() {
}

void connexionDatabase::connexionDB(std::string infoString)
{

	//if (!conn->is_open())
	//{
		pthread_mutex_lock( &mutex1 );
		Tokens tokens = utils.StrSplit(infoString, ";");
		Tokens::iterator iter;
		std::string host, port_or_socket, user, password , database ,connectionString ;
		char const* unix_socket;

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
		pthread_mutex_unlock( &mutex1 );
	//}





}

void connexionDatabase::deconnexionDB()
{
	conn->deactivate();
}


void connexionDatabase::PrepareStatement(int index, const char* sql)
{
	pthread_mutex_lock( &mutex1 );

	std::ostringstream oss;
	oss << index;
	std::string indexDB = suffix + oss.str() ;

	conn->prepare(indexDB.c_str(), sql);
    pthread_mutex_unlock( &mutex1 );

}

pqxx::result connexionDatabase::executionPrepareStatement(int index,int nombreArgument,...)
{
	pthread_mutex_lock( &mutex1 );

	std::ostringstream oss;
	oss << index;
	std::string indexDB = suffix + oss.str() ;

	pqxx::result resultat;
	char * argument;
	txn = new pqxx::work(*conn);
	va_list  listOfArgument;
	va_start(listOfArgument, nombreArgument);
	try{
		conn->activate();
		if(txn->prepared(indexDB.c_str()).exists())
		{
			pqxx::prepare::invocation invoc =  txn->prepared(indexDB.c_str());

			for (int i = 0 ;i < nombreArgument ; i++ )
			{
				argument = va_arg(listOfArgument,char*);
				invoc(argument);
			}
			resultat = invoc.exec();
		}
		txn->commit();
		conn->deactivate();
	}
    catch (const std::exception &e)
       {
         std::cerr << e.what() << std::endl;
       }
	va_end(listOfArgument);
    delete txn;
    pthread_mutex_unlock( &mutex1 );
    return resultat;

}
