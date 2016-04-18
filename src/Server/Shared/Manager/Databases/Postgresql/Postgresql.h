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
#include <Manager/Databases/Database.h>
#include <time.h>
#include <Manager/Databases/DatabaseException.h>

/*
 *
 */
class Postgresql: public Database {
public:
    Postgresql();
    virtual ~Postgresql();

    void connection(std::string infoConnection);
    void deconnection();
    void prepareStatement(std::string index, const char * sql);
    void executionPrepareStatement(std::string index, Tokens * resultat, int idTransaction = 0,
            int nombreArgument = 0, va_list listOfArgument = 0);
    int createTransaction();
    void commit(int idTransaction);

private:
    pqxx::lazyconnection * connexion;
    std::map<int, pqxx::work *> listOfTransaction;
    time_t timer;
    boost::mutex mutex1;

    void conversionRetour(pqxx::result resultat, Tokens * resultatToken);

};

#endif /* SRC_SERVER_SHARED_DATABASES_POSTGRESQL_POSTGRESQL_H_ */
