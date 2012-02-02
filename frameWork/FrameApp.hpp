/*
The FrameApp class is the central application organizing location. It only has two member variables:

    the application state manager
    an indicator of whether the application is to be shut down or not 
*/


#ifndef OGRE_DEMO_HPP
#define OGRE_DEMO_HPP
 
#include "AdvancedOgreFramework.hpp"
#include "AppStateManager.hpp"
 
class FrameApp
{
public:
	FrameApp();
	~FrameApp();
 
	void startFrame();
 
private:
	AppStateManager*	m_pAppStateManager;
};
 
#endif