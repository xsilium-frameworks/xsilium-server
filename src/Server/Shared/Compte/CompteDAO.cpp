/*
 * CompteManager.cpp
 *
 *  Created on: 6 oct. 2015
 *      Author: joda
 */

#include "CompteDAO.h"

CompteDAO::CompteDAO() {
	suffix = "Compte";

	database->prepareStatement(suffix + database->ToString(REALMS_SEL_ACCOUNT),"SELECT id_account,sha_pass_hash,email,joindate,last_ip,locked,last_login,online,locale FROM compte.account where username = $1 ");
	database->prepareStatement(suffix + database->ToString(REALMS_UPD_ACCOUNT),"UPDATE compte.account SET sha_pass_hash = $2,email=$3,joindate = to_timestamp($4),last_ip = $5,locked = $6,last_login = to_timestamp($7),online = $8,locale = $9 WHERE id_account = $1");
	database->prepareStatement(suffix + database->ToString(REALMS_INS_ACCOUNT),"INSERT INTO compte.account VALUES (DEFAULT,$1,$2,$3,to_timestamp($4),$5,$6,to_timestamp($7),$8,$9)");
	database->prepareStatement(suffix + database->ToString(REALMS_DEL_ACCOUNT),"DELETE FROM compte.account WHERE id_account = $1");

}

CompteDAO::~CompteDAO() {
	// TODO Auto-generated destructor stub
}

bool CompteDAO::createCompte(Compte * compte)
{
	bool retour;
	Tokens tokens;
	retour = database->executionPrepareStatement(
			suffix + database->ToString(REALMS_INS_ACCOUNT),
			&tokens,
			idTransaction,
			9,
			username.c_str(),
			sha_pass_hash.c_str(),
			email.c_str(),
			database->ToString(joindate).c_str(),
			last_ip.c_str(),
			database->ToString(locked).c_str(),
			database->ToString(last_login).c_str(),
			database->ToString(online).c_str(),
			database->ToString(locale).c_str());
	return retour;
}
void CompteDAO::updateCompte()
{

}
Compte * CompteDAO::readCompte()
{

}
void CompteDAO::deleteCompte(Compte * compte)
{

}
