/*
 * \file GestionnaireSession.cpp
 *
 *  Created on: \date 12 janv. 2013
 *      Author: \author joda
 *  \brief :
 */

#include "GestionnaireSession.h"

GestionnaireSession::GestionnaireSession(Connexion * connexion) {
	this->connexion = connexion ;
	connexion->addlistenneur(XSILIUM_KINGDOM,ID_CONNEXION,this,&GestionnaireSession::creerSession );
	connexion->addlistenneur(XSILIUM_KINGDOM,ID_DECONEXION,this,&GestionnaireSession::supprimerSession );


}

GestionnaireSession::~GestionnaireSession() {
	// TODO Auto-generated destructor stub
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
	return 0;
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


	if( trouverSession(packet->peer->address) != 0)
	{
		listOfSession.erase(session);
	}

}
