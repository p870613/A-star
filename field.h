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
        bool accessable(Coordinate);
        int offset(Coordinate);
        void init_zone(int *);
    public:
        Field_3D(int *);
        Block *get_position(Coordinate);
        bool set_position(Block *, Coordinate);
};

#endif
