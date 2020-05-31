#include "route.h"
#include "debug.h"
#include <iostream>
using std::cout;
using std::endl;

Route::Route(struct Route_Node *src)
{
    this->src = src;
}

void Route::dbg_prt()
{
    struct Route_Node *ptr;
    int i;

    ptr = this->src;
    i = 0;

    while(ptr) {
        cout << "Node: " << i << endl;
        ptr->coor.dbg_prt();
        cout << endl << endl;
    }

    ptr = NULL;
}
