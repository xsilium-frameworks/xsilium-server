/*
 * \file NetworkListener.h
 *
 *  Created on: \date 9 déc. 2014
 *      Author: \author joda
 *  \brief :
 */
#ifndef SRC_SERVER_SHARED_NETWORK_NETWORKLISTENER_H_
#define SRC_SERVER_SHARED_NETWORK_NETWORKLISTENER_H_

#include <queue>
#include <boost/thread.hpp>

#include "MessagePacket.h"
#include <Model/Session/Session.h>
#include <Utilities/Utilities.h>

/*
 *
 *
 *
 */

struct MessageNetwork {
	Session * session;
	MessagePacket * messagePacket;

};

#define NUM_THREAD_MODULE 4

class NetworkListener: public Utilities {
public:
	NetworkListener();
	virtual ~NetworkListener();

	void run();

	void stopThread();

	virtual void processPacket(MessageNetwork * messageNetwork) = 0;

	void setPacket(Session * session, MessagePacket * messagePacket);
	MessageNetwork * getPacket();

	bool isEmpty();

	bool controleData(MessagePacket * messagePacket, std::vector<std::string> * tableauData);

protected:

	static void threadProcess(void * arguments);

	boost::condition_variable condition_Queue;
	boost::thread_group groupThread;
	bool endThread;

private:
	std::queue<MessageNetwork *> ListOfPacket;
	boost::mutex mutexList;

};

#endif /* SRC_SERVER_SHARED_NETWORK_NETWORKLISTENER_H_ */
