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
#include <Session/SessionListener.h>
#include <string>

/*
 * Enum type session
 */
enum typeOfSession
{
	SESSION_COMPTE = 0,
	SESSION_PERSO,
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

	void setSessionListener(SessionListener * sessionListener);
	SessionListener * getSessionListener();

	std::string getIP();

	int getSessionEtape() const;
	void setSessionEtape(int sessionEtape);

private:
	ENetPeer * peer;
	SessionListener * sessionListener;
	int sessionEtape;


};

#endif /* SRC_SERVER_SHARED_SESSION_SESSION_H_ */
