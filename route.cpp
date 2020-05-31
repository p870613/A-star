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
        ptr->coor.dbg_info();
        dbg("\n");
        ptr = ptr->next;
    }

    ptr = NULL;
}
