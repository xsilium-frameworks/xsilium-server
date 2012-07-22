/*
 * \file Threading.h
 *
 *  Created on: \date 15 juil. 2012
 *      Author: \author joda
 *  \brief :
 */


#include <iostream>
#include <pthread.h>
#include <cassert>
#include <memory>

class Runnable
    {
        public:
            virtual ~Runnable() {}
            virtual void * run() = 0;
    };

class Thread {
public:
	Thread(std::auto_ptr<Runnable> run, bool isDetached = false);
	Thread(bool isDetached = false);
	virtual ~Thread();
	void start();
	void* join();
private:
	// thread ID
	pthread_t PthreadThreadID;
	// true if thread created in detached state
	bool detached;
	pthread_attr_t threadAttribute;
	// runnable object will be deleted automatically
	std::auto_ptr<Runnable> runnable;
	Thread(const Thread&);
	const Thread& operator=(const Thread&);
	// called when run() completes
	void setCompleted();
	// stores return value from run()
	void* result;
	virtual void* run() {}
	static void* startThreadRunnable(void* pVoid);
	static void* startThread(void* pVoid);
};
