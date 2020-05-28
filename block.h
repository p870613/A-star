#ifndef _TYPES_H_
#define _TYPES_H_

#include "result.h"

enum B_TY {
    B_BLOCK,
    B_EMPTY,
    B_KOZ,
    B_PATH
};

class Block
{
    private:
        Coordinate coor;
        enum B_TY type;

    public:
        Block(int, int, int, enum B_TY);
        virtual Result *is_reached();
        /*
         * TODO:
         * Empty: return NULL
         * Koz: return Fail
         * path: return Reached, and will have a Route as contant
         */
        virtual inline void dbg_prt();
        /*
         * TODO:
         * will be implement like #if DEBUG 1
         * ...
         * impl
         * ...
         * #endif
         */
        virtual inline void dbg_prt_list();
        enum B_TY get_type();
};

class Empty : public Block
{
    private:
    public:
        Empty(Coordinate);
        Result *is_reached();
        inline void dbg_prt();
        inline void dbg_prt_list();
};

class Koz : public Block
{
    private:
    public:
        Koz(Coordinate);
        Result *is_reached();
        inline void dbg_prt();
        inline void dbg_prt_list();
};

class Path : public Block
{
    private:
        Block *prev;
        /*
         * Path will be a linked list from destination to source
         *
         * Trace_back() is used to create a new list named route whitch only contant coordinate
         * u
         * and the list will start from source to destination
         *
         * This Route will be saved in Result
         */
        Route_Node *trace_back(); // For create route(coordinate only) after A*
    public:
        Path(Coordinate);
        Result *is_reached();
        inline void dbg_prt();
        inline void dbg_prt_list();
};

#endif
