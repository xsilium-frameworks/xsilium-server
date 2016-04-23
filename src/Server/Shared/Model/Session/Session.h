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
#include <Model/Model.h>
#include <string>

#define INET_ADDRSTRLEN 16

/*
 * Enum type session
 */
enum typeOfSession {

    SESSION_REALM = 0, SESSION_ZONE, SESSION_COMPTE, SESSION_PERSO,
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

    void setSessionHost(ENetHost * host);
    ENetHost * getSessionHost();

    ENetAddress * getSessionID();

    void setSessionListener(Model * model);
    Model * getSessionListener();

    std::string getIP();

    int getSessionEtape() const;
    void setSessionEtape(int sessionEtape);

private:
    ENetPeer * peer;
    ENetHost * host;
    Model * model;
    int sessionEtape;

};

#endif /* SRC_SERVER_SHARED_SESSION_SESSION_H_ */
