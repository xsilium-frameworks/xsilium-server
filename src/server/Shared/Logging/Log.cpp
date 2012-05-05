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

void Log::Start(Priority maxPriority,const string& logFile)
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

void Log::Write(Priority priority, const string& message)
{
	time(&temps);
	strcpy(date,ctime(&temps));
	date[strlen(date)-1]='\0';

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
						   << message
						   << endl;
			}
		}
		cout << date
			 << " - "
			 << PRIORITY_NAMES[priority]
			 << ": "
			 << message
			 << endl;
	}
}
