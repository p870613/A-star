#ifndef _DEBUG_H_
#define _DEBUG_H_

#include <stdio.h>

// The flag be customize outside
#ifndef _DBG_
    #define _DBG_ 1
#endif

#if _DBG_
    #define dbg(fmt, ...) printf (fmt, ##__VA_ARGS__)
#else
    #define dbg(fmt, ...)
#endif

#endif
