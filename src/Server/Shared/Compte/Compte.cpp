/*
 * \file Compte.cpp
 *
 *  Created on: \date 29 déc. 2014
 *      Author: \author joda
 *  \brief :
 */
#include "Compte.h"

Compte::Compte(std::string nomString) {
	suffix = "Compte";
	id_account = 0;
	username = nomString;
	sha_pass_hash = "";
	email = "";
	joindate = 0 ;
	last_ip = "" ;
	locked = false;
	last_login = 0 ;
	online = false ;
	locale = 0;


	database->prepareStatement(suffix + database->ToString(REALMS_SEL_ACCOUNT),"SELECT id_account,sha_pass_hash,email,joindate,last_ip,locked,last_login,online,locale FROM compte.account where username = $1 ");
	database->prepareStatement(suffix + database->ToString(REALMS_UPD_ACCOUNT),"UPDATE compte.account SET sha_pass_hash = $2,email=$3,joindate = to_timestamp($4),last_ip = $5,locked = $6,last_login = to_timestamp($7),online = $8,locale = $9 WHERE id_account = $1");
	database->prepareStatement(suffix + database->ToString(REALMS_INS_ACCOUNT),"INSERT INTO compte.account VALUES (DEFAULT,$1,$2,$3,to_timestamp($4),$5,$6,to_timestamp($7),$8,$9)");
	database->prepareStatement(suffix + database->ToString(REALMS_DEL_ACCOUNT),"DELETE FROM compte.account WHERE id_account = $1");
}

Compte::~Compte() {
	// TODO Auto-generated destructor stub
}

bool Compte::create(int idTransaction)
{
	bool retour;
	Tokens tokens;
	retour = database->executionPrepareStatement(suffix + database->ToString(REALMS_INS_ACCOUNT),&tokens,idTransaction,9,username.c_str(),sha_pass_hash.c_str(),email.c_str(),database->ToString(joindate).c_str(),last_ip.c_str(),database->ToString(locked).c_str(),database->ToString(last_login).c_str(),database->ToString(online).c_str(),database->ToString(locale).c_str());
	read();
	return retour;
}
bool Compte::read(int idTransaction)
{
	bool retour;
	Tokens resultsqlT;
	retour = database->executionPrepareStatement(suffix + database->ToString(REALMS_SEL_ACCOUNT),&resultsqlT,idTransaction,1,username.c_str());

	if(resultsqlT.empty())
	{
		retour = false;
	}
	else
	{
		Tokens resultatsql;

		resultatsql = database->strSplit( resultsqlT[0] ,";");

		id_account = database->ToInt(resultatsql[0]);
		sha_pass_hash = resultatsql[1];
		email = resultatsql[2];
		joindate = database->ToDate(resultatsql[3]);
		last_ip = resultatsql[4];
		locked = database->ToBool(resultatsql[5]) ;
		last_login = database->ToDate(resultatsql[6]);
		online = database->ToBool(resultatsql[8]) ;
		locale = database->ToInt(resultatsql[8]);

		retour = true;
	}

	return retour;
}
bool Compte::update(int idTransaction)
{
	Tokens resultsqlT;
	return database->executionPrepareStatement(suffix + database->ToString(REALMS_UPD_ACCOUNT),&resultsqlT,idTransaction,9,database->ToString(id_account).c_str(),sha_pass_hash.c_str(),email.c_str(),database->ToString(joindate).c_str(),last_ip.c_str(),database->ToString(locked).c_str(),database->ToString(last_login).c_str(),database->ToString(online).c_str(),database->ToString(locale).c_str());

}
bool Compte::suppr(int idTransaction)
{
	Tokens resultsqlT;
	return  database->executionPrepareStatement(suffix + database->ToString(REALMS_DEL_ACCOUNT),&resultsqlT,idTransaction,1,database->ToString(id_account).c_str());

}

std::string& Compte::getEmail() {
	return email;
}

void Compte::setEmail(std::string& email) {
	this->email = email;
}

int Compte::getIdAccount() {
	return id_account;
}

void Compte::setIdAccount(int idAccount) {
	id_account = idAccount;
}

time_t Compte::getJoindate() {
	return joindate;
}

void Compte::setJoindate(time_t joindate) {
	this->joindate = joindate;
}

std::string& Compte::getLastIp() {
	return last_ip;
}

void Compte::setLastIp(std::string& lastIp) {
	last_ip = lastIp;
}

time_t Compte::getLastLogin() {
	return last_login;
}

void Compte::setLastLogin(time_t lastLogin) {
	last_login = lastLogin;
}

int Compte::getLocale() {
	return locale;
}

void Compte::setLocale(int locale) {
	this->locale = locale;
}

bool Compte::isLocked() {
	return locked;
}

void Compte::setLocked(bool locked) {
	this->locked = locked;
}

bool Compte::isOnline() {
	return online;
}

void Compte::setOnline(bool online) {
	this->online = online;
}

std::string& Compte::getShaPassHash() {
	return sha_pass_hash;
}

void Compte::setShaPassHash(std::string& shaPassHash) {
	sha_pass_hash = shaPassHash;
}

std::string& Compte::getUsername() {
	return username;
}

void Compte::setUsername(std::string& username) {
	this->username = username;
}
