/*
 * \file Connexion.h
 *
 *  Created on: \date 8 ao�t 2012
 *      Author: \author joda
 *  \brief :
 */

#ifndef CONNEXION_H_
#define CONNEXION_H_

#include <boost/thread.hpp>
#include "enet/enet.h"
#include "Singleton/Singleton.h"
#include "Callback/Callback.h"
#include "Opcode/Opcode.h"
#include "Structure/Packet.h"



/*
 *
 */
class Connexion : public Callback
{
public:

    /*!
     *  \brief Connexion
     *
     *  brief Constructeur de la classe Connexion
     *
     *  \param
     */

	Connexion();

    /*!
     *  \brief ~Connexion
     *
     *  brief Destructeur de la classe Connexion
     *
     *  \param
     */
	virtual ~Connexion();


    /*!
     *  \brief createConnexion
     *
     *  brief créer un connexion
     *
     *  \param
     */

bool createConnexion(ENetAddress adresse,int MaxClient);

	/*!
	 *  \brief deleteConnexion
	 *
	 *  brief Supprime la connexion
	 *
	 *  \param
	 */

bool deleteConnexion();

ENetEvent * getPacket();

ENetHost * getServer();

void deletePacket(ENetPacket * packet);

void sendPacket(ENetHost * host, enet_uint8 channel, ENetPacket * packet);

void sendPacket(ENetPeer * peer, enet_uint8 channel, ENetPacket * packet);

private :

	static void * threadConnexion(void * arguments);

	bool endThread;

	boost::thread thread;
	ENetHost * server;
	ENetEvent eventServer;
	ENetEvent * packet;
	ENetPeer *peer;

	boost::mutex mutexSend;
	boost::mutex mutexDelete;


};

#endif /* CONNEXION_H_ */
