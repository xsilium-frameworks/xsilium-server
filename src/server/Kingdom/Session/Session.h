/*
 * \file Session.h
 *
 *  Created on: \date 12 janv. 2013
 *      Author: \author joda
 *  \brief :
 */

#ifndef SESSION_H_
#define SESSION_H_

#include "enet/enet.h"

/*
 *
 */
class Session {
public:
	Session();
	virtual ~Session();

	void setSessionPeer(ENetPeer * peer);
	ENetAddress * getSessionID();


private:
	ENetPeer * peer;
};

#endif /* SESSION_H_ */
