/*
 * \file GestionnaireZone.cpp
 *
 *  Created on: \date 7 avr. 2013
 *      Author: \author joda
 *  \brief :
 */

#include "GestionnaireZone.h"

GestionnaireZone::GestionnaireZone(Connexion * connexionToClient) {
	this->connexionToClient = connexionToClient ;
}

GestionnaireZone::~GestionnaireZone() {
	// TODO Auto-generated destructor stub
}

void GestionnaireZone::creeZone()
{
	Zone * zoneTemp = new Zone();
	ENetEvent * packet = connexionToZone->getPacket();
	zoneTemp->setZonePeer(packet->peer);
	boost::mutex::scoped_lock lock(mutexZone);
	listOfZone.push_back(zoneTemp);
}
Zone * GestionnaireZone::trouveZone(ENetAddress address)
{
	boost::mutex::scoped_lock lock(mutexZone);
	for (zone=listOfZone.begin() ; zone!=listOfZone.end() ; ++zone)
	{
		if((*zone)->getZoneID()->host == address.host)
		{
			if((*zone)->getZoneID()->port == address.port)
			{
				return (*zone);
			}
		}

	}
	return NULL;
}
void GestionnaireZone::supprimerZone()
{
	ENetEvent * packet = connexionToZone->getPacket();
	if( trouveZone(packet->peer->address) != NULL)
	{
		boost::mutex::scoped_lock lock(mutexZone);
		delete *zone;
		zone = listOfZone.erase(zone);
	}
}


void GestionnaireZone::sendToZone(Zone * zone, ENetPacket * packet)
{

}

