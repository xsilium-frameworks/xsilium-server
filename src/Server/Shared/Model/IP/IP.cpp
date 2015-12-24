/*
 * \file IP.cpp
 *
 *  Created on: \date 21 févr. 2015
 *      Author: \author joda
 *  \brief :
 */
#include "IP.h"

IP::IP(std::string ip_temp_ip ) {

	ip_temp_nessais = 0;
	id_ip = 0;
	this->ip_temp_ip = ip_temp_ip;

}

IP::~IP() {
	// TODO Auto-generated destructor stub
}

int IP::getIdIp() const {
	return id_ip;
}

void IP::setIdIp(int idIp) {
	id_ip = idIp;
}

const std::string& IP::getIpTempIp() const {
	return ip_temp_ip;
}

void IP::setIpTempIp(const std::string& ipTempIp) {
	ip_temp_ip = ipTempIp;
}

int IP::getIpTempNessais() const {
	return ip_temp_nessais;
}

void IP::setIpTempNessais(int ipTempNessais) {
	ip_temp_nessais = ipTempNessais;
}
