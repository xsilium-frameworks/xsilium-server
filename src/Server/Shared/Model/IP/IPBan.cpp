/*
 * \file IPBan.cpp
 *
 *  Created on: \date 30 mai 2015
 *      Author: \author joda
 *  \brief :
 */
#include "IPBan.h"

IPBan::IPBan(std::string ip) {
	setIp(ip);
	id_ip_banned = 0;
	bandate = 0;
	unbandate = 0;
	bannedby = 0;

}

IPBan::~IPBan() {
	// TODO Auto-generated destructor stub
}

time_t IPBan::getBandate() const {
	return bandate;
}

void IPBan::setBandate(time_t bandate) {
	this->bandate = bandate;
}

int IPBan::getBannedby() const {
	return bannedby;
}

void IPBan::setBannedby(int bannedby) {
	this->bannedby = bannedby;
}

int IPBan::getIdIpBanned() const {
	return id_ip_banned;
}

void IPBan::setIdIpBanned(int idIpBanned) {
	id_ip_banned = idIpBanned;
}

const std::string& IPBan::getIp() const {
	return ip;
}

void IPBan::setIp(const std::string& ip) {
	this->ip = ip;
}

const std::string& IPBan::getRaison() const {
	return raison;
}

void IPBan::setRaison(const std::string& raison) {
	this->raison = raison;
}

time_t IPBan::getUnbandate() const {
	return unbandate;
}

void IPBan::setUnbandate(time_t unbandate) {
	this->unbandate = unbandate;
}
