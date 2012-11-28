/*
 * \file Connexion.h
 *
 *  Created on: \date 8 ao�t 2012
 *      Author: \author joda
 *  \brief :
 */

#ifndef CONNEXION_H_
#define CONNEXION_H_

#include <pthread.h>
#include "enet/enet.h"
#include <vector>
#include "Singleton/Singleton.h"
#include "Callback/Callback.h"
#include "Opcode/Opcode.h"


struct struct_callback
{
	typerequete requete;
	Opcode opcode;
	CallbackMaster * callback;
};



/*
 *
 */
class Connexion : public Singleton<Connexion> {

	friend class Singleton<Connexion>;

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
template <typename templeteListener>
bool addlistenneur(typerequete requete,Opcode opcode,templeteListener * object, void(templeteListener::*fpt)())
{
	struct_callback newcallback;
	Callback<templeteListener> * callback = new Callback<templeteListener>(object,fpt);
	newcallback.requete = requete;
	newcallback.opcode = opcode;
	newcallback.callback = callback ;
	listOfListenner.push_back(newcallback);
	return true;
};

void callback(typerequete requete, Opcode opcode);

private :

	static void * threadConnexion(void * arguments);

	bool endThread;

	pthread_t thread;
	ENetHost * server;
	ENetEvent eventServer;
	ENetEvent * packet;
	ENetPeer *peer;


    std::vector<struct_callback> listOfListenner ;
    std::vector<struct_callback>::iterator listenner ;


};

#endif /* CONNEXION_H_ */
