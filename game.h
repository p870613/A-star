#ifndef _GAME_H_
#define _GAME_H_

#include "config.h"
#include "block.h"

struct Stk_Node
{
    Path *edge;
    struct Stk_Node *next;
};

class Stack
{
    private:
        struct Stk_Node *top;
    public:
        Stack();
        void insert(Block *edge);
        Path *pop();
        bool is_empty();
}

class Game
{
    private:
        Block *kiz[X_MAX][Y_MAX][Z_MAX];
        Stack edges;
        struct Coordinate src;
        struct Coordinate des;
    public:
        Game(Block **, struct Coordinate, struct Coordinate);
        Result set();
        void next_step();
}

#endif
