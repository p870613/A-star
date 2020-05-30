#ifndef _TYPES_H_
#define _TYPES_H_

#include "result.h"
#include "coor.h"
#include "config.h"
class Path;
class Empty;
class Koz;
class Block
{
    protected:
        Coordinate coor;

    public:
        Block(Coordinate);
        Coordinate get_coor();
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
        virtual Path* update(Path* , Coordinate* );

};

class Empty : public Block
{
    private:
    public:
        Empty(Coordinate);
        Result *is_reached();
        inline void dbg_prt();
        Path* update(Path* ,Coordinate* );
};

class Koz : public Block
{
    private:
    public:
        Koz(Coordinate);
        Result *is_reached();
        inline void dbg_prt();
        inline void dbg_prt_list();
        Path* update(Path* , Coordinate* );
};

class Path : public Block
{
    private:
        Block *prev;
        dist_t g; // from source
        dist_t h; // to destination
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
        Path(Coordinate, Path*, dist_t, dist_t);
        Result *is_reached();
        dist_t get_g();
        inline void dbg_prt();
        inline void dbg_prt_list();
        Path* update(Path*, Coordinate* );

};

#endif
