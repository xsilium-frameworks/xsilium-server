/*
 * \file ListServeur.cpp
 *
 *  Created on: \date 19 nov. 2012
 *      Author: \author joda
 *  \brief :
 */

#include "ListServeur.h"

ListServeur::ListServeur() {
	realms = LoginDatabase::getInstance();
	m_UpdateInterval = 0;
	m_NextUpdateTime = time(NULL);
}

ListServeur::~ListServeur() {
	// TODO Auto-generated destructor stub
}

void ListServeur::Initialize(uint32_t updateInterval)
{
    m_UpdateInterval = updateInterval;
    ///- Get the content of the realmlist table in the database
    UpdateRealms();
}

void ListServeur::UpdateIfNeed()
{
    // maybe disabled or updated recently
    if (!m_UpdateInterval || m_NextUpdateTime > time(NULL))
        return;

    m_NextUpdateTime = time(NULL) + m_UpdateInterval;

    // Get the content of the realmlist table in the database
    UpdateRealms();
}

/*void ListServeur::UpdateRealm(uint32_t ID, const std::string& name, const std::string& address, uint32_t port, uint8_t allowedSecurityLevel, uint32_t population, const std::string& build)
{
    ///- Create new if not exist or update existed
	Serveur& serveur = listeServeur[name];

	serveur.m_ID = ID;
	serveur.address	=	address;
	serveur.port = port;
	serveur.allowedSecurityLevel = allowedSecurityLevel;
	serveur.NBJoueur = population ;
	serveur.version = build;

}*/

void ListServeur::UpdateRealms()
{
	pqxx::result resultsql;
	resultsql = realms->executionPrepareStatement(REALMS_SEL_LISTESERVEUR_RECUPLISTESERVEUR);

    if (!resultsql.empty())
    {
    	for (int rownum=0; rownum < resultsql.size(); ++rownum)
    	 {

    		//UpdateRealm(resultsql[rownum][0].as<int>(),resultsql[rownum][1].as<std::string>(),resultsql[rownum][2].as<std::string>(),resultsql[rownum][3].as<int>(),resultsql[rownum][4].as<int>(),resultsql[rownum][5].as<int>(),resultsql[rownum][5].as<std::string>());
    	 }
    }
}

ListeServeur ListServeur::getListServeur()
{
	return listeServeur;
}
