/*
 * Realm.h
 *
 *  Created on: 24 déc. 2015
 *      Author: joda
 */

#ifndef SRC_SERVER_AUTHENTIFICATION_MODEL_REALM_REALM_H_
#define SRC_SERVER_AUTHENTIFICATION_MODEL_REALM_REALM_H_

#include <Model/Model.h>
#include <string>

namespace Auth {

class Realm : public Model {
public:
    Realm(std::string nameRealm);
    virtual ~Realm();

    int getAutorisationRoyaume() ;
    void setAutorisationRoyaume(int autorisationRoyaume);
    int getIdRoyaume() ;
    void setIdRoyaume(int idRoyaume);
     std::string getKeyRoyaume() ;
    void setKeyRoyaume( std::string keyRoyaume);
     std::string getNameRoyaume() ;
    void setNameRoyaume( std::string nameRoyaume);
    bool isOnlineRoyaume() ;
    void setOnlineRoyaume(bool onlineRoyaume);
    int getPortRoyaume() ;
    void setPortRoyaume(int portRoyaume);
     std::string getUrlRoyaume() ;
    void setUrlRoyaume( std::string urlRoyaume);
    int getVersionClientRoyaume() ;
    void setVersionClientRoyaume(int versionClientRoyaume);

private:

    int idRoyaume;
    std::string keyRoyaume;
    std::string nameRoyaume;
    std::string urlRoyaume;
    int portRoyaume;
    int autorisationRoyaume;
    int versionClientRoyaume;
    bool online_royaume;
};

} /* namespace Auth */

#endif /* SRC_SERVER_AUTHENTIFICATION_MODEL_REALM_REALM_H_ */
