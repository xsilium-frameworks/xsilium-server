/*
 * \file IP.h
 *
 *  Created on: \date 21 févr. 2015
 *      Author: \author joda
 *  \brief :
 */
#ifndef SRC_SERVER_SHARED_IP_IP_H_
#define SRC_SERVER_SHARED_IP_IP_H_

#include <Databases/CRUD.h>

enum IPDatabaseStatements {
	REALMS_DEL_IPTEMPORAIRE_SUPPRLIGNEIP,
	REALMS_SEL_IPTEMPORAIRE_LECTURENERREURS,
	REALMS_INS_IPTEMPORAIRE_STOCKAGEIPTEMPORAIRE,
	REALMS_UPD_IPTEMPORAIRE_MAJIPTEMPORAIRE
};

/*
 *
 */
class IP : public CRUD {
public:
	IP(std::string ip_temp_ip );
	virtual ~IP();

	bool create(int idTransaction = 0);
	bool read(int idTransaction = 0);
	bool update(int idTransaction = 0);
	bool suppr(int idTransaction = 0);

	int getIdIp() const;
	void setIdIp(int idIp);
	const std::string& getIpTempIp() const;
	void setIpTempIp(const std::string& ipTempIp);
	int getIpTempNessais() const;
	void setIpTempNessais(int ipTempNessais);

private:
	int id_ip;
	std::string ip_temp_ip;
	int ip_temp_nessais;
};

#endif /* SRC_SERVER_SHARED_IP_IP_H_ */
