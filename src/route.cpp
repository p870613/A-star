#include "route.h"
#define _DBG_ 1
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
        i++;
        ptr->coor.dbg_info();
        dbg("\n");
        ptr = ptr->next;
    }
    dbg("Total %d steps\n", i);
    ptr = NULL;
}
