// x: 9.95 -> 11.95 => 200
// y: -3 -> -9.75 => 700  
// z: 3.9 -> 5.9 => 200
//-> 3 * 10 x y z
// float mapping to int
// x' = (x - 9.95) * 100; -> inverse x = x' / 100 + 9.95   
// y' = -( (y + 3) * 100 ); -> inverse y = -(y' / 100 - 3) 
// z' = ( z - 3.9 ) * 100 ;  -> inverse  z = z' / 100 + 3.9

#include "gen_evn.h"
#include "block.h"
#include "config.h"
Block ** generator_evnironment()
{
    int data[X_MAX][Y_MAX][Z_MAX];
    for(int i = 0; i < 9; i++)
    {
        min_index[i][0] = int((min[i][0] - 9.95) * 100);
        min_index[i][1] = int(- ((min[i][1] + 3) * 100));
        min_index[i][2] = int((min[i][2] - 3.9) * 100);
        max_index[i][0] = int((max[i][0] - 9.95) * 100);
        max_index[i][1] = int(- ((max[i][1] + 3) * 100));
        max_index[i][2] = int((max[i][2] - 3.9) * 100); 
    }
    
   /*data init*/
    for(int i = 0; i < X_SIZE; i++)
        for(int j = 0; j < Y_SIZE; j ++)
            for(int k = 0; k < Z_SIZE; k++)
                data[i][j][k] = 0;
                
    for(int index = 0; index < 9; index++)
    {
        for(int i = min_index[index][0]; i <= max_index[index][0]; i++)
            for(int j = min_index[index][1]; j <= max_index[index][1]; j++)
                for(int k = min_index[index][2]; k <= max_index[index][2]; k++)
                    data[i][j][k] = 1;
    }
    // source to path
    data[source.x][source.y][source.z] = 2;

    /*kiz init*/
    Block **kiz = new Block *[X_MAX * Y_MAX * Z_MAX];
    for(int i = 0; i < X_MAX; i++)
    {
        for(int j = 0; j < Y_MAX; j++)
        {
            for(int k = 0; k < Z_MAX; k++)
            {
                int offset = i * (Y_MAX * Z_MAX) + j * Z_MAX + k;
                if(data[i][j][k] == 0)
                {
                    Empty *empty = new Empty();
                    (kiz + offset)  = empty;
                }
                else if(data[i][j][k] == 1)
                {
                    Koz *koz = new Koz();
                    (kiz + offset) = koz;
                }
                else
                {
                     Path *path = new path();
                     (kiz + n) = path;
                }
                (kiz + offset) -> set_coordinate(i, j, k);
            }
        }
    }
    return kiz;
}
