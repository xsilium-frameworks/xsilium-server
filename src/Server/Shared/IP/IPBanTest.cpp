/*
 * \file IPBanTest.cpp
 *
 *  Created on: \date 30 mai 2015
 *      Author: \author joda
 *  \brief :
 */

#ifndef TEST_IPBAN
#define TEST_IPBAN

#include "IPBan.h"

#include <cppunit/extensions/HelperMacros.h>

class IPBanTest: public CppUnit::TestFixture {
public:
	IPBanTest() {
		databaseManager = 0;

	}
	virtual ~IPBanTest() {

	}

	void setUp() {
		databaseManager = DatabaseManager::getInstance();

		databaseManager->createServer(0);
		databaseManager->connection("192.69.200.6;5432;Xsilium;Xsilium;DevAuth");
	}

	void tearDown() {
		databaseManager->deconnection();
		DatabaseManager::DestroyInstance();
	}

	void testIPBanCreate()
	{
		IPBan ipBan("127.0.0.1");
		ipBan.setBandate(time(NULL));
		ipBan.setBannedby(0);
		ipBan.setRaison("CPPUNIT");
		ipBan.setUnbandate(time(NULL) + 300000);
		CPPUNIT_ASSERT_EQUAL(true,ipBan.create());
	}

	void testIPBanRead()
	{
		IPBan ipBan("127.0.0.1");
		CPPUNIT_ASSERT_EQUAL(true,ipBan.read());
	}

	void testIPBanUpdate()
	{
		IPBan ip("127.0.0.1");
		IPBan ip2("127.0.0.1");
		ip.read();
		ip.setBannedby(1);
		ip.update();

		ip2.read();

		CPPUNIT_ASSERT_EQUAL(1,ip2.getBannedby());
	}

	void testIPBanDelete()
	{
		IPBan ip("127.0.0.1");
		ip.read();
		//ip.suppr();
		//IPBan ip2("127.0.0.1");
		//CPPUNIT_ASSERT_EQUAL(false,ip2.read());
	}



	CPPUNIT_TEST_SUITE(IPBanTest);
	CPPUNIT_TEST(testIPBanCreate);
	CPPUNIT_TEST(testIPBanRead);
	CPPUNIT_TEST(testIPBanUpdate);
	CPPUNIT_TEST(testIPBanDelete);
	CPPUNIT_TEST_SUITE_END();

private:
	DatabaseManager * databaseManager;

};

CPPUNIT_TEST_SUITE_REGISTRATION(IPBanTest);

#endif
