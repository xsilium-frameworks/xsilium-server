/*
 * schedulingService.cpp
 *
 *  Created on: 1 févr. 2016
 *      Author: joda
 */

#include "schedulingService.h"

schedulingService::schedulingService() {
    // TODO Auto-generated constructor stub

}

schedulingService::~schedulingService() {
    // TODO Auto-generated destructor stub
}

void schedulingService::runLoop()
{
    boost::posix_time::ptime now;

    timestampSave = boost::posix_time::second_clock::local_time();

    while(1)
    {
        boost::posix_time::time_duration diff = now - timestampSave;

        callBack(diff.total_milliseconds());


        usleep(50);
    }



}


void schedulingService::callBack(int diff)
{

}
