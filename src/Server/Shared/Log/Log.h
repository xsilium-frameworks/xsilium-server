/*
 * \file Log.h
 *
 *  Created on: \date 24 oct. 2014
 *      Author: \author joda
 *  \brief :
 */
#ifndef SRC_SERVER_SHARED_LOG_LOG_H_
#define SRC_SERVER_SHARED_LOG_LOG_H_

#include <string>
#include <fstream>
#include <iostream>
#include <cstdarg>
#include <sstream>
#include <cstring>
#include <Singleton/Singleton.h>
#include "../../../../lib/Enet/enet/time.h"

/*
 *
 */
class Log: public Singleton<Log> {

public:

	Log();
	virtual ~Log();

	/*!
	 *  \brief Priority
	 *
	 *  brief Permet de classer le
	 *
	 *  \param
	 */
	enum Priority {
		ERROR, WARNING, INFO, CONFIG, DEBUG
	};

	/*!
	 *  \brief Start
	 *
	 *  brief demarre et ouvre les log
	 *
	 *  \param
	 */
	void start(Priority maxPriority, std::string logFile);

	/*!
	 *  \brief Stop
	 *
	 *  brief Stop et ferme les log
	 *
	 *  \param
	 */

	void stop();

	/*!
	 *  \brief Write
	 *
	 *  brief ecris dans les log et inclu la priorité du message.
	 *
	 *  \param
	 */

	void write(Priority priority, std::string message, ...);

	void activationConsole();
	void desactivationConsole();

	void activationFile();
	void desactivationFile();

private:

	bool activeFile;
	bool activeConsole;
	std::ofstream fileStream;
	time_t temps;
	char date[256];
	Priority maxPriority;

	static const std::string PRIORITY_NAMES[];
};

#endif /* SRC_SERVER_SHARED_LOG_LOG_H_ */
