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
    clientNetwork = new NetworkManager();
    configuration = ConfigurationManager::getInstance();
    log = LogManager::getInstance();
    databaseManager = DatabaseManager::getInstance();
    schedulingService = new SchedulingService();
    chatService = new ChatService(clientNetwork);
    playerService = new PlayerService(clientNetwork);
    authentificationService = new AuthentificationService(clientNetwork);

}

KingdomServer::KingdomServer(ConfigurationManager * configuration, LogManager * log,
        DatabaseManager * databaseManager, NetworkManager * networkManager,
        SchedulingService * schedulingService, ChatService * chatService,
        PlayerService * playerService) {

    this->clientNetwork = networkManager;
    this->configuration = configuration;
    this->log = log;
    this->databaseManager = databaseManager;
    this->schedulingService = schedulingService;
    this->chatService = chatService;
    this->playerService = playerService;

}

KingdomServer::~KingdomServer() {
    delete authentificationService;
    delete schedulingService;
    delete chatService;
    delete clientNetwork;
    DatabaseManager::DestroyInstance();
    ConfigurationManager::DestroyInstance();
    LogManager::DestroyInstance();
}

void KingdomServer::startServer(std::string configFile) {
    try {

        int logLevel, typeDatabase, serverPort, numClient;
        std::string infoDB;
        ENetAddress adresse;

        if (!configuration->load(configFile))
            return;

        configuration->get("LogLevel", logLevel);
        log->start((LogManager::Priority) logLevel, "kingdomServer.log");
        log->activationFile();

        log->write(LogManager::DEBUG, "Demarrage de la connexion SQL (loginDB) ");
        configuration->get("typeDatabase", typeDatabase);
        configuration->get("databaseInfo", infoDB);

        databaseManager->createServer(typeDatabase);
        databaseManager->connection(infoDB);

        log->write(LogManager::DEBUG, "Demarrage du Service Authentification");
        authentificationService->run();

        log->write(LogManager::DEBUG, "Demarrage du Service de chat");
        chatService->run();

        log->write(LogManager::DEBUG, "Demarrage du Service de chat");
        playerService->run();

        configuration->get("portClient", serverPort);
        configuration->get("clientMax", numClient);
        adresse.host = ENET_HOST_ANY;
        adresse.port = (enet_uint16) serverPort;

        log->write(LogManager::DEBUG, "Demarrage du socket Kingdom");

        if (!clientNetwork->createConnexion(&adresse, numClient)) {
            log->write(LogManager::DEBUG, "Impossible d'ouvrir la connexion ");
            return;
        }

        schedulingService->runLoop();

        stopThread();

    } catch (SignalException& e) {
        std::cerr << "SignalException: " << e.what() << std::endl;
    }
}
void KingdomServer::stopThread() {
    log->write(LogManager::DEBUG, "Extinction du serveur ");
    clientNetwork->disconnexion();
    databaseManager->deconnection();

}

} /* namespace Kingdom */

int main(int argc, char* argv[]) {
    if (argc == 2) {
        Kingdom::KingdomServer kingdomServer;
        kingdomServer.startServer(argv[1]);
    }
}
