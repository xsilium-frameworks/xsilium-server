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

	CompteTest()
	{
		compte = 0;
		realms = 0;
	};
	virtual ~CompteTest(){};

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

	void testLockCompte()
	{
		compte = new Compte();
		compte->chargementCompte("Joda");
		compte->lockCompte();
		CPPUNIT_ASSERT(compte->islocked() == true);
	}

	void testUnLockCompte()
	{
		compte = new Compte();
		compte->chargementCompte("Joda");
		compte->unlockCompte();
		CPPUNIT_ASSERT(compte->islocked() == false);
	}

	void testGetNiveauCompte()
	{
		compte = new Compte();
		compte->chargementCompte("Joda");
		CPPUNIT_ASSERT(compte->getNiveauCompte() == 0);
	}

	void testGetEtapeConnextion()
	{
		compte = new Compte();
		compte->chargementCompte("Joda");
		compte->setEtapeConnexion(1);
		CPPUNIT_ASSERT(compte->getEtapeConnextion() == 1);
	}

	void testSetNombreEssai()
	{
		compte = new Compte();
		compte->chargementCompte("Joda");
		compte->setNombreEssai(1);
		CPPUNIT_ASSERT(true);
	}

	void testGetNombreEssai()
	{
		compte = new Compte();
		compte->chargementCompte("Joda");
		CPPUNIT_ASSERT(compte->getNombreEssai() == 1);
	}


	/*
	void setLastIP(std::string lastIP);
	std::string * getLastIP();

	void banCompte(time_t unbandate,const char * raison,int bannedby);
	void unbanCompte();
	bool isBanned();

	time_t * getAccountUnBanDate();

	 */

	CPPUNIT_TEST_SUITE(CompteTest);
	CPPUNIT_TEST(testUserErreur);
	CPPUNIT_TEST(testUserOk);
	CPPUNIT_TEST(testGetIdLogin);
	CPPUNIT_TEST(testGetNomCompte);
	CPPUNIT_TEST(testLockCompte);
	CPPUNIT_TEST(testUnLockCompte);
	CPPUNIT_TEST(testGetNiveauCompte);
	CPPUNIT_TEST(testGetEtapeConnextion);
	CPPUNIT_TEST(testSetNombreEssai);
	CPPUNIT_TEST(testGetNombreEssai);
	CPPUNIT_TEST_SUITE_END();


};
CPPUNIT_TEST_SUITE_REGISTRATION(CompteTest);


#endif


