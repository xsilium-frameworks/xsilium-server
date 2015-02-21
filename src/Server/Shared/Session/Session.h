/*
 * \file Session.h
 *
 *  Created on: \date 16 déc. 2014
 *      Author: \author joda
 *  \brief :
 */
#ifndef SRC_SERVER_SHARED_SESSION_SESSION_H_
#define SRC_SERVER_SHARED_SESSION_SESSION_H_

#include <enet/enet.h>

#include <Compte/Compte.h>

/*
 * Enum type session
 */

enum SessionType {
	SESSION_NONE,
	SESSION_CLIENT,
	SESSION_ROYAUME,
	SESSION_ZONE
};

/*
 *
 */
class Session {
public:
	Session();
	virtual ~Session();

	void setSessionPeer(ENetPeer * peer);
	ENetPeer * getSessionPeer();
	ENetAddress * getSessionID();

	void setCompte(Compte * compte);
	Compte * getCompte();

	void setSessionType(SessionType sessionType);
	SessionType getSessionType();

	char * getIP();


private:
	ENetPeer * peer;
	Compte * compte;
	SessionType sessionType;


};

#endif /* SRC_SERVER_SHARED_SESSION_SESSION_H_ */
