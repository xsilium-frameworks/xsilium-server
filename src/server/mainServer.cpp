#include <stdio.h> // Printf
#include <signal.h> // gestion de signaux

#include "Auth/authServer.h" // serveur d'authantification

int main()
{
	printf("Lancement du serveur Xsilium\n");

    authServer::authServer * authServer = new authServer::authServer();
    authServer->startThread();

    return 0 ;
}
