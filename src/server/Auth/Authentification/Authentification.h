/*
 * Authentification.h
 *
 *  Created on: 7 févr. 2012
 *      Author: joda2
 */
#ifndef AUTHENTIFICATION_H_
#define AUTHENTIFICATION_H_

#include <stdlib.h> // For atoi
#include <cstring> // For strlen
#include <stdio.h>



class Authentification {
public:
	Authentification();
	virtual ~Authentification();

    bool _HandleLogonChallenge( unsigned char *data);
    bool _HandleLogonProof();
    bool _HandleReconnectChallenge();
    bool _HandleReconnectProof();
    bool _HandleRealmList();

private:

};

#endif /* AUTHENTIFICATION_H_ */
