/*
 * \file ConfigurationTest.cpp
 *
 *  Created on: \date 20 janv. 2014
 *      Author: \author joda
 *  \brief :
 */


#ifndef TEST_ConfigurationTest
#define TEST_ConfigurationTest


#include <boost/test/unit_test.hpp>

#include <Configuration/Configuration.h>


BOOST_AUTO_TEST_SUITE(ConfigurationTest)

BOOST_AUTO_TEST_CASE(testLoadFail)
{
	Configuration * configuration = Configuration::getInstance();
	BOOST_CHECK_EQUAL(configuration->load("Erreur"), false );
	Configuration::DestroyInstance();
}

BOOST_AUTO_TEST_CASE(testLoadPass)
{
	Configuration * configuration = Configuration::getInstance();
	BOOST_CHECK_EQUAL(configuration->load("./TestConfig.config"), true );
	Configuration::DestroyInstance();
}

BOOST_AUTO_TEST_CASE(testContainsFail)
{
	Configuration * configuration = Configuration::getInstance();
	configuration->load("./TestConfig.config");
	BOOST_CHECK_EQUAL(configuration->contains("testErreur"), false );
	Configuration::DestroyInstance();
}

BOOST_AUTO_TEST_CASE(testContainsPass)
{
	Configuration * configuration = Configuration::getInstance();
	configuration->load("./TestConfig.config");
	BOOST_CHECK_EQUAL(configuration->contains("testInt"), true );
	Configuration::DestroyInstance();
}

BOOST_AUTO_TEST_CASE(testGetStringPass)
{
	Configuration * configuration = Configuration::getInstance();
	std::string testString;

	configuration->load("./TestConfig.config");
	configuration->get("testString",testString);

	BOOST_CHECK_EQUAL(testString.compare("Test"), false );
	Configuration::DestroyInstance();
}

BOOST_AUTO_TEST_CASE(testGetIntPass)
{
	Configuration * configuration = Configuration::getInstance();
	int testInt;

	configuration->load("./TestConfig.config");
	configuration->get("testInt",testInt);

	BOOST_CHECK_EQUAL(testInt,4);
	Configuration::DestroyInstance();
}

BOOST_AUTO_TEST_CASE(testGetLongPass)
{
	Configuration * configuration = Configuration::getInstance();
	long testLong;

	configuration->load("./TestConfig.config");
	configuration->get("testLong",testLong);

	BOOST_CHECK_EQUAL(testLong,(long) 100000 );
	Configuration::DestroyInstance();
}

BOOST_AUTO_TEST_CASE(testGetDoublePass)
{
	Configuration * configuration = Configuration::getInstance();
	double testDouble;

	configuration->load("./TestConfig.config");
	configuration->get("testDouble",testDouble);

	BOOST_CHECK_EQUAL(testDouble,2.3 );
	Configuration::DestroyInstance();
}

BOOST_AUTO_TEST_CASE(testGetBoolPass)
{
	Configuration * configuration = Configuration::getInstance();
	bool testBool;

	configuration->load("./TestConfig.config");
	configuration->get("testBool",testBool);

	BOOST_CHECK_EQUAL(testBool,true );
	Configuration::DestroyInstance();
}

BOOST_AUTO_TEST_SUITE_END()
#endif
