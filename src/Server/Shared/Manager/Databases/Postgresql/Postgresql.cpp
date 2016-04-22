/*
 * \file Postgresql.cpp
 *
 *  Created on: \date 20 oct. 2014
 *      Author: \author joda
 *  \brief :
 */
#include "Manager/Databases/Postgresql/Postgresql.h"

Postgresql::Postgresql() {
    connexion = NULL;
    timer = time(NULL);
}

Postgresql::~Postgresql() {
    delete connexion;
}

void Postgresql::connection(std::string infoConnection) {
    Tokens::iterator iter;
    std::string dataConnexion[5], connectionString;
    int increment = 0;

    Tokens tokens = strSplit(infoConnection, ";");

    iter = tokens.begin();

    while (iter != tokens.end() && increment < 5) {
        dataConnexion[increment] = *iter++;
        increment++;
    }

    if (increment != 5) {
        throw new DatabaseException("Mauvais nombre d'arguments");
    }

    connectionString = "host=" + dataConnexion[0] + " port=" + dataConnexion[1] + " user="
            + dataConnexion[2] + " password=" + dataConnexion[3] + " dbname=" + dataConnexion[4];

    connexion = new pqxx::lazyconnection(connectionString.c_str());

    connexion->activate();
}

void Postgresql::deconnection() {

    try {

        if (connexion->is_open()) {
            connexion->disconnect();
        }

    } catch (const pqxx::pqxx_exception &e) {
        std::cerr << e.base().what() << std::endl;
        throw new DatabaseException(e.base());
    }
}

void Postgresql::prepareStatement(std::string index, const char * sql) {
    boost::mutex::scoped_lock lock(mutex1);

    connexion->prepare(index.c_str(), sql);
}

void Postgresql::executionPrepareStatement(std::string index, Tokens * resultat, int idTransaction,
        int nombreArgument, va_list listOfArgument) {
    boost::mutex::scoped_lock lock(mutex1);

    pqxx::work * txn;
    bool autoCommit = false;

    std::map<int, pqxx::work *>::iterator iter = listOfTransaction.find(idTransaction);
    if (iter == listOfTransaction.end()) {
        txn = new pqxx::work(*connexion);
        autoCommit = true;
    } else
        txn = iter->second;

    try {
        if (txn->prepared(index.c_str()).exists()) {
            txn->exec("SET client_encoding = LATIN9");
            pqxx::prepare::invocation invoc = txn->prepared(index.c_str());

            for (int increment = 0; increment < nombreArgument; increment++) {
                invoc (va_arg(listOfArgument, char*));}
            conversionRetour(invoc.exec(), resultat);
        }

        if (autoCommit) {
            txn->commit();
            delete txn;
        }
    } catch (const pqxx::pqxx_exception &e) {
        txn->abort();
        delete txn;
        std::cerr << e.base().what() << std::endl;
        throw new DatabaseException(e.base());
    }
}

int Postgresql::createTransaction() {
    boost::mutex::scoped_lock lock(mutex1);

    int delta = time(NULL) - timer;

    listOfTransaction[delta] = new pqxx::work(*connexion);

    return delta;
}

void Postgresql::commit(int idTransaction) {
    boost::mutex::scoped_lock lock(mutex1);

    std::map<int, pqxx::work *>::iterator iter = listOfTransaction.find(idTransaction);
    if (iter != listOfTransaction.end()) {
        pqxx::work * txn = iter->second;
        txn->commit();
        delete txn;
        listOfTransaction.erase(iter);
    }
    connexion->deactivate();
}

void Postgresql::conversionRetour(pqxx::result resultat, Tokens * resultatToken) {

    for (pqxx::result::const_iterator row = resultat.begin(); row != resultat.end(); ++row) {
        std::string ligneRetour;

        for (pqxx::tuple::const_iterator field = row->begin(); field != row->end(); ++field) {
            if (!ligneRetour.empty())
                ligneRetour += ";";
            if (field.is_null())
                ligneRetour += "false";
            else
                ligneRetour += field->c_str();

        }
        resultatToken->push_back(ligneRetour);
    }
}
