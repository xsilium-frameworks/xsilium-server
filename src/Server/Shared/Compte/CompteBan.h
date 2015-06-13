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
	CompteBan();
	virtual ~CompteBan();

	bool create(int idTransaction);
	bool read(int idTransaction) ;
	bool update(int idTransaction);
	bool suppr(int idTransaction);


	time_t getBandate() const;
	void setBandate(time_t bandate);
	int getBannedby() const;
	void setBannedby(int bannedby);
	int getIdAccount() const;
	void setIdAccount(int idAccount);
	int getIdAccountBanned() const;
	void setIdAccountBanned(int idAccountBanned);
	const std::string& getRaison() const;
	void setRaison(const std::string& raison);
	time_t getUnbandate() const;
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
