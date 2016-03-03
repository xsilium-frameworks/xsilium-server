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
    bool retour = true;
    if (database) {
        retour = database->deconnection();
    }

    return retour;

}
void DatabaseManager::prepareStatement(std::string index, const char * sql) {
    boost::mutex::scoped_lock lock(mutex1);
    database->prepareStatement(index, sql);
}
bool DatabaseManager::executionPrepareStatement(std::string index, Tokens * resultat,
        int idTransaction, int nombreArgument, ...) {
    boost::mutex::scoped_lock lock(mutex1);
    va_list listOfArgument;
    bool retour;

    va_start(listOfArgument, nombreArgument);
    retour = database->executionPrepareStatement(index, resultat, idTransaction, nombreArgument,
            listOfArgument);
    va_end(listOfArgument);
    return retour;
}
int DatabaseManager::createTransaction() {
    boost::mutex::scoped_lock lock(mutex1);
    return database->createTransaction();
}
void DatabaseManager::commit(int idTransaction) {
    boost::mutex::scoped_lock lock(mutex1);
    database->commit(idTransaction);
}
