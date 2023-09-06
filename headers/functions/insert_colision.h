#ifndef INSERT_COLISION_H
#define INSERT_COLISION_H
#include "../variables/var.h"
#include "../variables/map.h"
#include "../variables/piece.h"

void insert_colition()
{

    for (int i = 0; i < size_x; i++)
    {
        for (int j = 0; j < size_y; j++)
        {
            if (current_piece[i][j] != 0)
            {
                map[center_y + i][center_x + j] = 8;
            }
        }
    }
};

#endif