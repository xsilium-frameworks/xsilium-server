/*
 * \file Royaume.h
 *
 *  Created on: \date 21 févr. 2015
 *      Author: \author joda
 *  \brief :
 */
#ifndef SRC_SERVER_SHARED_ROYAUME_ROYAUME_H_
#define SRC_SERVER_SHARED_ROYAUME_ROYAUME_H_

#include <Databases/CRUD.h>

/*
 *
 */
enum RoyaumeDatabaseStatements {
	REALMS_SEL_LISTESROYAUMES,
	REALMS_INS_LISTESROYAUMES,
	REALMS_UPD_LISTESROYAUMES,
	REALMS_DEL_LISTESROYAUMES
};

/*
 *
 */
class Royaume : public CRUD {
public:
	Royaume(int idRoyaume);
	virtual ~Royaume();

	bool create(int idTransaction = 0);
	bool read(int idTransaction = 0) ;
	bool update(int idTransaction = 0);
	bool suppr(int idTransaction = 0);

	int getAutorisationRoyaume();

	void setAutorisationRoyaume(int autorisationRoyaume);

	int getIdRoyaume();

	void setIdRoyaume(int idRoyaume);

	const std::string& getKeyRoyaume();

	void setKeyRoyaume(std::string& keyRoyaume);

	const std::string& getNameRoyaume();

	void setNameRoyaume(std::string& nameRoyaume);

	bool isOnlineRoyaume() ;

	void setOnlineRoyaume(bool onlineRoyaume);

	int getPortRoyaume() ;

	void setPortRoyaume(int portRoyaume);

	const std::string& getUrlRoyaume();

	void setUrlRoyaume(std::string& urlRoyaume);

	int getVersionClientRoyaume();

	void setVersionClientRoyaume(int versionClientRoyaume);

	void loadRoyaume();

	std::string ToExport();

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

#endif /* SRC_SERVER_SHARED_ROYAUME_ROYAUME_H_ */
