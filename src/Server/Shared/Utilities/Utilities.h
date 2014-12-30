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
#include <cstdlib>
/*
 *
 */

typedef std::vector<std::string> Tokens;

class Utilities {
public:
	Utilities();
	virtual ~Utilities();

	Tokens strSplit(std::string src, std::string sep);

	int ToInt(std::string str);
	long ToLong(std::string str);
	double ToDouble(std::string str);
	bool ToBool(std::string str);

	template<typename T>
	std::string ToString(T variable) {
		std::ostringstream ss;
		ss << variable;
		return ss.str();
	}

};

#endif /* SRC_SERVER_SHARED_UTILITIES_UTILITIES_H_ */
