#include <cstdlib>
#include "game.h"
#define _DBG_ 0
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
    int i=0;

    ptr= &(this->top);
    while (*ptr && *edge > *((*ptr)->edge)) {
        ptr = &((*ptr)->next);
        i++;
    }
    *ptr = new_sn (edge, (*ptr));
}

Path *Stack::pop()
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

void Stack::remove(Block *tar)
{
    struct Stk_Node **ptr;
    struct Stk_Node *buf;

    ptr = &(this->top);
    while (*ptr) {
        if ((*ptr)->edge == tar) {
            buf = *ptr;
            *ptr = (*ptr)->next;
            delete buf;
            break;
        }
        ptr = &((*ptr)->next);
    }
}

bool Stack::is_empty()
{
    return this->top == NULL;
}

void Stack::dbg_info()
{
    struct Stk_Node *ptr;
    int i;

    ptr = this->top;
    i = 0;
    while (ptr) {
        dbg("Node %d\n", i++);
        ptr = ptr->next;
        dbg("\n");
    }
}

Game::Game(Field_3D *kiz, Coordinate *src, Coordinate *des)
{
    Path *src_p;

    src_p = new Path(*src, NULL, 0, src->euc_dis(*des));
    this->kiz = kiz;
    this->src = src;
    this->des = des;
    kiz->set_position(src_p, *src);
    this->edges.insert(src_p);
}

Result *Game::set()
{
    Block *des;
    if (this->edges.is_empty())
        return new Unreach();

    des = this->kiz->get_position (*(this->des));
    return des->is_reached(); // Check destination's type, return None Null pointer if it not Empty
}

void Game::next_step()
{
    Path *cur_edge;
    Coordinate *adjs;

    cur_edge = this->edges.pop();
    if (!cur_edge) {
        dbg("Stack is empty");
        return;
    }

    //dbg("Current edge: %p\n", cur_edge);
    adjs = cur_edge->get_adjs();
    for (int i=0; i<ADJ_SZ; i++) {
        Block *next_edge;
        Path *result;

        next_edge = this->kiz->get_position(adjs[i]);
        if(next_edge == NULL) // Out of range
            continue;

        //dbg("Next EDGE: %p\n", next_edge);
        result = next_edge->update(cur_edge, this->des); // Return path if update, otherwise return NULL

        if (result) { // Remove old one from stack and replace new on
            this->edges.remove(next_edge);
            delete next_edge;

            this->kiz->update(result);
            this->edges.insert(result);
        }

        result = NULL;
        next_edge = NULL;
    }

    delete adjs;
    adjs = NULL;
}

void Game::dbg_info()
{
    /*
    dbg("-- Game --\n");
    dbg("Source: \n");
    this->src->dbg_info();
    dbg("Destination: \n");
    this->des->dbg_info();
    dbg("----------\n");
    */
}

void Game::dbg_stk_info()
{
    this->edges.dbg_info();
}

void Game::dbg_visual_2D(int z)
{
    Block *ptr;

    dbg(" \t");
    for (int y=0; y<Y_MAX; y++) // Row number
        dbg("%d\t", y);
    dbg("\n");

    for (int x=0; x<X_MAX; x++) {
        dbg("%d\t", x); // Column number
        for (int y=0; y<Y_MAX; y++) {
            ptr = this->kiz->get_position(Coordinate(x, y, z));
            dbg("%d\t", (int)ptr->dbg_char()); // KOZ:(-1), Empty(0)
        }
        dbg("\n");
    }
}
