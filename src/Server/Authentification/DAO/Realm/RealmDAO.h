/*
 * RealmDAO.h
 *
 *  Created on: 11 juil. 2015
 *      Author: Skronak
 */

#ifndef SRC_SERVER_AUTHENTIFICATION_REALM_DAO_REALMDAO_H_
#define SRC_SERVER_AUTHENTIFICATION_REALM_DAO_REALMDAO_H_
#include <DAO/DAO.h>

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
	RealmDAO(std::string nameRoyaume);
	virtual ~RealmDAO();

	bool create(int idTransaction = 0);
	bool read(int idTransaction = 0) ;
	bool update(int idTransaction = 0);
	bool suppr(int idTransaction = 0);


	int getAutorisationRoyaume();
	void setAutorisationRoyaume(int autorisationRoyaume);
	int getIdRoyaume() ;
	void setIdRoyaume(int idRoyaume);
	 std::string getKeyRoyaume() ;
	void setKeyRoyaume( std::string keyRoyaume);
	 std::string getNameRoyaume() ;
	void setNameRoyaume( std::string nameRoyaume);
	bool isOnlineRoyaume() ;
	void setOnlineRoyaume(bool onlineRoyaume);
	int getPortRoyaume() ;
	void setPortRoyaume(int portRoyaume);
	 std::string getUrlRoyaume() ;
	void setUrlRoyaume( std::string urlRoyaume);
	int getVersionClientRoyaume() ;
	void setVersionClientRoyaume(int versionClientRoyaume);

private:

	int idRoyaume;
	std::string keyRoyaume;
	std::string nameRoyaume;
	std::string urlRoyaume;
	int portRoyaume;
	int autorisationRoyaume;
	int versionClientRoyaume;
	bool online_royaume;
};

} /* namespace Auth */

#endif /* SRC_SERVER_AUTHENTIFICATION_REALM_DAO_REALMDAO_H_ */
