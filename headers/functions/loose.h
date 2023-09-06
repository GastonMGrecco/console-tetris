#ifndef LOOSE_H
#define LOOSE_H
#include "../variables/var.h"
void print_loose(int _x, int _y){
    attron(COLOR_PAIR(1));
    move(_y, _x);
    printw(" ____  ____  ____  ____  __  ____  ____  ____  _   ");
    move(_y+1, _x);
    printw("(  _ \\(  __)(  _ \\(    \\(  )/ ___)(_  _)(  __)/ \\  ");
    move(_y+2, _x);
    printw(" ) __/ ) _)  )   / ) D ( )( \\___ \\  )(   ) _) \\_/  ");
    move(_y+3, _x);
    printw("(__)  (____)(__\\_)(____/(__)(____/ (__) (____)(_)   ");
    attroff(COLOR_PAIR(1));
}

#endif