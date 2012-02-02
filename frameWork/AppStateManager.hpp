/*
	The class AppStateManager inherits from the class AppStateListener shown above and mainly implements its abstract methods. 
	Furthermore it contains:
	a std::vector for all existing states (m_States)
    a std::vector for the active states, so the stack of those states currently is use (m_ActiveStateStack)
*/
 
#ifndef APP_STATE_MANAGER_HPP
#define APP_STATE_MANAGER_HPP
 
#include "AppState.hpp"
 
class AppStateManager : public AppStateListener
{
public:
	typedef struct
	{
		Ogre::String name;
		AppState* state;
	} state_info;
 
	AppStateManager();
	~AppStateManager();
 
	void manageAppState(Ogre::String stateName, AppState* state);
 
	AppState* findByName(Ogre::String stateName);
 
	void start(AppState* state);
	void changeAppState(AppState* state);
	bool pushAppState(AppState* state);
	void popAppState();
	void pauseAppState();
	void shutdown();
        void popAllAndPushAppState(AppState* state);
 
protected:
	void init(AppState *state);
 
	std::vector<AppState*>		m_ActiveStateStack;
	std::vector<state_info>		m_States;
	bool				m_bShutdown;
};
 
#endif

