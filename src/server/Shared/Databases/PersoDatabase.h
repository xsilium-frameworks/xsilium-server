﻿/*
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

MAINSERVEUR_INS_TICKETRUBRIQUE_CREERUBRIQUE,
MAINSERVEUR_UPD_TICKETRUBRIQUE_SUPPRRUBRIQUE,
MAINSERVEUR_UPD_TICKETRUBRIQUE_REACTRUBRIQUE,
MAINSERVEUR_UPD_TICKETRUBRIQUE_MODNOM,
MAINSERVEUR_INS_TICKETSOUSRUBRIQUE1_CREESOUSRUBRIQUE1,
MAINSERVEUR_UPD_TICKETSOUSRUBRIQUE1_SUPPRSOUSRUBRIQUE1,
MAINSERVEUR_UPD_TICKETSOUSRUBRIQUE1_REACTSOUSRUBRIQUE1,
MAINSERVEUR_UPD_TICKETSOUSRUBRIQUE1_MODNOM,
MAINSERVEUR_UPD_TICKETSOUSRUBRIQUE1_MODRUBRIQUE,
MAINSERVEUR_INS_TICKETSOUSRUBRIQUE2_CREESOUSRUBRIQUE2,
MAINSERVEUR_UPD_TICKETSOUSRUBRIQUE2_SUPPRSOUSRUBRIQUE2,
MAINSERVEUR_UPD_TICKETSOUSRUBRIQUE2_REACTSOUSRUBRIQUE2,
MAINSERVEUR_UPD_TICKETSOUSRUBRIQUE2_MODNOM,
MAINSERVEUR_UPD_TICKETSOUSRUBRIQUE2_MODSOUSRUBRIQUE1,
MAINSERVEUR_INS_TICKETTYPEETAT_CREEETAT,
MAINSERVEUR_UPD_TICKETTYPEETAT_SUPPRETAT,
MAINSERVEUR_UPD_TICKETTYPEETAT_REACTETAT,
MAINSERVEUR_UPD_TICKETTYPEETAT_MODNOM,
MAINSERVEUR_INS_TICKET_CREETICKET,
MAINSERVEUR_SEL_TICKET_LISTETICKETS,
MAINSERVEUR_SEL_TICKET_LISTETICKETSEXPEDITEUR,
MAINSERVEUR_SEL_TICKET_DETAILSTICKET,
MAINSERVEUR_SEL_TICKET_LISTETICKETSRUBRIQUE,
MAINSERVEUR_SEL_TICKET_LISTETICKETSSOUSRUBRIQUE1,
MAINSERVEUR_SEL_TICKET_LISTETICKETSSOUSRUBRIQUE2,
MAINSERVEUR_UPD_TICKET_MAJTICKET,
MAINSERVEUR_UPD_TICKET_DEPLACETICKET,
MAINSERVEUR_DEL_TICKET_SUPPRTICKET,
MAINSERVEUR_SEL_TICKETRUBRIQUE_LISTERUBRIQUESACTIF,
MAINSERVEUR_SEL_TICKETRUBRIQUE_LISTERUBRIQUESSUPPR,
MAINSERVEUR_SEL_TICKETSOUSRUBRIQUE1_LISTESOUSRUBRIQUE1ACTIF,
MAINSERVEUR_SEL_TICKETSOUSRUBRIQUE1_LISTESOUSRUBRIQUE1SUPPR,
MAINSERVEUR_SEL_TICKETSOUSRUBRIQUE2_LISTESOUSRUBRIQUE2ACTIF,
MAINSERVEUR_SEL_TICKETSOUSRUBRIQUE2_LISTESOUSRUBRIQUE2SUPPR,

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
