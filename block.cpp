#include "block.h"

Block::Block(Coordinate posi)
{
    this->coor = posi;
}

Coordinate get_coor()
{
    return this->coor;
}

Empty::Empty(Coordinate posi) : Block(posi);

Koz::Koz(Coordinate posi) : Block(posi);

Path::Path(Coordinate posi, Block *prev, dist_t g, dist_t h) : Block(posi)
{
}
