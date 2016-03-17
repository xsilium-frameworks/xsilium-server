/*
 * \file NetworkManager.h
 *
 *  Created on: \date 4 nov. 2014
 *      Author: \author joda
 *  \brief :
 */
#ifndef SRC_SERVER_SHARED_NETWORK_NETWORKMANAGER_H_
#define SRC_SERVER_SHARED_NETWORK_NETWORKMANAGER_H_

#include <boost/serialization/serialization.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/thread.hpp>

#include <Model/Network/MessagePacket.h>
#include <Service/Service.h>
#include "Opcode.h"
#include <Manager/Session/SessionManager.h>

enum typeNetwork {
    NETWORK_TYPE_SERVER = 0, NETWORK_TYPE_CLIENT
};

class Service;

/*
 *
 */
class NetworkManager: public Singleton<NetworkManager> {
public:
    NetworkManager();
    virtual ~NetworkManager();

    /*!
     *  \brief createConnexion
     *
     *  brief créer un connexion
     *
     *  \param
     */

    bool createConnexion(ENetAddress * adresse = NULL, int MaxClient = 1);

    /*!
     *  \brief deleteConnexion
     *
     *  brief Supprime la connexion
     *
     *  \param
     */

    int connexionToHost(std::string url, int port);

    void disconnexion();

    ENetHost * getHost();
    ENetPeer * getPeer();

    void addListenneur(int identifiant, Service * service);
    void removeListenneur(int identifiant);
    void callBack(int identifiant, Session * session = 0, MessagePacket * messagePacket = 0);

    void sendPacket(MessageNetwork * messageToSend);

private:

    void sendPacket(ENetHost * host, enet_uint8 channel, MessagePacket * messagePacket);
    void sendPacket(ENetPeer * peer, enet_uint8 channel, MessagePacket * messagePacket);

    static void * threadConnexion(void * arguments);

    bool endThread;

    bool isConnectedflag;

    boost::thread thread;

    ENetHost * host;

    ENetEvent event;

    ENetPeer *peer;

    boost::mutex mutexSend;

    std::map<int, Service *> listOfListenner;

};

#endif /* SRC_SERVER_SHARED_NETWORK_NETWORKMANAGER_H_ */
