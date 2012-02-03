/*
 * AuthSocket.h
 *
 *  Created on: 3 févr. 2012
 *      Author: joda2
 */

#ifndef AUTHSOCKET_H_
#define AUTHSOCKET_H_

#include "RakPeerInterface.h"


class AuthSocket {
public:
	AuthSocket();
	virtual ~AuthSocket();
	void Start();
	unsigned ConnectionCount() const;
	void Update();



private:
	RakNet::RakPeerInterface *peer;

};

#endif /* AUTHSOCKET_H_ */
