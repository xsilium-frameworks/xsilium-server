/*
 * schedulingService.h
 *
 *  Created on: 1 févr. 2016
 *      Author: joda
 */

#ifndef SRC_SERVER_SHARED_SERVICE_SCHEDULINGSERVICE_H_
#define SRC_SERVER_SHARED_SERVICE_SCHEDULINGSERVICE_H_

#include <boost/date_time/posix_time/posix_time.hpp>
#include <unistd.h>
#include "Manager/Signal/SignalHandler.h"
#include "Manager/Manager.h"

class SchedulingService {
public:
    SchedulingService();
    virtual ~SchedulingService();

    void runLoop();

private:
    void callBack(int diff);
    SignalHandler signalHandler;
};

#endif /* SRC_SERVER_SHARED_SERVICE_SCHEDULINGSERVICE_H_ */
