#include <cstdio>
#include <cstdlib>
#include "game.h"
#include "config.h"
#define _DBG_ 1
#include "debug.h"
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



int main(void)
{
    dbg("Debug mode\n");
    Game *game;
    Result *ret;
    //koz cooridnate set
    static Coordinate koz_min[KOZ_NUM];
    static Coordinate koz_max[KOZ_NUM];
    for(int i = 0; i < KOZ_NUM; i++)
    {
        koz_min[i].mapping(min[i][0], min[i][1], min[i][2]);
        koz_max[i].mapping(max[i][0], max[i][2], max[i][3]);
    }
 
    Field_3D *kiz;
    Coordinate *src;
    Coordinate *des;

 
    int i;

    //dbg("KIZ\n");
    kiz = new Field_3D(koz_min, koz_max);

    //dbg("SRC\n");
    src = new Coordinate(100, 75, 95);

    //dbg("DES\n");
    des = new Coordinate(155, 270, 60);

    //dbg("Game\n");
    game = new Game (kiz, src, des);

    // do A*
    dbg("A star\n");
    i = 0;
    while (!(ret = game->set())) {
        dbg("Step %d\n", i++);
        game->next_step();
        //dbg("\nCkeckout Stack\n");
        //game->dbg_stk_info();
        //dbg("+++++++++++++\n");
        //game->dbg_visual_2D(1);
        //getchar();
    }
    dbg("Finish\n");

    dbg("Total %d steps\n", i);

    return ret->get() == NULL;
}
