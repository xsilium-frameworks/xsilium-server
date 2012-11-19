/*
 * LoginDatabase.cpp
 *
 *  Created on: 18 fevrier. 2012
 *      Author: joda2
 */
// Derniere maj par nico le 18-11-2012
//Normalisation nom requete : {nom base}_{type requete}_{tableimpactee}_{resume requete}

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
    connexionDatabase::PrepareStatement(REALMS_UPD_IPBANNED_DEBANAUTOIP, "Update ip_banned set \"Ban_actif\"=false WHERE \"unbandate\"<=now() AND \"Ban_actif\"=true");
    //connexionDatabase::PrepareStatement(REALMS_UPD_IPBANNED_DEBANAUTOIP, "Update ip_banned set Ban_actif=false WHERE unbandate<=now() AND Ban_actif=true");
    //connexionDatabase::PrepareStatement(LOGIN_SET_EXPIREDIPBANS, "DELETE FROM ip_banned WHERE unbandate<=now() AND unbandate<>bandate");

//requete qui deban automatiquement l'account apres une date de deban passee --Nico - le 16-11-2012
    connexionDatabase::PrepareStatement(REALMS_UPD_ACCOUNTBANNED_DEBANAUTOCOMPTE, "UPDATE account_banned SET \"active\" = false WHERE \"unbandate\"<=now() AND \"active\"=true");


// requete qui va chercher les infos sur l'ip dans la table ip_banned
	connexionDatabase::PrepareStatement(REALMS_SEL_IPBANNED_INFOSSURIPBANNIES, "SELECT * FROM ip_banned WHERE \"ip\" = $1");


//requete d'autoban apres erreur d'authentification -- Nico le 13-11-2012 modifiee le 15-11-2012 pour erreur de variables
connexionDatabase::PrepareStatement(REALMS_INS_ACCOUNTBANNED_AUTOBANCOMPTEAUTH, "INSERT INTO account_banned VALUES (DEFAULT, now(), now() + INTERVAL  '20 minute', 'AutoBan erreur authentification', true, $1, $2)");
//connexionDatabase::PrepareStatement(LOGIN_SET_ACCAUTOBANNED, "INSERT INTO account_banned VALUES ($1, now(), now() + INTERVAL  '20 minute', 'AutoBan erreur authentification', 'Xsilium Auth', 1)");
//    connexionDatabase::PrepareStatement(LOGIN_SET_IPAUTOBANNED, "INSERT INTO ip_banned VALUES ($1, now(), now()+$2,'Xsilium Auth', 'Failed login autoban')");
//connexionDatabase::PrepareStatement(LOGIN_SET_ACCAUTOBANNED, "INSERT INTO account_banned VALUES ($1, now(), now() + INTERVAL  '20 minute', 'Xsilium Auth', 'Failed login autoban', true)");


    //PrepareStatement(LOGIN_SET_LOGONPROOF, "UPDATE account SET sessionkey = ?, last_ip = ?, last_login = NOW(), locale = ?, failed_logins = 0 WHERE username = ?");


//Requete de mise a jour du nombre d'erreurs d'authentification -- nico - le 13-11-2012
	connexionDatabase::PrepareStatement(REALMS_UPD_ACCOUNT_MAJERREURSAUTH, "UPDATE account SET \"failed_logins\" = $2 WHERE \"Util_numero\" = $1");
 //connexionDatabase::PrepareStatement(LOGIN_SET_FAILEDLOGINS, "UPDATE account SET failed_logins = $2 WHERE id = $1");


//requete qui donne la date de fin de bannissement d'un compte donc le ban est actif --nico - le 13-11-2012
    connexionDatabase::PrepareStatement(REALMS_SEL_ACCOUNTBANNED_RECUPDATEFINBANCOMPTE, "SELECT \"unbandate\" FROM account_banned WHERE \"active\" = true AND \"bandate\" <=now() AND \"id_user_ban\" = $1");
    //connexionDatabase::PrepareStatement(LOGIN_GET_ACCBANNED, "SELECT unbandate FROM account_banned WHERE unbandate >now() and unbandate<>bandate AND active = true AND bandate <=now() AND id = $1");


//requete qui recupere les infos en fonction du username --nico le 13-11-2012
     connexionDatabase::PrepareStatement(REALMS_SEL_ACCOUNT_RECUPINFOSCOMPTE, "SELECT \"sha_pass_hash\",\"Util_numero\",\"locked\",\"last_ip\",\"failed_logins\" FROM account WHERE \"username\" = $1");
    // connexionDatabase::PrepareStatement(LOGIN_GET_ACCIDBYNAME, "SELECT a.sha_pass_hash,a.id,a.locked,a.last_ip,a.failed_logins FROM account a WHERE a.username = $1");


    //PrepareStatement(LOGIN_GET_NUMCHARSONREALM, "SELECT numchars FROM realmcharacters WHERE realmid = ? AND acctid= ?");

//requete d'ajout d'avertissement sur un compte -- Nico le 15-11-2012
connexionDatabase::PrepareStatement(REALMS_INS_AVERTISSEMENTS_AJOUTAVERTISSEMENTS, "INSERT INTO avertissements VALUES (DEFAULT, $1, $2, $3, now())");

//requete de mise a jour du nombre d'avertissements sur un compte -- Nico le 15-11-2012
connexionDatabase::PrepareStatement(REALMS_UPD_ACCOUNT_MAJAVERTISSEMENTSCOMPTE, "UPDATE account SET \"N_avertissements\" = $2 WHERE \"util_numero\" = $1");

//requete auto_ban pour nombre d'avertissements --Nico le 15-11-2012
connexionDatabase::PrepareStatement(REALMS_INS_ACCOUNTBANNED_AUTOBANCOMPTEPOURAVERTISSEMENTS,"INSERT INTO account_banned VALUES (DEFAULT, now(), '9999-12-31 00:00:00.000000', 'AutoBan pour avertissement ', true, $1, $2)");

//requete deban d'un compte --Nico le 15-11-2012
connexionDatabase::PrepareStatement(REALMS_UPD_ACCOUNTBANNED_DEBANCOMPTE, "UPDATE account_banned SET \"active\" = false WHERE \"id_user_ban\" = $1");

//requete listing des infos de la liste des serveurs --Nico le 15-11-2012
connexionDatabase::PrepareStatement(REALMS_SEL_LISTESERVEUR_RECUPLISTESERVEUR, "SELECT \"id_serveur\", \"serveur_nom_serveur\", \"serveur_domain_name\", \"serveur_port\", \"serveur_level_requis\", \"serveur_n_online\", \"serveur_version_client_mini\", \"serveur_serveur_online\" FROM liste_serveur");

//requete mise a jour du gm_level d'un compte --nico le 15-11-2012
connexionDatabase::PrepareStatement(REALMS_UPD_ACCOUNTACCESS_MAJGMLEVELCOMPTE, "UPDATE account_access SET \"gmlevel\" = $2 WHERE \"id_user\" = $1");

//requete deban d'une ip --Nico le 15-11-2012
connexionDatabase::PrepareStatement(REALMS_UPD_IPBANNED_DEBANIP, "UPDATE ip_banned SET \"ban_actif\" = false WHERE \"ip\" = $1");

//requete de ban auto d'une ip --Nico le 16-11-2012
connexionDatabase::PrepareStatement(REALMS_INS_BANIP_BANAUTOIP,"INSERT INTO ip_banned VALUES ($1, now(), now() + INTERVAL  '20 minute', 'AutoBan pour erreur authentification ', DEFAULT, $2, true)");

//requete qui met a jour le nombre de comptes online sur un serveur --nico le 17-11-2012
connexionDatabase::PrepareStatement(REALMS_UPD_LISTESERVEUR_MAJCOMPTEONLINE,"UPDATE liste_serveur SET \"serveur_n_online\" = $1 WHERE \"id_serveur\" = $2");

//requete qui cree un nouveau serveur --nico le 17-11-2012
connexionDatabase::PrepareStatement(REALMS_INS_LISTESERVEUR_CREATIONSERVEUR,"INSERT INTO liste_serveur VALUES (DEFAULT, $1, $2, $3, $4, '0', $5, DEFAULT)");

//requete qui ban un compte --nico le 17-11-2012
connexionDatabase::PrepareStatement(REALMS_INS_ACCOUNTBANNED_BANCOMPTE,"INSERT INTO account_banned VALUES (DEFAULT, $1, $2, $3, true, $4, $5)");

//requete qui ban une ip --nico le 17-11-2012
connexionDatabase::PrepareStatement(REALMS_INS_IPBANNED_BANIP,"INSERT INTO ip_banned VALUES ($1, $2, $3, $4, DEFAULT, $5, true)");

//requete qui passe le compte online a la connexion, remet le failed login à zero, loggue son ip de connexion--nico le 17-11-2012
connexionDatabase::PrepareStatement(REALMS_UPD_ACCOUNT_LOGCONNEXIONCOMPTE,"UPDATE account SET \"last_ip\" = $1, \"failed_logins\" = '0', \"last_login\" = now(), \"online\" = true WHERE \"Util_numero\" = $2");

//requete qui met a jour l'adresse mail associee a un compte --nico le 17-11-2012
connexionDatabase::PrepareStatement(REALMS_UPD_ACCOUNT_MAJMAIL,"UPDATE account SET \"email\" = $1 WHERE \"Util_numero\" = $2");

//requete qui met a jour le mot de passe d'un compte --nico le 17-11-2012
connexionDatabase::PrepareStatement(REALMS_UPD_ACCOUNT_MAJPASS,"UPDATE account SET \"sha_pass_hash\" = $1 WHERE \"Util_numero\" = $2");

//requete qui cree l'acces du compte a la creation du compte gm level a zero par defaut -- nico le 17-11-2012
connexionDatabase::PrepareStatement(REALMS_INS_ACCOUNTACCESS_CREATIONACCESS,"INSERT INTO account_access VALUES (DEFAULT, $1, '0', SELECT MAX(Util_numero) from account, $4, $5, true)");

//requete qui liste les avertissements d'un compte --nico le 18-11-2012
connexionDatabase::PrepareStatement(REALMS_SEL_AVERTISSEMENTS_LISTEAVERTOS,"SELECT \"avertissement_date\", \"avertissements_raison\", \"username\" from avertissements, account WHERE \"avertissements_numero_util\" = $1 and \"avertissements.avertissements_id_gm\" = \"account.util_numero\"");

//requete qui stocke l'ip temporairement en cas d'erreur d'authentification --nico le 18-11-2012
connexionDatabase::PrepareStatement(REALMS_INS_IPTEMPORAIRE_STOCKAGEIPTEMPORAIRE,"INSERT INTO ip_temporaire VALUES (DEFAULT, $1, '1')");

//requete qui met a jour le nombre d'erreurs sur l'ip temporaire --nico le 18-11-2012
connexionDatabase::PrepareStatement(REALMS_UPD_IPTEMPORAIRE_MAJIPTEMPORAIRE,"UPDATE ip_temporaire SET \"ip_temp_nessais\" = $1 WHERE \"ip_temp_ip\" = $2");

//requete qui lit le nombre d'erreurs d'authentificatio sur l'ip temporaire --nico le 18-11-2012
connexionDatabase::PrepareStatement(REALMS_SEL_IPTEMPORAIRE_LECTURENERREURS,"SELECT \"ip_temp_nessais\" FROM ip_temporaire where \"ip_temp_ip\" = $1");

//requete qui detruit la ligne des ip sur authentification correcte sur l'ip temporaire --nico le 18-11-2012
connexionDatabase::PrepareStatement(REALMS_DEL_IPTEMPORAIRE_SUPPRLIGNEIP,"DELETE FROM ip_temporaire where \"ip_temp_nessais\" = '0'");

//requete qui permet de mettre un serveur online --nico le 19-11-2012
connexionDatabase::PrepareStatement(REALMS_UPD_LISTESERVEUR_MISEONLINESERVEUR,"UPDATE liste_serveur set \"serveur_serveur_online\"=true WHERE \"serveur_nom_serveur\"=$1");

//requete qui permet de mettre un serveur offline --nico le 19-11-2012
connexionDatabase::PrepareStatement(REALMS_UPD_LISTESERVEUR_MISEOFFLINESERVEUR,"UPDATE liste_serveur set \"serveur_serveur_online\"=false WHERE \"serveur_nom_serveur\"=$1");

}
