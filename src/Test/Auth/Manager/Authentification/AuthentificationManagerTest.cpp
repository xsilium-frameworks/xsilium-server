/*
 * AuthentificationManagerTest.cpp
 *
 *  Created on: 9 janv. 2016
 *      Author: joda
 */

#ifndef TEST_AUTHENTIFICATIONMANAGER
#define TEST_AUTHENTIFICATIONMANAGER



#include <boost/test/auto_unit_test.hpp>
#include <turtle/mock.hpp>
#include <Manager/Authentification/AuthentificationManager.h>


BOOST_AUTO_TEST_SUITE(AuthentificationManagerTest)

MOCK_BASE_CLASS( IPBanDAOMock , DAO )
{
    MOCK_METHOD( create, 2);
    MOCK_METHOD( update, 2);
    MOCK_METHOD( read, 2);
    MOCK_METHOD( suppr, 2);

};

MOCK_BASE_CLASS( IPDAOMock , DAO )
{
    MOCK_METHOD( create, 2);
    MOCK_METHOD( update, 2);
    MOCK_METHOD( read, 2);
    MOCK_METHOD( suppr, 2);

};


BOOST_AUTO_TEST_CASE(checkIp)
{
    IPBanDAOMock * ipBanDAOMock = new IPBanDAOMock() ;
    IPDAOMock * ipDAOMock = new IPDAOMock();



    Auth::AuthentificationManager * authentificationManager = new Auth::AuthentificationManager(0,0,ipBanDAOMock,ipDAOMock);
    MOCK_EXPECT( ipBanDAOMock->read ).returns( false );
    MOCK_EXPECT( ipDAOMock->read ).returns( false );

    bool resultat =  authentificationManager->checkIp("127.0.0.1");

    mock::verify( *ipBanDAOMock );

    BOOST_CHECK_EQUAL( true , resultat);

    delete authentificationManager;

}

BOOST_AUTO_TEST_SUITE_END()

#endif
