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
	log = Log::getInstance();
}

GestionnaireSession::~GestionnaireSession() {
	connexion->removelistenneur((XSILIUM_ALL * 1000 ) + ID_CONNEXION);
	connexion->removelistenneur((XSILIUM_ALL * 1000 ) + ID_DECONEXION);
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
				log->Write(Log::INFO,"La Session avec l'IP : %d, Port : %d a ete trouve ",address.host,address.port);
				return (*session);
			}
		}

	}
	log->Write(Log::INFO,"Le Session avec l'IP : %d, Port : %d n'a pas ete trouve ",address.host,address.port);
	return NULL;
}

void GestionnaireSession::creerSession()
{
	Session * sessionTemp = new Session();
	ENetEvent * packet = connexion->getPacket();
	sessionTemp->setSessionPeer(packet->peer);
	boost::mutex::scoped_lock lock(mutexSession);
	log->Write(Log::INFO,"Creation d'une nouvelle Session avec IP : %d , Port: %d",packet->peer->address.host,packet->peer->address.port);
	listOfSession.push_back(sessionTemp);

}

void GestionnaireSession::supprimerSession()
{
	ENetEvent * packet = connexion->getPacket();
	if( trouverSession(packet->peer->address) != NULL)
	{
		boost::mutex::scoped_lock lock(mutexSession);
		log->Write(Log::INFO,"deconnexion de la Session avec IP : %d, Port : %d ",packet->peer->address.host,packet->peer->address.port);
		delete *session;
		session = listOfSession.erase(session);
	}
}

void GestionnaireSession::setConnexion(Connexion * connexion)
{
	this->connexion = connexion ;
	connexion->addlistenneur((XSILIUM_ALL * 1000 ) + ID_CONNEXION,	boost::bind(&GestionnaireSession::creerSession, this) );
	connexion->addlistenneur((XSILIUM_ALL * 1000 ) + ID_DECONEXION,	boost::bind(&GestionnaireSession::supprimerSession, this));
}
