/*
 * ConnexionDatabase.h
 *
 *  Created on: 29 juin 2012
 *      Author: mathieu
 */

#ifndef CONNEXIONDATABASE_H_
#define CONNEXIONDATABASE_H_

#include <pqxx/pqxx>
#include "Utilities/Utils.h"
#include <boost/thread.hpp>
#include <iostream>
#include <stdarg.h>

class ConnexionDatabase {

public:

	/*!
	 *  \briefCconnexionDatabase
	 *
	 *  brief Constructeur
	 *
	 *  \param
	 */

	ConnexionDatabase();

	/*!
	 *  \brief ~ConnexionDatabase
	 *
	 *  brief Destructeur de la classe
	 *
	 *  \param
	 */
	virtual ~ConnexionDatabase();

	/*!
	 *  \brief connexionDB
	 *
	 *  brief Permet de ce connectera la DB souhaitee
	 *
	 *  \param
	 */
	void ConnexionDB(std::string infoString);


	/*!
	 *  \brief deconnexionDB
	 *
	 *  brief Ferme la connexion a la DB
	 *
	 *  \param
	 */
	void DeconnexionDB();

	/*!
	 *  \brief PrepareStatement
	 *
	 *  brief ??
	 *
	 *  \param
	 */
	void PrepareStatement(int index, const char* sql);

	/*!
	 *  \brief executionPrepareStatement
	 *
	 *  brief ??
	 *
	 *  \param
	 */
	pqxx::result ExecutionPrepareStatement(int index,pqxx::work * transaction = NULL, int nombreArgument = 0,...);

protected:
	Utils utils;
	pqxx::lazyconnection * conn;
	boost::mutex mutex1;
	std::string suffix;

};

#endif /* CONNEXIONDATABASE_H_ */
