/*
	AppStateManager(): Constructeur
    ~AppStateManager(): Destructeur, sort tous les états d'application actif et vide le std::vectors 
*/

#include "AppStateManager.hpp"
 
#include <OgreWindowEventUtilities.h>
 
AppStateManager::AppStateManager()
{
	m_bShutdown = false;
}
 
AppStateManager::~AppStateManager()
{
	state_info si;
 
        while(!m_ActiveStateStack.empty())
	{
		m_ActiveStateStack.back()->exit();
		m_ActiveStateStack.pop_back();
	}
 
	while(!m_States.empty())
	{
		si = m_States.back();
                si.state->destroy();
                m_States.pop_back();
	}
}

//  manageAppState(): Called from within the state creation macro and sets some information of the new state, as well as pushing it on the active states stack 

void AppStateManager::manageAppState(Ogre::String stateName, AppState* state)
{
	try
	{
		state_info new_state_info;
		new_state_info.name = stateName;
		new_state_info.state = state;
		m_States.push_back(new_state_info);		
	}
	catch(std::exception& e)
	{
		delete state;
		throw Ogre::Exception(Ogre::Exception::ERR_INTERNAL_ERROR, "Error while trying to manage a new AppState\n" + Ogre::String(e.what()), "AppStateManager.cpp (39)");
	}
}

// findByName(): Returns a pointer to the state with the respective name 

AppState* AppStateManager::findByName(Ogre::String stateName)
{
	std::vector<state_info>::iterator itr;
 
	for(itr=m_States.begin();itr!=m_States.end();itr++)
	{
		if(itr->name==stateName)
			return itr->state;
	}
 
	return 0;
}

/*
	start(): Main loop of the application that does the following steps: 

    change to the state specified
    start loop
    capture keyboard and mouse input
    update the current state (the top most of the stack)
    call the OgreFramework class to update and render 

*/

void AppStateManager::start(AppState* state)
{
	changeAppState(state);
 
	int timeSinceLastFrame = 1;
	int startTime = 0;
 
	while(!m_bShutdown)
	{
		if(OgreFramework::getSingletonPtr()->m_pRenderWnd->isClosed())m_bShutdown = true;
 
		Ogre::WindowEventUtilities::messagePump();
 
		if(OgreFramework::getSingletonPtr()->m_pRenderWnd->isActive())
		{
			startTime = OgreFramework::getSingletonPtr()->m_pTimer->getMillisecondsCPU();
 
			OgreFramework::getSingletonPtr()->m_pKeyboard->capture();
			OgreFramework::getSingletonPtr()->m_pMouse->capture();
 
			m_ActiveStateStack.back()->update(timeSinceLastFrame);
 
			OgreFramework::getSingletonPtr()->updateOgre(timeSinceLastFrame);
			OgreFramework::getSingletonPtr()->m_pRoot->renderOneFrame();
 
			timeSinceLastFrame = OgreFramework::getSingletonPtr()->m_pTimer->getMillisecondsCPU() - startTime;
		}
		else
		{
#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
            Sleep(1000);
#else
            sleep(1);
#endif
		}
	}
 
	OgreFramework::getSingletonPtr()->m_pLog->logMessage("Main loop quit");
}

// changeAppState(): Exits the current state (if there is any) and starts the new specified one 

void AppStateManager::changeAppState(AppState* state)
{
	if(!m_ActiveStateStack.empty())
	{
		m_ActiveStateStack.back()->exit();
		m_ActiveStateStack.pop_back();
	}
 
	m_ActiveStateStack.push_back(state);
	init(state);
	m_ActiveStateStack.back()->enter();
}

// pushAppState(): Puts an new state on the top of the stack and starts it 

bool AppStateManager::pushAppState(AppState* state)
{
	if(!m_ActiveStateStack.empty())
	{
		if(!m_ActiveStateStack.back()->pause())
			return false;
	}
 
	m_ActiveStateStack.push_back(state);
	init(state);
	m_ActiveStateStack.back()->enter();
 
	return true;
}

// popAppState(): Removes the top most state and resumes the one below if there is one, otherwise shutdown the application 

void AppStateManager::popAppState()
{
	if(!m_ActiveStateStack.empty())
	{
		m_ActiveStateStack.back()->exit();
		m_ActiveStateStack.pop_back();
	}
 
	if(!m_ActiveStateStack.empty())
	{
		init(m_ActiveStateStack.back());
		m_ActiveStateStack.back()->resume();
	}
    else
		shutdown();
}

// popAllAndPushAppState(): Exits all existing app state on the stack and enters the given new state 

void AppStateManager::popAllAndPushAppState(AppState* state)
{
    while(!m_ActiveStateStack.empty())
    {
        m_ActiveStateStack.back()->exit();
        m_ActiveStateStack.pop_back();
    }
 
    pushAppState(state);
}

// pauseAppState(): Pauses the current app state and resumes the one in the stack below

void AppStateManager::pauseAppState()
{
	if(!m_ActiveStateStack.empty())
	{
		m_ActiveStateStack.back()->pause();
	}
 
	if(m_ActiveStateStack.size() > 2)
	{
		init(m_ActiveStateStack.at(m_ActiveStateStack.size() - 2));
		m_ActiveStateStack.at(m_ActiveStateStack.size() - 2)->resume();
	}
}

// shutdown(): Exits the application 

void AppStateManager::shutdown()
{
	m_bShutdown = true;
}

// init(): Initializes a new state and links the input and SDKTrays callback on it, as well as resetting the Ogre statistics (FPS?, triangle count, batch count, ...) 

void AppStateManager::init(AppState* state)
{
    OgreFramework::getSingletonPtr()->m_pKeyboard->setEventCallback(state);
	OgreFramework::getSingletonPtr()->m_pMouse->setEventCallback(state);
    OgreFramework::getSingletonPtr()->m_pTrayMgr->setListener(state);
 
	OgreFramework::getSingletonPtr()->m_pRenderWnd->resetStatistics();
}