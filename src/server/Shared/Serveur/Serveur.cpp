/*
 * \file Serveur.cpp
 *
 *  Created on: \date 8 mars 2014
 *      Author: \author joda
 *  \brief :
 */

#include "Serveur.h"

Serveur::Serveur(uint32_t IDServeur) {
	m_ID = IDServeur;
	address = '';
	port = 0;
	name = '';
	allowedSecurityLevel = 0;
	NBJoueur = 0;
	version = '';
	online = false;

	realms = LoginDatabase::getInstance();
}

bool Serveur::ChargementServeur()
{
	pqxx::result resultsql;

	resultsql = realms->executionPrepareStatement(REALMS_SEL_LISTESERVEUR_RECUPSERVEUR,1,ToString(m_ID).c_str());

	if(resultsql.empty())
	{
		return false;
	}

	name = resultsql[0][0].as<std::string>();
	address = resultsql[0][1].as<std::string>();
	port = resultsql[0][2].as<int>();
	allowedSecurityLevel = resultsql[0][3].as<int>();
	NBJoueur = resultsql[0][4].as<int>();
	version = resultsql[0][5].as<std::string>() ;
	online = resultsql[0][6].as<bool>() ;

	return true;
}

Serveur::~Serveur() {
	// TODO Auto-generated destructor stub
}

void Serveur::setAddress(std::string address)
{
	this->address = address;

}
std::string Serveur::getAddress()
{
	return this->address;
}

void Serveur::setPort(uint32_t port)
{
	this->port = port;
}
uint32_t Serveur::getPort()
{
	return this->port;
}

void Serveur::setName(std::string name)
{
	this->name = name;
}
std::string Serveur::getName()
{
	return this->name;
}

uint32_t Serveur::getID()
{
	return this->m_ID;
}

void Serveur::setSecurity(uint8_t SecurityLevel)
{
	this->allowedSecurityLevel = SecurityLevel;
}
uint8_t Serveur::getSecurity()
{
	return this->allowedSecurityLevel;
}

void Serveur::setNBJoueur(uint32_t NBJoueur)
{
	this->NBJoueur = NBJoueur ;
}
uint32_t Serveur::getNBJoueur()
{
	return this->NBJoueur;
}

void Serveur::setVersion(std::string version)
{
	this->version = version ;
}
std::string Serveur::getVersion()
{
	return this->version;
}
