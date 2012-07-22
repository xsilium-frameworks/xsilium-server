/*
 * \file Utils.h
 *
 *  Created on: \date 15 juil. 2012
 *      Author: \author joda
 *  \brief :
 */

#ifndef UTILS_H_
#define UTILS_H_

#include <string>
#include <vector>

typedef std::vector<std::string> Tokens;

/*
 *
 */
class Utils {
public:
	Utils();
	virtual ~Utils();

	Tokens StrSplit(const std::string &src, const std::string &sep);
};

#endif /* UTILS_H_ */
