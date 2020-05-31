#include <cstdio>
#include <cstdlib>
#include "game.h"
#define _DBG_ 1
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

    //dbg("KIZ\n");
    kiz = new Field_3D();

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
