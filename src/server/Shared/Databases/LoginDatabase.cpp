/*
 * LoginDatabase.cpp
 *
 *  Created on: 18 f�vr. 2012
 *      Author: joda2
 */

#include "LoginDatabase.h"
// #include "SHA1.h"
#include <stdlib.h>
#include <sstream>


LoginDatabase::LoginDatabase() {

}

LoginDatabase::~LoginDatabase() {
}

void LoginDatabase::connexionDB(std::string infoString)
{
	connexionDatabase::connexionDB(infoString);

	connexionDatabase::suffix = "Login";

	//PrepareStatement(LOGIN_GET_REALMLIST, "SELECT id, name, address, port, icon, color, timezone, allowedSecurityLevel, population, gamebuild FROM realmlist WHERE color <> 3 ORDER BY name");
    connexionDatabase::PrepareStatement(LOGIN_SET_EXPIREDIPBANS, "DELETE FROM ip_banned WHERE unbandate<=now() AND unbandate<>bandate");
//    connexionDatabase::PrepareStatement(LOGIN_SET_EXPIREDACCBANS, "UPDATE account_banned SET active = false WHERE unbandate<=now() AND unbandate<>bandate");
    connexionDatabase::PrepareStatement(LOGIN_GET_IPBANNED, "SELECT * FROM ip_banned WHERE ip = $1");
//    connexionDatabase::PrepareStatement(LOGIN_SET_IPAUTOBANNED, "INSERT INTO ip_banned VALUES ($1, now(), now()+$2,'Xsilium Auth', 'Failed login autoban')");
    connexionDatabase::PrepareStatement(LOGIN_SET_ACCAUTOBANNED, "INSERT INTO account_banned VALUES ($1, now(), now() + INTERVAL  '20 minute', 'Xsilium Auth', 'Failed login autoban', true)");
    //PrepareStatement(LOGIN_SET_LOGONPROOF, "UPDATE account SET sessionkey = ?, last_ip = ?, last_login = NOW(), locale = ?, failed_logins = 0 WHERE username = ?");
    connexionDatabase::PrepareStatement(LOGIN_SET_FAILEDLOGINS, "UPDATE account SET failed_logins = $2 WHERE id = $1");
    connexionDatabase::PrepareStatement(LOGIN_GET_ACCBANNED, "SELECT unbandate FROM account_banned WHERE unbandate >now() and unbandate<>bandate AND active = true AND bandate <=now() AND id = $1");

    connexionDatabase::PrepareStatement(LOGIN_GET_ACCIDBYNAME, "SELECT a.sha_pass_hash,a.id,a.locked,a.last_ip,a.failed_logins FROM account a WHERE a.username = $1");
    //PrepareStatement(LOGIN_GET_NUMCHARSONREALM, "SELECT numchars FROM realmcharacters WHERE realmid = ? AND acctid= ?");

}
