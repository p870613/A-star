#ifndef _FUND_H_
#define _FUND_H_

#define ADJ_SZ 6
#include "config.h"
class Coordinate
{
    private:
        int x;
        int y;
        int z;
    public:
        Coordinate(int, int, int);
        Coordinate(){};
        Coordinate *get_adjs();
        bool operator>(Coordinate);
        int offset(int, int);
        dist_t euc_dis(Coordinate);
};
// TODO overide equal


#endif
