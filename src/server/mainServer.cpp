#include <stdio.h> // Printf
#include <signal.h> // gestion de signaux
#include <cmath>

#include "Auth/AuthServer.h" // serveur d'authantification

int main()
{
	printf("Lancement du serveur Xsilium\n");

    authServer::authServer * authServer = new authServer::authServer();
    authServer->startThread();
    while(1);
    return 0 ;
}
