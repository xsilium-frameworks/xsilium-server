/*
 * \file Royaume.cpp
 *
 *  Created on: \date 21 févr. 2015
 *      Author: \author joda
 *  \brief :
 */
#include "Royaume.h"

Royaume::Royaume(int idRoyaume) {
	database = DatabaseManager::getInstance();

	suffix = "Royaume";
	this->idRoyaume = idRoyaume;
	keyRoyaume = "";
	nameRoyaume = "";
	urlRoyaume = "";
	portRoyaume = 0;
	autorisationRoyaume = 0;
	versionClientRoyaume = 0;
	online_royaume = 0;

	database->prepareStatement(suffix + database->ToString(REALMS_SEL_LISTESROYAUMES_RECUPINFO),
			"SELECT key_royaume,name_royaume,url_royaume,port_royaume,autorisation_royaume,version_client_royaume,online_royaume FROM royaumes.liste_royaume where id_royaume = $1");

	loadRoyaume();


}

Royaume::~Royaume() {
	// TODO Auto-generated destructor stub
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

bool Royaume::create(int idTransaction)
{

	return true;
}
bool Royaume::read(int idTransaction)
{
	Tokens resultsqlT;

	resultsqlT = database->executionPrepareStatement(suffix + database->ToString(REALMS_SEL_LISTESROYAUMES_RECUPINFO),0,1,database->ToString(idRoyaume).c_str());

	if(resultsqlT.empty())
	{
		return ;
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


	}
}
bool Royaume::update(int idTransaction)
{
	return true;
}
bool Royaume::suppr(int idTransaction)
{
	return true;
}

std::string Royaume::ToExport()
{
	return urlRoyaume +";" + database->ToString(portRoyaume) + ";" + nameRoyaume + database->ToString(online_royaume) ;
}

std::vector<int> Royaume::getListeRoyaume()
{
	Tokens resultsqlT;
	std::vector<int> listeID;
	DatabaseManager::getInstance()->prepareStatement("Royaumes" + DatabaseManager::getInstance()->ToString(REALMS_SEL_LISTESROYAUMES_RECUPID),
			"SELECT id_royaume FROM royaumes.liste_royaume");

	resultsqlT = DatabaseManager::getInstance()->executionPrepareStatement("Royaumes" + DatabaseManager::getInstance()->ToString(REALMS_SEL_LISTESROYAUMES_RECUPID),0);

	if(resultsqlT.empty())
		{

			return listeID;
		}
		else
		{
			for (int i = 0;i < resultsqlT.size();i++)
			{
				listeID.push_back(DatabaseManager::getInstance()->ToInt(resultsqlT[i]));
			}
			return listeID;
		}


}

