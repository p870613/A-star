#include <cstdlib>
#include "debug.h"
#include "block.h"

Block::Block(const Coordinate posi)
{
    this->coor = posi;
}

Coordinate Block::get_coor()
{
    return this -> coor;
}

Empty::Empty(const Coordinate posi) : Block(posi){}

Koz::Koz(const Coordinate posi) : Block(posi){}

Path::Path(const Coordinate posi, Path *prev, dist_t g, dist_t h) : Block(posi)
{
    this->prev = prev;
    this->g = g;
    this->h = h;
}

bool Path::operator>(Path cmper)
{
    if (this->g + this->h > cmper.g + cmper.h) {
        return true;
    }
    return false;
}

dist_t Path::get_g()
{
    return this->g;
}

Coordinate *Path::get_adjs()
{
    Coordinate *ret;

    ret = this->coor.get_adjs();

    return ret;
}

Result *Block::is_reached()
{
    return NULL;
}

Result *Empty::is_reached()
{
    return NULL;
}

Result *Koz::is_reached()
{
    Koz_fail *ret;
    ret = new Koz_fail();
    return ret;
}

Result *Path::is_reached()
{
    Route *route;
    Result *ret;

    route = new Route (this->trace_back(NULL));
    ret = new Reached(route);
    return ret;
}

struct Route_Node *Path::trace_back(struct Route_Node *prev)
{
    struct Route_Node *cur;
    cur = new struct Route_Node;
    cur->coor = this->coor;
    cur->next = prev;
    if (this->prev) {
        return this->prev->trace_back(cur);
    }
    return cur;
}

Path *Block::update(Path* prev, Coordinate* des)
{
    return NULL;
}

Path *Empty::update(Path* prev, Coordinate* des)
{
    const int g = prev -> get_g() + 1;
    const int h = des -> euc_dis(this -> get_coor());

    Path *new_path = new Path(this->get_coor(), prev, g, h);

    return new_path;
}

Path *Koz::update(Path* prev, Coordinate* des)
{
    return NULL;
}

Path *Path::update(Path* prev, Coordinate* des)
{
    Path *ret;

    ret = NULL;
    if((this -> g) > (prev -> g + 1))
    {
        ret = new Path(this->coor, prev, prev->g + 1, this->h);
    }

    return ret;
}

void Block::dbg_info()
{
    dbg("== Block ==\n");
    dbg("Position:\n");
    this->coor.dbg_info();
    dbg("============\n");
}

void Empty::dbg_info()
{
    dbg("== Empty ==\n");
    dbg("Position:\n");
    this->coor.dbg_info();
    dbg("============\n");
}

void Koz::dbg_info()
{
    dbg("== Koz ==\n");
    dbg("Position:\n");
    this->coor.dbg_info();
    dbg("============\n");
}


void Path::dbg_info()
{
    dbg("== Path ==\n");
    dbg("Position:\n");
    this->coor.dbg_info();
    dbg("G: %lf\n", this->g);
    dbg("H: %lf\n", this->h);
    dbg("============\n");
}
