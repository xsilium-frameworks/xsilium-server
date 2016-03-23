/*
 * Service.h
 *
 *  Created on: 22 déc. 2015
 *      Author: joda
 */

#ifndef SRC_SERVER_SHARED_SERVICE_SERVICE_H_
#define SRC_SERVER_SHARED_SERVICE_SERVICE_H_

#include <queue>
#include <boost/thread.hpp>

#include <Model/Network/MessagePacket.h>
#include <Manager/Log/LogManager.h>
#include <Utilities/Utilities.h>

#define NUM_THREAD_MODULE 4

class Service {

public:
    Service();
    virtual ~Service();

    void run();

    void stopThread();

    virtual void processPacket(MessageNetwork * messageNetwork) = 0;

    void setPacket(Session * session, MessagePacket * messagePacket);
    MessageNetwork * getPacket();

    bool isEmpty();

    bool controleData(MessagePacket * messagePacket, std::vector<std::string> * tableauData);

protected:

    enum {
        ID_NOERROR = 0, ID_ERROR_PACKET_SIZE, ID_OTHER_ERROR
    };

    static void threadProcess(void * arguments);

    boost::condition_variable condition_Queue;
    boost::thread_group groupThread;
    bool endThread;

    LogManager * log;

private:
    std::queue<MessageNetwork *> ListOfPacket;
    boost::mutex mutexList;
};

#endif /* SRC_SERVER_SHARED_SERVICE_SERVICE_H_ */
