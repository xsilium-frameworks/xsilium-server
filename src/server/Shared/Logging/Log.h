/*
 * \file Log.h
 *
 *  Created on: \date 5 mai 2012
 *      Author: \author joda
 *  \brief :
 */

#ifndef LOG_H_
#define LOG_H_

#include <string.h>
#include <fstream>
#include <iostream>
#include <time.h>
#include <cstdarg>
#include <sstream>
#include "Singleton/Singleton.h"

/*
 *
 */
class Log : public Singleton<Log> {

	friend class Singleton<Log>;

public:

	/*!
	 *  \brief Priority
	 *
	 *  brief Permet de classer le
	 *
	 *  \param
	 */
	enum Priority
	    {
			ERROR,
			WARNING,
			INFO,
			CONFIG,
			DEBUG
	    };

	/*!
	 *  \brief Start
	 *
	 *  brief demarre et ouvre les log
	 *
	 *  \param
	 */
	void Start(Priority maxPriority,std::string logFile);

	/*!
	 *  \brief Stop
	 *
	 *  brief Stop et ferme les log
	 *
	 *  \param
	 */


	void Stop();

	/*!
	 *  \brief Write
	 *
	 *  brief ecris dans les log et inclu la priorité du message.
	 *
	 *  \param
	 */


	void Write(Priority priority,std::string message,...);


private:
	Log();
	virtual ~Log();
	bool active;
	std::ofstream fileStream;
	time_t temps;
	char date[256];
	Priority maxPriority;


	static const std::string PRIORITY_NAMES[];
};

#endif /* LOG_H_ */
