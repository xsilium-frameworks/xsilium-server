/*
 * PersoDatabase.cpp
 *
 *  Created on: 25 avril. 2013
 *      Author: nico
 */
//Normalisation nom requete : {nom base}_{type requete}_{tableimpactee}_{resume requete}

#include "PersoDatabase.h"
// #include "SHA1.h"
#include <stdlib.h>
#include <sstream>


PersoDatabase::PersoDatabase() {

}

PersoDatabase::~PersoDatabase() {
}

void PersoDatabase::connexionDB(std::string infoString)
{
	connexionDatabase::connexionDB(infoString);

	connexionDatabase::suffix = "Perso";

   //requete qui crée une rubrique
	connexionDatabase::PrepareStatement(ROYAUME_INS_TICKETRUBRIQUE_CREERUBRIQUE, "Insert into ticket_rubrique values (DEFAULT, $1, DEFAULT)");
   //requete qui supprime une rubrique
	connexionDatabase::PrepareStatement(ROYAUME_UPD_TICKETRUBRIQUE_SUPPRRUBRIQUE, "Update ticket_rubrique set \"ticket_rubrique_suppr\" = true where \"id_ticket_rubrique\" = $1");
   //requete qui reactive une rubrique supprimée
	connexionDatabase::PrepareStatement(ROYAUME_UPD_TICKETRUBRIQUE_REACTRUBRIQUE, "Update ticket_rubrique set \"ticket_rubrique_suppr\" = false where \"id_ticket_rubrique\" = $1");
   //requete qui modifie le nom d'une rubrique
	connexionDatabase::PrepareStatement(ROYAUME_UPD_TICKETRUBRIQUE_MODNOM, "Update ticket_rubrique set \"ticket_rubrique_nom\" = $1 where \"id_ticket_rubrique\" = $2");
   //requete qui crée une sous rubrique 1
	connexionDatabase::PrepareStatement(ROYAUME_INS_TICKETSOUSRUBRIQUE1_CREESOUSRUBRIQUE1, "Insert into ticket_sous_rubrique1 values (DEFAULT, $1, $2, DEFAULT)");
   //requete qui supprime une sous rubrique 1
	connexionDatabase::PrepareStatement(ROYAUME_UPD_TICKETSOUSRUBRIQUE1_SUPPRSOUSRUBRIQUE1, "Update ticket_sous_rubrique1 set \"ticket_sous_rubrique1_suppr\" = true where \"id_ticket_sous_rubrique1\" = $1");
   //requete qui reactive une sous rubrique 1 supprimée
	connexionDatabase::PrepareStatement(ROYAUME_UPD_TICKETSOUSRUBRIQUE1_REACTSOUSRUBRIQUE1, "Update ticket_sous_rubrique1 set \"ticket_sous_rubrique1_suppr\" = false where \"id_ticket_sous_rubrique1\" = $1");
   //requete qui modifie le nom d'une sous rubrique 1
	connexionDatabase::PrepareStatement(ROYAUME_UPD_TICKETSOUSRUBRIQUE1_MODNOM, "Update ticket_sous_rubrique1 set \"ticket_sous_rubrique1_nom\" = $1 where \"id_ticket_sous_rubrique1\" = $2");
   //requete qui change la rubrique de reference d'une sous_rubrique 1
	connexionDatabase::PrepareStatement(ROYAUME_UPD_TICKETSOUSRUBRIQUE1_MODRUBRIQUE, "Update ticket_sous_rubrique1 set \"ticket_sous_rubrique1_id_ticket_rubrique\" = $1 where \"id_ticket_sous_rubrique1\" = $2");
   //requete qui crée une sous rubrique 2
	connexionDatabase::PrepareStatement(ROYAUME_INS_TICKETSOUSRUBRIQUE2_CREESOUSRUBRIQUE2, "Insert into ticket_sous_rubrique2 values (DEFAULT, $1, $2, DEFAULT)");
   //requete qui supprime une sous rubrique 2
	connexionDatabase::PrepareStatement(ROYAUME_UPD_TICKETSOUSRUBRIQUE2_SUPPRSOUSRUBRIQUE2, "Update ticket_sous_rubrique2 set \"ticket_sous_rubrique2_suppr\" = true where \"id_ticket_sous_rubrique2\" = $1");
   //requete qui reactive une sous rubrique 2 supprimée
	connexionDatabase::PrepareStatement(ROYAUME_UPD_TICKETSOUSRUBRIQUE2_REACTSOUSRUBRIQUE2, "Update ticket_sous_rubrique2 set \"ticket_sous_rubrique2_suppr\" = false where \"id_ticket_sous_rubrique2\" = $1");
   //requete qui modifie le nom d'une sous rubrique 2
	connexionDatabase::PrepareStatement(ROYAUME_UPD_TICKETSOUSRUBRIQUE2_MODNOM, "Update ticket_sous_rubrique2 set \"ticket_sous_rubrique2_nom\" = $1 where \"id_ticket_sous_rubrique2\" = $2");
   //requete qui change la sous rubrique 1 de reference d'une sous_rubrique 2
	connexionDatabase::PrepareStatement(ROYAUME_UPD_TICKETSOUSRUBRIQUE2_MODSOUSRUBRIQUE1, "Update ticket_sous_rubrique2 set \"ticket_sous_rubrique2_id_ticket_sous_rubrique1\" = $1 where \"id_ticket_sous_rubrique2\" = $2");
   //requete qui crée un nouvel etat
	connexionDatabase::PrepareStatement(ROYAUME_INS_TICKETTYPEETAT_CREEETAT, "Insert into ticket_type_etat values (DEFAULT, $1, DEFAULT)");
   //requete qui supprime un etat
	connexionDatabase::PrepareStatement(ROYAUME_UPD_TICKETTYPEETAT_SUPPRETAT, "Update ticket_type_etat set \"ticket_type_etat_suppr\" = true where \"id_ticket_type_etat\" = $1");
   //requete qui reactive un etat supprimé
	connexionDatabase::PrepareStatement(ROYAUME_UPD_TICKETTYPEETAT_REACTETAT, "Update ticket_type_etat set \"ticket_type_etat_suppr\" = false where \"id_ticket_type_etat\" = $1");
   //requete qui modifie le libellé d'un etat
	connexionDatabase::PrepareStatement(ROYAUME_UPD_TICKETTYPEETAT_MODNOM, "Update ticket_type_etat set \"ticket_type_etat_etat\" = $1 where \"id_ticket_type_etat\" = $2");
   //requete qui crée un nouveau ticket
	connexionDatabase::PrepareStatement(ROYAUME_INS_TICKET_CREETICKET, "Insert into ticket (\"id_ticket\",\"ticket_id_ticket_rubrique\",\"ticket_id_ticket_sousrubrique1\",\"ticket_id_ticket_sous_rubrique2\",\"ticket_id_expediteur\",\"ticket_dateheure_sousmission\",\"ticket_sujet\",\"ticket_description\",\"ticket_pj\") values (DEFAULT, $1, $2, $3, $4, now(), $5, $6, $7)");
   //requete pour recuperer la liste des tickets sans tri (renvoie id du ticket, id de l'expediteur, et sujet), ne liste que les tickets
	connexionDatabase::PrepareStatement(ROYAUME_SEL_TICKET_LISTETICKETS, "Select \"id_ticket\", \"ticket_id_expediteur\", \"ticket_sujet\" FROM ticket");
	//requete pour recuperer la liste des tickets venant d'une personne en particulie (renvoie id du ticket, sujet et date soumission)
	connexionDatabase::PrepareStatement(ROYAUME_SEL_TICKET_LISTETICKETSEXPEDITEUR, "Select \"id_ticket\",\"ticket_sujet\", \"ticket_dateheure_soumission\" FROM ticket where \"ticket_id_expediteur\" = $1");
   //requete qui donne tous les détails d'un ticket choisi
	connexionDatabase::PrepareStatement(ROYAUME_SEL_TICKET_DETAILSTICKET, "Select * from ticket where \"id_ticket\" = $1");
   //requete qui renvoie la liste des tickets d'une certaine rubrique (renvoie id du ticket, id de l'expediteur, et sujet)
	connexionDatabase::PrepareStatement(ROYAUME_SEL_TICKET_LISTETICKETSRUBRIQUE, "Select \"id_ticket\", \"ticket_id_expediteur\", \"ticket_sujet\" FROM ticket where \"ticket_id_ticket_rubrique\" = $1 ");
   //requete qui renvoie la liste des tickets d'une sous rubrique 1 (renvoie id du ticket, id de l'expediteur, et sujet)
	connexionDatabase::PrepareStatement(ROYAUME_SEL_TICKET_LISTETICKETSSOUSRUBRIQUE1, "Select \"id_ticket\", \"ticket_id_expediteur\", \"ticket_sujet\" FROM ticket where \"ticket_id_ticket_sous_rubrique1\" = $1 ");
   //requete qui renvoie la liste des tickets d'une sous rubrique 2 (renvoie id du ticket, id de l'expediteur, et sujet)
	connexionDatabase::PrepareStatement(ROYAUME_SEL_TICKET_LISTETICKETSSOUSRUBRIQUE2, "Select \"id_ticket\", \"ticket_id_expediteur\", \"ticket_sujet\" FROM ticket where \"ticket_id_ticket_sous_rubrique2\" = $1 ");
   //requete qui met à jour un ticket
	connexionDatabase::PrepareStatement(ROYAUME_UPD_TICKET_MAJTICKET, "Update ticket set \"ticket_sujet\"=$1, \"ticket_description\"=$2, \"ticket_pj\"=$3, \"ticket_solution\"=$4, \"ticket_id_joueur_derniere_maj\"=$5, \"ticket_dateheure_derniere_maj\"=now()where \"id_ticket\" = $6");
   //requete qui deplace un ticket dans une autre rubrique et/ou sous_rubrique
	connexionDatabase::PrepareStatement(ROYAUME_UPD_TICKET_DEPLACETICKET, "Update ticket set \"ticket_id_ticket_rubrique\" = $1, \"ticket_id_ticket_sous_rubrique1\" = $2, \"ticket_id_ticket_sous_rubrique2\" = $3 where \"id_ticket\" = $4");
   //requete qui supprime totalement et physiquement un ticket (attention cela supprime de la base)
	connexionDatabase::PrepareStatement(ROYAUME_DEL_TICKET_SUPPRTICKET, "Delete from ticket where \"id_ticket\" = $1");
   //requete qui liste toutes les rubriques non supprimées (renvoie id et nom)
	connexionDatabase::PrepareStatement(ROYAUME_SEL_TICKETRUBRIQUE_LISTERUBRIQUESACTIF, "Select \"id_ticket_rubrique\", \"ticket_rubrique_nom\" from ticket_rubrique where \"ticket_rubrique_suppr\" = 'false' ");
	//requete qui liste toutes les rubriques supprimées (renvoie id et nom)
	connexionDatabase::PrepareStatement(ROYAUME_SEL_TICKETRUBRIQUE_LISTERUBRIQUESSUPPR, "Select \"id_ticket_rubrique\", \"ticket_rubrique_nom\" from ticket_rubrique where \"ticket_rubrique_suppr\" = 'true' ");
	//requete qui liste toutes les sous rubrique 1 non supprimées d'une rubrique selectionnée (renvoie id et nom)
	connexionDatabase::PrepareStatement(ROYAUME_SEL_TICKETSOUSRUBRIQUE1_LISTESOUSRUBRIQUE1ACTIF, "Select \"id_ticket_sous_rubrique1\", \"ticket_sous_rubrique1_nom\" from ticket_sous_rubrique1 where \"ticket_sous_rubrique1_suppr\" = 'false' and \"ticket_sous_rubrique1_id_ticket_rubrique\" = $1 ");
	//requete qui liste toutes les sous rubrique 1 supprimées d'une rubrique selectionnée (renvoie id et nom)
	connexionDatabase::PrepareStatement(ROYAUME_SEL_TICKETSOUSRUBRIQUE1_LISTESOUSRUBRIQUE1SUPPR, "Select \"id_ticket_sous_rubrique1\", \"ticket_sous_rubrique1_nom\" from ticket_sous_rubrique1 where \"ticket_sous_rubrique1_suppr\" = 'true' and \"ticket_sous_rubrique1_id_ticket_rubrique\" = $1 ");
	//requete qui liste toutes les sous rubrique 2 non supprimées d'une sous rubrique 1 selectionnée (renvoie id et nom)
	connexionDatabase::PrepareStatement(ROYAUME_SEL_TICKETSOUSRUBRIQUE2_LISTESOUSRUBRIQUE2ACTIF, "Select \"id_ticket_sous_rubrique2\", \"ticket_sous_rubrique2_nom\" from ticket_sous_rubrique2 where \"ticket_sous_rubrique2_suppr\" = 'false' and \"ticket_sous_rubrique2_id_ticket_sous_rubrique1\" = $1 ");
	//requete qui liste toutes les sous rubrique 2 supprimées d'une sous rubrique 1 selectionnée (renvoie id et nom)
	connexionDatabase::PrepareStatement(ROYAUME_SEL_TICKETSOUSRUBRIQUE2_LISTESOUSRUBRIQUE2SUPPR, "Select \"id_ticket_sous_rubrique2\", \"ticket_sous_rubrique2_nom\" from ticket_sous_rubrique2 where \"ticket_sous_rubrique2_suppr\" = 'true' and \"ticket_sous_rubrique2_id_ticket_sous_rubrique1\" = $1 ");

}


