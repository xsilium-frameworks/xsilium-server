/*
 * \file ListServeur.h
 *
 *  Created on: \date 19 nov. 2012
 *      Author: \author joda
 *  \brief :
 */
/*!
 * \file Authentification.h
 * \brief ListServeur
 * \author joda2
 *
 */


#ifndef LISTSERVEUR_H_
#define LISTSERVEUR_H_


#include "Serveur/Serveur.h"


#include <map>

typedef std::map<int,Serveur*> ListeServeur;


class ListServeur {
public:


    /*!
     *  \brief Constructeur
     *
     *  Constructeur de la classe ListServeur
     *	\param
     */

	ListServeur();

    /*!
     *  \brief Destructeur
     *
     *  Destructeur de la classe ListServeur
     *  \param
     */
	virtual ~ListServeur();

    /*!
     *  \brief Initialize
     *
     *  Reception du contenu de la table Realmlist
     *  \param
     */

	void Initialize(uint32_t updateInterval);

    /*!
     *  \brief UpdateIfNeed
     *
     *  Reception du contenu de la table Realmlist
     *  \param
     */

	void UpdateIfNeed();
	ListeServeur getListServeur();

	void loadServeur();


private:
    uint32_t   m_UpdateInterval;
    time_t   m_NextUpdateTime;
    LoginDatabase * realms ;

    ListeServeur ListOfServer;


	void UpdateRealms();

};

#endif /* LISTSERVEUR_H_ */
