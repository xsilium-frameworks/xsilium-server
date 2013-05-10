/*
 * \file GestionnaireSession.cpp
 *
 *  Created on: \date 12 janv. 2013
 *      Author: \author joda
 *  \brief :
 */

#include "GestionnaireSession.h"

GestionnaireSession::GestionnaireSession() {
	connexion = NULL;
}

GestionnaireSession::~GestionnaireSession() {
	connexion->removelistenneur((XSILIUM_ALL * 10 ) + ID_CONNEXION);
	connexion->removelistenneur((XSILIUM_ALL * 10 ) + ID_DECONEXION);
}

Session * GestionnaireSession::trouverSession(ENetAddress address)
{
	boost::mutex::scoped_lock lock(mutexSession);
	for (session=listOfSession.begin() ; session!=listOfSession.end() ; ++session)
	{
		if((*session)->getSessionID()->host == address.host)
		{
			if((*session)->getSessionID()->port == address.port)
			{
				return (*session);
			}
		}

	}
	return NULL;
}

void GestionnaireSession::creerSession()
{
	Session * sessionTemp = new Session();
	ENetEvent * packet = connexion->getPacket();
	sessionTemp->setSessionPeer(packet->peer);

	boost::mutex::scoped_lock lock(mutexSession);
	listOfSession.push_back(sessionTemp);

}

void GestionnaireSession::supprimerSession()
{
	ENetEvent * packet = connexion->getPacket();
	if( trouverSession(packet->peer->address) != NULL)
	{
		boost::mutex::scoped_lock lock(mutexSession);
		delete *session;
		session = listOfSession.erase(session);
	}

}

void GestionnaireSession::setConnexion(Connexion * connexion)
{
	this->connexion = connexion ;
	connexion->addlistenneur((XSILIUM_ALL * 10 ) + ID_CONNEXION,	boost::bind(&GestionnaireSession::creerSession, this) );
	connexion->addlistenneur((XSILIUM_ALL * 10 ) + ID_DECONEXION,	boost::bind(&GestionnaireSession::supprimerSession, this));
}
