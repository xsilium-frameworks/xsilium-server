/*
 * \file DatabaseManager.cpp
 *
 *  Created on: \date 23 oct. 2014
 *      Author: \author joda
 *  \brief :
 */
#include "../../../Server/Shared/Databases/DatabaseManager.h"

DatabaseManager::DatabaseManager() {
	database = 0;
}

DatabaseManager::~DatabaseManager() {
	if (database)
		delete database;
}

void DatabaseManager::createServer(int choixServerDB) {
	switch (choixServerDB) {
	case POSTGRESQL:
		database = new Postgresql();
		break;
	default:
		break;
	}
}

bool DatabaseManager::connection(std::string infoConnection)
{
	return database->connection(infoConnection);
}
bool DatabaseManager::deconnection()
{
	return database->deconnection();
}
void DatabaseManager::prepareStatement(std::string index, const char * sql)
{
	database->prepareStatement(index,sql);
}
Tokens DatabaseManager::executionPrepareStatement(std::string index, int idTransaction,
		int nombreArgument, ...)
{
	va_list listOfArgument;
	Tokens tokens;

	va_start(listOfArgument,nombreArgument);
	tokens = database->executionPrepareStatement(index,idTransaction,nombreArgument,listOfArgument);
	va_end(listOfArgument);
	return tokens;
}
int DatabaseManager::createTransaction()
{
	return database->createTransaction();
}
void DatabaseManager::commit(int idTransaction)
{
	database->commit(idTransaction);
}
