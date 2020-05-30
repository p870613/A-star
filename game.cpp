#include <cstdlib>
#include "game.h"
#include "debug.h"

static struct Stk_Node *new_sn(Path *edge, struct Stk_Node *next)
{
    struct Stk_Node *ret;
    ret = new struct Stk_Node;
    ret->edge = edge;
    ret->next = next;
    return ret;
}

Stack::Stack()
{
    this->top = NULL;
}

void Stack::insert(Path *edge)
{
    struct Stk_Node **ptr;

    ptr= &(this->top);
    while (*ptr && edge < (*ptr)->edge) {
        ptr = &((*ptr)->next);
    }
    *ptr = new_sn (edge, (*ptr)->next);
}

Path* Stack::pop()
{
    Path *ret;
    struct Stk_Node *buf;

    ret = NULL;
    if (this->top) {
        buf = this->top;
        this->top = this->top->next;
        ret = buf->edge;
        delete buf;
        buf = NULL;
    }

    return ret;
}

Game::Game(Field_3D *kiz, Coordinate *src, Coordinate *des)
{
    Path *src_p;

    src_p = new Path(*src);
    this->kiz = kiz;
    this->src = src;
    this->des = des;
    kiz->set_position(src_p, *src);
    (this->edges).insert(src_p);
}

Result *Game::set()
{
    Block *des;
    Result *ret;

    des = this->kiz->get_position (*(this->des));
    ret = des->is_reached();

    return ret;
}

void Game::next_step()
{
    Path *cur_edge;
    dist_t cur_g;
    Coordinate *adjs;

    cur_edge = (this->edges).pop();
    if (!cur_edge) {
        dbg("Stack is empty");
        return;
    }

    cur_g = cur_edge->get_g();
    adjs = cur_edge->get_adjs();

    for (int i=0; i<ADJ_SZ; i++) {
        Block *next_edge;
        Block *result;
        next_edge = this->kiz->get_position(adjs[i]);//block
        if(next_edge == NULL)
            continue;
        result = next_edge->update(cur_edge, this->des); // return path if next is path or empty
        if (result) {
            this->kiz->update(result);
            (this->edges).insert(result);
            delete next_edge;
            next_edge = NULL;
        }
    }
}
