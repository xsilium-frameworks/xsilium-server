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
void DatabaseManager::deconnection() {
    if (database) {
        database->deconnection();
    }
}
void DatabaseManager::prepareStatement(std::string index, const char * sql) {
    boost::mutex::scoped_lock lock(mutex1);
    database->prepareStatement(index, sql);
}
void DatabaseManager::executionPrepareStatement(std::string index, Tokens * resultat,
        int idTransaction, int nombreArgument, ...) {
    boost::mutex::scoped_lock lock(mutex1);
    va_list listOfArgument;

    va_start(listOfArgument, nombreArgument);
    database->executionPrepareStatement(index, resultat, idTransaction, nombreArgument,
            listOfArgument);
    va_end(listOfArgument);
}
int DatabaseManager::createTransaction() {
    boost::mutex::scoped_lock lock(mutex1);
    return database->createTransaction();
}
void DatabaseManager::commit(int idTransaction) {
    boost::mutex::scoped_lock lock(mutex1);
    database->commit(idTransaction);
}
