/*
 * \file Compte.cpp
 *
 *  Created on: \date 11 juil. 2013
 *      Author: \author joda
 *  \brief :
 */

#include "Compte.h"

Compte::Compte() {

	realms = LoginDatabase::getInstance();

	idCompte = 0;
	shaPassHash = "";
	locked = false;
	banned = false;
	nbPassage = 0;
	lastIP = "";
	gmlevel = 0;
	accountUnBanDate = 0;
	etapeDeConnexion = 1;

}

Compte::~Compte() {
}

bool Compte::chargementCompte(const char * nom)
{
	pqxx::result resultsql;
	std::string nomString(nom);

	realms->executionPrepareStatement(REALMS_UPD_ACCOUNTBANNED_DEBANAUTOCOMPTE);

	resultsql = realms->executionPrepareStatement(REALMS_SEL_ACCOUNT_RECUPINFOSCOMPTE,1,nomString.c_str());

	if(resultsql.empty())
	{
		return false;
	}

	idCompte = resultsql[0][0].as<int>();
	nomDuCompte = resultsql[0][1].as<std::string>();
	shaPassHash = resultsql[0][2].as<std::string>();
	locked = resultsql[0][3].as<bool>();
	lastIP = resultsql[0][4].as<std::string>();
	nbPassage = resultsql[0][5].as<int>();

	if(resultsql[0][6].is_null())
		banned = false;
	else
		banned = true;

	if(!resultsql[0][7].is_null())
	{
		struct tm tm;
		printf("%s \n",resultsql[0][7].as<std::string>().c_str());
		strptime((resultsql[0][7].as<std::string>()).c_str(), "%Y-%m-%d %H:%M:%S", &tm);
		accountUnBanDate = mktime(&tm);
	}
	return true;
}

int Compte::getIdLogin()
{
	return idCompte;
}
std::string * Compte::getNomCompte()
{
	return &nomDuCompte;
}
std::string * Compte::getMDPSHA()
{
	return &shaPassHash;
}

void Compte::lockCompte()
{
	locked = true;
}
void Compte::unlockCompte()
{
	locked = false;
}
bool Compte::islocked()
{
	return locked;
}

void Compte::setLastIP(std::string lastIP)
{
	this->lastIP = lastIP;
	realms->executionPrepareStatement(REALMS_UPD_ACCOUNT_MAJLASTIP,2,idCompte,lastIP.c_str());

}
std::string * Compte::getLastIP()
{
	return &lastIP;
}

uint8_t Compte::getNiveauCompte()
{
	return gmlevel;
}

void Compte::banCompte(time_t unbandate,const char * raison,int bannedby)
{
	banned = true;
	this->accountUnBanDate = unbandate;
	realms->executionPrepareStatement(REALMS_INS_ACCOUNTBANNED_AUTOBANCOMPTEAUTH,4,idCompte,ToString(unbandate).c_str(),raison,ToString(bannedby).c_str());
}
void Compte::unbanCompte()
{
	realms->executionPrepareStatement(REALMS_UPD_ACCOUNTBANNED_DEBANCOMPTE,1,idCompte);
	banned = false;
}
bool Compte::isBanned()
{
	return banned;
}

void Compte::setEtapeConnexion(uint8_t etape )
{
	etapeDeConnexion = etape;

}
uint8_t Compte::getEtapeConnextion()
{
	return etapeDeConnexion;
}
time_t * Compte::getAccountUnBanDate()
{
	return &accountUnBanDate;
}

void Compte::setNombreEssai(uint8_t essai)
{
	pqxx::result resultsql;
	nbPassage = essai;
	realms->executionPrepareStatement(REALMS_UPD_ACCOUNT_MAJERREURSAUTH,2,ToString(idCompte).c_str(),ToString(nbPassage).c_str());
}

uint8_t Compte::getNombreEssai()
{
	return nbPassage;
}


