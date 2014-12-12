/*
 * \file NetworkManager.h
 *
 *  Created on: \date 4 nov. 2014
 *      Author: \author joda
 *  \brief :
 */
#ifndef SRC_SERVER_SHARED_NETWORK_NETWORKMANAGER_H_
#define SRC_SERVER_SHARED_NETWORK_NETWORKMANAGER_H_

#include <enet/enet.h>

#include <boost/serialization/serialization.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>

#include "NetworkListener.h"

/*
 *
 */
class NetworkManager {
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

	bool createConnexion(ENetAddress adresse, int MaxClient);

	/*!
	 *  \brief deleteConnexion
	 *
	 *  brief Supprime la connexion
	 *
	 *  \param
	 */

	bool deleteConnexion();

	void sendPacket(ENetHost * host, enet_uint8 channel, MessagePacket * messagePacket);

	void sendPacket(ENetPeer * peer, enet_uint8 channel, MessagePacket * messagePacket);

private:

	static void * threadConnexion(void * arguments);

	bool endThread;

	boost::thread thread;

	ENetHost * server;

	ENetEvent eventServer;

	ENetPeer *peer;

	boost::mutex mutexSend;

};

#endif /* SRC_SERVER_SHARED_NETWORK_NETWORKMANAGER_H_ */
