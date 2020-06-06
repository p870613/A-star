#include <cstdio>
#include <cstdlib>
#include "game.h"
#define _DBG_ 0
#include "debug.h"

int main(void)
{
    dbg("Debug mode\n");

    Field_3D *kiz;
    Coordinate *p[2][3];
    Coordinate *origin;
    Coordinate *src;
    Coordinate *des;
    Game *game;
    Result *ret;
    int i;

    /*
    Coordinate of QR codes
    11.5, -5.7, 4.5
    11, -6, 5.55
    11, -5.5, 4.33
    10.30, -7.5, 4.7
    11.5, -8, 5
    11, -7.7, 5.55
    */
    origin = new Coordinate(10.95, -3.75, 4.85);
    p[0][0] = new Coordinate(11.5, -5.7, 4.5);
    p[0][1] = new Coordinate(11.0, -6.0, 5.55);
    p[0][2] = new Coordinate(11.0, -5.5, 4.33);
    p[1][0] = new Coordinate(10.30, -7.5, 4.7);
    p[1][1] = new Coordinate(11.5, -8.0, 5.0);
    p[1][2] = new Coordinate(11.0, -7.7, 5.55);

    dbg("Init env\n");
    kiz = new Field_3D(); // KOZ init in gen_env
    src = p[0][2];
    des = p[1][0];
    game = new Game (kiz, src, des);
    game->dbg_info ();
    dbg("A star\n");
    i = 0;
    while (!(ret = game->set ())) {
        dbg("Turn %d\n", i++);
        game->next_step (); // Pop next edge and try adjacent blocks
#if _DBG_ == 2
        game->dbg_visual_2D (0);
#endif
        //getchar();
    }
    dbg("\nTotal %d turns\n", i);

    return ret->get () == NULL;
}
