/*
 * \file Postgresql.cpp
 *
 *  Created on: \date 20 oct. 2014
 *      Author: \author joda
 *  \brief :
 */
#include "Databases/Postgresql/Postgresql.h"

Postgresql::Postgresql() {
	connexion = NULL;
	timer = time(NULL);
}

Postgresql::~Postgresql() {
	delete connexion ;
}

bool Postgresql::connection(std::string infoConnection) {
	Tokens::iterator iter;
	std::string dataConnexion[5], connectionString;
	int increment = 0;

	Tokens tokens = strSplit(infoConnection, ";");

	iter = tokens.begin();

	while (iter != tokens.end() && increment < 5) {
		dataConnexion[increment] = *iter++;
		increment++;
	}

	if (increment != 5)
		return false;

	connectionString = "host=" + dataConnexion[0] + " port=" + dataConnexion[1]
																			 + " user=" + dataConnexion[2] + " password=" + dataConnexion[3]
																																		  + " dbname=" + dataConnexion[4];

	connexion = new pqxx::lazyconnection(connectionString.c_str());
	try {
		connexion->activate();
		return connexion->is_open();
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
		return false;
	}

}

bool Postgresql::deconnection() {

	try {

		if (connexion->is_open()) {
			connexion->disconnect();
			return true;
		}

	}
	catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
		return false;
	}
	return false;
}

void Postgresql::prepareStatement(std::string index, const char * sql) {
	boost::mutex::scoped_lock lock(mutex1);

	connexion->prepare(index.c_str(), sql);
}

bool Postgresql::executionPrepareStatement(std::string index,Tokens * resultat, int idTransaction,int nombreArgument,va_list listOfArgument) {
	boost::mutex::scoped_lock lock(mutex1);

	bool retour = true;
	char * argument;
	pqxx::work * txn;
	bool autoCommit = false;

	std::map<int, pqxx::work *>::iterator iter = listOfTransaction.find(
			idTransaction);
	if (iter == listOfTransaction.end()) {
		txn = new pqxx::work(*connexion);
		autoCommit = true;
	} else
		txn = iter->second;

	try {
		if (txn->prepared(index.c_str()).exists()) {
			pqxx::prepare::invocation invoc = txn->prepared(index.c_str());

			for (int increment = 0; increment < nombreArgument; increment++) {
				argument = va_arg(listOfArgument,char*);
				invoc(argument);
			}
			 conversionRetour(invoc.exec(),resultat);
		}

		if (autoCommit) {
			txn->commit();
		}
	}
	catch (const std::exception &e) {
		resultat->push_back(e.what());
		txn->abort();
		retour = false;
	}

	if (autoCommit) {
		delete txn;
	}

	return retour;
}

int Postgresql::createTransaction() {
	boost::mutex::scoped_lock lock(mutex1);

	int delta = time(NULL) - timer;

	listOfTransaction[delta] = new pqxx::work(*connexion);

	return delta;
}

void Postgresql::commit(int idTransaction) {
	boost::mutex::scoped_lock lock(mutex1);

	pqxx::work * txn;

	std::map<int, pqxx::work *>::iterator iter = listOfTransaction.find(
			idTransaction);
	if (iter != listOfTransaction.end()) {
		txn = iter->second;
		txn->commit();
		delete txn;
		listOfTransaction.erase(iter);
	}
	connexion->deactivate();
}

bool Postgresql::conversionRetour(pqxx::result resultat,Tokens * resultatToken) {

	for (pqxx::result::const_iterator row = resultat.begin();
			row != resultat.end(); ++row) {
		std::string ligneRetour;

		for (pqxx::tuple::const_iterator field = row->begin();
				field != row->end(); ++field) {
			if (!ligneRetour.empty())
				ligneRetour += ";";
			if(field.is_null())
				ligneRetour += "false";
			else
				ligneRetour += field->c_str();

		}
		resultatToken->push_back(ligneRetour);
	}
	return true;
}
