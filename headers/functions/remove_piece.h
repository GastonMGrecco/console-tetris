#ifndef REMOVE_PIECE_H
#define REMOVE_PIECE_H
#include "../variables/var.h"
#include "../variables/map.h"
void remove_piece()
{
    for (int i = 0; i < size_x; i++)
    {
        for (int j = 0; j < size_y; j++)
        {
            if (current_piece[i][j] != 0)
            {
                map[center_y + i][center_x + j] = 0;
            }
        }
    }
};
#endif