#ifndef CLEAR_PIECE_H
#define CLEAR_PIECE_H
#include "../variables/var.h"
#include "../variables/map.h"


void clear_piece()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 8; j++)
        {

            current_piece[i][j] = 0;
        }
    }
}
#endif