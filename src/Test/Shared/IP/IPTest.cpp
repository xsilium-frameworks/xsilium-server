/*
 * \file IPTest.cpp
 *
 *  Created on: \date 21 févr. 2015
 *      Author: \author joda
 *  \brief :
 */
#ifndef TEST_IP
#define TEST_IP


#include <boost/test/unit_test.hpp>

#include <IP/IP.h>

BOOST_AUTO_TEST_SUITE(IPTest)

BOOST_AUTO_TEST_CASE(testIPCreate)
{
	DatabaseManager * databaseManager = DatabaseManager::getInstance();
	databaseManager->createServer(POSTGRESQL);
	BOOST_REQUIRE(databaseManager->connection("172.17.0.21;5432;Xsilium;Xsilium;DevAuth"));

	IP ip("127.0.0.1");
	ip.setIpTempNessais(0);
	BOOST_CHECK(ip.create());

	databaseManager->deconnection();
	DatabaseManager::DestroyInstance();
}

BOOST_AUTO_TEST_CASE(testIPRead)
{
	DatabaseManager * databaseManager = DatabaseManager::getInstance();
	databaseManager->createServer(POSTGRESQL);
	BOOST_REQUIRE(databaseManager->connection("172.17.0.21;5432;Xsilium;Xsilium;DevAuth"));

	IP ip("127.0.0.1");
	BOOST_CHECK(ip.read());

	databaseManager->deconnection();
	DatabaseManager::DestroyInstance();
}

BOOST_AUTO_TEST_CASE(testIPUpdate)
{
	DatabaseManager * databaseManager = DatabaseManager::getInstance();
	databaseManager->createServer(POSTGRESQL);
	BOOST_REQUIRE(databaseManager->connection("172.17.0.21;5432;Xsilium;Xsilium;DevAuth"));

	IP ip("127.0.0.1");

	ip.read();
	ip.setIpTempNessais(1);
	BOOST_CHECK(ip.update());
	IP ip2("127.0.0.1");
	BOOST_CHECK(ip2.read());
	BOOST_CHECK_EQUAL(1,ip2.getIpTempNessais());

	databaseManager->deconnection();
	DatabaseManager::DestroyInstance();
}

BOOST_AUTO_TEST_CASE(testIPDelete)
{
	DatabaseManager * databaseManager = DatabaseManager::getInstance();
	databaseManager->createServer(POSTGRESQL);
	BOOST_REQUIRE(databaseManager->connection("172.17.0.21;5432;Xsilium;Xsilium;DevAuth"));


	IP ip("127.0.0.1");
	BOOST_CHECK(ip.read());
	BOOST_CHECK(ip.suppr());
	IP ip2("127.0.0.1");
	BOOST_CHECK(!ip2.read());

	databaseManager->deconnection();
	DatabaseManager::DestroyInstance();
}

BOOST_AUTO_TEST_SUITE_END()
#endif
