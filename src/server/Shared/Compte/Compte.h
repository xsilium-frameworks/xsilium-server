/*
 * \file Compte.h
 *
 *  Created on: \date 11 juil. 2013
 *      Author: \author joda
 *  \brief :
 */

#ifndef COMPTE_H_
#define COMPTE_H_

#include <stdio.h>

#include "Databases/LoginDatabase.h"

/*
 *
 */
class Compte {
public:
	Compte();
	virtual ~Compte();

	bool chargementCompte(const char * nom);

	int getIdLogin();
	std::string * getNomCompte();
	std::string * getMDPSHA();

	void lockCompte();
	void unlockCompte();
	bool islocked();

	void setLastIP(std::string lastIP);
	std::string * getLastIP();

	uint8_t getNiveauCompte();

	void banCompte(time_t unbandate,const char * raison,int bannedby);
	void unbanCompte();
	bool isBanned();

	time_t * getAccountUnBanDate();

	void setEtapeConnexion(uint8_t etape );
	uint8_t getEtapeConnextion();

	void setNombreEssai(uint8_t essai);
	uint8_t getNombreEssai();







private:

    int idCompte; /*!< numero unique du compte dans la base de donn�e      */
    std::string nomDuCompte;
    std::string shaPassHash; /*!< Le mot de passe crypter */
    bool locked; /*!< Si le client lock sont compte sur l'ip*/
    uint8_t nbPassage; /*!<Le nombre d'essais que fait un clien */
    std::string lastIP; /*!< derniere IP du compte  */
    uint8_t gmlevel ; /*!<Niveau de MJ*/
    bool banned;
    time_t accountUnBanDate ; /*!<si le compte est bannie date de debanne du compte*/
    uint8_t	etapeDeConnexion;


    static ConnectionDatabase * connexionDatabase;



};

#endif /* COMPTE_H_ */
