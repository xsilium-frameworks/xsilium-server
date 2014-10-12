/*
 * \file Serveur.h
 *
 *  Created on: \date 8 mars 2014
 *      Author: \author joda
 *  \brief :
 */

#ifndef SERVEUR_H_
#define SERVEUR_H_

#include "Databases/LoginDatabase.h"

/*
 *
 */
class Serveur {
public:
	Serveur(uint32_t IDServeur);
	virtual ~Serveur();

	bool ChargementServeur();

	void setAddress(std::string address);
	std::string getAddress();

	void setPort(uint32_t port);
	uint32_t getPort();

	void setName(std::string name);
	std::string getName();

	uint32_t getID();

	void setSecurity(uint8_t SecurityLevel);
	uint8_t getSecurity();

	void setNBJoueur(uint32_t NBJoueur);
	uint32_t getNBJoueur();

	void setVersion(std::string version);
	std::string getVersion();

	void setOnline(bool online);
	bool isOnline();

private:
    std::string address;
    uint32_t port;
    std::string name;
    uint32_t m_ID;
    uint8_t allowedSecurityLevel;
    uint32_t NBJoueur;
    std::string version;
    bool online;

    LoginDatabase * realms ;
};

#endif /* SERVEUR_H_ */
