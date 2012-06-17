/*
 * LoginDatabase.cpp
 *
 *  Created on: 18 f�vr. 2012
 *      Author: joda2
 */

#include "LoginDatabase.h"
// #include "SHA1.h"
#include <stdlib.h>
// localtime
#include <time.h>


LoginDatabase::LoginDatabase() {
	// TODO Auto-generated constructor stub

}

LoginDatabase::~LoginDatabase() {
	// TODO Auto-generated destructor stub
}


bool LoginDatabase::selectAccount(const char * userName,sClient *client)
{
	/*
	PGresult *result;
	char query[512];
	if (strlen(userName)>32)
		return false ;
	sprintf(query, "SELECT a.sha_pass_hash,a.id,a.locked,a.last_ip,aa.gmlevel,aa.realmID,ab.unbandate FROM account a LEFT outer JOIN account_access aa ON (a.id = aa.id) Left outer join account_banned ab on a.id = ab.id WHERE a.username = '%s'",userName);
	if (ExecuteBlockingCommand(query, &result, false)==false)
	{
		PQclear(result);
		return false;
	}
	int numRows = PQntuples(result);
	if (numRows>0)
	{
		client->idLogin = atoi(PQgetvalue(result,0,PQfnumber(result, "id")));
		client->locked = (bool)PQgetvalue(result,0,PQfnumber(result, "locked"));
		for(int i  = 0 ; i < numRows ; i++)
		{
			client->gmlevel[atoi(PQgetvalue(result,i,PQfnumber(result, "realmID")))] = atoi(PQgetvalue(result,i,PQfnumber(result, "gmlevel")));
		}

		client->lastIP = PQgetvalue(result,0,PQfnumber(result, "last_ip"));
		client->shaPassHash = PQgetvalue(result,0,PQfnumber(result, "sha_pass_hash"));
		client->accountUnBanDate = atoi(PQgetvalue(result,0,PQfnumber(result, "unbandate")));
	}
	PQclear(result);
	*/
	return true ;
}


bool LoginDatabase::getIPBan(std::string *IP, bool *results)
{
	/*
	PGresult *result;
	char query[512];
	sprintf(query, "SELECT 1 FROM ip_banned WHERE ip = '%s'", IP->c_str() );
	if (!ExecuteBlockingCommand(query, &result, false))
	{
		PQclear(result);
		return false;
	}

	results = (bool*)PQntuples(result);
	*/
	return true;

}

bool LoginDatabase::setIPBan()
{
	/*
	PGresult *result;
	char query[512] = "DELETE FROM ip_banned WHERE unbandate<=now() AND unbandate<>bandate" ;
	if (ExecuteBlockingCommand(query, &result, false)==false)
	{
		PQclear(result);
		return false;
	}

	PQclear(result);
	*/
	return true ;
}

bool LoginDatabase::setAccountBan(sClient *client)
{
/*
	PGresult *result;
	char query[512] = "DELETE FROM ip_banned WHERE unbandate<=now() AND unbandate<>bandate" ;
	if (ExecuteBlockingCommand(query, &result, false)==false)
	{
		PQclear(result);
		return false;
	}

	PQclear(result);
	*/
	return true ;

}

