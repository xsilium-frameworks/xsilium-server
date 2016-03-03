/*
 * \file NetworkManagerTest.cpp
 *
 *  Created on: \date 18 déc. 2014
 *      Author: \author joda
 *  \brief :
 */

#ifndef TEST_DATABASEMANAGER
#define TEST_DATABASEMANAGER

#include <boost/test/auto_unit_test.hpp>

#include <Manager/Network/NetworkManager.h>

BOOST_AUTO_TEST_SUITE (NetworkManagerTest)

BOOST_AUTO_TEST_CASE(testConnection)
{
    NetworkManager * networkManager = new NetworkManager();

    ENetAddress adresse;
    adresse.host = ENET_HOST_ANY;
    adresse.port =60003;

    BOOST_CHECK(networkManager->createConnexion(&adresse,1));

    networkManager->disconnexion();

    delete networkManager;
}

BOOST_AUTO_TEST_CASE(testErrorConnection)
{
    NetworkManager * networkManager = new NetworkManager();

    ENetAddress adresse;
    adresse.host = ENET_HOST_ANY;
    adresse.port =60003;

    BOOST_REQUIRE(networkManager->createConnexion(&adresse,1));

    ENetAddress adresse2;
    adresse2.host = ENET_HOST_ANY;
    adresse2.port =60003;

    BOOST_CHECK(!networkManager->createConnexion(&adresse2,1));

    networkManager->disconnexion();
    delete networkManager;

}

BOOST_AUTO_TEST_SUITE_END()
#endif
