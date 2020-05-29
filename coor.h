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
        Coordinate *get_adjs();
        bool operator>(Coordinate);
        int offset(int, int);
};
// TODO overide equal


#endif
