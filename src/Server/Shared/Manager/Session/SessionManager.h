/*
 * \file SessionManager.h
 *
 *  Created on: \date 17 déc. 2014
 *      Author: \author joda
 *  \brief :
 */
#ifndef SRC_SERVER_SHARED_SESSION_SESSIONMANAGER_H_
#define SRC_SERVER_SHARED_SESSION_SESSIONMANAGER_H_

#include "Model/Session/Session.h"
#include <Service/Network/NetworkManager.h>
#include <Manager/Log/Log.h>

#include <Singleton/Singleton.h>

/*
 *
 */
class SessionManager: public Singleton<SessionManager> {
public:
	SessionManager();
	virtual ~SessionManager();

	void creerSession(ENetPeer * peer);
	void supprimerSession(ENetPeer * peer);
	Session * trouverSession(ENetAddress address);

private:
	std::vector<Session *> listOfSession;
	Log * log;

	boost::mutex mutexSession;

};

#endif /* SRC_SERVER_SHARED_SESSION_SESSIONMANAGER_H_ */
