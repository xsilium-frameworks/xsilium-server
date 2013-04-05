/*
 * \file GestionnaireSession.h
 *
 *  Created on: \date 12 janv. 2013
 *      Author: \author joda
 *  \brief :
 */

#ifndef GESTIONNAIRESESSION_H_
#define GESTIONNAIRESESSION_H_

#include <stdio.h>
#include <vector>

#include "Connexion/Connexion.h"
#include "Session/Session.h"

#include "Singleton/Singleton.h"

/*
 *
 */
class GestionnaireSession : public Singleton<GestionnaireSession>
{
	friend class Singleton<GestionnaireSession>;
public:
	GestionnaireSession();
	virtual ~GestionnaireSession();

    /*!
     *  \brief creerSession
     *
     *  Permet  la creation d'une session et de la stocker dans la pile
     *
     *  \param
     */

	void creerSession();

    /*!
     *  \brief supprimerSession
     *
     * supprime la session de la pile
     *
     *  \param
     */

	void supprimerSession();

    /*!
     *  \brief trouverSession
     *
     *  Trouve une session dans la pile
     *
     *  \param
     */

	Session * trouverSession(ENetAddress address);

	void setConnexion(Connexion * connexion);
private:

    std::vector<Session *> listOfSession ;
    std::vector<Session *>::iterator session ;


    Connexion * connexion;

	boost::mutex mutexSession;

};

#endif /* GESTIONNAIRESESSION_H_ */
