/*
 * LogManager.cpp
 *
 *  Created on: 17 déc. 2015
 *      Author: joda
 */

#include "LogManager.h"


LogManager::LogManager() {
    activeFile = false;
    activeConsole = true;
    maxPriority = ERROR;
    date[0] = '0';
    PRIORITY_NAMES[0] = "ERROR";
    PRIORITY_NAMES[1] = "WARNING";
    PRIORITY_NAMES[2] = "INFO";
    PRIORITY_NAMES[3] = "CONFIG";
    PRIORITY_NAMES[4] = "DEBUG";
}

LogManager::~LogManager() {
    // TODO Auto-generated destructor stub
}

void LogManager::start(Priority maxPriority, std::string logFile) {
    this->maxPriority = maxPriority;
    if (logFile != "") {
        fileStream.open(logFile.c_str());
    }
}

void LogManager::stop() {
    activeFile = false;
    activeConsole = false;
    if (fileStream.is_open()) {
        fileStream.close();
    }
}

void LogManager::write(Priority priority, std::string message, ...) {
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

void LogManager::activationConsole()
{
    activeConsole = true;
}

void LogManager::desactivationConsole()
{
    activeConsole = false;
}

void LogManager::activationFile()
{
    activeFile = true;
}

void LogManager::desactivationFile()
{
    activeFile = true;
}
