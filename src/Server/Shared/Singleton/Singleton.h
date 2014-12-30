/*
 * \file Singleton.h
 *
 *  Created on: \date 23 oct. 2014
 *      Author: \author joda
 *  \brief :
 */
#ifndef SRC_SERVER_SHARED_SINGLETON_SINGLETON_H_
#define SRC_SERVER_SHARED_SINGLETON_SINGLETON_H_

#include "stdlib.h"

template <typename Tsingleton>
class Singleton
{
public:
	static Tsingleton * getInstance()
	{
		if(NULL == _singleton)
			_singleton = new Tsingleton;

		return _singleton;
	}

	static void DestroyInstance()
	{
		if(NULL != _singleton)
		{
			delete _singleton;
			_singleton= NULL;
		}
	}

protected:
	Singleton(){}
	~Singleton(){}
private:
	static Tsingleton * _singleton;
};

template <typename Tsingleton>
Tsingleton * Singleton<Tsingleton>::_singleton = NULL;



#endif /* SRC_SERVER_SHARED_SINGLETON_SINGLETON_H_ */
