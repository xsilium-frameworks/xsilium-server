/*
 * LoginDatabase.h
 *
 *  Created on: 18 févr. 2012
 *      Author: joda2
 */

#ifndef LOGINDATABASE_H_
#define LOGINDATABASE_H_

#include <string>

#include "../PostgreSQLInterface/PostgreSQLInterface.h"

class LoginDatabase : public PostgreSQLInterface {
public:
	LoginDatabase();
	virtual ~LoginDatabase();

	bool selectAccout(const char *userName,char *results);
	bool getIPBan(std::string *IP,char *results);
	bool setIPBan();
};

#endif /* LOGINDATABASE_H_ */
