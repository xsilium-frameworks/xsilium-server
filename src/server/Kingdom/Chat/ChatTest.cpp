/*
 * \file ChatTest.cpp
 *
 *  Created on: \date 17 juin 2013
 *      Author: \author joda
 *  \brief :
 */


#ifndef TEST_ChatTest
#define TEST_ChatTest
#include "cppunit/extensions/HelperMacros.h"

#include "Chat.h"

class ChatTest : public CppUnit::TestFixture {
public:
	void SendMessageToAll()
	{
		Connexion * connexion = new Connexion();
		Chat * chat = new Chat(connexion);

		ENetEvent packet ;

		if ( chat->messageToAll(&packet) == NULL )
		{
			delete chat;
			delete connexion;
			CPPUNIT_ASSERT(true);
		}
		else
		{
			delete chat;
			delete connexion;
			CPPUNIT_ASSERT(false);
		}
	}
	void testChat__deleteConnexion()
	{
		CPPUNIT_ASSERT(true);
	}
	CPPUNIT_TEST_SUITE(ChatTest);
	CPPUNIT_TEST(SendMessageToAll);
	CPPUNIT_TEST(testChat__deleteConnexion);
	CPPUNIT_TEST_SUITE_END();
};
CPPUNIT_TEST_SUITE_REGISTRATION(ChatTest);
#endif

