#include <stdio.h>
#define DEBUG 0
#include "debug.h"

int main(void)
{
    debug("debug %d\n", 1);
    debug("debug %s\n", "hello world");
    return 0;
}
