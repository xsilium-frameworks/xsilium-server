/*
 * ChatService.h
 *
 *  Created on: 11 juil. 2015
 *      Author: Skronak
 */

#ifndef SRC_SERVER_AUTHENTIFICATION_AUTHENTIFICATION_SERVICE_CHATSERVICE_H_
#define SRC_SERVER_AUTHENTIFICATION_AUTHENTIFICATION_SERVICE_CHATSERVICE_H_

#include <Manager/Network/NetworkManager.h>

namespace Kingdom {

/*! Enumeration des types de message disponibles */
enum typeForChat {
    ID_KINGDOM, /*!< Message a destination de tout le royaume pour un canal particulier: world/trade...  */
    ID_AREA, /*!< Message a destination d'une zone du jeu*/
    ID_PRIVATE, /*!< Message prive entre 2 joueurs*/
    ID_COMMUNITY, /*!< Message a destination d'un groupe de joueur: Guilde, alliance...*/
    ID_ERREUR /*!< Message de retour en cas d'anomalie*/
};

/*! Enumeration des types de retour possibles */
enum erreurOfChat {
    ID_NOERROR = 0, ID_ERROR_PACKET_SIZE = 1, ID_SPAM = 3
};

class ChatService: public Service {
public:

    /*!
     *  \brief Constructeur de la classe Authentification et se connecte a la DB
     *  \param networkManager
     */
    ChatService(NetworkManager * networkManager);
    virtual ~ChatService();

    /*!
     * methode de lancement du thread
     */
    void run();

    void processPacket(MessageNetwork * messageNetwork);
    /*!
     *  \brief Gestion des messages a destination de l'ensemble du serveur
     *  \param messageNetwork:
     *      Forme du fichier en entree: String canal: canal de discution
     *  \return messageRetour
     */
    void handleChatKingdom(MessageNetwork * messageNetwork, MessageNetwork * messageRetour);
    /*!
     *  \brief Gestion des messages a destination d'une zone specifique
     *  \param messageNetwork:
     *      Forme du fichier en entree: String id_area: id de la zone, text: contenu du message
     *  \return messageRetour
     */
    void handleChatArea(MessageNetwork * messageNetwork, MessageNetwork * messageRetour);
    /*!
     *  \brief Gestion des messages a  destination d'un joueur
     *  \param messageNetwork:
     *      Forme du fichier en entree: String name_dest: nom du joueur destinataire, text: contenu du message
     *
     *  \return messageRetour
     */
    void handleChatPrivate(MessageNetwork * messageNetwork, MessageNetwork * messageRetour);
    /*!
     *  \brief Gestion des messages a  destination d'un groupe de joueurs
     *  \param messageNetwork:
     *      Forme du fichier en entree: String id_community: identifiant de la liste de joueurs, text: contenu du message
     *
     *  \return messageRetour
     */
    void handleChatCommunity(MessageNetwork * messageNetwork, MessageNetwork * messageRetour);

    /*!
     *  \brief Indicateur de spam de l'emetteur
     *  \param messageNetwork
     *  \return messageRetour
     */
    bool spamDetector(MessageNetwork * messageNetwork, MessagePacket * messageRetour);

    /*!
     * Alimentation des erreurs d'un packets
     * @param messageRetour
     * @param typeForAuth : type d'erreur
     */
    void sendErrorPacket(MessageNetwork * messageNetwork, MessageNetwork * messageRetour,
            int typeErreur);

private:
    NetworkManager * networkManager;
};

} /* namespace Auth */

#endif /* SRC_SERVER_AUTHENTIFICATION_AUTHENTIFICATION_SERVICE_CHATSERVICE_H_ */
