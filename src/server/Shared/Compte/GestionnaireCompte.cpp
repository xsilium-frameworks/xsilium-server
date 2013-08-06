/*
 * \file GestionnaireCompte.cpp
 *
 *  Created on: \date 27 juil. 2013
 *      Author: \author joda
 *  \brief :
 */

#include "GestionnaireCompte.h"

GestionnaireCompte::GestionnaireCompte() {
	log = Log::getInstance();

}

GestionnaireCompte::~GestionnaireCompte() {
	// TODO Auto-generated destructor stub
}

Compte * GestionnaireCompte::trouverCompte(const char * nomCompte)
{
	boost::mutex::scoped_lock lock(mutexCompte);
	for (compte=listOfCompte.begin() ; compte!=listOfCompte.end() ; ++compte)
	{
		if( strcmp((*compte)->getNomCompte()->c_str(),nomCompte) == 0)
		{
			log->Write(Log::INFO,"Le compte avec le nom %s a ete trouve ",nomCompte);
			return (*compte);
		}

	}
	log->Write(Log::INFO,"Le compte avec le nom %s n'a pas ete trouve ",nomCompte);
	return NULL;
}

bool GestionnaireCompte::creerCompte(const char * nomCompte)
{
	bool createCompte;
	Compte * compteTemp = new Compte();
	createCompte = compteTemp->chargementCompte(nomCompte);
	if(createCompte)
	{
		boost::mutex::scoped_lock lock(mutexCompte);
		log->Write(Log::INFO,"Creation du compte %s",nomCompte);
		listOfCompte.push_back(compteTemp);
	}
	return createCompte;
}

void GestionnaireCompte::supprimerCompte(const char * nomCompte)
{
	if( trouverCompte(nomCompte) != NULL)
	{
		boost::mutex::scoped_lock lock(mutexCompte);
		log->Write(Log::INFO,"Suppression du compte : %s ",nomCompte);
		delete *compte;
		compte = listOfCompte.erase(compte);
	}
}
