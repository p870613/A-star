#include <stdbool.h>
#include <stdlib.h>
#include "types.h"
#include "debug.h"

static struct Node *stk_head = NULL;

bool insert_node(struct Path *edge)
{
    struct Node **ptr;
    struct Node *new;

    ptr = &stk_head;
    while (*ptr && (*ptr)->cont->f < edge->f) {
        (*ptr) = &((*ptr)->next);
    }

    new = malloc (sizeof(new));
    if (!new) {
        return false;
    }
    new->next = *ptr;
    *ptr = new;

    return true;
}

struct Path *pop_node()
{
    struct Path *ret;
    struct Node *buf;

    if (stk_head) {
        buf = stk_head;
        ret = buf->cont;
        stk_head = stk_head->next;
        free (buf);
        buf = NULL;
        return ret;
    }

    return NULL;
}
