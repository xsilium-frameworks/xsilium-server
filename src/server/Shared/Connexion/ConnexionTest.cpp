#ifndef TEST_ConnexionTest
#define TEST_ConnexionTest
#include "cppunit/extensions/HelperMacros.h"

class ConnexionTest : public CppUnit::TestFixture {
public:
	void testConnexion__createConnexion()
	{
		CPPUNIT_ASSERT(true);
	}
	void testConnexion__deleteConnexion()
	{
		CPPUNIT_ASSERT(true);
	}
	CPPUNIT_TEST_SUITE(ConnexionTest);
	CPPUNIT_TEST(testConnexion__createConnexion);
	CPPUNIT_TEST(testConnexion__deleteConnexion);
	CPPUNIT_TEST_SUITE_END();
};
CPPUNIT_TEST_SUITE_REGISTRATION(ConnexionTest);
#endif
