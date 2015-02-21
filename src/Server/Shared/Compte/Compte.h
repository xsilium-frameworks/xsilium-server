/*
 * \file Compte.h
 *
 *  Created on: \date 29 déc. 2014
 *      Author: \author joda
 *  \brief :
 */
#ifndef SRC_SERVER_SHARED_COMPTE_COMPTE_H_
#define SRC_SERVER_SHARED_COMPTE_COMPTE_H_

#include <Databases/DatabaseManager.h>

/*
 *
 */

enum CompteDatabaseStatements {
	REALMS_UPD_ACCOUNTBANNED_DEBANAUTOCOMPTE,
	REALMS_SEL_ACCOUNT_RECUPINFOSCOMPTE,
	REALMS_UPD_ACCOUNT_MAJLASTIP,
	REALMS_INS_ACCOUNTBANNED_AUTOBANCOMPTEAUTH,
	REALMS_UPD_ACCOUNTBANNED_DEBANCOMPTE,
	REALMS_UPD_ACCOUNT_MAJERREURSAUTH
};

class Compte {
public:
	Compte(std::string nomString = "");
	virtual ~Compte();

	bool chargementCompte(std::string nomString);

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

	std::string suffix;

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

	DatabaseManager * database;

};

#endif /* SRC_SERVER_SHARED_COMPTE_COMPTE_H_ */
