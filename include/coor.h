#ifndef _FUND_H_
#define _FUND_H_

#include "config.h"
#define ADJ_SZ 26

class Coordinate
{
    private:
        int x;
        int y;
        int z;
    public:
        Coordinate();
        Coordinate(int, int, int);
        bool operator>(Coordinate);
        int offset(int, int);
        Coordinate *get_adjs();
        dist_t euc_dis(Coordinate);
        void dbg_info();
};

#endif
