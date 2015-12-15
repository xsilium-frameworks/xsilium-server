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

/*
 *
 */
class IP : public Model {
public:
	IP(std::string ip_temp_ip );
	virtual ~IP();

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
