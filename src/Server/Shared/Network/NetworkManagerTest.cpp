/*
 * \file NetworkManagerTest.cpp
 *
 *  Created on: \date 18 déc. 2014
 *      Author: \author joda
 *  \brief :
 */

#ifndef TEST_DATABASEMANAGER
#define TEST_DATABASEMANAGER

#include "Network/NetworkManager.h"

#include "cppunit/extensions/HelperMacros.h"

class NetworkManagerTest: public CppUnit::TestFixture {
public:
	NetworkManagerTest() {
		networkManager= 0;

	}
	virtual ~NetworkManagerTest() {

	}

	void setUp() {
		networkManager = new NetworkManager();
	}

	void tearDown() {
		delete networkManager;
	}

	void testConnection() {

		ENetAddress adresse;
		adresse.host = ENET_HOST_ANY;
		adresse.port  =60000;

		CPPUNIT_ASSERT_EQUAL(true,networkManager->createConnexion(adresse,1));


	}

	void testDeconnection() {
		ENetAddress adresse;
		adresse.host = ENET_HOST_ANY;
		adresse.port  =60000;

		networkManager->createConnexion(adresse,1);

		CPPUNIT_ASSERT_EQUAL(true,networkManager->deleteConnexion());

	}

	void testErrorConnection() {

		ENetAddress adresse;
		adresse.host = ENET_HOST_ANY;
		adresse.port  =60000;

		networkManager->createConnexion(adresse,1);

		ENetAddress adresse2;
		adresse2.host = ENET_HOST_ANY;
		adresse2.port  =60000;

		CPPUNIT_ASSERT_EQUAL(false,networkManager->createConnexion(adresse2,1));


	}

	CPPUNIT_TEST_SUITE(NetworkManagerTest);
	CPPUNIT_TEST(testConnection);
	CPPUNIT_TEST(testDeconnection);
	CPPUNIT_TEST(testErrorConnection);
	CPPUNIT_TEST_SUITE_END();

private:
	NetworkManager * networkManager;

};

CPPUNIT_TEST_SUITE_REGISTRATION(NetworkManagerTest);

#endif
