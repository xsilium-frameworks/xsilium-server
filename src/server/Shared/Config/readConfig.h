/*
 * readConfig.h
 *
 *  Created on: 29 mars 2012
 *      Author: mathieu
 */




#ifndef READCONFIG_H_
#define READCONFIG_H_

#include <string>
#include <fstream>
#include <iostream>


class readConfig {
public:
	readConfig();
	virtual ~readConfig();

	void testFile();
	void testRead();
	void readFile();



};

#endif /* READCONFIG_H_ */
