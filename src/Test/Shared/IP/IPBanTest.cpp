/*
 * \file IPBanTest.cpp
 *
 *  Created on: \date 30 mai 2015
 *      Author: \author joda
 *  \brief :
 */

#ifndef TEST_IPBAN
#define TEST_IPBAN

#include <boost/test/unit_test.hpp>

#include <IP/IPBan.h>

BOOST_AUTO_TEST_SUITE(IPBanTest)

BOOST_AUTO_TEST_CASE(testIPBanCreate)
{
	DatabaseManager * databaseManager = DatabaseManager::getInstance();
	databaseManager->createServer(POSTGRESQL);
	BOOST_REQUIRE(databaseManager->connection("192.69.200.6;5432;Xsilium;Xsilium;DevAuth"));

	IPBan ipBan("127.0.0.1");
	ipBan.setBandate(time(NULL));
	ipBan.setBannedby(0);
	ipBan.setRaison("CPPUNIT");
	ipBan.setUnbandate(time(NULL) + 300000);
	BOOST_CHECK(ipBan.create());

	databaseManager->deconnection();
	DatabaseManager::DestroyInstance();
}

BOOST_AUTO_TEST_CASE(testIPBanRead)
{
	DatabaseManager * databaseManager = DatabaseManager::getInstance();
	databaseManager->createServer(POSTGRESQL);
	BOOST_REQUIRE(databaseManager->connection("192.69.200.6;5432;Xsilium;Xsilium;DevAuth"));

	IPBan ipBan("127.0.0.1");
	BOOST_CHECK(ipBan.read());

	databaseManager->deconnection();
	DatabaseManager::DestroyInstance();
}

BOOST_AUTO_TEST_CASE(testIPBanUpdate)
{
	DatabaseManager * databaseManager = DatabaseManager::getInstance();
	databaseManager->createServer(POSTGRESQL);
	BOOST_REQUIRE(databaseManager->connection("192.69.200.6;5432;Xsilium;Xsilium;DevAuth"));

	IPBan ip("127.0.0.1");
	ip.read();
	ip.setBannedby(1);
	BOOST_CHECK(ip.update());

	IPBan ip2("127.0.0.1");
	BOOST_CHECK(ip2.read());
	BOOST_CHECK_EQUAL(ip2.getBannedby(),1);

	databaseManager->deconnection();
	DatabaseManager::DestroyInstance();
}

BOOST_AUTO_TEST_CASE(testIPBanDelete)
{
	DatabaseManager * databaseManager = DatabaseManager::getInstance();
	databaseManager->createServer(POSTGRESQL);
	BOOST_REQUIRE(databaseManager->connection("192.69.200.6;5432;Xsilium;Xsilium;DevAuth"));

	IPBan ip("127.0.0.1");
	ip.read();
	ip.suppr();
	IPBan ip2("127.0.0.1");
	BOOST_CHECK(!ip2.read());

	databaseManager->deconnection();
	DatabaseManager::DestroyInstance();
}

BOOST_AUTO_TEST_SUITE_END()
#endif
