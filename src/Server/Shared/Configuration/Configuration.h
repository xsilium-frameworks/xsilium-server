/*
 * \file Configuration.h
 *
 *  Created on: \date 23 oct. 2014
 *      Author: \author joda
 *  \brief :
 */
#ifndef SRC_SERVER_SHARED_CONFIGURATION_CONFIGURATION_H_
#define SRC_SERVER_SHARED_CONFIGURATION_CONFIGURATION_H_

#include <map>
#include <string>
#include <fstream>
#include <iostream>
#include "Singleton/Singleton.h"
#include <boost/thread.hpp>

using namespace std;

/*
 *
 */
class Configuration : public Singleton<Configuration>
{

public:
	Configuration();
	virtual ~Configuration();

	/*!
	 *  \brief Clear
	 *
	 *  brief clear all values
	 *
	 *  \param
	 */
	void Clear();


	/*!
	 *  \brief Load
	 *
	 *  brief load a configuration file
	 *
	 *  \param
	 */

	bool Load(const string& File);

	/*!
	 *  \brief Contains
	 *
	 *  brief check if value associated with given key exists
	 *
	 *  \param
	 */

	bool Contains(const string& key) const;


	/*!
	 *  \brief Get
	 *
	 *  brief get value associated with given key
	 *
	 *  \param
	 */

	bool Get(const string& key, string& value) const;
	bool Get(const string& key, int&    value) const;
	bool Get(const string& key, long&   value) const;
	bool Get(const string& key, double& value) const;
	bool Get(const string& key, bool&   value) const;

private:
	// the container
	map<string,string> data;

	boost::mutex mutex1 ;

	// remove leading and trailing tabs and spaces
	static string Trim(const string& str);

};


#endif /* SRC_SERVER_SHARED_CONFIGURATION_CONFIGURATION_H_ */
