/*
 * \file Compte.cpp
 *
 *  Created on: \date 29 déc. 2014
 *      Author: \author joda
 *  \brief :
 */
#include "Compte.h"

Compte::Compte(std::string nomString) {
    id_account = 0;
    joindate = 0;
    locked = false;
    last_login = 0;
    online = false;
    locale = 0;
    compteBan = 0;

    setUsername(nomString);

}

Compte::~Compte() {
    if (compteBan)
        delete compteBan;
}

std::string& Compte::getEmail() {
    return email;
}

void Compte::setEmail(std::string& email) {
    this->email = email;
    updateData = true;
}

int Compte::getIdAccount() {
    return id_account;
}

void Compte::setIdAccount(int idAccount) {
    id_account = idAccount;
    updateData = true;
}

time_t Compte::getJoindate() {
    return joindate;
}

void Compte::setJoindate(time_t joindate) {
    this->joindate = joindate;
    updateData = true;
}

std::string& Compte::getLastIp() {
    return last_ip;
}

void Compte::setLastIp(std::string& lastIp) {
    last_ip = lastIp;
    updateData = true;
}

time_t Compte::getLastLogin() {
    return last_login;
}

void Compte::setLastLogin(time_t lastLogin) {
    last_login = lastLogin;
    updateData = true;
}

int Compte::getLocale() {
    return locale;
}

void Compte::setLocale(int locale) {
    this->locale = locale;
    updateData = true;
}

bool Compte::isLocked() {
    return locked;
}

void Compte::setLocked(bool locked) {
    this->locked = locked;
    updateData = true;
}

std::string& Compte::getShaPassHash() {
    return sha_pass_hash;
}

void Compte::setShaPassHash(std::string& shaPassHash) {
    sha_pass_hash = shaPassHash;
    updateData = true;
}

std::string& Compte::getUsername() {
    return username;
}

void Compte::setUsername(std::string& username) {
    this->username = username;
    updateData = true;
}

void Compte::setCompteBan(CompteBan * compteBan) {
    this->compteBan = compteBan;
    updateData = true;
}
CompteBan * Compte::getCompteBan() {
    return compteBan;
}
