#ifndef _DEBUG_H_
#define _DEBUG_H_

#include <stdio.h>

// The flag can be customize outside
#ifndef _DBG_
    #define _DBG_ 1
#endif

#if _DBG_
    #define dbg(fmt, ...) printf (fmt, ##__VA_ARGS__)
    #define dbgln(fmt, ...) printf (fmt "\n", ##__VA_ARGS__)
    #define dbg_full(fmt, ...) printf ("%s: %s(%d)" fmt, __FILE__, __FUNCTION__, __LINE__, ##__VA_ARGS__)
#else
    #define dbg(fmt, ...)
    #define dbgln(fmt, ...)
    #define dbg_full(fmt, ...)
#endif

#endif
