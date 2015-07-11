/*
 * RealmDAO.h
 *
 *  Created on: 11 juil. 2015
 *      Author: Skronak
 */

#ifndef SRC_SERVER_AUTHENTIFICATION_REALM_DAO_REALMDAO_H_
#define SRC_SERVER_AUTHENTIFICATION_REALM_DAO_REALMDAO_H_
#include <Databases/CRUD.h>

namespace Auth {

class RealmDAO: public CRUD {
public:
	RealmDAO();
	virtual ~RealmDAO();
};

	bool create(int idTransaction = 0);
	bool read(int idTransaction = 0) ;
	bool update(int idTransaction = 0);
	bool suppr(int idTransaction = 0);

} /* namespace Auth */

#endif /* SRC_SERVER_AUTHENTIFICATION_REALM_DAO_REALMDAO_H_ */
