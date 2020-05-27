#include "game.h"

int main(void)
{
    Game game;
    Result ret;
  
    game = new Game (gen_kiz(), gen_src(), gen_dst());

    // do A*
    while (!(ret = game.set())) {
        game.next_step();
    }

    return ret.get() != NULL;
}
