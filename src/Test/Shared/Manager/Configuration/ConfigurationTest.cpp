/*
 * \file ConfigurationTest.cpp
 *
 *  Created on: \date 20 janv. 2014
 *      Author: \author joda
 *  \brief :
 */


#ifndef TEST_ConfigurationTest
#define TEST_ConfigurationTest


#include <boost/test/auto_unit_test.hpp>

#include <Manager/Configuration/ConfigurationManager.h>


BOOST_AUTO_TEST_SUITE(ConfigurationTest)

BOOST_AUTO_TEST_CASE(testLoadFail)
{
    ConfigurationManager * configurationManager = ConfigurationManager::getInstance();
	BOOST_CHECK_EQUAL(configurationManager->load("Erreur"), false );
	ConfigurationManager::DestroyInstance();
}

BOOST_AUTO_TEST_CASE(testLoadPass)
{
	ConfigurationManager * configurationManager = ConfigurationManager::getInstance();
	BOOST_CHECK_EQUAL(configurationManager->load("./TestConfig.config"), true );
	ConfigurationManager::DestroyInstance();
}

BOOST_AUTO_TEST_CASE(testContainsFail)
{
	ConfigurationManager * configurationManager = ConfigurationManager::getInstance();
	configurationManager->load("./TestConfig.config");
	BOOST_CHECK_EQUAL(configurationManager->contains("testErreur"), false );
	ConfigurationManager::DestroyInstance();
}

BOOST_AUTO_TEST_CASE(testContainsPass)
{
	ConfigurationManager * configurationManager = ConfigurationManager::getInstance();
	configurationManager->load("./TestConfig.config");
	BOOST_CHECK_EQUAL(configurationManager->contains("testInt"), true );
	ConfigurationManager::DestroyInstance();
}

BOOST_AUTO_TEST_CASE(testGetStringPass)
{
	ConfigurationManager * configurationManager = ConfigurationManager::getInstance();
	std::string testString;

	configurationManager->load("./TestConfig.config");
	configurationManager->get("testString",testString);

	BOOST_CHECK_EQUAL(testString.compare("Test"), false );
	ConfigurationManager::DestroyInstance();
}

BOOST_AUTO_TEST_CASE(testGetIntPass)
{
	ConfigurationManager * configurationManager = ConfigurationManager::getInstance();
	int testInt;

	configurationManager->load("./TestConfig.config");
	configurationManager->get("testInt",testInt);

	BOOST_CHECK_EQUAL(testInt,4);
	ConfigurationManager::DestroyInstance();
}

BOOST_AUTO_TEST_CASE(testGetLongPass)
{
	ConfigurationManager * configurationManager = ConfigurationManager::getInstance();
	long testLong;

	configurationManager->load("./TestConfig.config");
	configurationManager->get("testLong",testLong);

	BOOST_CHECK_EQUAL(testLong,(long) 100000 );
	ConfigurationManager::DestroyInstance();
}

BOOST_AUTO_TEST_CASE(testGetDoublePass)
{
	ConfigurationManager * configurationManager = ConfigurationManager::getInstance();
	double testDouble;

	configurationManager->load("./TestConfig.config");
	configurationManager->get("testDouble",testDouble);

	BOOST_CHECK_EQUAL(testDouble,2.3 );
	ConfigurationManager::DestroyInstance();
}

BOOST_AUTO_TEST_CASE(testGetBoolPass)
{
	ConfigurationManager * configurationManager = ConfigurationManager::getInstance();
	bool testBool;

	configurationManager->load("./TestConfig.config");
	configurationManager->get("testBool",testBool);

	BOOST_CHECK_EQUAL(testBool,true );
	ConfigurationManager::DestroyInstance();
}

BOOST_AUTO_TEST_SUITE_END()
#endif
