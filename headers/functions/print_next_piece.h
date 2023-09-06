#ifndef PRINT_NEXT_PIECE_H
#define PRINT_NEXT_PIECE_H
#include "../variables/var.h"
#include "../variables/map.h"
#include "../functions.h"

void print_next_piece(int x, int y)
{
    bool character_piece = true;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (next_piece[i][j] != 0)
            {
                attron(COLOR_PAIR(next_piece[i][j]));
                move(y + i, x + j);
                if (piece)
                {
                    if (character_piece)
                        printw("[");
                    else
                        printw("]");
                    character_piece = !character_piece;
                }
                else
                    printw("%s", block.c_str());
                attroff(COLOR_PAIR(next_piece[i][j]));
            }
        }
    }
}

#endif