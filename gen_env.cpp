// x: 9.95 -> 11.95 => 200
// y: -3 -> -9.75 => 700
// z: 3.9 -> 5.9 => 200
//-> 3 * 10 x y z
// float mapping to int
// x' = (x - 9.95) * 100; -> inverse x = x' / 100 + 9.95
// y' = -( (y + 3) * 100 ); -> inverse y = -(y' / 100 - 3)
// z' = ( z - 3.9 ) * 100 ;  -> inverse  z = z' / 100 + 3.9

/*
#include <iostream>
using std::cout;
using std::endl;
*/
#include "gen_env.h"
#include "block.h"
#include "config.h"
#define _DBG_ 0
#include "debug.h"
#include "coor.h"

/*
bool is_koz(int x, int y, int z)
{
    for(int i = 0; i < 9; i++)
        if((x >= min[i][0] && x <= max[i][0]) ||  (y >= min[i][1] && y <= max[i][1]) || (z >= min[i][2] && z <= max[i][2]))
            return true;
    return false;
}
*/
Block **gen_env(Coordinate *min, Coordinate *max)
{

    dbg("Gen env\n");

    /*kiz init*/
    dbg("Init nodes\n");
    int offset = 0;
    Block **kiz = new Block *[X_MAX * Y_MAX * Z_MAX];
    for(int i = 0; i < X_MAX; i++)
    {
        for(int j = 0; j < Y_MAX; j++)
        {
            for(int k = 0; k < Z_MAX; k++, offset++)
            {
                Coordinate cur(i, j, k);
                if(! cur.is_range_in(min, max))
                {
                    Empty *empty = new Empty(cur);
                    *(kiz + offset)  = empty;
                }
                else
                {
                    Koz *koz = new Koz(cur);
                    *(kiz + offset) = koz;
                }
            }
        }
    }
    return kiz;
}
