/*
 * \file Configuration.cpp
 *
 *  Created on: \date 3 mai 2012
 *      Author: \author joda
 *  \brief :
 */

#include "Configuration.h"

Configuration::Configuration() {
	// TODO Auto-generated constructor stub

}

Configuration::~Configuration() {
	// TODO Auto-generated destructor stub
}

void Configuration::Clear()
{
    data.clear();
}

bool Configuration::Load(const string& file)
{
    ifstream inFile(file.c_str());

    if (!inFile.good())
    {
        cout << "Cannot read configuration file " << file << endl;
        return false;
    }

    while (inFile.good() && ! inFile.eof())
    {
        string line;
        getline(inFile, line);

        // filter out comments
        if (!line.empty())
        {
            int pos = line.find('#');

            if (pos != (int)string::npos)
            {
                line = line.substr(0, pos);
            }
        }

        // split line into key and value
        if (!line.empty())
        {
            int pos = line.find('=');

            if (pos != (int)string::npos)
            {
                string key     = Trim(line.substr(0, pos));
                string value   = Trim(line.substr(pos + 1));

                if (!key.empty() && !value.empty())
                {
                    data[key] = value;
                }
            }
        }
    }

    return true;
}

bool Configuration::Contains(const string& key) const
{
    return data.find(key) != data.end();
}

bool Configuration::Get(const string& key, string& value) const
{
    map<string,string>::const_iterator iter = data.find(key);

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

bool Configuration::Get(const string& key, int& value) const
{
    string str;

    if (Get(key, str))
    {
        value = atoi(str.c_str());
        return true;
    }
    else
    {
        return false;
    }
}

bool Configuration::Get(const string& key, long& value) const
{
    string str;

    if (Get(key, str))
    {
        value = atol(str.c_str());
        return true;
    }
    else
    {
        return false;
    }
}

bool Configuration::Get(const string& key, double& value) const
{
    string str;

    if (Get(key, str))
    {
        value = atof(str.c_str());
        return true;
    }
    else
    {
        return false;
    }
}

bool Configuration::Get(const string& key, bool& value) const
{
    string str;

    if (Get(key, str))
    {
        value = (str == "true");
        return true;
    }
    else
    {
        return false;
    }
}

string Configuration::Trim(const string& str)
{
    int first = str.find_first_not_of(" \t");

    if (first != (int)string::npos)
    {
        int last = str.find_last_not_of(" \t");

        return str.substr(first, last - first + 1);
    }
    else
    {
        return "";
    }
}
