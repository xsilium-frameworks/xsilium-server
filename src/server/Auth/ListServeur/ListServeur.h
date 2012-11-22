/*
 * \file ListServeur.h
 *
 *  Created on: \date 19 nov. 2012
 *      Author: \author joda
 *  \brief :
 */

#ifndef LISTSERVEUR_H_
#define LISTSERVEUR_H_

#include <string>
#include "time.h"
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
	ListServeur();
	virtual ~ListServeur();

	void Initialize(uint32_t updateInterval);
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
