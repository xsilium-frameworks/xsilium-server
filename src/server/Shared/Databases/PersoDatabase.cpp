/*
 * PersoDatabase.cpp
 *
 *  Created on: 25 avril. 2013
 *      Author: nico
 */
//Normalisation nom requete : {nom base}_{type requete}_{tableimpactee}_{resume requete}

#include "PersoDatabase.h"
// #include "SHA1.h"
#include <stdlib.h>
#include <sstream>


PersoDatabase::PersoDatabase() {

}

PersoDatabase::~PersoDatabase() {
}

void PersoDatabase::connexionDB(std::string infoString)
{
	connexionDatabase::connexionDB(infoString);

	connexionDatabase::suffix = "Perso";



