#include "route.h"
#include "debug.h"

Route::Route(struct Route_Node *src)
{
    this->src = src;
}

void Route::dbg_info()
{
    struct Route_Node *ptr;
    int i;

    ptr = this->src;
    i = 0;

    while(ptr) {
        dbg("Node: %d\n", i++);
        ptr->coor.dbg_info();
        ptr = ptr->next;
    }

    ptr = NULL;
}
