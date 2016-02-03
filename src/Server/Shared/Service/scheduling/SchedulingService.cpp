/*
 * SchedulingService.cpp
 *
 *  Created on: 1 févr. 2016
 *      Author: joda
 */

#include "SchedulingService.h"

SchedulingService::SchedulingService() {
}

SchedulingService::~SchedulingService() {
    // TODO Auto-generated destructor stub
}

void SchedulingService::runLoop()
{
    boost::posix_time::ptime realCurrTime;
    boost::posix_time::ptime realPrevTime = boost::posix_time::microsec_clock::local_time();
    int prevSleepTime = 0;
    boost::posix_time::time_duration diff;

    signalHandler.setupSignalHandlers();

    while(!signalHandler.gotExitSignal())
    {
        realCurrTime = boost::posix_time::microsec_clock::local_time();
        diff = realCurrTime - realPrevTime;

        callBack(diff.total_milliseconds());

        realPrevTime = realCurrTime;

        if( diff.total_milliseconds() <= 50 + prevSleepTime )
        {
            prevSleepTime = 50 + prevSleepTime - diff.total_milliseconds() ;
            boost::this_thread::sleep_for(boost::chrono::milliseconds(prevSleepTime));
        }
        else
        {
            prevSleepTime = 0 ;
        }
    }
}


void SchedulingService::callBack(int diff)
{
    std::vector<Manager*>::iterator it;

    for (it = Manager::listOfManager.begin() ; it != Manager::listOfManager.end(); ++it)
    {
        (*it)->update(diff);
    }

    printf("%d \n",diff);
}
