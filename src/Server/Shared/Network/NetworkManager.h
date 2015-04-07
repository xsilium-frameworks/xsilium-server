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


enum typeNetwork {
	NETWORK_TYPE_SERVER = 0,
	NETWORK_TYPE_CLIENT
};

/*
 *
 */
class NetworkManager {
public:
	NetworkManager(int TypeConnexion);
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

	int connexionToHost(std::string url,int port);

	bool disconnexion();

	void sendPacket(ENetHost * host, enet_uint8 channel, MessagePacket * messagePacket);

	void sendPacket(ENetPeer * peer, enet_uint8 channel, MessagePacket * messagePacket);

	void addListenneur(int identifiant,NetworkListener * networkListener);
	void removeListenneur(int identifiant);
	void callBack(int identifiant,Session * session = 0,MessagePacket * messagePacket = 0);

private:

	int typeConnexion;

	static void * threadConnexion(void * arguments);

	bool endThread;

	bool isConnectedflag;

	boost::thread thread;

	ENetHost * host;

	ENetEvent event;

	ENetPeer *peer;

	boost::mutex mutexSend;

	std::map<int,NetworkListener *> listOfListenner ;

};

#endif /* SRC_SERVER_SHARED_NETWORK_NETWORKMANAGER_H_ */
