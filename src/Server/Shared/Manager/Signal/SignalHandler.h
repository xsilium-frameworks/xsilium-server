/*
 * SignalException.h
 *
 *  Created on: 11 f�vr. 2012
 *      Author: joda2
 */

/*!
 * \file SignalHandler
 * \brief
 * \author joda2
 *
 */

#ifndef SIGNALEXCEPTION_H_
#define SIGNALEXCEPTION_H_

#include <stdexcept>

using std::runtime_error;

class SignalException : public runtime_error
{
public:
   SignalException(const char * _message)
      : std::runtime_error(_message)
   {}
};

class SignalHandler
{
protected:
    static bool mbGotExitSignal;

public:
    /*!
     *  \brief Constructeur
     *
     *  Default Constructor.
     *
     *  \param
     */
    SignalHandler();
    /*!
     *  \brief Destructeur
     *
     *  Destructeur
     *
     *  \param
     */
    ~SignalHandler();
    /*!
     *  \brief gotExitSignal
     *
     *  Returns the bool flag indicating whether we received an exit signal
     *  @return Flag indicating shutdown of program
     *
     *  \param
     */
    static bool gotExitSignal();
    /*!
     *  \brief gotExitSignal
     *
     *	sets the bool flag indicating whether we received an exit signal
     *
     *  \PARAM
     */
    static void setExitSignal(bool _bExitSignal);
    /*!
     *  \brief setupSignalHandlers
     *
     *	Set up the signal handlers for CTRL-C.
     *
     *  \PARAM
     */
    static void setupSignalHandlers();
    /*!
     *  \brief exitSignalHandler
     *
     * Sets exit signal to true.
     * @param[in] _ignored Not used but required by function prototype
     * to match required handler.
     *
     *  \param
     */
    static void exitSignalHandler(int _ignored);

};

#endif /* SIGNALEXCEPTION_H_ */

