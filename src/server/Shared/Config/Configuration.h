/*
 * \file Configuration.h
 *
 *  Created on: \date 3 mai 2012
 *      Author: \author joda
 *  \brief :
 */

#ifndef CONFIGURATION_H_
#define CONFIGURATION_H_

#include <map>
#include <string>
#include <fstream>
#include <iostream>
#include "Singleton/Singleton.h"
#include "pthread.h"

using namespace std;

/*
 *
 */
class Configuration : public Singleton<Configuration>
{
	friend class Singleton<Configuration>;

public:
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

		Configuration();
		~Configuration();
	    // the container
	    map<string,string> data;

	    pthread_mutex_t mutex1 ;

	    // remove leading and trailing tabs and spaces
	    static string Trim(const string& str);

};

#endif /* CONFIGURATION_H_ */
