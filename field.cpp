#include <cstdlib>
#include "field.h"
#include "debug.h"
#include "config.h"

Field_3D::Field_3D(int *arr)
{
    this->x_sz = X_MAX;
    this->y_sz = Y_MAX;
    this->z_sz = Z_MAX;
    this->init_zone(arr);
}

bool Field_3D::accessable(Coordinate pst)
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

Block **Field_3D::offset(Coordinate pst)
{
    if (!this->accessable(pst))
        return NULL;

    return this->zone
            + pst.x * this->y_sz * this->z_sz
            + pst.y * this->z_sz
            + pst.z;
}

gen_zone(int *arr)
{
    int range;
    range = x_sz * y_sz * z_sz;
    this->zone = new Block*[range];
    for (int i=0; i<range; i++) {
        Block *cur_blk;
        if (arr[i] == 1) {
            cur_blk = new Koz()
        } else {

        }
    }
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
