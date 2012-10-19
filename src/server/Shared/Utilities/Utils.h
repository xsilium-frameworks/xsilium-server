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
#include <time.h>

typedef std::vector<std::string> Tokens;

/*
 *
 */
class Utils {
public:
	Utils();
	virtual ~Utils();

	Tokens StrSplit(const std::string &src, const std::string &sep);
	time_t convertToDate(std::string valeur);

};

#endif /* UTILS_H_ */
