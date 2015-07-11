/*
 * RealmDAO.cpp
 *
 *  Created on: 11 juil. 2015
 *      Author: Skronak
 */

#include "RealmDAO.h"

namespace Auth {

RealmDAO::RealmDAO() {
	// TODO Auto-generated constructor stub

}

RealmDAO::~RealmDAO() {
	// TODO Auto-generated destructor stub
}

bool Royaume::create(int idTransaction)
{
	bool retour;
	Tokens tokens;
	retour = database->executionPrepareStatement(suffix + database->ToString(REALMS_INS_LISTESROYAUMES),&tokens,idTransaction,7,keyRoyaume.c_str(),nameRoyaume.c_str(),urlRoyaume.c_str(),database->ToString(portRoyaume).c_str(),database->ToString(autorisationRoyaume).c_str(),database->ToString(versionClientRoyaume).c_str(),database->ToString(online_royaume).c_str());
	retour = read();
	return retour;
}
bool Royaume::read(int idTransaction)
{
	bool retour ;
	Tokens resultsqlT;

	retour = database->executionPrepareStatement(suffix + database->ToString(REALMS_SEL_LISTESROYAUMES),&resultsqlT,idTransaction,1,database->ToString(idRoyaume).c_str());

	if(resultsqlT.empty())
	{
		retour = false ;
	}
	else
	{
		Tokens resultatsql;
		resultatsql = database->strSplit( resultsqlT[0] ,";");

		nameRoyaume = resultatsql[0];
		keyRoyaume = resultatsql[1];
		urlRoyaume = resultatsql[2];
		portRoyaume = database->ToInt(resultatsql[3]);
		autorisationRoyaume = database->ToInt(resultatsql[4]);
		versionClientRoyaume = database->ToInt(resultatsql[5]);
		online_royaume = database->ToBool(resultatsql[6]);

		retour = true ;

	}

	return retour ;

}
bool Royaume::update(int idTransaction)
{
	Tokens resultsqlT;
	return database->executionPrepareStatement(suffix + database->ToString(REALMS_UPD_LISTESROYAUMES),&resultsqlT,idTransaction,8,database->ToString(idRoyaume).c_str(),keyRoyaume.c_str(),nameRoyaume.c_str(),urlRoyaume.c_str(),database->ToString(portRoyaume).c_str(),database->ToString(autorisationRoyaume).c_str(),database->ToString(versionClientRoyaume).c_str(),database->ToString(online_royaume).c_str());

}
bool Royaume::suppr(int idTransaction)
{
	Tokens resultsqlT;
	return  database->executionPrepareStatement(suffix + database->ToString(REALMS_DEL_LISTESROYAUMES),&resultsqlT,idTransaction,1,database->ToString(idRoyaume).c_str());

}

} /* namespace Auth */
