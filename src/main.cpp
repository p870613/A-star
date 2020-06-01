#include <cstdio>
#include <cstdlib>
#include "game.h"
#include "debug.h"

int main(void)
{
    dbg("Debug mode\n");
    Game *game;
    Result *ret;

    Field_3D *kiz;
    Coordinate *src;
    Coordinate *des;
    int i;

    kiz = new Field_3D();
    src = new Coordinate(100, 75, 95);
    des = new Coordinate(155, 270, 60);
    game = new Game (kiz, src, des);

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

    dbg("\nTotal %d steps\n", i);

    return ret->get() == NULL;
}
