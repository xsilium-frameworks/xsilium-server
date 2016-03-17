/*
 * \file Utilities.h
 *
 *  Created on: \date 17 déc. 2014
 *      Author: \author joda
 *  \brief :
 */
#ifndef SRC_SERVER_SHARED_UTILITIES_UTILITIES_H_
#define SRC_SERVER_SHARED_UTILITIES_UTILITIES_H_

#include <string>
#include <vector>
#include <sstream>
#include <stdlib.h>
#include <boost/date_time/posix_time/posix_time.hpp>
/*
 *
 */

typedef std::vector<std::string> Tokens;

class Utilities {
public:
    Utilities();
    virtual ~Utilities();

    static Tokens strSplit(std::string src, std::string sep);

    static int toInt(std::string str);
    static long toLong(std::string str);
    static double toDouble(std::string str);
    static bool toBool(std::string str);
    static time_t toDate(std::string str);

    template<typename T>
    static std::string toString(T variable) {
        std::ostringstream ss;
        ss << variable;
        return ss.str();
    }

};

#endif /* SRC_SERVER_SHARED_UTILITIES_UTILITIES_H_ */
