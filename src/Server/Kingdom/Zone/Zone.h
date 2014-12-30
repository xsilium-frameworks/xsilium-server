/*
 * \file Zone.h
 *
 *  Created on: \date 7 avr. 2013
 *      Author: \author joda
 *  \brief :
 */

#ifndef ZONE_H_
#define ZONE_H_

#include "enet/enet.h"

/*
 *
 */
class Zone {
public:
	Zone();
	virtual ~Zone();

	void setZonePeer(ENetPeer * peer);
	ENetPeer * getZonePeer();
	ENetAddress * getZoneID();

private:
	ENetPeer * peer;

};

#endif /* ZONE_H_ */
