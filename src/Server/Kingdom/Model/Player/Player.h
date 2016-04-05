/*
 * Player.h
 *
 *  Created on: 25 mars 2016
 *      Author: joda
 */

#ifndef SRC_SERVER_KINGDOM_MODEL_PLAYER_PLAYER_H_
#define SRC_SERVER_KINGDOM_MODEL_PLAYER_PLAYER_H_

#include <string>

namespace Kingdom {

class Player {
public:
    Player();
    virtual ~Player();

private:
    int id;
    std::string name;
};

} /* namespace Kingdom */

#endif /* SRC_SERVER_KINGDOM_MODEL_PLAYER_PLAYER_H_ */
