/*
 * RealmDAO.h
 *
 *  Created on: 11 juil. 2015
 *      Author: Skronak
 */

#ifndef SRC_SERVER_AUTHENTIFICATION_REALM_DAO_REALMDAO_H_
#define SRC_SERVER_AUTHENTIFICATION_REALM_DAO_REALMDAO_H_
#include <DAO/DAO.h>
#include <Model/Realm/Realm.h>

namespace Auth {

/*
 *
 */
enum RoyaumeDatabaseStatements {
	REALMS_SEL_LISTESROYAUMES,
	REALMS_INS_LISTESROYAUMES,
	REALMS_UPD_LISTESROYAUMES,
	REALMS_DEL_LISTESROYAUMES
};

class RealmDAO: public DAO {
public:
	RealmDAO();
	virtual ~RealmDAO();

	bool create(Model * model, int idTransaction = 0);
	bool read(Model * model, int idTransaction = 0) ;
	bool update(Model * model, int idTransaction = 0);
	bool suppr(Model * model, int idTransaction = 0);
};

} /* namespace Auth */

#endif /* SRC_SERVER_AUTHENTIFICATION_REALM_DAO_REALMDAO_H_ */
