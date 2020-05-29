#include "block.h"
Coordinate Block::get_coor()
{
    return this -> coor;
}

Path* Empty::update(Path* prev, Coordinate* des)
{
    int g = prev -> g + 1;
    int h =  des -> euc_dis(this -> get_coor());
    Path *new_path = new Path(this->get_coor(), prev, g, h);
    return new_path;
}

Path* Koz::update(Path* prev, Coordinate* des)
{
    return NULL;
}
//issue '>' or '>='
//compare two path and then return cost less
Path* Path::update(Path* prev, Coordinate* des)
{
    if((this -> g) > (prev -> g + 1))
    {
        this -> prev = prev;
        this -> g = prev -> g + 1;
    }
    return this 
}


