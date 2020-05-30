#include <cstdlib>
#include "field.h"
#include "debug.h"
#include "config.h"
#include "gen_env.h"
#include "block.h"
Field_3D::Field_3D()
{
    this->x_sz = X_MAX;
    this->y_sz = Y_MAX;
    this->z_sz = Z_MAX;
    this->zone = gen_env();
}

bool Field_3D::accessable(Coordinate pst)
{
    Coordinate max(this->x_sz, this->y_sz, this->z_sz);
    Coordinate min(0, 0, 0);

    if (min > pst || pst > max) {
        dbg("Access over size\n");
        return false;
    }
    return true;
}

Block **Field_3D::offset(Coordinate pst)
{
    if (!this->accessable(pst))
        return NULL;

    return this->zone + pst.offset(this->y_sz, this->z_sz);
}

Block *Field_3D::get_position(Coordinate pst)
{
    return *(this->offset(pst));
}

bool Field_3D::set_position(Block *blk, Coordinate pst)
{
    Block **ptr;

    ptr = this->offset(pst);
    if (ptr) {
        *(ptr) = blk;
        return true;
    }
    return true;
}

void Field_3D::update(Block *blk)
{
    const Coordinate pos = blk->get_coor();
    this -> set_position(blk, pos);
    delete blk;
    blk = NULL;
}
