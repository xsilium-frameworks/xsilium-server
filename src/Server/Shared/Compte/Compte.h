/*
 * \file Compte.h
 *
 *  Created on: \date 29 déc. 2014
 *      Author: \author joda
 *  \brief :
 */
#ifndef SRC_SERVER_SHARED_COMPTE_COMPTE_H_
#define SRC_SERVER_SHARED_COMPTE_COMPTE_H_

#include <Databases/CRUD.h>
#include <Session/SessionListener.h>

/*
 *
 */

enum CompteDatabaseStatements {
	REALMS_SEL_ACCOUNT,
	REALMS_INS_ACCOUNT,
	REALMS_UPD_ACCOUNT,
	REALMS_DEL_ACCOUNT
};

class Compte : public SessionListener , public CRUD  {
public:
	Compte(std::string nomString = "");
	virtual ~Compte();

	bool create(int idTransaction);
	bool read(int idTransaction) ;
	bool update(int idTransaction);
	bool suppr(int idTransaction);


	const std::string& getEmail() const;
	void setEmail(const std::string& email);
	int getIdAccount() const;
	void setIdAccount(int idAccount);
	time_t getJoindate() const;
	void setJoindate(time_t joindate);
	const std::string& getLastIp() const;
	void setLastIp(const std::string& lastIp);
	time_t getLastLogin() const;
	void setLastLogin(time_t lastLogin);
	int getLocale() const;
	void setLocale(int locale);
	bool isLocked() const;
	void setLocked(bool locked);
	bool isOnline() const;
	void setOnline(bool online);
	const std::string& getShaPassHash() const;
	void setShaPassHash(const std::string& shaPassHash);
	const std::string& getUsername() const;
	void setUsername(const std::string& username);

private:

	int id_account; /*!< numero unique du compte dans la base de donn�e      */
	std::string username; /*!< Le nom du compte */
	std::string sha_pass_hash; /*!< Le mot de passe crypter */
	std::string email; /*!<L'email du compte */
	time_t joindate ; /*!< date de creation du compte  */
	std::string last_ip ; /*!< derniere IP du compte  */
	bool locked; /*!< Si le client lock sont compte sur l'ip*/
	time_t last_login ; /*!< derniere date de connexion du compte  */
	bool online ; /*!< le compte est utilise  */
	int locale; /*!< langue du compte  */

};

#endif /* SRC_SERVER_SHARED_COMPTE_COMPTE_H_ */
