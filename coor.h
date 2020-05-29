#ifndef _FUND_H_
#define _FUND_H_

#define ADJ_SZ 26
class Coordinate
{
    private:
        int x;
        int y;
        int z;
    public:
        Coordinate(int, int, int);
        get_adjs();
};
// TODO overide equal


#endif
