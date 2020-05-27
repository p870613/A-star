#ifndef _ROUTE_H_
#define _ROUTE_H_

#include "fund.h"

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
        inline void dbg_prt();
        Route(struct Route_Node *);
};

#endif
