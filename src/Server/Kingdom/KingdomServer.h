/*
 * \file KingdomServer.h
 *
 *  Created on: \date 1 janv. 2015
 *      Author: \author joda
 *  \brief :
 */
#ifndef SRC_SERVER_KINGDOM_KINGDOMSERVER_H_
#define SRC_SERVER_KINGDOM_KINGDOMSERVER_H_

#include <Signal/SignalHandler.h>
#include <unistd.h>
#include <iostream>

namespace Kingdom {

/*
 *
 */
class KingdomServer {
public:
	KingdomServer();
	virtual ~KingdomServer();

	void startServer();
	void stopThread();
};

} /* namespace Kingdom */

#endif /* SRC_SERVER_KINGDOM_KINGDOMSERVER_H_ */
