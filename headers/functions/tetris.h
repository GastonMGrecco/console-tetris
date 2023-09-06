#ifndef TETRIS_H
#define TETRIS_H
#include "../variables/var.h"
void print_tetris(int _x, int _y)
{
    attron(COLOR_PAIR(2));
    move(_y, _x);
    printw(" ____  ____  ____  ____  __  ____  _   ");
    move(_y + 1, _x);
    printw("(_  _)(  __)(_  _)(  _ \\(  )/ ___)/ \\  ");
    move(_y + 2, _x);
    printw("  )(   ) _)   )(   )   / )( \\___  \\_/  ");
    move(_y + 3, _x);
    printw(" (__) (____) (__) (__\\_)(__)(____/(_)   ");
    attroff(COLOR_PAIR(2));
}

#endif