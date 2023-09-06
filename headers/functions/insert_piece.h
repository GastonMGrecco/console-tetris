#ifndef INSERT_PIECE_H
#define INSERT_PIECE_H
#include "../variables/var.h"
#include "../variables/map.h"
void insert_piece()
{

    for (int i = 0; i < size_x; i++)
    {
        for (int j = 0; j < size_y; j++)
        {
            if (current_piece[i][j] != 0)
            {
                map[center_y + i][center_x + j] = current_piece[i][j];
            }
        }
    }
};
#endif