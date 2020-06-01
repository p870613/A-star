#include "debug.h"
#include "result.h"

Result::Result(){}

Koz_fail::Koz_fail(){}

Reached::Reached(Route *route)
{
    this->route = route;
}

Route *Result::get()
{
    dbg("No result\n");
    return NULL;
}

Route *Koz_fail::get()
{
    dbg("Destination is inside KOZ\n");
    return NULL;
}

Route *Reached::get()
{
    dbg("Got a path\n");
    this->route->dbg_info();
    return this->route;
}
