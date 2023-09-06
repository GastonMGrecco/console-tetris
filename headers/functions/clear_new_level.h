#ifndef CLEAR_NEW_LEVEL_H
#define CLEAR_NEW_LEVEL_H
#include "../variables/var.h"
void clear_new_level(int _x, int _y){
    attron(COLOR_PAIR(3));
    move(_y, _x);
    printw("                                                 ");
    move(_y+1, _x);
    printw("                                                 ");
    move(_y+2, _x);
    printw("                                                 ");
    move(_y+3, _x);     
    printw("                                                 ");
    move(_y+6, _x);     
    printw("                                                 ");
    move(_y+7, _x);     
    printw("                                                 ");
    move(_y+8, _x);     
    printw("                                                 ");
    move(_y+9, _x);     
    printw("                                                 ");
    attroff(COLOR_PAIR(3));
}

#endif