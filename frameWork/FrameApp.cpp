/*

The central application file, managing everything:

    FrameApp(): Constructor
    ~FrameApp(): Destructor
    startFrame(): Starts the application: 

    fires up the OgreFramework
    initializes Ogre (via the OgreFramework)
    create an AppStateManager instance
    creates the application states (MenuState, GameState and PauseState)
    orders the AppStateManager to start its main loop function 

*/

#include "FrameApp.hpp"
 
#include "MenuState.hpp"
#include "GameState.hpp"
#include "PauseState.hpp"
 
FrameApp::FrameApp()
{
	m_pAppStateManager = 0;
}
 
FrameApp::~FrameApp()
{
	delete m_pAppStateManager;
        delete OgreFramework::getSingletonPtr();
}
 
void FrameApp::startFrame()
{
	new OgreFramework();
	if(!OgreFramework::getSingletonPtr()->initOgre("AdvancedOgreFramework", 0, 0))
		return;
 
	OgreFramework::getSingletonPtr()->m_pLog->logMessage("Demo initialized!");
 
	m_pAppStateManager = new AppStateManager();
 
	MenuState::create(m_pAppStateManager, "MenuState");
	GameState::create(m_pAppStateManager, "GameState");
        PauseState::create(m_pAppStateManager, "PauseState");
 
	m_pAppStateManager->start(m_pAppStateManager->findByName("MenuState"));
}