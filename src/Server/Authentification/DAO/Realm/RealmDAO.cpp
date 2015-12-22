/*
 * RealmDAO.cpp
 *
 *  Created on: 11 juil. 2015
 *      Author: Skronak
 */

#include "RealmDAO.h"

namespace Auth {

RealmDAO::RealmDAO(std::string nameRoyaume) {
	suffix = "Royaume";
	this->nameRoyaume = nameRoyaume;
	idRoyaume = 0;
	keyRoyaume = "";

	urlRoyaume = "";
	portRoyaume = 0;
	autorisationRoyaume = 0;
	versionClientRoyaume = 0;
	online_royaume = 0;

	database->prepareStatement(suffix + database->ToString(REALMS_SEL_LISTESROYAUMES),
			"SELECT id_royaume,key_royaume,url_royaume,port_royaume,autorisation_royaume,version_client_royaume,online_royaume FROM royaumes.liste_royaume where name_royaume = $1");
	database->prepareStatement(suffix + database->ToString(REALMS_UPD_LISTESROYAUMES),"UPDATE royaumes.liste_royaume SET "
			"keyRoyaume = $2,nameRoyaume=$3,urlRoyaume = $4,portRoyaume=$5,autorisationRoyaume=$6,versionClientRoyaume=$7,online_royaume = $8 WHERE idRoyaume = $1");
	database->prepareStatement(suffix + database->ToString(REALMS_INS_LISTESROYAUMES),"INSERT INTO royaumes.liste_royaume VALUES (DEFAULT,$1,$2,$3,$4,$5,$6,$7)");
	database->prepareStatement(suffix + database->ToString(REALMS_DEL_LISTESROYAUMES),"DELETE FROM royaumes.liste_royaume WHERE id_royaume = $1");


}

RealmDAO::~RealmDAO() {
	// TODO Auto-generated destructor stub
}

bool RealmDAO::create(int idTransaction)
{
	bool retour;
	Tokens tokens;
	retour = database->executionPrepareStatement(suffix + database->ToString(REALMS_INS_LISTESROYAUMES),&tokens,idTransaction,7,keyRoyaume.c_str(),nameRoyaume.c_str(),urlRoyaume.c_str(),database->ToString(portRoyaume).c_str(),database->ToString(autorisationRoyaume).c_str(),database->ToString(versionClientRoyaume).c_str(),database->ToString(online_royaume).c_str());
	retour = read();
	return retour;
}
bool RealmDAO::read(int idTransaction)
{
	bool retour ;
	Tokens resultsqlT;

	retour = database->executionPrepareStatement(suffix + database->ToString(REALMS_SEL_LISTESROYAUMES),&resultsqlT,idTransaction,1,database->ToString(idRoyaume).c_str());

	if(resultsqlT.empty())
	{
		retour = false ;
	}
	else
	{
		Tokens resultatsql;
		resultatsql = database->strSplit( resultsqlT[0] ,";");

		nameRoyaume = resultatsql[0];
		keyRoyaume = resultatsql[1];
		urlRoyaume = resultatsql[2];
		portRoyaume = database->ToInt(resultatsql[3]);
		autorisationRoyaume = database->ToInt(resultatsql[4]);
		versionClientRoyaume = database->ToInt(resultatsql[5]);
		online_royaume = database->ToBool(resultatsql[6]);

		retour = true ;

	}

	return retour ;

}
bool RealmDAO::update(int idTransaction)
{
	Tokens resultsqlT;
	return database->executionPrepareStatement(suffix + database->ToString(REALMS_UPD_LISTESROYAUMES),&resultsqlT,idTransaction,8,database->ToString(idRoyaume).c_str(),keyRoyaume.c_str(),nameRoyaume.c_str(),urlRoyaume.c_str(),database->ToString(portRoyaume).c_str(),database->ToString(autorisationRoyaume).c_str(),database->ToString(versionClientRoyaume).c_str(),database->ToString(online_royaume).c_str());

}
bool RealmDAO::suppr(int idTransaction)
{
	Tokens resultsqlT;
	return  database->executionPrepareStatement(suffix + database->ToString(REALMS_DEL_LISTESROYAUMES),&resultsqlT,idTransaction,1,database->ToString(idRoyaume).c_str());

}

int RealmDAO::getAutorisationRoyaume()  {
	return autorisationRoyaume;
}

void RealmDAO::setAutorisationRoyaume(int autorisationRoyaume) {
	this->autorisationRoyaume = autorisationRoyaume;
}

int RealmDAO::getIdRoyaume()  {
	return idRoyaume;
}

void RealmDAO::setIdRoyaume(int idRoyaume) {
	this->idRoyaume = idRoyaume;
}

std::string RealmDAO::getKeyRoyaume()  {
	return keyRoyaume;
}

void RealmDAO::setKeyRoyaume( std::string keyRoyaume) {
	this->keyRoyaume = keyRoyaume;
}

std::string RealmDAO::getNameRoyaume()  {
	return nameRoyaume;
}

void RealmDAO::setNameRoyaume( std::string nameRoyaume) {
	this->nameRoyaume = nameRoyaume;
}

bool RealmDAO::isOnlineRoyaume()  {
	return online_royaume;
}

void RealmDAO::setOnlineRoyaume(bool onlineRoyaume) {
	online_royaume = onlineRoyaume;
}

int RealmDAO::getPortRoyaume()  {
	return portRoyaume;
}

void RealmDAO::setPortRoyaume(int portRoyaume) {
	this->portRoyaume = portRoyaume;
}

std::string RealmDAO::getUrlRoyaume()  {
	return urlRoyaume;
}

void RealmDAO::setUrlRoyaume( std::string urlRoyaume) {
	this->urlRoyaume = urlRoyaume;
}

int RealmDAO::getVersionClientRoyaume()  {
	return versionClientRoyaume;
}

void RealmDAO::setVersionClientRoyaume(int versionClientRoyaume) {
	this->versionClientRoyaume = versionClientRoyaume;
}

} /* namespace Auth */
