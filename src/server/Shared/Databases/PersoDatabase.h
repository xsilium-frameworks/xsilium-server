/*
 * PersoDatabase.h
 *
 *  Created on: 25 avril. 2013
 *      Author: nico
 */

/*!
 * \file GPersoDatabase.h
 * \brief Login Database
 * \author joda2
 *
 */

#ifndef LOGINDATABASE_H_
#define LOGINDATABASE_H_

#include "PostgreSQLInterface/connexionDatabase.h"
#include "Structure/Server.h"
#include "Singleton/Singleton.h"

enum LoginDatabaseStatements
{
    /*  Naming standard for defines:
        {DB}_{SEL/INS/UPD/DEL}_{table}_{Summary of data changed}
        When updating more than one field, consider looking at the calling function
        name for a suiting suffix.
    */


};


  /*! \class LoginDatabase
   * \brief
   *
   */

class PersoDatabase : public Singleton<PersoDatabase>, public connexionDatabase {

	friend class Singleton<PersoDatabase>;


public:

	/*!
	 *  \brief Constructeur
     *
	 *  Constructeur de la classe LoginDatabase
     *
     *  \param
     */
	PersoDatabase();

    /*!
     *  \brief Destructeur
     *
     *  Destructeur de la classe LoginDatabase
     *
     *  \param
     */


	virtual ~PersoDatabase();

	void connexionDB(std::string infoString);

private:


};

#endif /* LOGINDATABASE_H_ */
