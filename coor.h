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
        Coordinate();
        Coordinate(int, int, int);
        bool operator>(Coordinate);
        int offset(int, int);
        Coordinate *get_adjs();
        dist_t euc_dis(Coordinate);
        void dbg_prt();
};

#endif
