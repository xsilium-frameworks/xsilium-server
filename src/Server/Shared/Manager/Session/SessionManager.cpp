/*
 * \file SessionManager.cpp
 *
 *  Created on: \date 17 déc. 2014
 *      Author: \author joda
 *  \brief :
 */
#include "SessionManager.h"

SessionManager::SessionManager() {
	log = LogManager::getInstance();
}

SessionManager::~SessionManager() {
	// TODO Auto-generated destructor stub
}

Session * SessionManager::trouverSession(ENetAddress address)
{
	boost::mutex::scoped_lock lock(mutexSession);
	std::vector<Session *>::iterator session ;
	for (session=listOfSession.begin() ; session!=listOfSession.end() ; ++session)
	{
		if((*session)->getSessionID()->host == address.host)
		{
			if((*session)->getSessionID()->port == address.port)
			{
				log->write(LogManager::INFO,"La Session avec l'IP : %d, Port : %d a ete trouve ",address.host,address.port);
				return (*session);
			}
		}
	}
	log->write(LogManager::INFO,"Le Session avec l'IP : %d, Port : %d n'a pas ete trouve ",address.host,address.port);
	return NULL;
}

void SessionManager::creerSession(ENetPeer * peer)
{
	Session * sessionTemp = new Session();
	sessionTemp->setSessionPeer(peer);
	boost::mutex::scoped_lock lock(mutexSession);
	log->write(LogManager::INFO,"Creation d'une nouvelle Session avec IP : %d , Port: %d",peer->address.host,peer->address.port);
	listOfSession.push_back(sessionTemp);
}

void SessionManager::supprimerSession(ENetPeer * peer)
{
	boost::mutex::scoped_lock lock(mutexSession);
	std::vector<Session *>::iterator session ;
	for (session=listOfSession.begin() ; session!=listOfSession.end() ; ++session)
	{
		if((*session)->getSessionID()->host == peer->address.host)
		{
			if((*session)->getSessionID()->port == peer->address.port)
			{
				log->write(LogManager::INFO,"deconnexion de la Session avec IP : %d, Port : %d ",peer->address.host,peer->address.port);
				delete *session;
				session = listOfSession.erase(session);
			}
		}
	}
}


