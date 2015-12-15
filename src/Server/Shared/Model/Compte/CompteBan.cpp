/*
 * \file CompteBan.cpp
 *
 *  Created on: \date 13 juin 2015
 *      Author: \author joda
 *  \brief :
 */
#include "CompteBan.h"

CompteBan::CompteBan(int id_account) {

	id_account_banned = 0;
	this->id_account = id_account;
	bandate = 0;
	unbandate = 0;
	raison = "";
	bannedby = 0;

}

CompteBan::~CompteBan() {
	// TODO Auto-generated destructor stub
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
