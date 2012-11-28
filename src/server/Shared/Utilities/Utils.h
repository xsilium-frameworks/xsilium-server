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

	/*!
	 *  \brief Utils
	 *
	 *  brief Constructeur
	 *
	 *  \param
	 */

	Utils();
	/*!
	 *  \brief ~Utils
	 *
	 *  brief Destructeur
	 *
	 *  \param
	 */
	virtual ~Utils();


	/*!
	 *  \brief QtrSplit
	 *
	 *  brief ???
	 *
	 *  \param
	 */
	Tokens StrSplit(const std::string &src, const std::string &sep);

	/*!
	 *  \brief convertToDate
	 *
	 *  brief permet d'obtenir la date sous cette forme %Y-%m-%d %H:%M:%S
	 *
	 *  \param
	 */
	time_t convertToDate(std::string valeur);

};

#endif /* UTILS_H_ */
