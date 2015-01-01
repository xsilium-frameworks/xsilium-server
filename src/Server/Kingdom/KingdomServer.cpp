/*
 * \file KingdomServer.cpp
 *
 *  Created on: \date 1 janv. 2015
 *      Author: \author joda
 *  \brief :
 */
#include "KingdomServer.h"

namespace Kingdom {

KingdomServer::KingdomServer() {
	// TODO Auto-generated constructor stub

}

KingdomServer::~KingdomServer() {
	// TODO Auto-generated destructor stub
}

} /* namespace Kingdom */

int main()
{
	Kingdom::KingdomServer * kingdomServer = new Kingdom::KingdomServer();
	//authserver->startServer();
	delete kingdomServer;
}
