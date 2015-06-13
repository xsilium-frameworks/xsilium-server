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


	database->prepareStatement(suffix + database->ToString(REALMS_SEL_ACCOUNT),"SELECT a.id_account,a.username,a.sha_pass_hash,a.locked,a.last_ip,a.failed_logins,b.active,b.unbandate FROM compte.account a left outer join compte.account_banned b on b.id_account_banned = a.id_account and b.unbandate > now() where a.username = $1 ");
	database->prepareStatement(suffix + database->ToString(REALMS_UPD_ACCOUNT),"UPDATE compte.account SET last_ip = $2 WHERE id_account = $1");
	database->prepareStatement(suffix + database->ToString(REALMS_INS_ACCOUNT),"UPDATE compte.account SET failed_logins = $2 WHERE id_account = $1");
	database->prepareStatement(suffix + database->ToString(REALMS_DEL_ACCOUNT),"UPDATE compte.account SET failed_logins = $2 WHERE id_account = $1");
}

Compte::~Compte() {
	// TODO Auto-generated destructor stub
}

bool Compte::create(int idTransaction)
{
	bool retour;
	Tokens tokens;
	retour = database->executionPrepareStatement(suffix + database->ToString(REALMS_INS_ACCOUNTBANNED),&tokens,0,5,database->ToString(id_account).c_str(),database->ToString(bandate).c_str(),database->ToString(unbandate).c_str(),raison.c_str(),database->ToString(bannedby).c_str());
	read();
	return retour;
}
bool Compte::read(int idTransaction)
{
	return true;
}
bool Compte::update(int idTransaction)
{
	return true;
}
bool Compte::suppr(int idTransaction)
{
	return true;
}

const std::string& Compte::getEmail() const {
	return email;
}

void Compte::setEmail(const std::string& email) {
	this->email = email;
}

int Compte::getIdAccount() const {
	return id_account;
}

void Compte::setIdAccount(int idAccount) {
	id_account = idAccount;
}

time_t Compte::getJoindate() const {
	return joindate;
}

void Compte::setJoindate(time_t joindate) {
	this->joindate = joindate;
}

const std::string& Compte::getLastIp() const {
	return last_ip;
}

void Compte::setLastIp(const std::string& lastIp) {
	last_ip = lastIp;
}

time_t Compte::getLastLogin() const {
	return last_login;
}

void Compte::setLastLogin(time_t lastLogin) {
	last_login = lastLogin;
}

int Compte::getLocale() const {
	return locale;
}

void Compte::setLocale(int locale) {
	this->locale = locale;
}

bool Compte::isLocked() const {
	return locked;
}

void Compte::setLocked(bool locked) {
	this->locked = locked;
}

bool Compte::isOnline() const {
	return online;
}

void Compte::setOnline(bool online) {
	this->online = online;
}

const std::string& Compte::getShaPassHash() const {
	return sha_pass_hash;
}

void Compte::setShaPassHash(const std::string& shaPassHash) {
	sha_pass_hash = shaPassHash;
}

const std::string& Compte::getUsername() const {
	return username;
}

void Compte::setUsername(const std::string& username) {
	this->username = username;
}
