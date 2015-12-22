/*
 * IPBanDAO.h
 *
 *  Created on: 15 déc. 2015
 *      Author: Aeden
 */

#ifndef SRC_SERVER_SHARED_DAO_IP_IPBANDAO_H_
#define SRC_SERVER_SHARED_DAO_IP_IPBANDAO_H_

#include <DAO/DAO.h>
#include <Model/IP/IPBan.h>

enum IPBanDatabaseStatements {
	REALMS_SEL_IPBANNED_INFOSSURIPBANNIES,
	REALMS_INS_IPBANNED_BANIP,
	REALMS_DEL_IPBANNED_DEBANIP,
	REALMS_UPD_IPBANNED_DEBANIP
};

class IPBanDAO: public DAO {
public:
	IPBanDAO();
	virtual ~IPBanDAO();

	bool create(IPBan * ipBan, int idTransaction = 0);
	bool update(IPBan * ipBan, int idTransaction = 0);
	bool read(IPBan * ipBan, int idTransaction = 0);
	bool suppr(IPBan * ipBan, int idTransaction = 0);

private:

};

#endif /* SRC_SERVER_SHARED_DAO_IP_IPBANDAO_H_ */
