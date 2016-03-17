/*
 * \file Utilities.cpp
 *
 *  Created on: \date 17 déc. 2014
 *      Author: \author joda
 *  \brief :
 */
#include "Utilities.h"

Utilities::Utilities() {
    // TODO Auto-generated constructor stub

}

Utilities::~Utilities() {
    // TODO Auto-generated destructor stub
}

Tokens Utilities::strSplit(std::string src, std::string sep) {
    Tokens r;
    std::string s;
    for (std::string::const_iterator i = src.begin(); i != src.end(); ++i) {
        if (sep.find(*i) != std::string::npos) {
            if (s.length())
                r.push_back(s);
            s = "";
        } else {
            s += *i;
        }
    }
    if (s.length())
        r.push_back(s);
    return r;
}
;

int Utilities::toInt(std::string str) {
    return atoi(str.c_str());
}

long Utilities::toLong(std::string str) {
    return atol(str.c_str());

}

double Utilities::toDouble(std::string str) {
    return atof(str.c_str());

}

bool Utilities::toBool(std::string str) {
    if (str == "true")
        return true;
    else if (str == "1")
        return true;
    else
        return false;
}

time_t Utilities::toDate(std::string str) {
    boost::posix_time::ptime t(boost::posix_time::time_from_string(str));
    boost::posix_time::ptime start(boost::gregorian::date(1970, 1, 1));
    boost::posix_time::time_duration dur = t - start;
    return dur.total_seconds();
}
