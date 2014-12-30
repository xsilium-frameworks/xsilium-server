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
		CPPUNIT_ASSERT(configuration->Load("Erreur"));
	}

	void testLoadPass()
	{
		CPPUNIT_ASSERT(configuration->Load("TestConfig.config"));
	}

	void testContainsFail()
	{
		configuration->Load("TestConfig.config");
		CPPUNIT_ASSERT(configuration->Contains("testErreur"));
	}

	void testContainsPass()
	{
		configuration->Load("TestConfig.config");
		CPPUNIT_ASSERT(configuration->Contains("testInt"));
	}

	void testGetStringPass()
	{
		std::string testString;
		configuration->Load("TestConfig.config");

		configuration->Get("testString",testString);
		CPPUNIT_ASSERT(testString.compare("Test"));
	}

	void testGetIntPass()
	{
		int testInt;
		configuration->Load("TestConfig.config");

		configuration->Get("testInt",testInt);
		CPPUNIT_ASSERT(testInt == 4);
	}



//    bool Get(const string& key, int&    value) const;
//	  bool Get(const string& key, long&   value) const;
//    bool Get(const string& key, double& value) const;
//    bool Get(const string& key, bool&   value) const;

	CPPUNIT_TEST_SUITE(ConfigurationTest);
	CPPUNIT_TEST(testLoadFail);
	CPPUNIT_TEST(testLoadPass);
	CPPUNIT_TEST(testContainsPass);
	CPPUNIT_TEST(testContainsFail);
	CPPUNIT_TEST(testGetStringPass);
	CPPUNIT_TEST(testGetIntPass);

	CPPUNIT_TEST_SUITE_END();


};
CPPUNIT_TEST_SUITE_REGISTRATION(ConfigurationTest);
#endif


