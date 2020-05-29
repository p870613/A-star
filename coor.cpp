#include "coor.h"

Coordinate::Coordinate(int x, int y, int z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

bool Coordinate::operator>(Coordinate cmper)
{
    if (this->x > cmper.x ||
        this->y > cmper.y ||
        this->z > cmper.z) {
        return true;
    }
    return false;
}

int Coordinate::offset(int y_sz, int z_sz)
{
    return this->x * y_sz * z_sz
    + this->y * z_sz
    + this->z;
}
