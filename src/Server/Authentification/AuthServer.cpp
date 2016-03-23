/*
 * \file AuthServer.cpp
 *
 *  Created on: \date 18 déc. 2014
 *      Author: \author joda
 *  \brief :
 */
#include "AuthServer.h"

namespace Auth {

AuthServer::AuthServer() {
    networkManager = new NetworkManager();
    configuration = ConfigurationManager::getInstance();
    log = LogManager::getInstance();
    databaseManager = DatabaseManager::getInstance();
    schedulingService = new SchedulingService();
    realmService = new RealmService(networkManager);
    authentificationService = new AuthentificationService(networkManager);

}

AuthServer::AuthServer(ConfigurationManager * configuration, LogManager * log,
        DatabaseManager * databaseManager, NetworkManager * networkManager,
        AuthentificationService * authentificationService, RealmService * realmService,
        SchedulingService * schedulingService) {
    this->networkManager = networkManager;
    this->configuration = configuration;
    this->log = log;
    this->databaseManager = databaseManager;
    this->schedulingService = schedulingService;
    this->realmService = realmService;
    this->authentificationService = authentificationService;
}

AuthServer::~AuthServer() {
    delete schedulingService;
    delete authentificationService;
    delete realmService;
    delete networkManager;
    DatabaseManager::DestroyInstance();
    ConfigurationManager::DestroyInstance();
    LogManager::DestroyInstance();
}

void AuthServer::startServer() {
    try {

        int logLevel, typeDatabase, serverPort, numClient;
        std::string infoDB;
        ENetAddress adresse;

        if (!configuration->load("../etc/auth.config"))
            return;

        configuration->get("LogLevel", logLevel);
        log->start((LogManager::Priority) logLevel, "authserver.log");
        log->activationFile();

        log->write(LogManager::DEBUG, "Demarrage de la connexion SQL (loginDB) ");
        configuration->get("typeDatabase", typeDatabase);
        configuration->get("databaseInfo", infoDB);

        databaseManager->createServer(typeDatabase);
        databaseManager->connection(infoDB);

        log->write(LogManager::DEBUG, "Demarrage du serveur d'authentification");
        authentificationService->run();

        log->write(LogManager::DEBUG, "Demarrage du serveur de Royaume");
        realmService->run();

        configuration->get("port", serverPort);
        configuration->get("clientMax", numClient);
        adresse.host = ENET_HOST_ANY;
        adresse.port = (enet_uint16) serverPort;

        log->write(LogManager::DEBUG, "Demarrage du socket d'authentification");

        if (!networkManager->createConnexion(&adresse, numClient)) {
            log->write(LogManager::DEBUG, "Impossible d'ouvrir la connexion ");
            return;
        }

        schedulingService->runLoop();

        stopThread();

    } catch (SignalException& e) {
        std::cerr << "SignalException: " << e.what() << std::endl;
    }

}

void AuthServer::stopThread() {
    log->write(LogManager::DEBUG, "Extinction du serveur ");
    networkManager->disconnexion();
    realmService->stopThread();
    authentificationService->stopThread();
    databaseManager->deconnection();

}

} /* namespace Auth */

int main() {
    Auth::AuthServer * authserver = new Auth::AuthServer();
    authserver->startServer();
    delete authserver;
}
