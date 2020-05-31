#ifndef _ROUTE_H_
#define _ROUTE_H_

#include "coor.h"

struct Route_Node
{
    Coordinate coor;
    struct Route_Node *next;
};

class Route
{
    private:
        struct Route_Node *src;
    public:
        Route(struct Route_Node *);
        void dbg_prt();
};

#endif
