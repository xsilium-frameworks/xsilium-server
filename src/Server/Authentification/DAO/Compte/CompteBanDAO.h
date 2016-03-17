/*
 * CompteBanDAO.h
 *
 *  Created on: 15 déc. 2015
 *      Author: Aeden
 */

#ifndef SRC_SERVER_SHARED_DAO_BAN_COMPTEBANDAO_H_
#define SRC_SERVER_SHARED_DAO_BAN_COMPTEBANDAO_H_

#include <DAO/DAO.h>
#include  <Model/Compte/CompteBan.h>

enum CompteBanDatabaseStatements {
	REALMS_SEL_ACCOUNTBANNED,
	REALMS_INS_ACCOUNTBANNED,
	REALMS_UPD_ACCOUNTBANNED,
	REALMS_DEL_ACCOUNTBANNED
};

class CompteBanDAO : public DAO {
public:
	CompteBanDAO();
	virtual ~CompteBanDAO();

	bool create(Model * model, int idTransaction = 0);
	bool update(Model * model, int idTransaction = 0);
	bool read(Model * model, int idTransaction = 0);
	bool suppr(Model * model, int idTransaction = 0);

private:


};

#endif /* SRC_SERVER_SHARED_DAO_BAN_COMPTEBANDAO_H_ */
