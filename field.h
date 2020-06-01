#ifndef _FIELD_H_
#define _FIELD_H_

#include "block.h"
#include "coor.h"
class Field_3D
{
    private:
        Block **zone;
        int x_sz;
        int y_sz;
        int z_sz;
        bool accessable(Coordinate);
        Block **offset(Coordinate);
    public:
        Field_3D(Coordinate*, Coordinate*);
        Block *get_position(Coordinate);
        bool set_position(Block *, Coordinate);
        void update(Block *);
};

#endif
