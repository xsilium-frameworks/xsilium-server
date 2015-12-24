/*
 * Realm.cpp
 *
 *  Created on: 24 déc. 2015
 *      Author: joda
 */

#include "Realm.h"

namespace Auth {

Realm::Realm(std::string nameRealm) {

    idRoyaume = 0;
    keyRoyaume = "";
    nameRoyaume = nameRealm;
    urlRoyaume = "";
    portRoyaume = 0;
    autorisationRoyaume = 0;
    versionClientRoyaume = 0;
    online_royaume = false;

}

Realm::~Realm() {
    // TODO Auto-generated destructor stub
}

int Realm::getAutorisationRoyaume()  {
    return autorisationRoyaume;
}

void Realm::setAutorisationRoyaume(int autorisationRoyaume) {
    this->autorisationRoyaume = autorisationRoyaume;
}

int Realm::getIdRoyaume()  {
    return idRoyaume;
}

void Realm::setIdRoyaume(int idRoyaume) {
    this->idRoyaume = idRoyaume;
}

 std::string Realm::getKeyRoyaume()  {
    return keyRoyaume;
}

void Realm::setKeyRoyaume( std::string keyRoyaume) {
    this->keyRoyaume = keyRoyaume;
}

 std::string Realm::getNameRoyaume()  {
    return nameRoyaume;
}

void Realm::setNameRoyaume( std::string nameRoyaume) {
    this->nameRoyaume = nameRoyaume;
}

bool Realm::isOnlineRoyaume()  {
    return online_royaume;
}

void Realm::setOnlineRoyaume(bool onlineRoyaume) {
    online_royaume = onlineRoyaume;
}

int Realm::getPortRoyaume()  {
    return portRoyaume;
}

void Realm::setPortRoyaume(int portRoyaume) {
    this->portRoyaume = portRoyaume;
}

 std::string Realm::getUrlRoyaume()  {
    return urlRoyaume;
}

void Realm::setUrlRoyaume( std::string urlRoyaume) {
    this->urlRoyaume = urlRoyaume;
}

int Realm::getVersionClientRoyaume()  {
    return versionClientRoyaume;
}

void Realm::setVersionClientRoyaume(int versionClientRoyaume) {
    this->versionClientRoyaume = versionClientRoyaume;
}

} /* namespace Auth */
