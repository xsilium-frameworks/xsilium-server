/*
 * Service.cpp
 *
 *  Created on: 22 déc. 2015
 *      Author: joda
 */

#include "Service.h"

Service::Service() {
    endThread = false;

}

Service::~Service() {
}

void Service::run()
{
    for(int i = 0;i< NUM_THREAD_MODULE;i++)
    {
        groupThread.add_thread(new boost::thread(&Service::threadProcess, (void *) this) );
    }
}

void Service::stopThread()
{
    endThread = true;
    condition_Queue.notify_all();
    groupThread.join_all();
}


MessageNetwork * Service::getPacket()
{
    boost::unique_lock<boost::mutex> lock(mutexList);
    MessageNetwork *  message = ListOfPacket.front();
    ListOfPacket.pop();
    return message;
}

void Service::setPacket(Session * session,MessagePacket * messagePacket)
{
    boost::unique_lock<boost::mutex> lock(mutexList);

    MessageNetwork * message = new MessageNetwork();

    message->messagePacket = messagePacket;
    message->session = session;


    ListOfPacket.push(message);
    lock.unlock();
    condition_Queue.notify_one();
}

bool Service::isEmpty()
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

void Service::threadProcess(void * arguments)
{
    Service * service = static_cast<Service *>( arguments ) ;

    while(!service->endThread)
    {
        if(!service->isEmpty())
        {
            MessageNetwork * message = service->getPacket();
            service->processPacket(message);
            delete message;
        }
    }
}

bool Service::controleData(MessagePacket * messagePacket,std::vector<std::string> * tableauData)
{
    bool retour = true;
    for (std::vector<std::string>::iterator it = tableauData->begin() ; it != tableauData->end(); ++it)
    {
        if(!messagePacket->hasProperty(*it->c_str()))
            return false;
    }
    return true;
}
