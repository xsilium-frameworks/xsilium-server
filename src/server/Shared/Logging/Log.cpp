/*
 * \file Log.cpp
 *
 *  Created on: \date 5 mai 2012
 *      Author: \author joda
 *  \brief :
 */

#include "Log.h"

using namespace std;

const string Log::PRIORITY_NAMES[] =
{
	"ERROR",
	"WARNING",
	"INFO",
	"CONFIG",
    "DEBUG"
};

Log::Log() {
	// TODO Auto-generated constructor stub

}

Log::~Log() {
	// TODO Auto-generated destructor stub
}

void Log::Start(Priority maxPriority,string logFile)
{
    active = true;
    this->maxPriority = maxPriority;
    if (logFile != "")
    {
        fileStream.open(logFile.c_str());
    }
}

void Log::Stop()
{
    this->active = false;
    if (fileStream.is_open())
    {
        fileStream.close();
    }
}

void Log::Write(Priority priority,string message,...)
{
	char buffer[512];
	time(&temps);
	strcpy(date,ctime(&temps));
	date[strlen(date)-1]='\0';

	va_list Params;
	va_start(Params, message);
	std::vsprintf(buffer, message.c_str()  , Params);
	va_end(Params);


	if (priority <= this->maxPriority)
	{
		if (active)
		{
			if (fileStream.is_open())
			{
				fileStream << date
						   << " - "
						   << PRIORITY_NAMES[priority]
						   << ": "
						   << buffer
						   << endl;
			}
		}
		cout << date
			 << " - "
			 << PRIORITY_NAMES[priority]
			 << ": "
			 << buffer
			 << endl;
	}
}
