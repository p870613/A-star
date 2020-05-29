#include <cstdlib>
#include "game.h"
#include "debug.h"

Stack::Stack()
{
    this->top = NULL;
}

void Stack::insert(Path *edge)
{
    struct Stk_Node **ptr;

    ptr= &(this->top);
    while (*ptr && edge < ptr) {
        ptr = &((*ptr)->next);
    }

    edge->next = (*ptr)->next;
    *ptr = edge;
}

Path *pop()
{
    Path *ret;

    ret = this->top;
    if (this->top) {
        this->top = this->top->next;
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
    this->edges->push(src_p);
}

Result *Game::set()
{
    Block *des;
    Result *ret;

    des = this->kiz->get_position (*(this->des));
    ret = des->reached();

    return ret;
}

void Game::next_step()
{
    Path *cur_edge;
    dist_t cur_g;
    Coordinate *adjs;

    cur_edge = this->kiz->pop();
    if (!cur_edge) {
        dbg("Stack is empty");
        return;
    }

    cur_g = cur_edge->get_g();
    adjs = cur_edge->get_adjs();

    for (int i=0; i<ADJ_SZ; i++) {
        Block *next_edge;
        next_edge = this->kiz->get_position(adjs[i]);
        next_edge->update(cur_edge, this->kiz, this->edges);
    }
}
