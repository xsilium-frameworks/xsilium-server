/*
	The MenuState class is one of the actual AppState class implementations. By inheriting from AppState it is assured that all states have the same common functi|ons as enter(), exit(), pause(), resume() or update().

    DECLARE_APPSTATE_CLASS(MenuState): This line calls the macro defined in AppState.hpp, making this class a valid application state 
*/

#ifndef MENU_STATE_HPP
#define MENU_STATE_HPP
 
#include "AppState.hpp"
 
class MenuState : public AppState
{
public:
    MenuState();
 
	DECLARE_APPSTATE_CLASS(MenuState)
 
	void enter();
	void createScene();
	void exit();
 
	bool keyPressed(const OIS::KeyEvent &keyEventRef);
	bool keyReleased(const OIS::KeyEvent &keyEventRef);
 
	bool mouseMoved(const OIS::MouseEvent &evt);
	bool mousePressed(const OIS::MouseEvent &evt, OIS::MouseButtonID id);
	bool mouseReleased(const OIS::MouseEvent &evt, OIS::MouseButtonID id);
 
	void buttonHit(OgreBites::Button* button);
 
	void update(double timeSinceLastFrame);
 
private:
	bool m_bQuit;
};
 
#endif