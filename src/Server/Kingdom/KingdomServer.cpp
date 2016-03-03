/*
 * \file KingdomServer.cpp
 *
 *  Created on: \date 1 janv. 2015
 *      Author: \author joda
 *  \brief :
 */
#include "KingdomServer.h"

namespace Kingdom {

KingdomServer::KingdomServer() {
    signalHandler = 0;
    clientNetwork = new NetworkManager();
    authNetwork = new NetworkManager();
    configuration = ConfigurationManager::getInstance();
    log = LogManager::getInstance();
    databaseManager = DatabaseManager::getInstance();

}

KingdomServer::~KingdomServer() {
    delete clientNetwork;
    delete authNetwork;
    DatabaseManager::DestroyInstance();
    ConfigurationManager::DestroyInstance();
    LogManager::DestroyInstance();
}

void KingdomServer::startServer() {
    try {

        int logLevel, typeDatabase, serverPort, numClient;
        std::string infoDB;
        ENetAddress adresse;

        signalHandler->setupSignalHandlers();
        //if (!configuration->load("../etc/Kingdom.config"))
        //    return;

        //configuration->get("LogLevel", logLevel);
        //log->start((LogManager::Priority) logLevel, "kingdomServer.log");
        //log->activationFile();
        /*
         log->write(LogManager::DEBUG, "Demarrage de la connexion SQL (loginDB) ");
         configuration->get("typeDatabase", typeDatabase);
         configuration->get("databaseInfo", infoDB);

         databaseManager->createServer(typeDatabase);
         databaseManager->connection(infoDB);
         */

        /*configuration->get("portClient", serverPort);
         configuration->get("clientMax", numClient);
         adresse.host = ENET_HOST_ANY;
         adresse.port = (enet_uint16) serverPort;


         log->write(LogManager::DEBUG, "Demarrage du socket Kingdom");

         if (!clientNetwork->createConnexion(&adresse, numClient)) {
         log->write(LogManager::DEBUG, "Impossible d'ouvrir la connexion ");
         return;
         }
         */
        authNetwork->createConnexion();
        authNetwork->connexionToHost("127.0.0.1", 60000);
        while (!signalHandler->gotExitSignal())
            sleep(1);

        stopThread();

    } catch (SignalException& e) {
        std::cerr << "SignalException: " << e.what() << std::endl;
    }
}
void KingdomServer::stopThread() {
    log->write(LogManager::DEBUG, "Extinction du serveur ");
    clientNetwork->disconnexion();
    authNetwork->disconnexion();
    databaseManager->deconnection();

}

} /* namespace Kingdom */

int main() {
    Kingdom::KingdomServer * kingdomServer = new Kingdom::KingdomServer();
    kingdomServer->startServer();
    delete kingdomServer;
}
