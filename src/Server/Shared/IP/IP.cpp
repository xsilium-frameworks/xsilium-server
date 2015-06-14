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
	database->prepareStatement(suffix + database->ToString(REALMS_SEL_IPTEMPORAIRE_LECTURENERREURS),"SELECT id_ip,ip_temp_nessais FROM IP.ip_temporaire where ip_temp_ip = $1");
	database->prepareStatement(suffix + database->ToString(REALMS_INS_IPTEMPORAIRE_STOCKAGEIPTEMPORAIRE),"INSERT INTO IP.ip_temporaire VALUES (DEFAULT, $1, $2)");
	database->prepareStatement(suffix + database->ToString(REALMS_UPD_IPTEMPORAIRE_MAJIPTEMPORAIRE),"UPDATE IP.ip_temporaire SET ip_temp_nessais = $1 WHERE ip_temp_ip = $2");

}

IP::~IP() {
	// TODO Auto-generated destructor stub
}

bool IP::create(int idTransaction)
{
	bool retour;
	Tokens tokens;
	retour = database->executionPrepareStatement(suffix + database->ToString(REALMS_INS_IPTEMPORAIRE_STOCKAGEIPTEMPORAIRE),&tokens,idTransaction,2,ip_temp_ip.c_str(),database->ToString(ip_temp_nessais).c_str());
	read();
	return retour;
}
bool IP::read(int idTransaction)
{
	bool retour;
	Tokens resultsqlT ;

	retour = database->executionPrepareStatement(suffix + database->ToString(REALMS_SEL_IPTEMPORAIRE_LECTURENERREURS),&resultsqlT,idTransaction,1,ip_temp_ip.c_str());

	if(resultsqlT.empty())
	{
		retour = false ;
	}
	else
	{
		Tokens resultatsql;
		resultatsql = database->strSplit( resultsqlT[0] ,";");
		id_ip = database->ToInt(resultatsql[0]);
		ip_temp_nessais = database->ToInt(resultatsql[1]);
		retour = true ;
	}
	return retour ;
}
bool IP::update(int idTransaction)
{
	Tokens resultsqlT ;
	return database->executionPrepareStatement(suffix + database->ToString(REALMS_UPD_IPTEMPORAIRE_MAJIPTEMPORAIRE),&resultsqlT,idTransaction,2,database->ToString(ip_temp_nessais).c_str(),ip_temp_ip.c_str() );
}
bool IP::suppr(int idTransaction)
{
	Tokens resultsqlT ;
	return database->executionPrepareStatement(suffix + database->ToString(REALMS_DEL_IPTEMPORAIRE_SUPPRLIGNEIP),&resultsqlT,idTransaction,1,ip_temp_ip.c_str());

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
