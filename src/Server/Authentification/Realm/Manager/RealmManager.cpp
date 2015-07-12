/*
 * RealmManager.cpp
 *
 *  Created on: 11 juil. 2015
 *      Author: Skronak
 */

#include "RealmManager.h"

namespace Auth {

RealmManager::RealmManager() {
	// TODO Auto-generated constructor stub

}

RealmManager::~RealmManager() {
	// TODO Auto-generated destructor stub
}


void RealmManager::createRealm()
{

}
void RealmManager::updateRealm()
{

}

std::vector<std::string> RealmManager::getRealmsList()
{
	std::vector<std::string> retour;
	std::vector<RealmDAO *>::iterator it;


	for (it=listRoyaume.begin(); it!=listRoyaume.end(); ++it)
	{
		if(*it != NULL)
		{
			retour.push_back((*it)->getUrlRoyaume());
		}
		else
			listRoyaume.erase(it);

	}
	return retour;
}


} /* namespace Auth */
