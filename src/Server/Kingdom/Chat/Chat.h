/*
 * \file Chat.h
 *
 *  Created on: \date 3 janv. 2015
 *      Author: \author joda
 *  \brief :
 */
#include <Network/NetworkManager.h>
#include <Configuration/Configuration.h>

#ifndef SRC_SERVER_KINGDOM_CHAT_CHAT_H_
#define SRC_SERVER_KINGDOM_CHAT_CHAT_H_

namespace Kingdom {
	enum typeForChat
	{
		ID_WORLD,
		ID_AREA,
		ID_TRADE,
		ID_PRIVATE,
		ID_ERREUR
	};

	enum erreurOfChat
	{
		ID_NOERROR = 0,
		ID_ERROR_PACKET_SIZE,
		ID_SPAM
	};

/*
 *
 */
class Chat : public NetworkListener{

public:
	Chat(NetworkManager * NetworkManager);
	virtual ~Chat();
	void run();

	int HandleChatWorld(MessageNetwork * messageNetwork,MessagePacket * messageRetour);
	int HandleChatArea(MessageNetwork * messageNetwork,MessagePacket * messageRetour);
	int HandleChatTrade(MessageNetwork * messageNetwork,MessagePacket * messageRetour);
	int HandleChatPrivate(MessageNetwork * messageNetwork,MessagePacket * messageRetour);
	void processPacket(MessageNetwork * messageNetwork);


private:
	Log * log;
	Configuration * config ;
	NetworkManager * networkManager;
};


} /* namespace Kingdom */

#endif /* SRC_SERVER_KINGDOM_CHAT_CHAT_H_ */
