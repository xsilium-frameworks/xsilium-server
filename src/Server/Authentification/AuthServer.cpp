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
    realmService = 0;
    authentificationService = 0;

}

AuthServer::AuthServer(AuthServer & authServer) {
    setNetworkManager(authServer.getNetworkManager());
    setConfiguration(authServer.getConfiguration());
    setLog(authServer.getLog());
    setDatabaseManager(authServer.getDatabaseManager());
    setSchedulingService(authServer.getSchedulingService());
    setRealmService(authServer.getRealmService());
    setAuthentificationService(authServer.getAuthentificationService());
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

void AuthServer::startServer(std::string configFile) {
    try {

        int logLevel, typeDatabase, serverPort, numClient;
        std::string infoDB;
        ENetAddress adresse;

        if (!configuration->load(configFile))
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
        if (authentificationService == 0) {
            authentificationService = new AuthentificationService(networkManager);
        }
        authentificationService->run();

        log->write(LogManager::DEBUG, "Demarrage du serveur de Royaume");
        if (realmService == 0) {
            realmService = new RealmService(networkManager);
        }
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
    log->stop();

}

AuthentificationService*& AuthServer::getAuthentificationService() {
    return authentificationService;
}

void AuthServer::setAuthentificationService(AuthentificationService*& authentificationService) {
    this->authentificationService = authentificationService;
}

ConfigurationManager*& AuthServer::getConfiguration() {
    return configuration;
}

void AuthServer::setConfiguration(ConfigurationManager*& configuration) {
    this->configuration = configuration;
}

DatabaseManager*& AuthServer::getDatabaseManager() {
    return databaseManager;
}

void AuthServer::setDatabaseManager(DatabaseManager*& databaseManager) {
    this->databaseManager = databaseManager;
}

LogManager*& AuthServer::getLog() {
    return log;
}

void AuthServer::setLog(LogManager*& log) {
    this->log = log;
}

NetworkManager*& AuthServer::getNetworkManager() {
    return networkManager;
}

void AuthServer::setNetworkManager(NetworkManager*& networkManager) {
    this->networkManager = networkManager;
}

RealmService*& AuthServer::getRealmService() {
    return realmService;
}

void AuthServer::setRealmService(RealmService*& realmService) {
    this->realmService = realmService;
}

SchedulingService*& AuthServer::getSchedulingService() {
    return schedulingService;
}

void AuthServer::setSchedulingService(SchedulingService*& schedulingService) {
    this->schedulingService = schedulingService;
}

} /* namespace Auth */

int main(int argc, char* argv[]) {
    if (argc == 2) {
        Auth::AuthServer authserver;
        authserver.startServer(argv[1]);
    }
}
