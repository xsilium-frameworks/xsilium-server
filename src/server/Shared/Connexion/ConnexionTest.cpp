#ifndef TEST_ConnexionTest
#define TEST_ConnexionTest
#include "cppunit/extensions/HelperMacros.h"

#include "Connexion.h"

class ConnexionTest : public CppUnit::TestFixture {
public:
	void createConnexionDeconnexion()
	{
		ENetAddress adresse;
		bool flagTest = true;

		Connexion *connexiontToClient = new Connexion();
		adresse.host = ENET_HOST_ANY;
		adresse.port  = (enet_uint16) 60000;

		flagTest = connexiontToClient->createConnexion(adresse,100);

		if(!flagTest)
			CPPUNIT_ASSERT(flagTest);
		else
		{
			flagTest = connexiontToClient->deleteConnexion();

			if(!flagTest)
				CPPUNIT_ASSERT(flagTest);
		}
		delete connexiontToClient;
	}

	CPPUNIT_TEST_SUITE(ConnexionTest);
	CPPUNIT_TEST(createConnexionDeconnexion);
	CPPUNIT_TEST_SUITE_END();

};
CPPUNIT_TEST_SUITE_REGISTRATION(ConnexionTest);
#endif
