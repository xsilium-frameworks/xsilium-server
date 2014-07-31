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

	loadServeur();
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

void ListServeur::loadServeur()
{
	pqxx::result resultsql;
	resultsql = realms->executionPrepareStatement(REALMS_SEL_LISTESERVEUR_RECUPLISTESERVEUR);

	if (!resultsql.empty())
	{
		for (int rownum=0; rownum < resultsql.size(); ++rownum)
		{
			Serveur * serveur = new Serveur(resultsql[rownum][0].as<int>());
			ListOfServer[rownum] = serveur;
		}
	}
}

void ListServeur::UpdateRealms()
{
	pqxx::result resultsql;
	std::map<int,Serveur*>::iterator it;


	resultsql = realms->executionPrepareStatement(REALMS_SEL_LISTESERVEUR_UPDATESERVEUR);
	if (!resultsql.empty())
	{
		for (int rownum=0; rownum < resultsql.size(); ++rownum)
		{
			it = ListOfServer.find(rownum);
			if (it != ListOfServer.end() )
			{
				it->second->ChargementServeur();
			}
			else
			{
				Serveur * serveur = new Serveur(resultsql[rownum][0].as<int>());
				ListOfServer[rownum] = serveur;
			}
		}

	}
}

ListeServeur ListServeur::getListServeur()
{
	return ListOfServer;
}
