/*
 * Ticket.h
 *
 *  Created on: 27 juin 2015
 *      Author: Skronak
 */

#ifndef SRC_SERVER_KINGDOM_TICKET_TICKET_H_
#define SRC_SERVER_KINGDOM_TICKET_TICKET_H_

#include <Databases/CRUD.h>

enum TicketDatabaseStatements {
	KINGDOM_SEL_TICKET,
	KINGDOM_INS_TICKET,
	KINGDOM_DEL_TICKET,
	KINGDOM_UPD_TICKET
};

class Ticket : public CRUD {
public:
	Ticket();

	virtual ~Ticket();
	/// Mehode de creation d'un ticket
	bool create(int idTransaction = 0);
	/// Mehode de récupération d'un ticket
	bool read(int idTransaction = 0);
	/// Mehode de mise à jour d'un ticket
	bool update(int idTransaction = 0);
	/// Mehode de suppression d'un ticket
	bool suppr(int idTransaction = 0);

	int getIdTicket();
	void setIdTicket(int idTicket);
	int getIdReporter() const;
	void setIdReporter(int idReporter);
	int getIdResponsible();
	void setIdResponsible(int idResponsible);
	std::string& Ticket::getTitle();
	void Ticket::setTitle(std::string& title);
	std::string& Ticket::getText();
	void Ticket::setText(std::string& text);
	std::string& Ticket::getStatus();
	void Ticket::setStatus(std::string& status);
	std::string& Ticket::getCategory();
	void Ticket::setCategory(std::string& category);
	std::string& Ticket::getSubcategory();
	void Ticket::setSubCategory(std::string& subCategory);

private:
	/// identifiant du ticket
	int idTicket;
	/// identifiant de la personne ouvrant le ticket
	int idReporter;
	/// identifiant de la personne traitant le ticket
	int idResponsible;
	/// Titre du ticket
	std::string title;
	/// Contenu du ticket
	std::string text;
	/// Status: OPEN/ACCEPTED/REJECTED/PENDING.PROCESSING/CLOSED
	std::string status;
	/// Type de ticket: bug, report, support
	std::string category;
	/// sous catégorie, liste liée à la catégorie selectionnée
	std::string subCategory;
	/// coordonnee du reporter
	///? coord; TODO: coordonnee du reporter
};


#endif /* SRC_SERVER_KINGDOM_TICKET_TICKET_H_ */
