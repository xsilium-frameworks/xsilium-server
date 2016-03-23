/*
 * AuthentificationService.h
 *
 *  Created on: 11 juil. 2015
 *      Author: Skronak
 */

#ifndef SRC_SERVER_AUTHENTIFICATION_AUTHENTIFICATION_SERVICE_AUTHENTIFICATIONSERVICE_H_
#define SRC_SERVER_AUTHENTIFICATION_AUTHENTIFICATION_SERVICE_AUTHENTIFICATIONSERVICE_H_

#include <Service/Service.h>
#include <Manager/Network/NetworkManager.h>
#include <Manager/Authentification/AuthentificationManager.h>
#include <Manager/Realm/RealmManager.h>

namespace Auth {

class AuthentificationService: public Service {

    /*!
     * \enum typeForAuth
     * Enumeration des OPcodes
     */
    enum typeForAuth {
        ID_CHALLENGE = 0, //!< ID_CHALLENGE
        ID_REPONSE,      //!< ID_REPONSE
        ID_REALMSLIST,
        ID_SEND_CANCEL,  //!< ID_SEND_CANCEL
        ID_ERROR        //!< ID_ERREUR
    };

    enum erreurOfAuth {
        ID_CONNECTION_BANNED = Service::ID_OTHER_ERROR,
        ID_INVALID_ACCOUNT_OR_PASSWORD,
        ID_COMPTE_BANNIE,
        ID_INVALID_IP,
        ID_ERROR_ETAPE
    };

    enum stepOfAuth {
        STEP_CHALLENGE = 0, STEP_REPONSE, STEP_REAMSLIST

    };

public:

    /*!
     *  \brief Constructeur de la classe Authentification et se connecte a la DB
     *  \param networkManager
     */
    AuthentificationService(NetworkManager * networkManager);
    virtual ~AuthentificationService();

    /*!
     * methode de lancement du thread
     */
    void run();

    void processPacket(MessageNetwork * messageNetwork);
    /*!
     *  \brief _HandleLogonChallenge
     *
     *  Verifie la l'existence du client ainsi que son statut
     *  banni ou non et genere le defi
     *  \param
     */
    void handleLogonChallenge(MessageNetwork * messageNetwork, MessageNetwork * messageRetour);
    void handleLogonProof(MessageNetwork * messageNetwork, MessageNetwork * messageRetour);
    void handleRealmsList(MessageNetwork * messageNetwork, MessageNetwork * messageRetour);

    /*!
     * Alimentation des erreurs d'un packets
     * @param messageRetour
     * @param typeForAuth : type d'erreur
     */
    void sendErrorPacket(MessageNetwork * messageNetwork, MessageNetwork * messageRetour,
            int typeErreur);

private:

    AuthentificationManager * authentificationManager;
    RealmManager * realmManager;
    NetworkManager * networkManager;
};

} /* namespace Auth */

#endif /* SRC_SERVER_AUTHENTIFICATION_AUTHENTIFICATION_SERVICE_AUTHENTIFICATIONSERVICE_H_ */
