/*
 * StructureMail.h
 *
 *  Created on: 1 mai 2013
 *      Author: kiti
 *      Structure des mails
 */

#ifndef STRUCTUREMAIL_H_
#define STRUCTUREMAIL_H_

typedef struct MAILPACKET_C
{
	structure_opcodeT structure_opcode;
    uint8_t           typeMail;
    char	perso_out[64];		// source
    char	perso_in[64];		// destinataire
    char	objet_mail[64];		// objet du message
    //matrice d'objets ?
    int		item_mail[5];		// Item envoyé via mail !! déclaration id-items/stackable?
    char		corps_mail[1024];	// corps message
    bool	contre_remb;		//Activation flag remboursement !! Déclaration boolen ?
    int		val_remb;		// Somme necessaire reccuperations items.
} sMailPacket_C;



#endif /* STRUCTUREMAIL_H_ */
