#ifndef _FIELD_H_
#define _FIELD_H_

#include "block.h"

class Field_3D
{
    private:
        Block **zone;
        int x_sz;
        int y_sz;
        int z_sz;
        bool accessable(struct Coordinate);
        Block **offset(struct Coordinate);
    public:
        Field_3D(int *);
        Block *get_position(struct Coordinate);
        bool set_position(Block *, struct Coordinate);
};

#endif
