/*
 * \file Configuration.cpp
 *
 *  Created on: \date 3 mai 2012
 *      Author: \author joda
 *  \brief :
 */

#include "Configuration.h"

Configuration::Configuration()
{
}

Configuration::~Configuration() {
	// TODO Auto-generated destructor stub
}

void Configuration::clear()
{
    data.clear();
}

bool Configuration::load(std::string file)
{

	boost::mutex::scoped_lock lock(mutex1);

	std::ifstream inFile(file.c_str());

    if (!inFile.good())
    {
    	std::cout << "Cannot read configuration file " << file << std::endl;
        return false;
    }

    while (inFile.good() && ! inFile.eof())
    {
    	std::string line;
    	std::getline(inFile, line);

        // filter out comments
        if (!line.empty())
        {
            int pos = line.find('#');

            if (pos != (int)std::string::npos)
            {
                line = line.substr(0, pos);
            }
        }

        // split line into key and value
        if (!line.empty())
        {
            int pos = line.find('=');

            if (pos != (int)std::string::npos)
            {
            	std::string key     = trim(line.substr(0, pos));
            	std::string value   = trim(line.substr(pos + 1));

                if (!key.empty() && !value.empty())
                {
                    data[key] = value;
                }
            }
        }
    }

    return true;
}

bool Configuration::contains(std::string key)
{
    return data.find(key) != data.end();
}

bool Configuration::get(std::string key, std::string& value)
{
	std::map<std::string,std::string>::const_iterator iter = data.find(key);

    if (iter != data.end())
    {
        value = iter->second;

        return true;
    }
    else
    {
        return false;
    }
}

bool Configuration::get(std::string key, int& value)
{
	std::string str;

    if (get(key, str))
    {
        value = ToInt(str);
        return true;
    }
    else
    {
        return false;
    }
}

bool Configuration::get(std::string key, long& value)
{
	std::string str;

    if (get(key, str))
    {
        value = atol(str.c_str());
        return true;
    }
    else
    {
        return false;
    }
}

bool Configuration::get(std::string key, double& value)
{
	std::string str;

    if (get(key, str))
    {
        value = atof(str.c_str());
        return true;
    }
    else
    {
        return false;
    }
}

bool Configuration::get(std::string key, bool& value)
{
	std::string str;

    if (get(key, str))
    {
    	if(str == "true")
    		value = true;
    	else if(str == "1")
    		value = true;
    	else
    		value = false;
        return true;
    }
    else
    {
        return false;
    }
}

std::string Configuration::trim(std::string str)
{
    int first = str.find_first_not_of(" \t");

    if (first != (int)std::string::npos)
    {
        int last = str.find_last_not_of(" \t");

        return str.substr(first, last - first + 1);
    }
    else
    {
        return "";
    }
}
