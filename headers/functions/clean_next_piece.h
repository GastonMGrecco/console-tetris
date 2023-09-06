#ifndef CLEAN_NEXT_PIECE_H
#define CLEAN_NEXT_PIECE_H
#include "../variables/var.h"
#include "../variables/map.h"
#include "../functions.h"

void clean_next_piece(int x, int y)
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 8; j++)
        {

            move(y + i, x + j);

            printw(" ");
        }
    }
}

#endif