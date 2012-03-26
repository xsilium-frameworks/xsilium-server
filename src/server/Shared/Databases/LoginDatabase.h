/*
 * LoginDatabase.h
 *
 *  Created on: 18 f�vr. 2012
 *      Author: joda2
 */

/*!
 * \file LoginDatabase.h
 * \brief Login Database
 * \author joda2
 *
 */

#ifndef LOGINDATABASE_H_
#define LOGINDATABASE_H_

#include "PostgreSQLInterface/PostgreSQLInterface.h"
#include "Structure/Server.h"

  /*! \class LoginDatabase
   * \brief
   *
   */

class LoginDatabase : public PostgreSQLInterface {
public:

    /*!
     *  \brief Constructeur
     *
     *  Constructeur de la classe LoginDatabase
     *
     *  \param
     */
	LoginDatabase();

    /*!
     *  \brief Destructeur
     *
     *  Destructeur de la classe LoginDatabase
     *
     *  \param
     */


	virtual ~LoginDatabase();

    /*!
     *  \brief selectAccount
     *
     *  Destructeur de la classe LoginDatabase
     *
     *  \param
     */


	bool selectAccount(const char *userName,sClient *client);

    /*!
     *  \brief getIPBan
     *
     *   Reception Ip bannis
     *
     *  \param
     */

	bool getIPBan(std::string *IP, bool *results);

    /*!
     *  \brief setIPBan
     *
     *   supprime l'Ip bannis dans la table ip_banned
     *
     *  \param
     */

	bool setIPBan();
};

#endif /* LOGINDATABASE_H_ */
