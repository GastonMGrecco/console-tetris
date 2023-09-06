#ifndef PRINT_PIECE_H
#define PRINT_PIECE_H
#include "../variables/var.h"

void print_piece(int _x, int _y, int _type[4][8],int color, bool theme){
    bool character_piece = true;
     for (int i = 0; i < size_x; i++)
    {
        for (int j = 0; j < size_y; j++)
        {
            if (_type[i][j] != 0)
            {
                 attron(COLOR_PAIR(color));
                move(_y+i,_x+j);

                if (theme)
                {
                    if (character_piece)
                        printw("[");
                    else
                        printw("]");
                    character_piece = !character_piece;
                }
                else
                    printw("%s", block.c_str());
                attroff(COLOR_PAIR(color));
            }
        }
    }
}

#endif