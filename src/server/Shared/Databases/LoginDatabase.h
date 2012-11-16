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

#include "PostgreSQLInterface/connexionDatabase.h"
#include "Structure/Server.h"
#include "Singleton/Singleton.h"

enum LoginDatabaseStatements
{
    /*  Naming standard for defines:
        {DB}_{SET/DEL/ADD/REP}_{Summary of data changed}
        When updating more than one field, consider looking at the calling function
        name for a suiting suffix.
    */

    LOGIN_GET_REALMLIST,
    LOGIN_SET_EXPIREDIPBANS,
    LOGIN_SET_EXPIREDACCBANS,
    LOGIN_GET_IPBANNED,
    LOGIN_SET_IPAUTOBANNED,
    LOGIN_GET_ACCBANNED,
    LOGIN_SET_ACCAUTOBANNED,
    LOGIN_GET_SESSIONKEY,
    LOGIN_SET_VS,
    LOGIN_SET_LOGONPROOF,
    LOGIN_GET_LOGONCHALLENGE,
    LOGIN_SET_FAILEDLOGINS,
    LOGIN_GET_FAILEDLOGINS,
    LOGIN_GET_ACCIDBYNAME,
    LOGIN_GET_NUMCHARSONREALM,
    AJOUT_AVERTISSEMENT,
    MAJ_AVERTISSEMENTS,
    AUTO_BAN_AVERTO,
    DEBAN_COMPTE,
    LISTE_SERVER,
    MAJ_GM_LEVEL,
    DEBAN_IP,
    MAX_LOGINDATABASE_STATEMENTS
};




  /*! \class LoginDatabase
   * \brief
   *
   */

class LoginDatabase : public Singleton<LoginDatabase>, public connexionDatabase {

	friend class Singleton<LoginDatabase>;


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

	void connexionDB(std::string infoString);

private:


};

#endif /* LOGINDATABASE_H_ */
