/*
 * TicketManager.h
 *
 *  Created on: 27 juin 2015
 *      Author: Skronak
 */

#ifndef SRC_SERVER_KINGDOM_TICKET_TICKETMANAGER_H_
#define SRC_SERVER_KINGDOM_TICKET_TICKETMANAGER_H_

#include <Network/NetworkManager.h>
#include <Configuration/Configuration.h>
#include <Ticket/Ticket.h>

namespace Kingdom {

enum typeForTicket
{
	ID_CREATE = 0,
	ID_SHOW,
	ID_EDIT,
	ID_DELETE,
	ID_ERREUR
};

enum erreurOfTicket
{
	ID_NOERROR = 0,
	ID_ERROR_PACKET_SIZE,
	ID_ERROR_DB
};


class TicketManager: public NetworkListener {
public:
	/*!
	 *  \brief Constructeur
	 *
	 *  Constructeur de la classe TicketManager
	 *	Et se connecte a la DB
	 *  \param
	 */
	TicketManager(NetworkManager * networkManager);
	/*!
	 *  \brief Constructeur
	 *
	 *  Destructeur de la classe TicketManager
	 *  Et se deconnecte de la DB
	 *  \param
	 */
	virtual ~TicketManager();

	void run();

	void processPacket(MessageNetwork * messageNetwork);

	/*!
	 *  \brief Methode de gestion pour creer un ticket
	 *  \param messageNetwork
	 *  \param messageNetwork
	 *	MessagePacket.propery:
	 *  	title: Intitulé du ticket
	 *  	text: Contenu du ticket
	 *  	coord: coordonée de l'emetteur
	 *  	idReporter: identité de la personne envoyant le ticket
	 *  	category: Categorie du ticket
	 *  	subCategory: sous categorie du ticket
	 *  \return messageRetour
	 */
	int  handleTicketCreate(MessageNetwork * messageNetwork,MessagePacket * messageRetour);
	/*!
	 *  \brief Methode de gestion pour editer un ticket	 *  \param messageNetwork
	 *  \param messageNetwork
	 *	MessagePacket.propery:
	 *  	idTicket: numéro de ticket
	 *		idReponsible: identité de la personne traitant le ticket
	 *  	title: Intitulé du ticket
	 *  	text: Contenu du ticket
	 *  	category: Categorie du ticket
	 *  	subCategory: sous categorie du ticket
	 *  	coord: coordonée de l'emetteur
	 *  \return messageRetour
	 */
	int  handleTicketEdit(MessageNetwork * messageNetwork,MessagePacket * messageRetour);
	/*!
	 *  \brief Methode de gestion pour supprimer un ticket	 *  \param messageNetwork
	 *  \param messageNetwork
	 *	MessagePacket.propery:
	 *  	idTicket: numéro de ticket
	 *  \return messageRetour
	 */
	int  handleTicketSuppr(MessageNetwork * messageNetwork,MessagePacket * messageRetour);
	/*!
	 *  \brief Methode de gestion pour visualiser un ticket
	 *  \param messageNetwork
	 *	MessagePacket.propery:
	 *  	idTicket: numéro de ticket
	 *		idReponsible: identité de la personne traitant le ticket
	 *		idReporter: identité de la personne envoyant le ticket
	 *  	title: Intitulé du ticket
	 *  	text: Contenu du ticket
	 *  	coord: coordonée de l'emetteur
	 *  	category: Categorie du ticket
	 *  	subCategory: sous categorie du ticket
	 *  	coord: coordonée de l'emetteur
	 *  \return messageRetour
	 */
	int  handleTicketRead(MessageNetwork * messageNetwork,MessagePacket * messageRetour);

	/*!
	 *  \brief Methode de creation d'un ticket en bdd
	 *  \param messageNetwork
	 *  \return messageRetour
	 */
	void TicketManager::createTicket(MessageNetwork * messageNetwork, MessagePacket * messageRetour);


private:
	Log * log;
	Configuration * config ;
	NetworkManager * networkManager;
};

} /* namespace Kingdom */

#endif /* SRC_SERVER_KINGDOM_TICKET_TICKETMANAGER_H_ */
