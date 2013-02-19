/*
 * \file GestionnaireSession.cpp
 *
 *  Created on: \date 12 janv. 2013
 *      Author: \author joda
 *  \brief :
 */

#include "GestionnaireSession.h"

GestionnaireSession::GestionnaireSession() {
}

GestionnaireSession::~GestionnaireSession() {
	connexion->removelistenneur(XSILIUM_KINGDOM,ID_CONNEXION);
	connexion->removelistenneur(XSILIUM_KINGDOM,ID_DECONEXION);
}

Session * GestionnaireSession::trouverSession(ENetAddress address)
{
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
	ENetEvent * packet;
	packet = connexion->getPacket();
	sessionTemp->setSessionID(&packet->peer->address);

	listOfSession.push_back(sessionTemp);

}

void GestionnaireSession::supprimerSession()
{

	ENetEvent * packet = connexion->getPacket();


	if( trouverSession(packet->peer->address) != NULL)
	{
		listOfSession.erase(session);
		delete *session;
	}

}

void GestionnaireSession::setConnexion(Connexion * connexion)
{
	this->connexion = connexion ;
	connexion->addlistenneur(XSILIUM_ALL,ID_CONNEXION,this,&GestionnaireSession::creerSession );
	connexion->addlistenneur(XSILIUM_ALL,ID_DECONEXION,this,&GestionnaireSession::supprimerSession );
}
