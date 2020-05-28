#include <cstdlib>
#include "game.h"

Stack::Stack()
{
    this->top = NULL;
}

void Stack::insert(Block *edge)
{
    struct Stk_Node **ptr;
    prt = &(this->top);
    while (*ptr && ) { // TODO operator override

    }
}

Game::Game(Field_3D *kiz, Coordinate *src, Coordinate *des)
{
    Path *src_p;

    src_p = new Path(*src);
    this->kiz = kiz;
    this->src = src;
    this->des = des;
    kiz->set_position(src_p, *src);
    this->edges->push(src_p);
}

Result *Game::set()
{
    Block *des;
    enum B_TY type;
    Result *ret;

    des = this->kiz->get_position (this->des);

    type = des.get_type ();
    switch (type) {
        case B_BLOCK:
        case B_KOZ:
            return new Fail (type);

        case B_EMPTY:
            return NULL;

        case B_PATH:
            ret = Reached (des); // Track back and make linked list
            delete this->kiz;
            return ret;
    }

    return new Fail (-1);
}

Result *Game::set()
{
    Block *des;
    des = this->kiz->get_position(this->des);
    enum B_TY type;

    type = des.type();
    switch (type) {
        case B_BLOCK:
        case B_KOZ:
            return new Fail (type);

        case B_EMPTY:
            return NULL;

        case B_PATH:
            return new Reached(this->kiz);
    }
    return new Fail(-1);
}
