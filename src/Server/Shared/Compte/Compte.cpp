/*
 * \file Compte.cpp
 *
 *  Created on: \date 29 déc. 2014
 *      Author: \author joda
 *  \brief :
 */
#include "Compte.h"

Compte::Compte(std::string nomString) {
	database = DatabaseManager::getInstance();

	idCompte = 0;
	shaPassHash = "";
	locked = false;
	banned = false;
	nbPassage = 0;
	lastIP = "";
	gmlevel = 0;
	accountUnBanDate = 0;
	etapeDeConnexion = 1;
	suffix = "Compte";

	database->prepareStatement(suffix + database->ToString(REALMS_UPD_ACCOUNTBANNED_DEBANAUTOCOMPTE),"UPDATE compte.account_banned SET active = false WHERE unbandate<=now() AND active=true");
	database->prepareStatement(suffix + database->ToString(REALMS_SEL_ACCOUNT_RECUPINFOSCOMPTE),"SELECT a.id_account,a.username,a.sha_pass_hash,a.locked,a.last_ip,a.failed_logins,b.active,b.unbandate FROM compte.account a left outer join compte.account_banned b on b.id_account_banned = a.id_account and b.unbandate > now() where a.username = $1 ");
	database->prepareStatement(suffix + database->ToString(REALMS_UPD_ACCOUNT_MAJLASTIP),"UPDATE compte.account SET last_ip = $2 WHERE id_account = $1");
	database->prepareStatement(suffix + database->ToString(REALMS_INS_ACCOUNTBANNED_AUTOBANCOMPTEAUTH),"INSERT INTO compte.account_banned VALUES (DEFAULT,$1,now(),to_timestamp($2), 'AutoBan erreur authentification', true,$3)");
	database->prepareStatement(suffix + database->ToString(REALMS_UPD_ACCOUNTBANNED_DEBANCOMPTE),"UPDATE compte.account_banned SET active = false WHERE id_account = $1");
	database->prepareStatement(suffix + database->ToString(REALMS_UPD_ACCOUNT_MAJERREURSAUTH),"UPDATE compte.account SET failed_logins = $2 WHERE id_account = $1");
	if (!nomString.empty())
		chargementCompte(nomString);
}

Compte::~Compte() {
	// TODO Auto-generated destructor stub
}

bool Compte::chargementCompte(std::string nomString)
{
	Tokens resultsqlT;

	database->executionPrepareStatement(suffix + database->ToString(REALMS_UPD_ACCOUNTBANNED_DEBANAUTOCOMPTE));

	resultsqlT = database->executionPrepareStatement(suffix + database->ToString(REALMS_SEL_ACCOUNT_RECUPINFOSCOMPTE),0,1,nomString.c_str());

	if(resultsqlT.empty())
	{
		return false;
	}
	else
	{
		Tokens resultatsql;

		resultatsql = database->strSplit( resultsqlT[0] ,";");

		idCompte = database->ToInt(resultatsql[0]);
		nomDuCompte = resultatsql[1];
		shaPassHash = resultatsql[2];
		locked = database->ToBool(resultatsql[3]);
		lastIP = resultatsql[4];
		nbPassage = database->ToInt(resultatsql[5]);


		if(!database->ToBool(resultatsql[6]))
			banned = false;
		else
			banned = true;

		if(resultatsql[7].compare("false") != 0)
		{
			struct tm tm;
			printf("Date de ban %s \n",resultatsql[7].c_str());
			strptime(resultatsql[7].c_str(), "%Y-%m-%d %H:%M:%S", &tm);
			accountUnBanDate = mktime(&tm);
		}

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
	database->executionPrepareStatement(suffix + database->ToString(REALMS_UPD_ACCOUNT_MAJLASTIP),0,2,idCompte,lastIP.c_str());

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
	database->executionPrepareStatement(suffix + database->ToString(REALMS_INS_ACCOUNTBANNED_AUTOBANCOMPTEAUTH),0,4,idCompte,database->ToString(unbandate).c_str(),raison,database->ToString(bannedby).c_str());
}
void Compte::unbanCompte()
{
	database->executionPrepareStatement(suffix + database->ToString(REALMS_UPD_ACCOUNTBANNED_DEBANCOMPTE),0,1,idCompte);
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
	database->executionPrepareStatement(suffix + database->ToString(REALMS_UPD_ACCOUNT_MAJERREURSAUTH),0,2,database->ToString(idCompte).c_str(),database->ToString((int)nbPassage).c_str());
}

uint8_t Compte::getNombreEssai()
{
	return nbPassage;
}
