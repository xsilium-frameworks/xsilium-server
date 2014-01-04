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


#include <map>
#include "Databases/LoginDatabase.h"

struct Serveur
{
    std::string address;
    uint32_t port;
    std::string name;
    uint32_t m_ID;
    uint8_t allowedSecurityLevel;
    uint32_t NBJoueur;
    std::string version;
};
typedef std::map<std::string, Serveur> ListeServeur;


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


private:
	ListeServeur listeServeur;
    uint32_t   m_UpdateInterval;
    time_t   m_NextUpdateTime;
    LoginDatabase * realms ;


	void UpdateRealms();
	void UpdateRealm(uint32_t ID, const std::string& name, const std::string& address, uint32_t port, uint8_t allowedSecurityLevel, uint32_t population, const std::string& build);

};

#endif /* LISTSERVEUR_H_ */
