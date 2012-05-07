#include "Auth/AuthServer.h" // serveur d'authantification

int main()
{
	    authServer::authServer * authServer = new authServer::authServer();
	    authServer->startServer();
	    delete authServer;
}




