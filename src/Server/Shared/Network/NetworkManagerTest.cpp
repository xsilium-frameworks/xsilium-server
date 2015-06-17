/*
 * \file NetworkManagerTest.cpp
 *
 *  Created on: \date 18 déc. 2014
 *      Author: \author joda
 *  \brief :
 */

#ifndef TEST_DATABASEMANAGER
#define TEST_DATABASEMANAGER


#include <boost/test/unit_test.hpp>

#include <Network/NetworkManager.h>

BOOST_AUTO_TEST_SUITE(NetworkManagerTest)

BOOST_AUTO_TEST_CASE(testConnection)
{
	NetworkManager * networkManager = new NetworkManager(NETWORK_TYPE_SERVER);

	ENetAddress adresse;
	adresse.host = ENET_HOST_ANY;
	adresse.port  =60003;

	BOOST_CHECK(networkManager->createConnexion(adresse,1));

	networkManager->disconnexion();

	delete networkManager;
}

/*BOOST_AUTO_TEST_CASE(testDeconnection)
{
	NetworkManager * networkManager = new NetworkManager(NETWORK_TYPE_SERVER);
	ENetAddress adresse;
	adresse.host = ENET_HOST_ANY;
	adresse.port  =60004;

	BOOST_REQUIRE(networkManager->createConnexion(adresse,1));

	BOOST_CHECK(networkManager->disconnexion());

	delete networkManager;

}

BOOST_AUTO_TEST_CASE(testErrorConnection)
{
	NetworkManager * networkManager = new NetworkManager(NETWORK_TYPE_SERVER);

	ENetAddress adresse;
	adresse.host = ENET_HOST_ANY;
	adresse.port  =60005;

	BOOST_REQUIRE(networkManager->createConnexion(adresse,1));

	ENetAddress adresse2;
	adresse2.host = ENET_HOST_ANY;
	adresse2.port  =60005;

	BOOST_CHECK(!networkManager->createConnexion(adresse2,1));

	delete networkManager;


}*/

BOOST_AUTO_TEST_SUITE_END()
#endif
