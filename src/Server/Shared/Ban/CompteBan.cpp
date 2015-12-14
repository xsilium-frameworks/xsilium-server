/*
 * \file CompteBan.cpp
 *
 *  Created on: \date 13 juin 2015
 *      Author: \author joda
 *  \brief :
 */
#include "CompteBan.h"

CompteBan::CompteBan(int id_account) {
	suffix = "COMPTEBAN";

	id_account_banned = 0;
	this->id_account = id_account;
	bandate = 0 ;
	unbandate = 0 ;
	raison = "" ;
	bannedby = 0 ;

	database->prepareStatement(suffix + database->ToString(REALMS_SEL_ACCOUNTBANNED),"SELECT id_account_banned,bandate,unbandate,raison,bannedby FROM compte.account_banned WHERE unbandate>now() and id_account=$1");
	database->prepareStatement(suffix + database->ToString(REALMS_INS_ACCOUNTBANNED),"INSERT INTO compte.account_banned VALUES (DEFAULT,$1,to_timestamp($2),to_timestamp($3), 'AutoBan erreur authentification',$4)");
	database->prepareStatement(suffix + database->ToString(REALMS_UPD_ACCOUNTBANNED),"UPDATE compte.account_banned SET bandate=to_timestamp($1),unbandate=to_timestamp($2),raison=$3,bannedby=$4 WHERE id_account_banned=$5");
	database->prepareStatement(suffix + database->ToString(REALMS_DEL_ACCOUNTBANNED),"DELETE FROM compte.account_banned WHERE id_account_banned=$1");


}

CompteBan::~CompteBan() {
	// TODO Auto-generated destructor stub
}

bool CompteBan::create(int idTransaction)
{
	bool retour;
	Tokens tokens;
	retour = database->executionPrepareStatement(suffix + database->ToString(REALMS_INS_ACCOUNTBANNED),&tokens,idTransaction,5,database->ToString(id_account).c_str(),database->ToString(bandate).c_str(),database->ToString(unbandate).c_str(),raison.c_str(),database->ToString(bannedby).c_str());
	read();
	return retour;
}
bool CompteBan::read(int idTransaction)
{
	bool retour;
	Tokens resultsqlT;
	retour = database->executionPrepareStatement(suffix + database->ToString(REALMS_SEL_ACCOUNTBANNED),&resultsqlT,idTransaction,1,database->ToString(id_account).c_str());

	if(resultsqlT.empty())
	{
		retour = false;
	}
	else
	{
		Tokens resultatsql;

		resultatsql = database->strSplit( resultsqlT[0] ,";");

		id_account_banned = database->ToInt(resultatsql[0]);
		bandate = database->ToDate(resultatsql[1]);
		unbandate = database->ToDate(resultatsql[2]);
		raison = resultatsql[3];
		bannedby = database->ToInt(resultatsql[4]);
		retour = true;
	}

	return retour;
}
bool CompteBan::update(int idTransaction)
{
	Tokens resultsqlT;
	return database->executionPrepareStatement(suffix + database->ToString(REALMS_UPD_ACCOUNTBANNED),&resultsqlT,idTransaction,5,database->ToString(bandate).c_str(),database->ToString(unbandate).c_str(),raison.c_str(),database->ToString(bannedby).c_str(),database->ToString(id_account_banned).c_str());

}
bool CompteBan::suppr(int idTransaction)
{
	Tokens resultsqlT;
	return  database->executionPrepareStatement(suffix + database->ToString(REALMS_DEL_ACCOUNTBANNED),&resultsqlT,idTransaction,1,database->ToString(id_account_banned).c_str());
}


time_t CompteBan::getBandate() {
	return bandate;
}

void CompteBan::setBandate(time_t bandate) {
	this->bandate = bandate;
}

int CompteBan::getBannedby() {
	return bannedby;
}

void CompteBan::setBannedby(int bannedby) {
	this->bannedby = bannedby;
}

int CompteBan::getIdAccount() {
	return id_account;
}

void CompteBan::setIdAccount(int idAccount) {
	id_account = idAccount;
}

int CompteBan::getIdAccountBanned() {
	return id_account_banned;
}

void CompteBan::setIdAccountBanned(int idAccountBanned) {
	id_account_banned = idAccountBanned;
}

std::string& CompteBan::getRaison() {
	return raison;
}

void CompteBan::setRaison(std::string& raison) {
	this->raison = raison;
}

time_t CompteBan::getUnbandate() {
	return unbandate;
}

void CompteBan::setUnbandate(time_t unbandate) {
	this->unbandate = unbandate;
}
