#ifndef _GAME_H_
#define _GAME_H_

#include "config.h"
#include "block.h"
#include "field.h"

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
        void insert(Path *);
        Path *pop();
        bool is_empty();
        void dbg_info();
};

class Game
{
    private:
        Field_3D *kiz;
        Stack edges;
        struct Coordinate *src;
        struct Coordinate *des;
        void dbg_info();

    public:
        Game(Field_3D *, Coordinate *, Coordinate *); // kiz src des
        Result *set();
        void next_step();
        void dbg_stk_info();
};

#endif
