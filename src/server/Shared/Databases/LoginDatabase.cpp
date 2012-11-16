/*
 * LoginDatabase.cpp
 *
 *  Created on: 18 fevrier. 2012
 *      Author: joda2
 */
// Derniere maj par nico le 16-11-2012

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


//requete qui met a jour la table des bans ip lorsque la date de ban est passee -- Nico le 13-11-2012
	connexionDatabase::PrepareStatement(LOGIN_SET_EXPIREDIPBANS, "Update ip_banned set ban_actif=false WHERE unbandate<=now() AND ban_actif=true");
 //connexionDatabase::PrepareStatement(LOGIN_SET_EXPIREDIPBANS, "DELETE FROM ip_banned WHERE unbandate<=now() AND unbandate<>bandate");

//requete qui deban automatiquement l'account apres une date de deban passee --Nico - le 16-11-2012
    connexionDatabase::PrepareStatement(LOGIN_SET_EXPIREDACCBANS, "UPDATE account_banned SET active = false WHERE unbandate<=now() AND active=true");


// requete qui va chercher les infos sur l'ip dans la table ip_banned
	connexionDatabase::PrepareStatement(LOGIN_GET_IPBANNED, "SELECT * FROM ip_banned WHERE ip = $1");


//requete d'autoban apres erreur d'authentification -- Nico le 13-11-2012 modifiee le 15-11-2012 pour erreur de variables
connexionDatabase::PrepareStatement(LOGIN_SET_ACCAUTOBANNED, "INSERT INTO account_banned VALUES (now(), now() + INTERVAL  '20 minute', 'AutoBan erreur authentification', true, $1, $2)");

//connexionDatabase::PrepareStatement(LOGIN_SET_ACCAUTOBANNED, "INSERT INTO account_banned VALUES ($1, now(), now() + INTERVAL  '20 minute', 'AutoBan erreur authentification', 'Xsilium Auth', 1)");
//    connexionDatabase::PrepareStatement(LOGIN_SET_IPAUTOBANNED, "INSERT INTO ip_banned VALUES ($1, now(), now()+$2,'Xsilium Auth', 'Failed login autoban')");
//connexionDatabase::PrepareStatement(LOGIN_SET_ACCAUTOBANNED, "INSERT INTO account_banned VALUES ($1, now(), now() + INTERVAL  '20 minute', 'Xsilium Auth', 'Failed login autoban', true)");


    //PrepareStatement(LOGIN_SET_LOGONPROOF, "UPDATE account SET sessionkey = ?, last_ip = ?, last_login = NOW(), locale = ?, failed_logins = 0 WHERE username = ?");


//Requete de mise a jour du nombre d'erreurs d'authentification -- nico - le 13-11-2012
	connexionDatabase::PrepareStatement(LOGIN_SET_FAILEDLOGINS, "UPDATE account SET failed_logins = $2 WHERE util_numero = $1");
 //connexionDatabase::PrepareStatement(LOGIN_SET_FAILEDLOGINS, "UPDATE account SET failed_logins = $2 WHERE id = $1");


//a voir cette requete --nico - le 13-11-2012
    connexionDatabase::PrepareStatement(LOGIN_GET_ACCBANNED, "SELECT unbandate FROM account_banned WHERE unbandate >now() and unbandate<>bandate AND active = true AND bandate <=now() AND id = $1");


//requete qui recupere les infos en fonction du username --nico le 13-11-2012
 connexionDatabase::PrepareStatement(LOGIN_GET_ACCIDBYNAME, "SELECT sha_pass_hash,util_numero,locked,last_ip,failed_logins FROM account WHERE username = $1");
// connexionDatabase::PrepareStatement(LOGIN_GET_ACCIDBYNAME, "SELECT a.sha_pass_hash,a.id,a.locked,a.last_ip,a.failed_logins FROM account a WHERE a.username = $1");


    //PrepareStatement(LOGIN_GET_NUMCHARSONREALM, "SELECT numchars FROM realmcharacters WHERE realmid = ? AND acctid= ?");

//requete d'ajout d'avertissement sur un compte -- Nico le 15-11-2012
connexionDatabase::PrepareStatement(AJOUT_AVERTISSEMENT, "INSERT INTO Avertissements VALUES ($1, $2, $3, now())");

//requete de mise a jour du nombre d'avertissements sur un compte -- Nico le 15-11-2012
connexionDatabase::PrepareStatement(MAJ_AVERTISSEMENTS, "UPDATE account SET N_avertissements = $2 WHERE util_numero = $1");

//requete auto_ban pour nombre d'avertissements --Nico le 15-11-2012
connexionDatabase::PrepareStatement(AUTO_BAN_AVERTO,"INSERT INTO account_banned  VALUES (now(), '9999-12-31 00:00:00.000000', 'AutoBan pour avertissement ', true, $1, $2)");

//requete deban d'un compte --Nico le 15-11-2012
connexionDatabase::PrepareStatement(DEBAN_COMPTE, "UPDATE account_banned SET active = false WHERE id_user_ban = $1");

//requete listing des infos de la liste des serveurs --Nico le 15-11-2012
connexionDatabase::PrepareStatement(LISTE_SERVER, "SELECT * FROM Liste_serveur");

//requete mise a jour du gm_level d'un compte --nico le 15-11-2012
connexionDatabase::PrepareStatement(MAJ_GM_LEVEL, "UPDATE account_access SET gmlevel = $2 WHERE id_user = $1");

//requete deban d'une ip --Nico le 15-11-2012
connexionDatabase::PrepareStatement(DEBAN_IP, "UPDATE ip_banned SET ban_actif = false WHERE ip = $1");

//requete de ban auto d'une ip --Nico le 16-11-2012
connexionDatabase::PrepareStatement(REALMS_INS_BANIP_BANAUTOIP,"INSERT INTO ip_banned VALUES ($1, now(), now() + INTERVAL  '20 minute', 'AutoBan pour erreur authentification ', $2, true)");

}
