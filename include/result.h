#ifndef _RESULT_H_
#define _RESULT_H_

#include "route.h"

class Result
{
    public:
        Result();
        virtual Route *get();
};

class Koz_fail : public Result
{
    public:
        Koz_fail();
        Route *get(); // TODO: debug print Fail then return NULL
};

class Reached : public Result
{
    private:
        Route *route;
    public:
        Reached(Route *);
        Route *get(); // TODO: debug print the route then return it
};

class Unreach : public Result
{
    public:
        Unreach();
        Route *get();
};
#endif
