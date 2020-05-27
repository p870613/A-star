#include "game.h"

Stack::Stack()
{
    self.top = NULL;
}

Result *Game::set()
{
    Block *des;
    des = this->kiz.get_position(this->des);
    enum B_TY type;

    type = des.type();
    switch (type) {
        case B_BLOCK:
        case B_KOZ:
            return new Fail (type);

        case B_EMPTY:
            return NULL;

        case B_PATH:
            return new Reached(this->kiz);
    }
    return new Fail(-1);
}
