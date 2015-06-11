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
	suffix = "IP";
	this->ip_temp_ip = ip_temp_ip;

	database->prepareStatement(suffix + database->ToString(REALMS_DEL_IPTEMPORAIRE_SUPPRLIGNEIP),"DELETE FROM IP.ip_temporaire where ip_temp_ip = $1");
	database->prepareStatement(suffix + database->ToString(REALMS_SEL_IPTEMPORAIRE_LECTURENERREURS),"SELECT * FROM IP.ip_temporaire where ip_temp_ip = $1");
	database->prepareStatement(suffix + database->ToString(REALMS_INS_IPTEMPORAIRE_STOCKAGEIPTEMPORAIRE),"INSERT INTO IP.ip_temporaire VALUES (DEFAULT, $1, $2)");
	database->prepareStatement(suffix + database->ToString(REALMS_UPD_IPTEMPORAIRE_MAJIPTEMPORAIRE),"UPDATE IP.ip_temporaire SET ip_temp_nessais = $1 WHERE ip_temp_ip = $2");

}

IP::~IP() {
	// TODO Auto-generated destructor stub
}

bool IP::create(int idTransaction)
{
	database->executionPrepareStatement(suffix + database->ToString(REALMS_INS_IPTEMPORAIRE_STOCKAGEIPTEMPORAIRE),0,2,ip_temp_ip.c_str(),database->ToString(ip_temp_nessais).c_str());
	read();
	return true;
}
bool IP::read(int idTransaction)
{
	Tokens resultsqlT;

	resultsqlT = database->executionPrepareStatement(suffix + database->ToString(REALMS_SEL_IPTEMPORAIRE_LECTURENERREURS),0,1,ip_temp_ip.c_str());

	if(resultsqlT.empty())
	{
		return false ;
	}
	else
	{
		Tokens resultatsql;
		resultatsql = database->strSplit( resultsqlT[0] ,";");
		id_ip = database->ToInt(resultatsql[0]);
		ip_temp_nessais = database->ToInt(resultatsql[2]);
		return true ;
	}
}
bool IP::update(int idTransaction)
{
	database->executionPrepareStatement(suffix + database->ToString(REALMS_UPD_IPTEMPORAIRE_MAJIPTEMPORAIRE),0,2,database->ToString(ip_temp_nessais).c_str(),ip_temp_ip.c_str() );
	return true;
}
bool IP::suppr(int idTransaction)
{
	database->executionPrepareStatement(suffix + database->ToString(REALMS_DEL_IPTEMPORAIRE_SUPPRLIGNEIP),0,1,ip_temp_ip.c_str());
	return true;
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
