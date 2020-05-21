#ifndef _DEBUG_H_
#define _DEBUG_H_

#include <stdio.h>

#ifndef DEBUG
#define DEBUG 1
#endif

#if DEBUG
#define debug(fmt, ...) printf(fmt, ##__VA_ARGS__)
#else
#define debug(fmt, ...)
#endif

#endif
