/*
 * LoginDatabase.cpp
 *
 *  Created on: 18 févr. 2012
 *      Author: joda2
 */

// libpq-fe.h is part of PostgreSQL which must be installed on this computer to use the PostgreRepository
#include "libpq-fe.h"
#include "LoginDatabase.h"
// #include "SHA1.h"
#include <stdlib.h>
#include "LinuxStrings.h"
// localtime
#include <time.h>


LoginDatabase::LoginDatabase() {
	// TODO Auto-generated constructor stub

}

LoginDatabase::~LoginDatabase() {
	// TODO Auto-generated destructor stub
}


bool LoginDatabase::selectAccout(const char * userName,char * results)
{
	PGresult *result;
	char query[512];
	if (strlen(userName)>32)
		return false ;
	RakNet::RakString escapedUserName = GetEscapedString(userName);


		sprintf(query, "SELECT a.sha_pass_hash,a.id,a.locked,a.last_ip,aa.gmlevel,a.v,a.s FROM account a LEFT JOIN account_access aa ON (a.id = aa.id) WHERE a.username = '%s'", escapedUserName.C_String());
		if (ExecuteBlockingCommand(query, &result, false)==false)
		{
			PQclear(result);
			return false;
		}

		int numRows = PQntuples(result);
		if (numRows>0)
		{
			int fileIdIndex = PQfnumber(result, "fileId");
			int fileLengthIndex = PQfnumber(result, "fileLength");
		}
		PQclear(result);




	return true ;
}
