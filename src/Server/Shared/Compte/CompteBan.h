/*
 * \file CompteBan.h
 *
 *  Created on: \date 13 juin 2015
 *      Author: \author joda
 *  \brief :
 */
#ifndef SRC_SERVER_SHARED_COMPTE_COMPTEBAN_H_
#define SRC_SERVER_SHARED_COMPTE_COMPTEBAN_H_

#include <Databases/CRUD.h>


enum CompteBanDatabaseStatements {
	REALMS_SEL_ACCOUNTBANNED,
	REALMS_INS_ACCOUNTBANNED,
	REALMS_UPD_ACCOUNTBANNED,
	REALMS_DEL_ACCOUNTBANNED
};


/*
 *
 */
class CompteBan : public CRUD  {
public:
	CompteBan(int id_account);
	virtual ~CompteBan();

	bool create(int idTransaction = 0);
	bool read(int idTransaction = 0) ;
	bool update(int idTransaction = 0);
	bool suppr(int idTransaction = 0);


	time_t getBandate();
	void setBandate(time_t bandate);
	int getBannedby();
	void setBannedby(int bannedby);
	int getIdAccount();
	void setIdAccount(int idAccount);
	int getIdAccountBanned();
	void setIdAccountBanned(int idAccountBanned);
	std::string& getRaison();
	void setRaison(std::string& raison);
	time_t getUnbandate();
	void setUnbandate(time_t unbandate);

private:
	int id_account_banned;
	int id_account;
	time_t bandate ;
	time_t unbandate ;
	std::string raison ;
	int bannedby ;


};

#endif /* SRC_SERVER_SHARED_COMPTE_COMPTEBAN_H_ */
