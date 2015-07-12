/*
 * AuthentificationManager.cpp
 *
 *  Created on: 11 juil. 2015
 *      Author: Skronak
 */

#include "AuthentificationManager.h"

namespace Auth {

AuthentificationManager::AuthentificationManager() {
	config = Configuration::getInstance();
	log = Log::getInstance();

}

AuthentificationManager::~AuthentificationManager() {
	// TODO Auto-generated destructor stub
}

//TODO have fun
bool AuthentificationManager::checkIp(std::string ip){

	IPBan ipBan(ip);
	IP ipTemp(ip);


	if(ipBan.read())
		return false;


	if(ipTemp.read())
		ipTemp.create();

	return true ;
}

Compte * AuthentificationManager::isAccountExist(std::string Username,std::string ip)
{
	Compte * compte = new Compte(Username);

	if(!compte->read())
	{
		banIP(ip);
		return 0;
	}

	return compte;
}

bool AuthentificationManager::checkAccount(int idAccount)
{
	CompteBan compteBan( idAccount);

	if(compteBan.read())
		return false;

	return true;

}

void AuthentificationManager::banIP(std::string ip)
{
	int nombreErreurMax,banTime;
	int idTransaction = 0;
	IP ipTemp(ip);
	IPBan ipBan(ip);

	ipTemp.read();
	ipTemp.setIpTempNessais(ipTemp.getIpTempNessais() + 1);

	config->get("nombreErreurMax",nombreErreurMax);
	config->get("banTime",banTime);

	if( ( ipTemp.getIpTempNessais() % nombreErreurMax ) == 0 )
	{

		idTransaction = DatabaseManager::getInstance()->createTransaction();

		ipBan.setBandate(time(NULL));
		ipBan.setUnbandate((time(NULL) + (banTime * (ipTemp.getIpTempNessais() / nombreErreurMax ))  *60));
		ipBan.setRaison("autoban");
		ipBan.setBannedby(0);
		ipBan.create(idTransaction);
	}
	ipTemp.update(idTransaction);
}

void AuthentificationManager::resetIpTemp(std::string ip)
{
	IP ipTemp(ip);
	ipTemp.read();
	ipTemp.setIpTempNessais(0);
	ipTemp.update();
}

} /* namespace Auth */
