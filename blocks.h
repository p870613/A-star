#ifndef _TYPES_H_
#define _TYPES_H_

#include "result.h"

class Block
{
    private:
        struct Coordinate coor;
        Block *prev;
        virtual struct Route_Node *trace_back(); // For create route(coordinate only) after A*
        /*
         * Block will be a linked list from destination to source
         *
         * Trace_back() is used to create a new list named route whitch only contant coordinate
         * u
         * and the list will start from source to destination
         *
         * This Route will be saved in Result
         */

    public:
        virtual inline void dbg_prt();
        virtual inline void dbg_prt_list();
        virtual Block(struct Coordinate);
        virtual Result *is_reached();
        /*
         * TODO:
         * Empty: return NULL
         * Koz: return Fail
         * path: return Reached, and will have a Route as contant
         */
};

class Empty : public Block
{
    private:
    public:
}

class Koz : public Bloack
{
    private:
    public:
}

class path : public Block
{
    private:
    public:
}

#endif
