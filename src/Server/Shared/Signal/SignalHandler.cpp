/*
 * SignalException.cpp
 *
 *  Created on: 11 f�vr. 2012
 *      Author: joda2
 */

#include <signal.h>
#include <errno.h>
#include "SignalHandler.h"

bool SignalHandler::mbGotExitSignal = false;

/*!
* Default Contructor.
*/
SignalHandler::SignalHandler()
{
}
/*!
* Destructor.
*/
SignalHandler::~SignalHandler()
{
}

bool SignalHandler::gotExitSignal()
{
    return mbGotExitSignal;
}
/*!
* Sets the bool flag indicating whether we received an exit signal
*/
void SignalHandler::setExitSignal(bool _bExitSignal)
{
    mbGotExitSignal = _bExitSignal;
}
/*!
* Sets exit signal to true.
* \param[in] _ignored Not used but required by function prototype
*                     to match required handler.
*/
void SignalHandler::exitSignalHandler(int _ignored)
{
    mbGotExitSignal = true;
}

void SignalHandler::setupSignalHandlers()
{
    if (signal((int) SIGINT, SignalHandler::exitSignalHandler) == SIG_ERR)
    {
        throw SignalException("!!!!! Error setting up signal handlers !!!!!");
    }
}
