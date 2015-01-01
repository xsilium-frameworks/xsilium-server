/*
 * \file KingdomServer.h
 *
 *  Created on: \date 1 janv. 2015
 *      Author: \author joda
 *  \brief :
 */
#ifndef SRC_SERVER_KINGDOM_KINGDOMSERVER_H_
#define SRC_SERVER_KINGDOM_KINGDOMSERVER_H_

#include "Signal/SignalHandler.h"
#include <unistd.h>
#include <iostream>

#include "Configuration/Configuration.h"
#include "Log/Log.h"

#include "Databases/DatabaseManager.h"

#include "Network/NetworkManager.h"

namespace Kingdom {

/*
 *
 */
class KingdomServer {
public:
	KingdomServer();
	virtual ~KingdomServer();
};

} /* namespace Kingdom */

#endif /* SRC_SERVER_KINGDOM_KINGDOMSERVER_H_ */
