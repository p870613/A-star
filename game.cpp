#include <cstdlib>
#include "game.h"
#define _DBG_ 1
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
    //dbg("Insert @ place %d\n", i);
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
        if ((*ptr)->edge != tar) {
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
        ptr->edge->dbg_info();
        ptr = ptr->next;
        dbg("\n");
        break;
    }
}

Game::Game(Field_3D *kiz, Coordinate *src, Coordinate *des)
{
    Path *src_p;

    //dbg("Gen Src\n");
    src_p = new Path(*src, NULL, 0, src->euc_dis(*des));
    this->kiz = kiz;
    this->src = src;
    this->des = des;
    //dbg("Set Src\n");
    kiz->set_position(src_p, *src);
    //dbg("Insert Stack\n");
    this->edges.insert(src_p);
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
    //this->dbg_info();

    Path *cur_edge;
    Coordinate *adjs;

    cur_edge = this->edges.pop();
    if (!cur_edge) {
        dbg("Stack is empty");
        return;
    }
    dbg("Current edge:\n");
    cur_edge->dbg_info();

    adjs = cur_edge->get_adjs();

    for (int i=0; i<ADJ_SZ; i++) {
        //dbg("\nADJ: %d\n", i);
        Block *next_edge;
        Path *result;
        next_edge = this->kiz->get_position(adjs[i]);//block

        if(next_edge == NULL)
            continue;
        //next_edge->dbg_info();
        result = next_edge->update(cur_edge, this->des); // return path if next is path or empty
        if (result) {
            this->edges.remove(next_edge);
            delete next_edge;
            next_edge = NULL;
           // dbg("Update: %p\n", result);
           // result->dbg_info();
            this->kiz->update(result);
            this->edges.insert(result);
        }
        result = NULL;
    }
    delete adjs;
    adjs = NULL;
}

void Game::dbg_info()
{
    dbg("-- Game --\n");
    dbg("Source: \n");
    this->src->dbg_info();
    dbg("Destination: \n");
    this->des->dbg_info();
    dbg("----------\n");
}

void Game::dbg_stk_info()
{
    this->edges.dbg_info();
}
