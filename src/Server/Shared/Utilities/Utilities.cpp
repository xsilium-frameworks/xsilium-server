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

int Utilities::ToInt(std::string str) {
	return atoi(str.c_str());
}

long Utilities::ToLong(std::string str) {
	return atol(str.c_str());

}

double Utilities::ToDouble(std::string str) {
	return atof(str.c_str());

}

bool Utilities::ToBool(std::string str) {
	if (str == "true")
		return true;
	else if (str == "1")
		return true;
	else
		return false;
}
