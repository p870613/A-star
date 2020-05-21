#ifndef _TYPES_H_
#define _TYPES_H_

// Blocks
/* These structs are used to save the status of the blocks
 */
typedef enum Block_Type block_t;
enum Block_Type {
    BK_Err,
    BK_Empty,
    Bk_Koz,
    Bk_Path,
};

struct Block {
    int x;
    int y;
    int z;
    block_t type;
};

struct Empty {
    struct Block bk;
};

struct Koz
{
    struct Block bk;
};

struct Path
{
    struct Block bk;
    double g; // From source
    double h; // To destination
    double f; // Current cost
    struct Path *last;
};

// list
/*
 * Used to save the heap of tail of each path
 */

struct Node {
    struct Path *cont;
    struct Node *next;
}

#endif
