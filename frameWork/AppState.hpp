/*
	Classes: AppStateListener, AppState

	AppState: Va être appellé par le gestionaire des statistiques de l'application. 
	Doit être défini ici 

	AppstateListener(): Constructor
    ~AppStateListner(): Destructor
    manageGameState(): Function to later add a new state to the manager
    changeAppState(): Exits the current app state and starts the one specified as the parameter
    pushAppState(): Puts a new app state on the active state stack that will then be excecuted
    popGameState(): Removes the top active state from the stack, which results in returning to the one below
    shutdown(): Well, guess what happens here...
    popAllAndPushAppState(): Removes all current app states from the stack and moves to the given new state 

	AppState: Application Squelette de l'état de toutes les applications qui va en hériter.

	Fonctions d'entrée, de sortie, de pause, de retour et de mise à jour
	Fonctions pour appellé d'autres états (ex; Gestion du démarage de chaque fonctions)
	Intègre la camera et le SceneManager 
*/

#ifndef APP_STATE_HPP
#define APP_STATE_HPP

 
#include "AdvancedOgreFramework.hpp"
 
class AppState;
 
 
class AppStateListener
{
public:
	AppStateListener(){};
	virtual ~AppStateListener(){};
 
	virtual void manageAppState(Ogre::String stateName, AppState* state) = 0;
 
	virtual AppState*	findByName(Ogre::String stateName) = 0;
	virtual void		changeAppState(AppState *state) = 0;
	virtual bool		pushAppState(AppState* state) = 0;
	virtual void		popAppState() = 0;
	virtual void		pauseAppState() = 0;
	virtual void		shutdown() = 0;
        virtual void            popAllAndPushAppState(AppState* state) = 0;
};

 
class AppState : public OIS::KeyListener, public OIS::MouseListener, public OgreBites::SdkTrayListener
{
public:
	static void create(AppStateListener* parent, const Ogre::String name){};
 
	void destroy(){delete this;}
 
	virtual void enter() = 0;
	virtual void exit() = 0;
	virtual bool pause(){return true;}
	virtual void resume(){};
	virtual void update(double timeSinceLastFrame) = 0;
 
protected:
	AppState(){};
 
	AppState*	findByName(Ogre::String stateName){return m_pParent->findByName(stateName);}
	void		changeAppState(AppState* state){m_pParent->changeAppState(state);}
	bool		pushAppState(AppState* state){return m_pParent->pushAppState(state);}
	void		popAppState(){m_pParent->popAppState();}
	void		shutdown(){m_pParent->shutdown();}
        void            popAllAndPushAppState(AppState* state){m_pParent->popAllAndPushAppState(state);}
 
	AppStateListener*	m_pParent;
 
	Ogre::Camera*		m_pCamera;
	Ogre::SceneManager*	m_pSceneMgr;
    Ogre::FrameEvent            m_FrameEvent;
};

 // big #define statement. It defines the makro DECLARE_APPSTATE_CLASS via that you can later create the game states.
#define DECLARE_APPSTATE_CLASS(T)					\
static void create(AppStateListener* parent, const Ogre::String name)	\
{									\
	T* myAppState = new T();					\
	myAppState->m_pParent = parent;					\
	parent->manageAppState(name, myAppState);			\
}

 
#endif