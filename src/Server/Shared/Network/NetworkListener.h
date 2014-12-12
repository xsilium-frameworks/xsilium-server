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

/*
 *
 */

#define NUM_THREAD_MODULE 4

class NetworkListener {
public:
	NetworkListener();
	virtual ~NetworkListener();

	void run();

	void stopThread();

	virtual void processPacket() = 0;

	void setPacket(MessagePacket * messagePacket);
	MessagePacket * getPacket();

	bool isEmpty();

protected:

	static void threadProcess(void * arguments);

	boost::condition_variable condition_Queue;
	boost::thread_group groupThread;
	bool endThread;

private:
	std::queue<ENetEvent> ListOfPacket;
	boost::mutex mutexList;

};

#endif /* SRC_SERVER_SHARED_NETWORK_NETWORKLISTENER_H_ */
