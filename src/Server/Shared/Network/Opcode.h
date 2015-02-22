/*
 * \file Opcode.h
 *
 *  Created on: \date 18 déc. 2014
 *      Author: \author joda
 *  \brief :
 */
#ifndef SRC_SERVER_SHARED_NETWORK_OPCODE_H_
#define SRC_SERVER_SHARED_NETWORK_OPCODE_H_

enum Opcode

{

	// partie generique

	ID_CONNEXION = 0,

	ID_DECONEXION,

	// partie authentification

	ID_AUTH,
	ID_ROYAUME,
	ID_ZONE,

	//partie royaume

	ID_CHAT,

	//partie ticket

	ID_TICKET,

	//Partie message

	ID_MAIL,

	ID_ALL
};

#endif /* SRC_SERVER_SHARED_NETWORK_OPCODE_H_ */
