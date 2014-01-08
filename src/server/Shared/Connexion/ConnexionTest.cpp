#ifndef TEST_ConnexionTest
#define TEST_ConnexionTest
#include "cppunit/extensions/HelperMacros.h"

#include "Connexion.h"


class ConnexionTest : public CppUnit::TestFixture {

private:
	Connexion * connexiontToClient;

public:
    //~ Call before tests
    void setUp(void)
    {
    }
    //~ Call after tests
    void tearDown(void)
    {
    }

	void createConnexion()
	{
		ENetAddress adresse;
		bool flagTest = false;


		connexiontToClient = new Connexion();
		adresse.host = ENET_HOST_ANY;
		adresse.port  = (enet_uint16) 60000;

		flagTest = connexiontToClient->createConnexion(adresse,100);

		CPPUNIT_ASSERT(flagTest);
	}

	void deleteConnexion()
	{
		bool flagTest = false;
		//flagTest = connexiontToClient->deleteConnexion();

		delete connexiontToClient;
		CPPUNIT_ASSERT(flagTest);
	}


	CPPUNIT_TEST_SUITE(ConnexionTest);
	CPPUNIT_TEST(createConnexion);
	CPPUNIT_TEST(deleteConnexion);
	CPPUNIT_TEST_SUITE_END();


};
CPPUNIT_TEST_SUITE_REGISTRATION(ConnexionTest);
#endif
