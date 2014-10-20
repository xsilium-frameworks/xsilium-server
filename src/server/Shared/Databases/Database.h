/*
 * \file Database.h
 *
 *  Created on: \date 20 oct. 2014
 *      Author: \author joda
 *  \brief :
 */
#ifndef SRC_SERVER_SHARED_DATABASES_DATABASE_H_
#define SRC_SERVER_SHARED_DATABASES_DATABASE_H_


class Database
{
public:
	Database();
	virtual ~Database();

	virtual bool Connection();
	virtual bool Deconnection();
	virtual void Select();
	virtual void Insert();
	virtual void Delete();
	virtual void Update();
	virtual void GetTransaction();
	virtual void Commit();

};


#endif /* SRC_SERVER_SHARED_DATABASES_DATABASE_H_ */
