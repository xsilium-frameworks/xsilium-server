/*
 * connexionDatabase.h
 *
 *  Created on: 29 juin 2012
 *      Author: mathieu
 */

#ifndef CONNEXIONDATABASE_H_
#define CONNEXIONDATABASE_H_

#include <pqxx/pqxx>
#include "Utilities/Utils.h"
#include <pthread.h>
#include <iostream>
#include <stdarg.h>

class connexionDatabase {

public:

	/*!
	 *  \brief connexionDatabase
	 *
	 *  brief Constructeur
	 *
	 *  \param
	 */

	connexionDatabase();

	/*!
	 *  \brief ~connexionDatabase
	 *
	 *  brief Destructeur de la classe
	 *
	 *  \param
	 */
	virtual ~connexionDatabase();

	/*!
	 *  \brief connexionDB
	 *
	 *  brief Permet de ce connectera la DB souhaitee
	 *
	 *  \param
	 */
	void connexionDB(std::string infoString);


	/*!
	 *  \brief deconnexionDB
	 *
	 *  brief Ferme la connexion a la DB
	 *
	 *  \param
	 */
	void deconnexionDB();

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
	pqxx::result executionPrepareStatement(int index,int nombreArgument = 0,...);

protected:
	Utils utils;
	pqxx::lazyconnection * conn;
	pqxx::work * txn;
	pthread_mutex_t mutex1;
	std::string suffix;

};

template <typename T>
  std::string ToString ( T variable )
  {
     std::ostringstream ss;

     ss << variable;

     return ss.str();
  }

#endif /* CONNEXIONDATABASE_H_ */
