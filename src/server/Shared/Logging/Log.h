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

	enum Priority
	    {
			ERROR,
			WARNING,
			INFO,
			CONFIG,
			DEBUG
	    };

	void Start(Priority maxPriority,std::string logFile);
	void Stop();

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
