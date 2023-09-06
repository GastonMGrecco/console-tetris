#ifndef NEW_LEVEL_H
#define NEW_LEVEL_H
#include "../variables/var.h"
void new_level(int _x, int _y){
    attron(COLOR_PAIR(3));
    move(_y, _x);
    printw(" __ _  _  _  ____  _  _   __ ");
    move(_y+1, _x);
    printw("(  ( \\/ )( \\(  __)/ )( \\ /  \\       ");
    move(_y+2, _x);
    printw("/    /) \\/ ( ) _) \\ \\/ /(  O )      ");
    move(_y+3, _x);
    printw("\\_)__)\\____/(____) \\__/  \\__/       ");

    move(_y+6, _x);
    printw(" __ _  __  _  _  ____  __     _   ");
    move(_y+7, _x);
    printw("(  ( \\(  )/ )( \\(  __)(  )   / \\  ");
    move(_y+8, _x);
    printw("/    / )( \\ \\/ / ) _) / (_/\\ \\_/  ");
    move(_y+9, _x);
    printw("\\_)__)(__) \\__/ (____)\\____/ (_)");
    attroff(COLOR_PAIR(3));
}

#endif