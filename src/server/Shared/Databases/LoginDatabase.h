/*
 * LoginDatabase.h
 *
 *  Created on: 18 févr. 2012
 *      Author: joda2
 */

#ifndef LOGINDATABASE_H_
#define LOGINDATABASE_H_

#include "PostgreSQLInterface/PostgreSQLInterface.h"
#include "Structure/Server.h"


class LoginDatabase : public PostgreSQLInterface {
public:
	LoginDatabase();
	virtual ~LoginDatabase();

	bool selectAccount(const char *userName,sClient *client);
	bool getIPBan(std::string *IP, bool *results);
	bool setIPBan();
};

#endif /* LOGINDATABASE_H_ */
