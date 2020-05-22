#ifndef _GAME_H_
#define _GAME_H_

#include "config.h"
#include "block.h"

class Game
{
    private:
        Block *kiz[X_MAX][Y_MAX][Z_MAX];
    public:
        Game(Block **, struct Coordinate, struct Coordinate);
        Result set();
        void next_step();
}

#endif
