#ifndef _RESULT_H_
#define _RESULT_H_

#include "route.h"

class Result
{
    public:
        virtual Route *get();
}

class Fail : public Result
{
    public:
        Route *get(); // TODO: debug print Fail then return NULL
}

class Reached : public Result
{
    private:
        Route route;
    public:
        Route *get(); // TODO: debug print the route then return it
}

#endif
