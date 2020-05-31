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

    dbg("KIZ\n");
    kiz = new Field_3D();

    dbg("SRC\n");
    src = new Coordinate(1, 2, 1);

    dbg("DES\n");
    des = new Coordinate(1, 1, 1);

    dbg("Game\n");
    game = new Game (kiz, src, des);

    // do A*
    dbg("A star\n");
    i = 0;
    while (!(ret = game->set())) {
        dbg("Step %d\n", i++);
        game->next_step();
    }
    dbg("Finish\n");

    return ret->get() != NULL;
}
