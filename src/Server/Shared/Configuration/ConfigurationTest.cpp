/*
 * \file ConfigurationTest.cpp
 *
 *  Created on: \date 20 janv. 2014
 *      Author: \author joda
 *  \brief :
 */


#ifndef TEST_ConfigurationTest
#define TEST_ConfigurationTest
#include "cppunit/extensions/HelperMacros.h"

#include "Configuration.h"


class ConfigurationTest : public CppUnit::TestFixture {

private:
	Configuration * configuration;

public:
	ConfigurationTest()
	{
		configuration = 0;
	}

	virtual ~ConfigurationTest(){};

	//~ Call before tests
	void setUp(void)
	{
		configuration = Configuration::getInstance();
	}
	//~ Call after tests
	void tearDown(void)
	{
		Configuration::DestroyInstance();
	}

	void testLoadFail()
	{
		CPPUNIT_ASSERT_EQUAL(false,configuration->load("Erreur"));
	}

	void testLoadPass()
	{
		CPPUNIT_ASSERT(configuration->load("./TestConfig.config"));
	}

	void testContainsFail()
	{
		configuration->load("./TestConfig.config");
		CPPUNIT_ASSERT_EQUAL(false,configuration->contains("testErreur"));
	}

	void testContainsPass()
	{
		configuration->load("./TestConfig.config");
		CPPUNIT_ASSERT(configuration->contains("testInt"));
	}

	void testGetStringPass()
	{
		std::string testString;
		configuration->load("./TestConfig.config");

		configuration->get("testString",testString);
		CPPUNIT_ASSERT_EQUAL(0,testString.compare("Test"));
	}

	void testGetIntPass()
	{
		int testInt;
		configuration->load("./TestConfig.config");

		configuration->get("testInt",testInt);
		CPPUNIT_ASSERT_EQUAL(4,testInt);
	}

	void testGetLongPass()
	{
		long testLong;
		configuration->load("./TestConfig.config");
		configuration->get("testLong",testLong);
		CPPUNIT_ASSERT_EQUAL( (long) 100000,testLong);
	}

	void testGetDoublePass()
	{
		double testDouble;
		configuration->load("./TestConfig.config");

		configuration->get("testDouble",testDouble);
		CPPUNIT_ASSERT_EQUAL(2.3,testDouble);
	}

	void testGetBoolPass()
		{
			bool testBool;
			configuration->load("./TestConfig.config");

			configuration->get("testBool",testBool);
			CPPUNIT_ASSERT_EQUAL(true,testBool);
		}

	CPPUNIT_TEST_SUITE(ConfigurationTest);
	CPPUNIT_TEST(testLoadFail);
	CPPUNIT_TEST(testLoadPass);
	CPPUNIT_TEST(testContainsPass);
	CPPUNIT_TEST(testContainsFail);
	CPPUNIT_TEST(testGetStringPass);
	CPPUNIT_TEST(testGetIntPass);
	CPPUNIT_TEST(testGetLongPass);
	CPPUNIT_TEST(testGetDoublePass);
	CPPUNIT_TEST(testGetBoolPass);

	CPPUNIT_TEST_SUITE_END();


};
CPPUNIT_TEST_SUITE_REGISTRATION(ConfigurationTest);
#endif
