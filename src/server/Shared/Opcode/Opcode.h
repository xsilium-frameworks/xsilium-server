/*
 * AuthCodes.h
 *
 *  Created on: 24 f�vr. 2012
 *      Author: joda2
 */

#ifndef AUTHCODES_H_
#define AUTHCODES_H_

    /*!
     *  \brief Opcode
     *
     *  Declaration des Opcode pour chaque cas d'une connexion
     *  \param
     */

enum Opcode
{
	// partie generique
	ID_CONNEXION = 0,
	ID_DECONEXION,

	// partie authentification
	ID_AUTH,

    //partie royaume
    ID_CHAT,

    //partie ticket
    ID_TICKET,

    //Partie message
    ID_MAIL,

    //Partie Perso
    ID_PERSO,

    ID_ALL
};

enum typerequete
{
   XSILIUM_AUTH = 0,
   XSILIUM_KINGDOM,
   XSILIUM_ZONE,
   XSILIUM_ALL
};

#endif /* AUTHCODES_H_ */
