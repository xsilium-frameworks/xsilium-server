#include "Auth/AuthServer.h" // serveur d'authantification

int main()
{
	    authServer * authserver = new authServer();
	    authserver->startServer();
	    delete authserver;
}




