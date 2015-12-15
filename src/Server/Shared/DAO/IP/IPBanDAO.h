/*
 * IPBanDAO.h
 *
 *  Created on: 15 déc. 2015
 *      Author: Aeden
 */

#ifndef SRC_SERVER_SHARED_DAO_IP_IPBANDAO_H_
#define SRC_SERVER_SHARED_DAO_IP_IPBANDAO_H_

#include <Databases/CRUD.h>

enum IPBanDatabaseStatements {
	REALMS_SEL_IPBANNED_INFOSSURIPBANNIES,
	REALMS_INS_IPBANNED_BANIP,
	REALMS_DEL_IPBANNED_DEBANIP,
	REALMS_UPD_IPBANNED_DEBANIP
};

class IPBanDAO : public CRUD {
public:
	IPBanDAO();
	virtual ~IPBanDAO();

	bool create(IPBan * ipBan, int idTransaction);
	bool update(IPBan * ipBan, int idTransaction);
	bool read(IPBan * ipBan, int idTransaction);
	bool suppr(IPBan * ipBan, int idTransaction);

private:


};


#endif /* SRC_SERVER_SHARED_DAO_IP_IPBANDAO_H_ */
