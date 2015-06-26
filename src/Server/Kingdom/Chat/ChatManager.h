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
	ID_KINGDOM, /*!< Message a destination de tout le royaume pour un canal particulier: world/trade...  */
	ID_AREA,  /*!< Message a destination d'une zone du jeu*/
	ID_PRIVATE, /*!< Message prive entre 2 joueurs*/
	ID_COMMUNITY, /*!< Message a destination d'un groupe de joueur: Guilde, alliance...*/
	ID_ERREUR /*!< Message de retour en cas d'anomalie*/
};

/*! Enumeration des types de retour possibles */
enum erreurOfChat
{
	ID_NOERROR = 0,
	ID_ERROR_PACKET_SIZE = 1,
	ID_SPAM = 3
};

/*! Header du chatManager*/
class ChatManager : public NetworkListener{

public:
	ChatManager(NetworkManager * NetworkManager);
	virtual ~ChatManager();

	/*!
	 *  \brief Lancement du module chat
	 */
	void run();

	/*!
	 *  \brief Gestion des messages a destination de l'ensemble du serveur
	 *  \param messageNetwork:
	 *  	Forme du fichier en entree: String canal: canal de discution
	 *  \return messageRetour
	 */
	int HandleChatKingdom(MessageNetwork * messageNetwork,MessagePacket * messageRetour);
	/*!
	 *  \brief Gestion des messages a destination d'une zone specifique
	 *  \param messageNetwork:
	 *  	Forme du fichier en entree: String id_area: id de la zone, text: contenu du message
	 *  \return messageRetour
	 */
	int HandleChatArea(MessageNetwork * messageNetwork,MessagePacket * messageRetour);
	/*!
	 *  \brief Gestion des messages a  destination d'un joueur
	 *  \param messageNetwork:
	 *  	Forme du fichier en entree: String name_dest: nom du joueur destinataire, text: contenu du message
	 *
	 *  \return messageRetour
	 */
	int HandleChatPrivate(MessageNetwork * messageNetwork,MessagePacket * messageRetour);
	/*!
	 *  \brief Gestion des messages a  destination d'un groupe de joueurs
	 *  \param messageNetwork:
	 *  	Forme du fichier en entree: String id_community: identifiant de la liste de joueurs, text: contenu du message
	 *
	 *  \return messageRetour
	 */
	int HandleChatCommunity(MessageNetwork * messageNetwork,MessagePacket * messageRetour);

	/*!
	 *  \brief Indicateur de spam de l'emetteur
	 *  \param messageNetwork
	 *  \return messageRetour
	 */
	bool SpamDetector(MessageNetwork * messageNetwork,MessagePacket * messageRetour);
	/*!
	 *  \brief Traitement de l'envoie d'un packet de chat en fonction de son type
	 *  \param messageNetwork, messageRetour, typeForChat
	 */
	void SendPacketChat(MessageNetwork * messageNetwork,MessagePacket * messageRetour, int typeForChat);
	/*!
	 *  \brief Gestion des packets de Chat
	 *  \param messageNetwork
	 */
	void ProcessPacket(MessageNetwork * messageNetwork);

	private:
	Log * log;
	Configuration * config ;
	NetworkManager * networkManager;
};


} /* namespace Kingdom */

#endif /* SRC_SERVER_KINGDOM_CHAT_CHAT_H_ */
