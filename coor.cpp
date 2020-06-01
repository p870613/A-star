#include <cmath>
#include "coor.h"
#define _DBG_ 1
#include "debug.h"

Coordinate::Coordinate()
{
    this->x = -1;
    this->y = -1;
    this->z = -1;
}

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

Coordinate *Coordinate::get_adjs()
{
    Coordinate *ret;
    int x_off[ADJ_SZ] = {1, -1,
                         0,  0,
                         0,  0};

    int y_off[ADJ_SZ] = {0,  0,
                         1, -1,
                         0,  0};

    int z_off[ADJ_SZ] = {0,  0,
                         0,  0,
                         1, -1};

    ret = new Coordinate[ADJ_SZ];

    for (int i=0; i<ADJ_SZ; i++) {
        ret[i] = Coordinate(this->x + x_off[i], this->y + y_off[i], this->z + z_off[i]);
        //dbg("====\n");
        //ret[i].dbg_info();
    }
    return ret;
}

dist_t Coordinate::euc_dis(Coordinate des)
{
    dist_t cost_x = (this -> x) - (des.x);
    dist_t cost_y = (this -> y) - (des.y);
    dist_t cost_z = (this -> z) - (des.z);
    return dist_t(sqrt(cost_x * cost_x + cost_y * cost_y + cost_z * cost_z));
}

void Coordinate::dbg_info()
{
    dbg("x: %d, ", this->x);
    dbg("y: %d, ", this->y);
    dbg("z: %d, ", this->z);
}

void Coordinate::mapping(double const x, double const y, double const z)
{
    this -> x = int((x - 9.95) * 100);
    this -> y = int(- (y + 3) * 100);
    this -> z = int((z - 3.9) * 100);
}

bool Coordinate::is_range_in(Coordinate* min, Coordinate * max)
{
    for(int i = 0; i < KOZ_NUM; i++)
    {
         if((this->x >= min[i].x && this->x <= max[i].x) && (this->y >= min[i].y && this->y <= max[i].y) && (this->z >= min[i].z && this->z <= max[i].z))
        return true;

    }
       return false;
}
