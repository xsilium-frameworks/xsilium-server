/*
 * LogManager.h
 *
 *  Created on: 17 déc. 2015
 *      Author: joda
 */

#ifndef SRC_SERVER_SHARED_MANAGER_LOG_LOGMANAGER_H_
#define SRC_SERVER_SHARED_MANAGER_LOG_LOGMANAGER_H_

#include <string>
#include <fstream>
#include <iostream>
#include <cstdarg>
#include <sstream>
#include <cstring>
#include <Singleton/Singleton.h>
#include <time.h>


class LogManager : public Singleton<LogManager> {
public:
    LogManager();
    virtual ~LogManager();

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

    std::string PRIORITY_NAMES[5];
};

#endif /* SRC_SERVER_SHARED_MANAGER_LOG_LOGMANAGER_H_ */
