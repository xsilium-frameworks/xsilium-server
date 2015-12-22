/*
 * RealmService.h
 *
 *  Created on: 11 juil. 2015
 *      Author: Skronak
 */

#ifndef SRC_SERVER_AUTHENTIFICATION_REALM_SERVICE_REALMSERVICE_H_
#define SRC_SERVER_AUTHENTIFICATION_REALM_SERVICE_REALMSERVICE_H_
#include <Network/NetworkManager.h>
#include "Realm/Manager/RealmManager.h"

namespace Auth {

enum erreurOfRealm
{
	ID_NOERROR_R = 0,
	ID_ERROR_PACKET_SIZE_R,
	ID_ERROR_KEY
};

enum typeForRealm
{
	ID_REGISTER_REALM,
	ID_ERREUR_REALM

};

class RealmService : public NetworkListener {

public:
	RealmService(NetworkManager * networkManager);
	virtual ~RealmService();


	void run();
	void processPacket(MessageNetwork * messageNetwork);

	void handleRegisterRealm(MessageNetwork * messageNetwork,MessagePacket * messageRetour);
	/*!
	 * Alimentation des erreurs d'un packets
	 * @param messageRetour
	 * @param typeForAuth : type d'erreur
	 */
	void sendErrorPacket(MessagePacket * messageRetour, int typeError);

private:
	Log * log;
	NetworkManager * networkManager;
	RealmManager * realmManager;
	int idRealm;

};


} /* namespace Auth */

#endif /* SRC_SERVER_AUTHENTIFICATION_REALM_SERVICE_REALMSERVICE_H_ */
