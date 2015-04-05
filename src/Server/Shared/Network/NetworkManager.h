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

#include "NetworkListener.h"
#include "Opcode.h"
#include <Session/SessionManager.h>

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
	bool createConnexion();

	/*!
	 *  \brief deleteConnexion
	 *
	 *  brief Supprime la connexion
	 *
	 *  \param
	 */

	bool deleteConnexion();
	bool disconnexion();

	int connexionToHost(std::string url,int port);

	void sendPacket(ENetHost * host, enet_uint8 channel, MessagePacket * messagePacket);

	void sendPacket(ENetPeer * peer, enet_uint8 channel, MessagePacket * messagePacket);

	void addListenneur(int identifiant,NetworkListener * networkListener);
	void removeListenneur(int identifiant);
	void callBack(int identifiant,Session * session = 0,MessagePacket * messagePacket = 0);

private:

	static void * threadConnexionServer(void * arguments);
	static void * threadConnexionClient(void * arguments);

	bool endThread;
	bool isConnectedflag;

	boost::thread thread;

	ENetAddress address;

	ENetHost * client;

	ENetEvent eventClient;

	ENetHost * server;

	ENetEvent eventServer;

	ENetPeer *peer;

	boost::mutex mutexSend;

	std::map<int,NetworkListener *> listOfListenner ;

};

#endif /* SRC_SERVER_SHARED_NETWORK_NETWORKMANAGER_H_ */
