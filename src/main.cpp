#include <cstdio>
#include <cstdlib>
#include "game.h"
#define _DBG_ 1
#include "debug.h"

int main(void)
{
    dbg("Debug mode\n");

    Field_3D *kiz;
    Coordinate *src;
    Coordinate *des;
    Game *game;
    Result *ret;
    int i;

    dbg("Init env\n");
    kiz = new Field_3D(); // KOZ init in gen_env
    src = new Coordinate(0, 0, 0);
    des = new Coordinate(4, 4, 0);
    game = new Game (kiz, src, des);

    dbg("A star\n");
    i = 0;
    while (!(ret = game->set())) {
        dbg("Turn %d\n", i++);
        game->next_step(); // Pop next edge and try adjacent blocks
#if _DBG_
        //game->dbg_visual_2D(1);
#endif
        //getchar();
    }
    dbg("\nTotal %d turns\n", i);

    return ret->get() == NULL;
}
