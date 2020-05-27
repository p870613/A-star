#include <cstdlib>
#include "game.h"

int main(void)
{
    Game *game;
    Result *ret;
    Field_3D *kiz;
    Coordinate *src;
    Coordinate *dst;

    src = new Coordinate(1, 1, 1);
    dst = new Coordinate(1, 1, 1);

    kiz = new Field_3D(NULL);
    game = new Game (kiz, src, dst);

    // do A*
    while (!(ret = game->set())) {
        game->next_step();
    }

    return ret->get() != NULL;
}
