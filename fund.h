#ifndef _FUND_H_
#define _FUND_H_

struct Coordinate
{
    int x;
    int y;
    int z;
}

bool is_overlap(struct Coordinate *, struct Coordinate *);
#endif
