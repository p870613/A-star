#include "coor.h"
#include <cmath>
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
// issue y_sz z_sz is in config.h
int Coordinate::offset(int y_sz, int z_sz)
{
    return this->x * y_sz * z_sz
    + this->y * z_sz
    + this->z;
}

// calulate coordinate to coordinate distance
// issue int ?? float??
int Coordinate::euc_dis(Coordinate des)
{
    int cost_x = (this -> x) - (des -> x);
    int cost_y = (this -> y) - (des -> y);
    int cost_z = (this -> z) - (des -> z);
    return int(sqrt(cost_x * cost_x + cost_y * cost_y + cost_z * cost_z));
}
