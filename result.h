#ifndef _RESULT_H_
#define _RESULT_H_

#include "route.h"

class Result
{
    public:
        Result();
        virtual Route *get();
};

class Fail : public Result
{
    public:
        Fail(int);
        Route *get(); // TODO: debug print Fail then return NULL
};

class Reached : public Result
{
    private:
        Route *route;
    public:
        Reached();
        Route *get(); // TODO: debug print the route then return it
};

#endif
