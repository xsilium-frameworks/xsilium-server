/*
 * readConfig.cpp
 *
 *  Created on: 29 mars 2012
 *      Author: mathieu
 */

#include "readConfig.h"

using namespace std;

readConfig::readConfig() {
	// TODO Auto-generated constructor stub

}

readConfig::~readConfig() {
	// TODO Auto-generated destructor stub
}

void readConfig::testRead(){

	ifstream file( "config.txt" );
    if ( !file )
    {
        cout << "Erreur d'ouverture\n";
        return;
    }

    string line;
    if ( ! ( file >> line ) )
    {
        cout << "Erreur de lecture\n";
        return;
    }
    cout << "Ligne lue : " << line;
}


void readConfig::readFile(){

}

