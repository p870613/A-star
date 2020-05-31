#include <cstdlib>
#include <iostream>
#include "game.h"
#include "debug.h"
using std::cout;
using std::endl;

int main(void)
{
    Game *game;
    Result *ret;

    Field_3D *kiz;
    Coordinate *src;
    Coordinate *des;

    dbg("debug mode\n");
    cout << "KIZ" << endl;
    kiz = new Field_3D();

    cout << "src" << endl;
    src = new Coordinate(1, 2, 1);

    cout << "des" << endl;
    des = new Coordinate(1, 1, 1);

    cout << "Game" << endl;
    game = new Game (kiz, src, des);

    // do A*
    cout << "A*" << endl;
    while (!(ret = game->set())) {
        game->next_step();
    }
    cout << "Finished" << endl;

    return ret->get() != NULL;
}
