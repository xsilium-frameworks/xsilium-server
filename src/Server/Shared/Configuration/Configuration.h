/*!
 * \file Configuration.h
 * \date 23 oct. 2014
 * \author joda
 * \brief : File that contain Configuration class
 */
#ifndef SRC_SERVER_SHARED_CONFIGURATION_CONFIGURATION_H_
#define SRC_SERVER_SHARED_CONFIGURATION_CONFIGURATION_H_

#include <map>
#include <string>
#include <fstream>
#include <iostream>
#include <Singleton/Singleton.h>
#include <boost/thread.hpp>
#include <Utilities/Utilities.h>

/*!
 * \class Configuration
 * \brief Class that handle configuration stuff
 */
class Configuration : public Singleton<Configuration>, public Utilities
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
	void clear();
	/*!
	 *  \brief Load
	 *
	 *  brief load a configuration file
	 *
	 *  \param[in] File std::string type
	 */
	bool load(std::string File);
	/*!
	 *  \brief Contains
	 *
	 *  brief check if value associated with given key exists
	 *
	 *  \param[in] key std::string type
	 */
	bool contains(std::string key);
	/*!
	 *  \brief Get
	 *
	 *  brief get value associated with given key
	 *
	 *  \param key,value
	 */
	bool get(std::string key, std::string& value);
	bool get(std::string key, int&    value);
	bool get(std::string key, long&   value);
	bool get(std::string key, double& value);
	bool get(std::string key, bool&   value);

private:
	// the container
	std::map<std::string,std::string> data;

	boost::mutex mutex1 ;

	// remove leading and trailing tabs and spaces
	std::string trim(std::string str);

};


#endif /* SRC_SERVER_SHARED_CONFIGURATION_CONFIGURATION_H_ */
