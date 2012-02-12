#include <stdio.h> // Printf
#include <iostream>
#include "Shared/SignalHandler/SignalHandler.h"

#include "Auth/AuthServer.h" // serveur d'authantification


using namespace std;

int main()
{
	int iret ;

	  try
	  {
	    SignalHandler signalHandler;

	    // Register signal handler to handle kill signal
	    signalHandler.setupSignalHandlers();

		printf("Lancement du serveur Xsilium\n");

	    authServer::authServer * authServer = new authServer::authServer();
	    authServer->startThread();



	    // Infinite loop until signal ctrl-c (KILL) received
	    while(!signalHandler.gotExitSignal())
	    {
	        sleep(1);
	    }

	    authServer->stopThread();
	    delete authServer;
	    iret = EXIT_SUCCESS;
	  }
	  catch (SignalException& e)
	  {
	    std::cerr << "SignalException: " << e.what() << std::endl;
	    iret = EXIT_FAILURE;
	  }
	  return(iret);
	}




