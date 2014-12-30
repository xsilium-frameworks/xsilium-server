/*
 * \file GestionnaireCompte.h
 *
 *  Created on: \date 27 juil. 2013
 *      Author: \author joda
 *  \brief :
 */

#ifndef GESTIONNAIRECOMPTE_H_
#define GESTIONNAIRECOMPTE_H_


#include "Compte/Compte.h"
#include "Logging/Log.h"


/*
 *
 */
class GestionnaireCompte : public Singleton<GestionnaireCompte>
{
	friend class Singleton<GestionnaireCompte>;
public:
	GestionnaireCompte();
	virtual ~GestionnaireCompte();
	/*!
	 *  \brief creerSession
	 *
	 *  Permet  la creation d'une session et de la stocker dans la pile
	 *
	 *  \param
	 */

	bool creerCompte(const char * nomCompte);

	/*!
	 *  \brief supprimerSession
	 *
	 * supprime la session de la pile
	 *
	 *  \param
	 */

	void supprimerCompte(const char * nomCompte);

	/*!
	 *  \brief trouverSession
	 *
	 *  Trouve une session dans la pile
	 *
	 *  \param
	 */

	Compte * trouverCompte(const char * nomCompte);

private:
    std::vector<Compte *> listOfCompte ;
    std::vector<Compte *>::iterator compte ;

    Log * log;

	boost::mutex mutexCompte;

};

#endif /* GESTIONNAIRECOMPTE_H_ */
