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

	//								Session
	//requete qui detruit la ligne des ip sur authentification correcte sur l'ip temporaire

	connexionDatabase::PrepareStatement(REALMS_DEL_IPTEMPORAIRE_SUPPRLIGNEIP,"DELETE FROM compte.ip_temporaire where ip_temp_ip = $1");

	//requete qui lit le nombre d'erreurs d'authentificatio sur l'ip temporaire
	connexionDatabase::PrepareStatement(REALMS_SEL_IPTEMPORAIRE_LECTURENERREURS,"SELECT ip_temp_nessais FROM compte.ip_temporaire where ip_temp_ip = $1");

	//requete qui stocke l'ip temporairement en cas d'erreur d'authentification
	connexionDatabase::PrepareStatement(REALMS_INS_IPTEMPORAIRE_STOCKAGEIPTEMPORAIRE,"INSERT INTO compte.ip_temporaire VALUES (DEFAULT, $1, $2)");

	//requete qui met a jour le nombre d'erreurs sur l'ip temporaire
	connexionDatabase::PrepareStatement(REALMS_UPD_IPTEMPORAIRE_MAJIPTEMPORAIRE,"UPDATE compte.ip_temporaire SET ip_temp_nessais = $1 WHERE ip_temp_ip = $2");


	// requete qui va chercher les infos sur l'ip dans la table ip_banned
	connexionDatabase::PrepareStatement(REALMS_SEL_IPBANNED_INFOSSURIPBANNIES, "SELECT unbandate FROM compte.ip_banned WHERE unbandate > now() and ban_actif = true and ip = $1");

	//requete de ban d'une ip
	connexionDatabase::PrepareStatement(REALMS_INS_IPBANNED_BANIP,"INSERT INTO compte.ip_banned VALUES (DEFAULT,$1, now(), to_timestamp($2), $3, $4, true )");

	//requete qui met a jour la table des bans ip lorsque la date de ban est passee
	connexionDatabase::PrepareStatement(REALMS_UPD_IPBANNED_DEBANAUTOIP, "Update compte.ip_banned set ban_actif=false WHERE unbandate <=now() AND ban_actif = true ");

	//requete qui met a jour la table des bans ip
	connexionDatabase::PrepareStatement(REALMS_UPD_IPBANNED_DEBANIP, "Update compte.ip_banned set ban_actif=false WHERE ban_actif = true and ip = $1 ");


	//								Compte

	//requete qui permet de recuperer tout les informations du compte
	connexionDatabase::PrepareStatement(REALMS_SEL_ACCOUNT_RECUPINFOSCOMPTE,"SELECT a.id_account,a.username,a.sha_pass_hash,a.locked,a.last_ip,a.failed_logins,b.active,b.unbandate FROM compte.account a left outer join compte.account_banned b on b.id_account_banned = a.id_account and b.unbandate > now() where a.username = $1 ");

	//Requete de mise a jour du nombre d'erreurs d'authentification
	connexionDatabase::PrepareStatement(REALMS_UPD_ACCOUNT_MAJERREURSAUTH, "UPDATE compte.account SET failed_logins = $2 WHERE id_account = $1");

	//Requete de mise a jour de la derniere IP
	connexionDatabase::PrepareStatement(REALMS_UPD_ACCOUNT_MAJLASTIP, "UPDATE compte.account SET last_ip = $2 WHERE id_account = $1");


	//								Compte banni

	//requete qui deban automatiquement l'account apres une date de deban passee
	connexionDatabase::PrepareStatement(REALMS_UPD_ACCOUNTBANNED_DEBANAUTOCOMPTE, "UPDATE compte.account_banned SET active = false WHERE unbandate<=now() AND active=true");

	//requete d'autoban apres erreur d'authentification
	connexionDatabase::PrepareStatement(REALMS_INS_ACCOUNTBANNED_AUTOBANCOMPTEAUTH, "INSERT INTO compte.account_banned VALUES (DEFAULT,$1,now(),to_timestamp($2), 'AutoBan erreur authentification', true,$3)");

	//requete deban d'un compte
	connexionDatabase::PrepareStatement(REALMS_UPD_ACCOUNTBANNED_DEBANCOMPTE, "UPDATE compte.account_banned SET active = false WHERE id_account = $1");





	//								Liste Serveur
	//requete listing des infos de la liste des serveurs
		connexionDatabase::PrepareStatement(REALMS_SEL_LISTESERVEUR_RECUPLISTESERVEUR, "SELECT id_serveur, serveur_nom, domain_name, port, level_requis, online_personnage, version_client, serveur_online FROM compte.liste_serveur");


	/*


	//PrepareStatement(LOGIN_GET_NUMCHARSONREALM, "SELECT numchars FROM realmcharacters WHERE realmid = ? AND acctid= ?");

	//requete d'ajout d'avertissement sur un compte -- Nico le 15-11-2012
	connexionDatabase::PrepareStatement(REALMS_INS_AVERTISSEMENTS_AJOUTAVERTISSEMENTS, "INSERT INTO compte.avertissements VALUES (DEFAULT, $1, $2, $3, now())");

	//requete de mise a jour du nombre d'avertissements sur un compte -- Nico le 15-11-2012
	connexionDatabase::PrepareStatement(REALMS_UPD_ACCOUNT_MAJAVERTISSEMENTSCOMPTE, "UPDATE compte.account SET \"n_avertissements\" = $2 WHERE \"util_numero\" = $1");

	//requete auto_ban pour nombre d'avertissements --Nico le 15-11-2012
	connexionDatabase::PrepareStatement(REALMS_INS_ACCOUNTBANNED_AUTOBANCOMPTEPOURAVERTISSEMENTS,"INSERT INTO compte.account_banned VALUES (DEFAULT, now(), '9999-12-31 00:00:00.000000', 'AutoBan pour avertissement ', true, $1, $2)");

	//requete mise a jour du gm_level d'un compte --nico le 15-11-2012
	connexionDatabase::PrepareStatement(REALMS_UPD_ACCOUNTACCESS_MAJGMLEVELCOMPTE, "UPDATE compte.account_access SET \"gmlevel\" = $2 WHERE \"id_user\" = $1");

	//requete deban d'une ip --Nico le 15-11-2012
	connexionDatabase::PrepareStatement(REALMS_UPD_IPBANNED_DEBANIP, "UPDATE compte.ip_banned SET \"ban_actif\" = false WHERE \"ip\" = $1");

	//requete qui met a jour le nombre de comptes online sur un serveur --nico le 17-11-2012
	connexionDatabase::PrepareStatement(REALMS_UPD_LISTESERVEUR_MAJCOMPTEONLINE,"UPDATE compte.liste_serveur SET \"serveur_n_online\" = $1 WHERE \"id_serveur\" = $2");

	//requete qui cree un nouveau serveur --nico le 17-11-2012
	connexionDatabase::PrepareStatement(REALMS_INS_LISTESERVEUR_CREATIONSERVEUR,"INSERT INTO compte.liste_serveur VALUES (DEFAULT, $1, $2, $3, $4, '0', $5, DEFAULT)");

	//requete qui ban un compte --nico le 17-11-2012
	connexionDatabase::PrepareStatement(REALMS_INS_ACCOUNTBANNED_BANCOMPTE,"INSERT INTO compte.account_banned VALUES (DEFAULT, $1, $2, $3, true, $4, $5)");

	//requete qui ban une ip --nico le 17-11-2012
	connexionDatabase::PrepareStatement(REALMS_INS_IPBANNED_BANIP,"INSERT INTO compte.ip_banned VALUES ($1, $2, $3, $4, DEFAULT, $5, true)");

	//requete qui passe le compte online a la connexion, remet le failed login à zero, loggue son ip de connexion--nico le 17-11-2012
	connexionDatabase::PrepareStatement(REALMS_UPD_ACCOUNT_LOGCONNEXIONCOMPTE,"UPDATE compte.account SET \"last_ip\" = $1, \"failed_logins\" = '0', \"last_login\" = now(), \"online\" = true WHERE \"util_numero\" = $2");

	//requete qui met a jour l'adresse mail associee a un compte --nico le 17-11-2012
	connexionDatabase::PrepareStatement(REALMS_UPD_ACCOUNT_MAJMAIL,"UPDATE compte.account SET \"email\" = $1 WHERE \"util_numero\" = $2");

	//requete qui met a jour le mot de passe d'un compte --nico le 17-11-2012
	connexionDatabase::PrepareStatement(REALMS_UPD_ACCOUNT_MAJPASS,"UPDATE compte.account SET \"sha_pass_hash\" = $1 WHERE \"util_numero\" = $2");

	//requete qui cree l'acces du compte a la creation du compte gm level a zero par defaut -- nico le 17-11-2012
	connexionDatabase::PrepareStatement(REALMS_INS_ACCOUNTACCESS_CREATIONACCESS,"INSERT INTO compte.account_access VALUES (DEFAULT, $1, '0', SELECT MAX(util_numero) from compte.account, $4, $5, true)");

	//requete qui liste les avertissements d'un compte --nico le 18-11-2012
	connexionDatabase::PrepareStatement(REALMS_SEL_AVERTISSEMENTS_LISTEAVERTOS,"SELECT \"avertissement_date\", \"avertissements_raison\", \"username\" from compte.avertissements, account WHERE \"avertissements_numero_util\" = $1 and \"avertissements.avertissements_id_gm\" = \"account.util_numero\"");

	//requete qui permet de mettre un serveur online --nico le 19-11-2012
	connexionDatabase::PrepareStatement(REALMS_UPD_LISTESERVEUR_MISEONLINESERVEUR,"UPDATE compte.liste_serveur set \"serveur_serveur_online\"=true WHERE \"serveur_nom_serveur\"=$1");

	//requete qui permet de mettre un serveur offline --nico le 19-11-2012
	connexionDatabase::PrepareStatement(REALMS_UPD_LISTESERVEUR_MISEOFFLINESERVEUR,"UPDATE compte.liste_serveur set \"serveur_serveur_online\"=false WHERE \"serveur_nom_serveur\"=$1");
	 */
}
