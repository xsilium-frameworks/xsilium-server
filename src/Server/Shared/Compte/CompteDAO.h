/*
 * CompteDAO.h
 *
 *  Created on: 6 oct. 2015
 *      Author: joda
 */

#ifndef SRC_SERVER_SHARED_COMPTE_COMPTEDAO_H_
#define SRC_SERVER_SHARED_COMPTE_COMPTEDAO_H_

#include <Databases/CRUD.h>

class CompteDAO : public CRUD {
public:
	CompteDAO();
	virtual ~CompteDAO();

	bool createCompte(Compte * compte);
	void updateCompte();
	Compte * readCompte();
	void deleteCompte(Compte * compte);

private:


};

#endif /* SRC_SERVER_SHARED_COMPTE_COMPTEDAO_H_ */
