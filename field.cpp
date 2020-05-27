#include <cstdlib.h>
#include "field.h"
#include "debug.h"

using namespace Field_3D;

Field_3D(int *arr)
{
    // gen_env
}

bool accessable(struct Coordinate pst)
{

    if (pst.x >= x_sz ||
        pst.y >= y_sz ||
        pst.z >= z_sz ||
        pst.x < 0     ||
        pst.y < 0     ||
        pst.z < 0) {
        dbg("Access over size, x: %d, y: %d, z: %d\n", pst.x, pst.y, pst.z);
        return false;
    }
    return true;
}

Block **offset(struct Coordinate pst)
{
    if (!this->accessable(pst))
        return NULL;

    return this->zone
            + pst.x * this->y_sz * this->z_sz
            + pst.y * this->z_sz
            + pst.z;
}

Block *get_position(struct Coordinate pst)
{
    return *(this->offset(pst));
}

bool set_position(Block *blk, struct Coordinate pst)
{
    Block **ptr;

    ptr = this->offset(pst);
    if (ptr) {
        *(ptr) = blk;
        return true;
    }
    return true;
}
