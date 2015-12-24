/*
 * \file DatabaseManager.cpp
 *
 *  Created on: \date 23 oct. 2014
 *      Author: \author joda
 *  \brief :
 */
#include "Manager/Databases/DatabaseManager.h"

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

bool DatabaseManager::connection(std::string infoConnection) {
	return database->connection(infoConnection);
}
bool DatabaseManager::deconnection() {
	return database->deconnection();
}
void DatabaseManager::prepareStatement(std::string index, const char * sql) {
	database->prepareStatement(index, sql);
}
bool DatabaseManager::executionPrepareStatement(std::string index, Tokens * resultat,
		int idTransaction, int nombreArgument, ...) {
	va_list listOfArgument;
	bool retour;

	va_start(listOfArgument, nombreArgument);
	retour = database->executionPrepareStatement(index, resultat, idTransaction, nombreArgument,
			listOfArgument);
	va_end(listOfArgument);
	return retour;
}
int DatabaseManager::createTransaction() {
	return database->createTransaction();
}
void DatabaseManager::commit(int idTransaction) {
	database->commit(idTransaction);
}