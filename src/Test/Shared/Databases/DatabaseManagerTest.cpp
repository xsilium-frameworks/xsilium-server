/*
 * \file DatabaseManagerTest.cpp
 *
 *  Created on: \date 23 oct. 2014
 *      Author: \author joda
 *  \brief :
 */

#ifndef TEST_DATABASEMANAGER
#define TEST_DATABASEMANAGER


#include <boost/test/unit_test.hpp>

#include <Databases/DatabaseManager.h>


BOOST_AUTO_TEST_SUITE(DatabaseManagerTest)

BOOST_AUTO_TEST_CASE(testConnection)
{
	DatabaseManager * databaseManager = DatabaseManager::getInstance();
	databaseManager->createServer(POSTGRESQL);
	BOOST_CHECK_EQUAL(databaseManager->connection("172.17.0.21;5432;Xsilium;Xsilium;DevAuth"), true);
	databaseManager->deconnection();
	DatabaseManager::DestroyInstance();
}


BOOST_AUTO_TEST_CASE(testNonConnection)
{
	DatabaseManager * databaseManager = DatabaseManager::getInstance();
	databaseManager->createServer(POSTGRESQL);
	BOOST_CHECK_EQUAL(databaseManager->connection("127.0.0.1;5432;Xsilium;Xsilium;DevAuth"), false);
	databaseManager->deconnection();
	DatabaseManager::DestroyInstance();
}

BOOST_AUTO_TEST_CASE(testDeconnection)
{
	DatabaseManager * databaseManager = DatabaseManager::getInstance();
	databaseManager->createServer(POSTGRESQL);
	BOOST_REQUIRE(databaseManager->connection("172.17.0.21;5432;Xsilium;Xsilium;DevAuth"));
	BOOST_CHECK(databaseManager->deconnection());
	DatabaseManager::DestroyInstance();
}

BOOST_AUTO_TEST_CASE(testSelect)
{
	Tokens resultat;
	DatabaseManager * databaseManager = DatabaseManager::getInstance();
	databaseManager->createServer(POSTGRESQL);
	BOOST_REQUIRE(databaseManager->connection("172.17.0.21;5432;Xsilium;Xsilium;DevAuth"));
	databaseManager->prepareStatement("test1","select 2");
	BOOST_CHECK(databaseManager->executionPrepareStatement("test1",&resultat));
	databaseManager->deconnection();
	DatabaseManager::DestroyInstance();
}


BOOST_AUTO_TEST_CASE(testSelectCommit)
{
	Tokens resultat;
	DatabaseManager * databaseManager = DatabaseManager::getInstance();
	databaseManager->createServer(POSTGRESQL);
	BOOST_REQUIRE(databaseManager->connection("172.17.0.21;5432;Xsilium;Xsilium;DevAuth"));
	databaseManager->prepareStatement("test1","select 2");
	int commit = databaseManager->createTransaction();
	BOOST_CHECK(databaseManager->executionPrepareStatement("test1",&resultat,commit));
	databaseManager->commit(commit);
	BOOST_CHECK_EQUAL(resultat[0].compare("2"),false);
	databaseManager->deconnection();
	DatabaseManager::DestroyInstance();
}

BOOST_AUTO_TEST_SUITE_END()

#endif
