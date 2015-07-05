/*
 * \file Ticket.cpp
 *
 *  Created on: \date 27 june. 2015
 *      Author: \author Skronak
 *  \brief :
 */
#include "Ticket.h"

namespace Kingdom {

Ticket::Ticket() {

	idTicket = 0;
	suffix = "Ticket";
	std::string defaultStatus = "OPEN";

	database->prepareStatement(suffix + database->ToString(KINGDOM_DEL_TICKET),"DELETE FROM Ticket where idTicket = $1");
	database->prepareStatement(suffix + database->ToString(KINGDOM_SEL_TICKET),"SELECT idTicket, idReporter, idResponsible, text, title, category, subCategory, coord, status FROM Ticket where idTicket = $1");
	database->prepareStatement(suffix + database->ToString(KINGDOM_INS_TICKET),"INSERT INTO Ticket VALUES (DEFAULT, $1, $2, $3, $4, $5, $6, $7, "+defaultStatus+")");
	database->prepareStatement(suffix + database->ToString(KINGDOM_UPD_TICKET),"UPDATE Ticket SET status = $8, idResponsible= $3 WHERE idTicket = $1");
}

Ticket::~Ticket() {
	// TODO Auto-generated destructor stub
}

bool Ticket::create(int idTransaction)
{
	bool retour;
	Tokens tokens;
	retour = database->executionPrepareStatement(suffix + database->ToString(KINGDOM_INS_TICKET),&tokens,idTransaction,9,database->ToString(idTicket).c_str(),database->ToString(idReporter).c_str(), text.c_str(), title.c_str(), category.c_str(), subCategory.c_str(), coord.c_str(),defaultStatus.c_str());
	read();
	return retour;
}

//bool Ticket::read(int idTransaction)
//{
//	bool retour;
//	Tokens resultsqlT ;
//
//	retour = database->executionPrepareStatement(suffix + database->ToString(KINGDOM_SEL_TICKET),&resultsqlT,idTransaction,9,ticket_ticket.c_str());
//
//	if(resultsqlT.empty())
//	{
//		retour = false ;
//	}
//	else
//	{
//		Tokens resultatsql;
//		resultatsql = database->strSplit( resultsqlT[0] ,";");
//		idTicket = database->ToInt(resultatsql[0]);
//		retour = true ;
//	}
//	return retour ;
//}
//bool Ticket::update(int idTransaction)
//{
//	Tokens resultsqlT ;
//	return database->executionPrepareStatement(suffix + database->ToString(KINGDOM_UPD_TICKET),&resultsqlT,idTransaction,2,database->ToString(Ticket_temp_nessais).c_str(),database->ToString(id_Ticket).c_str() );
//}
//
//bool Ticket::suppr(int idTransaction)
//{
//	Tokens resultsqlT ;
//	return database->executionPrepareStatement(suffix + database->ToString(KINGDOM_DEL_TICKET),&resultsqlT,idTransaction,1,database->ToString(id_Ticket).c_str());
//
//}

int Ticket::getIdTicket() {
	return idTicket;
}

void Ticket::setIdTicket(int idTicket) {
	idTicket = idTicket;
}

int Ticket::getIdReporter() {
	return idReporter;
}

void Ticket::setIdReporter(int idTicket) {
	idReporter = idReporter;
}

int Ticket::getIdResponsible() {
	return idResponsible;
}

void Ticket::setIdResponsible(int idResponsible) {
	idResponsible = idResponsible;
}

std::string& Ticket::getTitle() {
	return title;
}

void Ticket::setTitle(std::string& title) {
	this->title = title;
}

std::string& Ticket::getText() {
	return text;
}

void Ticket::setText(std::string& text) {
	this->text = text;
}

std::string& Ticket::getStatus() {
	return status;
}

void Ticket::setStatus(std::string& status) {
	this->status = status;
}

std::string& Ticket::getCategory() {
	return category;
}

void Ticket::setCategory(std::string& category) {
	this->category = category;
}

std::string& Ticket::getSubCategory() {
	return subCategory;
}

void Ticket::setSubCategory(std::string& subCategory) {
	this->subCategory = subCategory;
}
///TODO get/set coord
}
