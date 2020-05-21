#ifndef _DEBUG_H_
#define _DEBUG_H_

#include <stdio.h>

#ifndef DEBUG
#define DEBUG 1
#endif

#if DEBUG
#define debug(fmt, ...) printf(fmt, ##__VA_ARGS__)
#define dbg_prt_block(bk) _dbg_prt_block(bk)
#else
#define debug(fmt, ...)
#define dbg_prt_block(bk)
#endif

#endif
