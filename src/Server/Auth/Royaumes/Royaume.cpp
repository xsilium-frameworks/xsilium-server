/*
 * \file Royaume.cpp
 *
 *  Created on: \date 21 févr. 2015
 *      Author: \author joda
 *  \brief :
 */
#include "Royaume.h"

Royaume::Royaume(int idRoyaume) {
	suffix = "Royaume";
	this->idRoyaume = idRoyaume;
	keyRoyaume = "";
	nameRoyaume = "";
	urlRoyaume = "";
	portRoyaume = 0;
	autorisationRoyaume = 0;
	versionClientRoyaume = 0;
	online_royaume = 0;

	database->prepareStatement(suffix + database->ToString(REALMS_SEL_LISTESROYAUMES),
			"SELECT key_royaume,name_royaume,url_royaume,port_royaume,autorisation_royaume,version_client_royaume,online_royaume FROM royaumes.liste_royaume where id_royaume = $1");
	database->prepareStatement(suffix + database->ToString(REALMS_UPD_LISTESROYAUMES),"UPDATE royaumes.liste_royaume SET "
			"keyRoyaume = $2,nameRoyaume=$3,urlRoyaume = $4,portRoyaume=$5,autorisationRoyaume=$6,versionClientRoyaume=$7,online_royaume = $8 WHERE idRoyaume = $1");
	database->prepareStatement(suffix + database->ToString(REALMS_INS_LISTESROYAUMES),"INSERT INTO royaumes.liste_royaume VALUES (DEFAULT,$1,$2,$3,$4,$5,$6,$7)");
	database->prepareStatement(suffix + database->ToString(REALMS_DEL_LISTESROYAUMES),"DELETE FROM royaumes.liste_royaume WHERE id_royaume = $1");


}

Royaume::~Royaume() {
	// TODO Auto-generated destructor stub
}

bool Royaume::create(int idTransaction)
{
	bool retour;
	Tokens tokens;
	retour = database->executionPrepareStatement(suffix + database->ToString(REALMS_INS_LISTESROYAUMES),&tokens,idTransaction,7,keyRoyaume.c_str(),nameRoyaume.c_str(),urlRoyaume.c_str(),database->ToString(portRoyaume).c_str(),database->ToString(autorisationRoyaume).c_str(),database->ToString(versionClientRoyaume).c_str(),database->ToString(online_royaume).c_str());
	retour = read();
	return retour;
}
bool Royaume::read(int idTransaction)
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

		keyRoyaume = resultatsql[0];
		nameRoyaume = resultatsql[1];
		urlRoyaume = resultatsql[2];
		portRoyaume = database->ToInt(resultatsql[3]);
		autorisationRoyaume = database->ToInt(resultatsql[4]);
		versionClientRoyaume = database->ToInt(resultatsql[5]);
		online_royaume = database->ToBool(resultatsql[6]);

		retour = true ;

	}

	return retour ;

}
bool Royaume::update(int idTransaction)
{
	Tokens resultsqlT;
	return database->executionPrepareStatement(suffix + database->ToString(REALMS_UPD_LISTESROYAUMES),&resultsqlT,idTransaction,8,database->ToString(idRoyaume).c_str(),keyRoyaume.c_str(),nameRoyaume.c_str(),urlRoyaume.c_str(),database->ToString(portRoyaume).c_str(),database->ToString(autorisationRoyaume).c_str(),database->ToString(versionClientRoyaume).c_str(),database->ToString(online_royaume).c_str());

}
bool Royaume::suppr(int idTransaction)
{
	Tokens resultsqlT;
	return  database->executionPrepareStatement(suffix + database->ToString(REALMS_DEL_LISTESROYAUMES),&resultsqlT,idTransaction,1,database->ToString(idRoyaume).c_str());

}

int Royaume::getAutorisationRoyaume() {
	return autorisationRoyaume;
}

void Royaume::setAutorisationRoyaume(int autorisationRoyaume) {
	this->autorisationRoyaume = autorisationRoyaume;
}

int Royaume::getIdRoyaume()  {
	return idRoyaume;
}

const std::string& Royaume::getKeyRoyaume()  {
	return keyRoyaume;
}

void Royaume::setKeyRoyaume( std::string& keyRoyaume) {
	this->keyRoyaume = keyRoyaume;
}

const std::string& Royaume::getNameRoyaume()  {
	return nameRoyaume;
}

void Royaume::setNameRoyaume( std::string& nameRoyaume) {
	this->nameRoyaume = nameRoyaume;
}

bool Royaume::isOnlineRoyaume() {
	return online_royaume;
}

void Royaume::setOnlineRoyaume(bool onlineRoyaume) {
	online_royaume = onlineRoyaume;
}

int Royaume::getPortRoyaume() {
	return portRoyaume;
}

void Royaume::setPortRoyaume(int portRoyaume) {
	this->portRoyaume = portRoyaume;
}

const std::string& Royaume::getUrlRoyaume() {
	return urlRoyaume;
}

void Royaume::setUrlRoyaume(std::string& urlRoyaume) {
	this->urlRoyaume = urlRoyaume;
}

int Royaume::getVersionClientRoyaume() {
	return versionClientRoyaume;
}

void Royaume::setVersionClientRoyaume(int versionClientRoyaume) {
	this->versionClientRoyaume = versionClientRoyaume;
}

std::string Royaume::ToExport()
{
	return urlRoyaume +";" + database->ToString(portRoyaume) + ";" + nameRoyaume + database->ToString(online_royaume) ;
}

