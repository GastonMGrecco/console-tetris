#ifndef PAUSE_H
#define PAUSE_H
#include "../variables/var.h"
void print_pause(int _x, int _y)
{
    attron(COLOR_PAIR(2));
    move(_y, _x);
    printw(" ____   __   _  _  ____   __  ");
    move(_y+1, _x);
    printw("(  _ \\ / _\\ / )( \\/ ___) / _\\ ");
    move(_y+2, _x);
    printw(" ) __//    \\) \\/ (\\___ \\/    \\");
    move(_y+3, _x);
    printw("(__)  \\_/\\_/\\____/(____/\\_/\\_/");
    attroff(COLOR_PAIR(2));
}

#endif