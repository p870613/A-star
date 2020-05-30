#include "block.h"
Coordinate Block::get_coor()
{
    return this -> coor;
}

Block* Empty::update(Block* prev, Coordinate* des)
{
    int g = prev -> g + 1;
    int h =  des -> euc_dis(this -> get_coor());
    Path *new_path = new Path(this->get_coor(), prev, g, h);
    return new_path;
}

Block* Koz::update(Block* prev, Coordinate* des)
{
    return NULL;
}
//issue '>' or '>='
//compare two path and then return cost less
Block* Path::update(Block* prev, Coordinate* des)
{
    if((this -> g) > (prev -> g + 1))
    {
        this -> prev = prev;
        this -> g = prev -> g + 1;
    }
    return this 
}

/*
Block::Block(Coordinate posi)
{
    this->coor = posi;
}
*/

Empty::Empty(Coordinate posi) : Block(posi);

Koz::Koz(Coordinate posi) : Block(posi);


Path::Path(Coordinate posi, Block *prev, dist_t g, dist_t h) : Block(posi)
{
}
