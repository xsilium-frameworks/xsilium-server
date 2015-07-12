/*
 * RealmManager.cpp
 *
 *  Created on: 11 juil. 2015
 *      Author: Skronak
 */

#include "RealmManager.h"

namespace Auth {

RealmManager::RealmManager() {
	configuration = Configuration::getInstance();
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

int RealmManager::checkRealmName(std::string nameRealm)
{
	RealmDAO realmDao(nameRealm);
	if (realmDao.read()) {
		return realmDao.getIdRoyaume();
	} else {
		return 0;
	}
}

bool RealmManager::checkRealmKey(std::string realmKey)
{
	std::string configKey;

	configuration->get("realmKey",configKey);

	if (configKey.compare(realmKey) != 0) {
		return false;
	} else {
		return true;
	}
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
