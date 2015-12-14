/*
 * \file Compte.h
 *
 *  Created on: \date 29 déc. 2014
 *      Author: \author joda
 *  \brief :
 */
#ifndef SRC_SERVER_SHARED_COMPTE_COMPTE_H_
#define SRC_SERVER_SHARED_COMPTE_COMPTE_H_

#include <Session/SessionListener.h>
#include <time.h>

/*
 *
 */

enum CompteDatabaseStatements {
	REALMS_SEL_ACCOUNT,
	REALMS_INS_ACCOUNT,
	REALMS_UPD_ACCOUNT,
	REALMS_DEL_ACCOUNT
};

class Compte : public SessionListener  {
public:
	Compte(std::string nomString = "");
	virtual ~Compte();

	void disconnect();


	std::string& getEmail();
	void setEmail(std::string& email);
	int getIdAccount();
	void setIdAccount(int idAccount);
	time_t getJoindate();
	void setJoindate(time_t joindate);
	std::string& getLastIp();
	void setLastIp(std::string& lastIp);
	time_t getLastLogin();
	void setLastLogin(time_t lastLogin);
	int getLocale();
	void setLocale(int locale);
	bool isLocked();
	void setLocked(bool locked);
	bool isOnline();
	void setOnline(bool online);
	std::string& getShaPassHash();
	void setShaPassHash(std::string& shaPassHash);
	std::string& getUsername();
	void setUsername(std::string& username);

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

	bool updateData;

};

#endif /* SRC_SERVER_SHARED_COMPTE_COMPTE_H_ */
