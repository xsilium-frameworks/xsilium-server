/*
 * \file CompteTest.cpp
 *
 *  Created on: \date 8 janv. 2014
 *      Author: \author joda
 *  \brief :
 */
#ifndef TEST_CompteTest
#define TEST_CompteTest


#include "cppunit/extensions/HelperMacros.h"
#include "Compte.h"

class CompteTest : public CppUnit::TestFixture {

private:
	LoginDatabase * realms ;
	Compte * compte;

public:
	//~ Call before tests
	void setUp(void)
	{
		realms = LoginDatabase::getInstance();
		realms->connexionDB("192.168.1.2;5432;Xsilium;Xsilium;Developpement");
	}
	//~ Call after tests
	void tearDown(void)
	{
		realms->deconnexionDB();
		LoginDatabase::DestroyInstance();
		delete compte;
	}

	void testUserErreur()
	{
		compte = new Compte();
		CPPUNIT_ASSERT(compte->chargementCompte("Erreur") == false);
	}

	void testUserOk()
	{
		compte = new Compte();
		CPPUNIT_ASSERT(compte->chargementCompte("Joda") == true);
	}

	void testGetIdLogin()
	{
		compte = new Compte();
		compte->chargementCompte("Joda");
		CPPUNIT_ASSERT(compte->getIdLogin() == 1);
	}

	void testGetNomCompte()
	{
		compte = new Compte();
		compte->chargementCompte("Joda");
		CPPUNIT_ASSERT(compte->getNomCompte()->compare("Joda") == false);
	}

	/*
	std::string * getMDPSHA();

	void lockCompte();
	void unlockCompte();
	bool islocked();

	void setLastIP(std::string lastIP);
	std::string * getLastIP();

	uint8_t getNiveauCompte();

	void banCompte(time_t unbandate,const char * raison,int bannedby);
	void unbanCompte();
	bool isBanned();

	time_t * getAccountUnBanDate();

	void setEtapeConnexion(uint8_t etape );
	uint8_t getEtapeConnextion();

	void setNombreEssai(uint8_t essai);
	uint8_t getNombreEssai();

*/

	CPPUNIT_TEST_SUITE(CompteTest);
	CPPUNIT_TEST(testUserErreur);
	CPPUNIT_TEST(testUserOk);
	CPPUNIT_TEST(testGetIdLogin);
	CPPUNIT_TEST(testGetNomCompte);
	CPPUNIT_TEST_SUITE_END();


};
CPPUNIT_TEST_SUITE_REGISTRATION(CompteTest);


#endif


