/*
 * \file IPTest.cpp
 *
 *  Created on: \date 21 févr. 2015
 *      Author: \author joda
 *  \brief :
 */
#ifndef TEST_IP
#define TEST_IP

#include "IP.h"

#include <cppunit/extensions/HelperMacros.h>

class IPTest: public CppUnit::TestFixture {
public:
	IPTest() {
		databaseManager = 0;

	}
	virtual ~IPTest() {

	}

	void setUp() {
		databaseManager = DatabaseManager::getInstance();

		databaseManager->createServer(0);
		databaseManager->connection("192.168.200.6;5432;Xsilium;Xsilium;DevAuth");
	}

	void tearDown() {
		databaseManager->deconnection();
		DatabaseManager::DestroyInstance();
	}

	void testIPCreate()
	{
		IP ip("127.0.0.1");
		ip.setIpTempNessais(0);
		CPPUNIT_ASSERT_EQUAL(true,ip.create());
	}

	void testIPRead()
	{
		IP ip("127.0.0.1");
		CPPUNIT_ASSERT_EQUAL(true,ip.read());
	}

	void testIPUpdate()
	{
		IP ip("127.0.0.1");
		IP ip2("127.0.0.1");
		ip.read();
		ip.setIpTempNessais(1);
		ip.update();

		ip2.read();


		CPPUNIT_ASSERT_EQUAL(1,ip2.getIpTempNessais());
	}

	void testIPDelete()
	{
		IP ip("127.0.0.1");
		IP ip2("127.0.0.1");
		ip.read();
		ip.suppr();
		CPPUNIT_ASSERT_EQUAL(false,ip2.read());
	}



	CPPUNIT_TEST_SUITE(IPTest);
	CPPUNIT_TEST_SUITE_END();

private:
	DatabaseManager * databaseManager;

};

CPPUNIT_TEST_SUITE_REGISTRATION(IPTest);

#endif
