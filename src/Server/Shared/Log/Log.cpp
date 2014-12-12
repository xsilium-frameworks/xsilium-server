/*
 * \file Log.cpp
 *
 *  Created on: \date 24 oct. 2014
 *      Author: \author joda
 *  \brief :
 */
#include "Log.h"

const std::string Log::PRIORITY_NAMES[] = { "ERROR", "WARNING", "INFO",
		"CONFIG", "DEBUG" };

Log::Log() {
	activeFile = false;
	activeConsole = true;
	maxPriority = ERROR;

}

Log::~Log() {
	// TODO Auto-generated destructor stub
}

void Log::start(Priority maxPriority, std::string logFile) {
	this->maxPriority = maxPriority;
	if (logFile != "") {
		fileStream.open(logFile.c_str());
	}
}

void Log::stop() {
	activeFile = false;
	activeConsole = false;
	if (fileStream.is_open()) {
		fileStream.close();
	}
}

void Log::write(Priority priority, std::string message, ...) {
	char buffer[512];
	time(&temps);
	strcpy(date, ctime(&temps));
	date[strlen(date) - 1] = '\0';

	va_list Params;
	va_start(Params, message);
	std::vsprintf(buffer, message.c_str(), Params);
	va_end(Params);

	if (priority <= this->maxPriority) {
		if (activeFile) {
			if (fileStream.is_open()) {
				fileStream << date << " - " << PRIORITY_NAMES[priority] << ": "
						<< buffer << std::endl;
			}
		}

		if (activeConsole) {
			std::cout << date << " - " << PRIORITY_NAMES[priority] << ": "
					<< buffer << std::endl;
		}
	}
}

void Log::activationConsole()
{
	activeConsole = true;
}

void Log::desactivationConsole()
{
	activeConsole = false;
}

void Log::activationFile()
{
	activeFile = true;
}

void Log::desactivationFile()
{
	activeFile = true;
}
