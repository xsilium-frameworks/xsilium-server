/*
 * \file DatabaseManagerTest.cpp
 *
 *  Created on: \date 23 oct. 2014
 *      Author: \author joda
 *  \brief :
 */

#ifndef TEST_DATABASEMANAGER
#define TEST_DATABASEMANAGER

#include <Databases/DatabaseManager.h>

#include <cppunit/extensions/HelperMacros.h>

class DatabaseManagerTest: public CppUnit::TestFixture {
public:
	DatabaseManagerTest() {
		databaseManager = 0;

	}
	virtual ~DatabaseManagerTest() {

	}

	void setUp() {
		databaseManager = DatabaseManager::getInstance();
	}

	void tearDown() {
		DatabaseManager::DestroyInstance();
	}

	void testConnection() {

		databaseManager->createServer(0);
		CPPUNIT_ASSERT_EQUAL(true,
				databaseManager->connection(
						"192.69.200.6;5432;Xsilium;Xsilium;DevAuth"));

	}

	void testNonConnection() {

		databaseManager->createServer(0);
		CPPUNIT_ASSERT_EQUAL(false,
				databaseManager->connection(
						"127.0.0.1;5432;Xsilium;Xsilium;DevAuth"));

	}

	void testDeconnection() {
		databaseManager->createServer(0);
		if(databaseManager->connection("192.69.200.6;5432;Xsilium;Xsilium;DevAuth"))
			CPPUNIT_ASSERT_EQUAL(true, databaseManager->deconnection());

	}

	void testNonDeconnection() {
		databaseManager->createServer(0);
		databaseManager->connection("127.0.0.1;5432;Xsilium;Xsilium;DevAuth");

		CPPUNIT_ASSERT_EQUAL(false, databaseManager->deconnection());

	}

	void testSelect()
	{
		databaseManager->createServer(0);
		databaseManager->connection("192.69.200.6;5432;Xsilium;Xsilium;DevAuth");

		databaseManager->prepareStatement("test1","select 2");
		Tokens resultat =  databaseManager->executionPrepareStatement("test1");

		CPPUNIT_ASSERT_EQUAL(0, resultat[0].compare("2")   );

		databaseManager->deconnection();

	}

	void testSelectCommit()
	{
		databaseManager->createServer(0);
		databaseManager->connection("192.69.200.6;5432;Xsilium;Xsilium;DevAuth");

		databaseManager->prepareStatement("test1","select 2");
		int commit = databaseManager->createTransaction();
		Tokens resultat =  databaseManager->executionPrepareStatement("test1",commit);
		databaseManager->commit(commit);

		CPPUNIT_ASSERT_EQUAL(0, resultat[0].compare("2")   );

		databaseManager->deconnection();

	}

	CPPUNIT_TEST_SUITE(DatabaseManagerTest);
	CPPUNIT_TEST(testConnection);
	CPPUNIT_TEST(testNonConnection);
	CPPUNIT_TEST(testDeconnection);
	CPPUNIT_TEST(testNonDeconnection);
	CPPUNIT_TEST(testSelect);
	CPPUNIT_TEST(testSelectCommit);
	CPPUNIT_TEST_SUITE_END();

private:
	DatabaseManager * databaseManager;

};

CPPUNIT_TEST_SUITE_REGISTRATION(DatabaseManagerTest);

#endif
