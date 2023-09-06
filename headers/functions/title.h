#ifndef TITLE_H
#define TITLE_H
#include "../variables/var.h"

void print_title(int _y)
{
    
        move(_y, windowWidth/2-23);
        printw("██████╗█████╗██████╗█████╗  ██████╗████████╗ ");
        move(_y+1, windowWidth/2-23);
        printw("  ██╔═╝██╔══╝  ██╔═╝██╔══██╗  ██╔═╝███╔════╝ ");
        move(_y+2, windowWidth/2-23);
        printw("  ██║  ████╗   ██║  ██████╔╝  ██║  ████████╗");
        move(_y+3, windowWidth/2-23);
        printw("  ██║  ██╔═╝   ██║  ██╔══██╗  ██║   ╚═══███║");
        move(_y+4, windowWidth/2-23);
        printw("  ██║  ██████╗ ██║  ██║  ██║██████╗████████║");
        move(_y+5, windowWidth/2-23);
        printw("  ╚═╝  ╚═════╝ ╚═╝  ╚═╝  ╚═╝╚═════╝ ╚══════╝");
}
#endif