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

class schedulingService {
public:
    schedulingService();
    virtual ~schedulingService();

    void runLoop();

private:

    void callBack(int diff);

    boost::posix_time::ptime timestampSave;
};

#endif /* SRC_SERVER_SHARED_SERVICE_SCHEDULINGSERVICE_H_ */
