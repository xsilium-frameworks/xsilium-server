/*
 * RealmService.h
 *
 *  Created on: 11 juil. 2015
 *      Author: Skronak
 */

#ifndef SRC_SERVER_AUTHENTIFICATION_REALM_SERVICE_REALMSERVICE_H_
#define SRC_SERVER_AUTHENTIFICATION_REALM_SERVICE_REALMSERVICE_H_
#include <Network/NetworkManager.h>

namespace Auth {

enum erreurOfRealm
{
	ID_NOERROR_R = 0,
	ID_ERROR_PACKET_SIZE_R,
};

enum typeForRealm
{
	ID_LIST_REALM = 0,
	ID_UPDATE_REALM,

};
#define NUM_UPDATE_ROYAUME 300000

class RealmService : public NetworkListener {

public:
	RealmService(NetworkManager * networkManager);
	virtual ~RealmService();


	void run();
	void processPacket(MessageNetwork * messageNetwork);

	int handleListRealm(MessageNetwork * messageNetwork,MessagePacket * messageRetour);
	int handleCreateRealm(MessageNetwork * messageNetwork,MessagePacket * messageRetour);
	/*!
	 * Alimentation des erreurs d'un packets
	 * @param messageRetour
	 * @param typeForAuth : type d'erreur
	 */
	void sendErrorPacket(MessagePacket * messageRetour, erreurOfRealm type);

private:
	Log * log;
	NetworkManager * networkManager;
	std::map<int,Royaume *> listRoyaume;
	time_t   m_NextUpdateTime;
};


} /* namespace Auth */

#endif /* SRC_SERVER_AUTHENTIFICATION_REALM_SERVICE_REALMSERVICE_H_ */
