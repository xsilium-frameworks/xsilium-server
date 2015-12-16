/*
 * IPDAO.h
 *
 *  Created on: 15 déc. 2015
 *      Author: Aeden
 */

#ifndef SRC_SERVER_SHARED_DAO_IP_IPDAO_H_
#define SRC_SERVER_SHARED_DAO_IP_IPDAO_H_

#include <Manager/Databases/CRUD.h>
#include <Model/IP/IP.h>

enum IPDatabaseStatements {
	REALMS_DEL_IPTEMPORAIRE,
	REALMS_SEL_IPTEMPORAIRE,
	REALMS_INS_IPTEMPORAIRE,
	REALMS_UPD_IPTEMPORAIRE
};

class IPDAO: public CRUD {
public:
	IPDAO();
	virtual ~IPDAO();

	bool create(IP * ip, int idTransaction);
	bool update(IP * ip, int idTransaction);
	bool read(IP * ip, int idTransaction);
	bool suppr(IP * ip, int idTransaction);

private:

};

#endif /* SRC_SERVER_SHARED_DAO_IP_IPDAO_H_ */
