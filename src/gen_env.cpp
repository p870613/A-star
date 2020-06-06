// x: 9.95 -> 11.95 => 200
// y: -3 -> -9.75 => 700
// z: 3.9 -> 5.9 => 200
//-> 3 * 10 x y z // float mapping to int
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


static int min_index[9][3];
static int max_index[9][3];

static double min[9][3] = {{10.75, -4.9, 4.8},
                     {10.75, -6.5, 3.9},
                     {9.95, -7.2, 3.9},
                     {10.10, -8.6, 5.4},
                     {11.45, -9.0, 4.1},
                     {9.95, -9.1, 4.6},
                     {10.95, -8.4, 4.9},
                     {11.05, -8.9, 4.2},
                     {10.45, -9.1, 4.6}};

static double max[9][3] = {{10.95, -4.7, 5.0},
                     {11.95, -6.4, 5.9},
                     {10.85, -7.1, 5.9},
                     {11.1, -8.3, 5.9},
                     {11.95, -8.5, 5.1},
                     {10.45, -8.6, 5.6},
                     {11.15, -8.2, 5.1},
                     {11.25, -8.7, 4.4},
                     {10.65, -8.9, 4.8}};

static int data[X_MAX][Y_MAX][Z_MAX];

bool is_koz(int x, int y, int z)
{
    for(int i = 0; i < 9; i++)
        if((x >= min[i][0] && x <= max[i][0]) &&  (y >= min[i][1] && y <= max[i][1]) && (z >= min[i][2] && z <= max[i][2]))
            return true;
    return false;
}

Block **gen_env()
{

    dbg("Gen env\n");
    for(int i = 0; i < 9; i++)
    {
        min_index[i][0] = int((min[i][0] - 9.95) * 100);
        min_index[i][1] = int(((min[i][1] + 9.75) * 100));
        min_index[i][2] = int((min[i][2] - 3.9) * 100);
        max_index[i][0] = int((max[i][0] - 9.95) * 100);
        max_index[i][1] = int(((max[i][1] + 9.75) * 100));
        max_index[i][2] = int((max[i][2] - 3.9) * 100);
        dbg("%d %d %d\n", min_index[i][0],min_index[i][1],min_index[i][2]);
        dbg("%d %d %d\n\n", max_index[i][0],max_index[i][1],max_index[i][2]);
    }

   //data init
    dbg("Gen date\n");
    for(int i = 0; i < X_MAX; i++)
        for(int j = 0; j < Y_MAX; j ++)
            for(int k = 0; k < Z_MAX; k++)
                data[i][j][k] = 0;
    dbg("Gen date\n");
    for(int index = 0; index < 9; index++)
    {
        for(int i = min_index[index][0]; i < max_index[index][0]; i++)
            for(int j = min_index[index][1]; j < max_index[index][1]; j++)
                for(int k = min_index[index][2]; k < max_index[index][2]; k++) {
                    dbg("%d %d %d\n", i, j, k);
                    data[i][j][k] = 1;
                }
    }

    /*
    // manual set
    for (int i=4; i<10; i++)
        data[i][2][0] = 1;

    for (int i=0; i<8; i++)
        data[i][5][0] = 1;

    for (int i=0; i<9; i++)
        data[i][8][0] = 1;
    data[1][3][0] = 1;
    data[2][3][0] = 1;
    data[0][1][0] = 1;
    data[1][1][0] = 1;
    */
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
                if(data[i][j][k] == 0)
                {
                    Empty *empty = new Empty(cur);
                    *(kiz + offset)  = empty;
                }
                else
                {
                    dbg("Gen Koz %d %d %d\n", i, j ,k);
                    //cur.dbg_info();
                    Koz *koz = new Koz(cur);
                    *(kiz + offset) = koz;
                }
            }
        }
    }
    return kiz;
}
