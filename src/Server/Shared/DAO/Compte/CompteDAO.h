/*
 * CompteDAO.h
 *
 *  Created on: 6 oct. 2015
 *      Author: joda
 */

#ifndef SRC_SERVER_SHARED_COMPTE_COMPTEDAO_H_
#define SRC_SERVER_SHARED_COMPTE_COMPTEDAO_H_

#include <Databases/CRUD.h>

enum CompteDatabaseStatements {
	REALMS_SEL_ACCOUNT,
	REALMS_INS_ACCOUNT,
	REALMS_UPD_ACCOUNT,
	REALMS_DEL_ACCOUNT
};

class CompteDAO : public CRUD {
public:
	CompteDAO();
	virtual ~CompteDAO();

	bool create(Compte * compte, int idTransaction);
	bool update(Compte * compte, int idTransaction);
	bool read(Compte * compte, int idTransaction);
	bool suppr(Compte * compte, int idTransaction);

private:


};

#endif /* SRC_SERVER_SHARED_COMPTE_COMPTEDAO_H_ */
