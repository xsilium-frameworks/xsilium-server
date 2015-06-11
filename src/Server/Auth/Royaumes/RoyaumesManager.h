/*
 * \file RoyaumesManager.h
 *
 *  Created on: \date 22 févr. 2015
 *      Author: \author joda
 *  \brief :
 */
#ifndef SRC_SERVER_AUTH_ROYAUMES_ROYAUMESMANAGER_H_
#define SRC_SERVER_AUTH_ROYAUMES_ROYAUMESMANAGER_H_

#include <Network/NetworkManager.h>
#include <map>
#include "Royaume.h"

namespace Auth {

/*
 *
 */

enum typeForRoyaume
{
	ID_LIST_ROYAUME = 0,
	ID_CREATE_ROAYUME
};

enum erreurOfRoyaume
{
	ID_NOERROR_R = 0,
	ID_ERROR_PACKET_SIZE_R
};

#define NUM_UPDATE_ROYAUME 300000

/*
 *
 */
class RoyaumesManager : public NetworkListener {
public:
	RoyaumesManager(NetworkManager * networkManager);
	virtual ~RoyaumesManager();

	void run();
	void processPacket(MessageNetwork * messageNetwork);

	int HandleListRoyaume(MessageNetwork * messageNetwork,MessagePacket * messageRetour);
	int HandleCreateRoyaume(MessageNetwork * messageNetwork,MessagePacket * messageRetour);

	void updateRoyaume();

private:
	Log * log;
	NetworkManager * networkManager;

	std::map<int,Royaume *> listRoyaume;
	time_t   m_NextUpdateTime;
};

} /* namespace Auth */

#endif /* SRC_SERVER_AUTH_ROYAUMES_ROYAUMESMANAGER_H_ */
