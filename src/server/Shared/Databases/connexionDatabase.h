/*
 * connexionDatabase.h
 *
 *  Created on: 29 juin 2012
 *      Author: mathieu
 */

#ifndef CONNEXIONDATABASE_H_
#define CONNEXIONDATABASE_H_

#include <pqxx/pqxx>

class connexionDatabase {
public:
	connexionDatabase();
	virtual ~connexionDatabase();

	void connexionDB();
	void deconnexionDB();
	void executionDB();
};

#endif /* CONNEXIONDATABASE_H_ */
