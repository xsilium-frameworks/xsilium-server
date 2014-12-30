/*
 * \file NetworkListener.cpp
 *
 *  Created on: \date 9 déc. 2014
 *      Author: \author joda
 *  \brief :
 */
#include "NetworkListener.h"

NetworkListener::NetworkListener() {
	endThread = false;

}

NetworkListener::~NetworkListener() {
	// TODO Auto-generated destructor stub
}

void NetworkListener::run()
{
	for(uint8_t i = 0;i< NUM_THREAD_MODULE;i++)
	{
		groupThread.add_thread(new boost::thread(&NetworkListener::threadProcess, (void *) this) );
	}
}

void NetworkListener::stopThread()
{
	endThread = true;
	condition_Queue.notify_all();
	groupThread.join_all();
}


MessageNetwork * NetworkListener::getPacket()
{
	boost::unique_lock<boost::mutex> lock(mutexList);
	MessageNetwork *  message = ListOfPacket.front();
	ListOfPacket.pop();
	return message;
}

void NetworkListener::setPacket(Session * session,MessagePacket * messagePacket)
{
	boost::unique_lock<boost::mutex> lock(mutexList);

	MessageNetwork * message = new MessageNetwork();

	message->messagePacket = messagePacket;
	message->session = session;


	ListOfPacket.push(message);
	lock.unlock();
	condition_Queue.notify_one();
}

bool NetworkListener::isEmpty()
{
	boost::unique_lock<boost::mutex> lock(mutexList);
	if(ListOfPacket.empty())
	{
		condition_Queue.wait(lock);
		return true;
	}
	else
		return false;
}

void NetworkListener::threadProcess(void * arguments)
{
	NetworkListener * moduleActif = static_cast<NetworkListener *>( arguments ) ;

	while(!moduleActif->endThread)
	{
		if(!moduleActif->isEmpty())
		{
			MessageNetwork * message = moduleActif->getPacket();
			moduleActif->processPacket(message);
			delete message;
		}
	}
}
