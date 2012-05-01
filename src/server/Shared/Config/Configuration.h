/*
 * \file Configuration.h
 *
 *  Created on: \date 1 mai 2012
 *      Author: \author joda
 *  \brief :
 */

#include <map>
#include <string>
#include <fstream>
#include <iostream>

using namespace std;




#ifndef CONFIGURATION_H_
#define CONFIGURATION_H_

/*
 *
 */
class Configuration {
public:
	Configuration();
	virtual ~Configuration();

	// clear all values
	void Clear();

	// load a configuration file
	bool Load(const string& File);

	// check if value associated with given key exists
	bool Contains(const string& key) const;

	// get value associated with given key
	bool Get(const string& key, string& value) const;
	bool Get(const string& key, int&    value) const;
	bool Get(const string& key, long&   value) const;
	bool Get(const string& key, double& value) const;
    bool Get(const string& key, bool&   value) const;



private:
    // the container
    map<string,string> data;

    // remove leading and trailing tabs and spaces
    static string Trim(const string& str);



};

#endif /* CONFIGURATION_H_ */
