// Appelle de la classe FrameApp.hpp afin d'appeller la fonction startFrame().

#include "FrameApp.hpp"

#if OGRE_PALTFORM == PLATFORM_WIN32 || OGRE_PLATFORM == OGRE_PALTFORM_WIN32
#define WIN32_LEAN_AND_MEAN
#include "windows.h"

INT WINAPI WinMain(HINSTANCE hInst, HINSTANCE, LPSTR strCmdLine, INT)
#else
int main(int argc, char **argv)
#endif
{
	FrameApp frame;
	try
	{
		frame.startFrame();
	}
	catch(std::exception& e)
	{
#if OGRE_PALTFORM == PLATFORM_WIN32 || OGRE_PLATFORM == OGRE_PLATFORM_WIN32
		MessageBoxA(NULL, e.what(), "Une exception est survenue!", MB_OK | MB_ICONERROR | MB_TASKMODAL);
#else
		fprintf(stderr, "Une exception est survenue: %s\n", e.what());
#endif
	}

	return 0;
}