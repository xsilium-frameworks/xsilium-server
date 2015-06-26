/*
 * \file ChatManager.h
 *
 *  Created on: \date 3 janv. 2015
 *      Author: \author joda
 *  \brief :
 */
#include <Network/NetworkManager.h>
#include <Configuration/Configuration.h>

#ifndef SRC_SERVER_KINGDOM_CHAT_CHATMANAGER_H_
#define SRC_SERVER_KINGDOM_CHAT_CHATMANAGER_H_

namespace Kingdom {

	/*! Enumeration des types de message disponibles */
	enum typeForChat
	{
		ID_KINGDOM, /*!< Message à destination de tout le royaume pour un canal particulier: world/trade...  */
		ID_AREA,  /*!< Message à destination d'une zone du jeu*/
		ID_PRIVATE, /*!< Message privé entre 2 joueurs*/
		ID_COMMUNITY, /*!< Message à destination d'un groupe de joueur: Guilde, alliance...*/
		ID_ERREUR /*!< Message de retour en cas d'anomalie*/
	};

	/*! Enumeration des types de retour possibles */
	enum erreurOfChat
	{
		ID_NOERROR = 0,
		ID_ERROR_PACKET_SIZE,
		ID_SPAM
	};

/*! Header du chatManager*/
class ChatManager : public NetworkListener{

public:
	ChatManager(NetworkManager * NetworkManager);
	virtual ~ChatManager();
	void run();

    /*!
     *  \brief Gestion des messages à destination de l'ensemble du serveur
     *  \param messageNetwork:
     *  	Forme du fichier en entrée: String canal: canal de discution
     *  \return messageRetour
     */
	int HandleChatKingdom(MessageNetwork * messageNetwork,MessagePacket * messageRetour);
    /*!
     *  \brief Gestion des messages à destination d'une zone spécifique
     *  \param messageNetwork:
     *  	Forme du fichier en entrée: String id_area: id de la zone
     *  \return messageRetour
     */
	int HandleChatArea(MessageNetwork * messageNetwork,MessagePacket * messageRetour);
	/*!
     *  \brief Gestion des messagesà  destination d'un joueur
     *  \param messageNetwork:
     *  	Forme du fichier en entrée: String name_dest: nom du joueur destinataire
     *
     *  \return messageRetour
     */
	int HandleChatPrivate(MessageNetwork * messageNetwork,MessagePacket * messageRetour);
	/*!
     *  \brief Indicateur de spam de l'emetteur
     *  \param messageNetwork
     *  \return messageRetour
     */
	bool SpamDetector(MessageNetwork * messageNetwork,MessagePacket * messageRetour);
	void processPacket(MessageNetwork * messageNetwork);

private:
	Log * log;
	Configuration * config ;
	NetworkManager * networkManager;
};


} /* namespace Kingdom */

#endif /* SRC_SERVER_KINGDOM_CHAT_CHAT_H_ */
