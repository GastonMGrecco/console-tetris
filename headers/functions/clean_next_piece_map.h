#ifndef CLEAN_NEXT_PIECE_MAP_H
#define CLEAN_NEXT_PIECE_MAP_H
#include "../variables/var.h"
#include "../variables/map.h"
#include "../functions.h"


void clean_next_piece_map()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            next_piece[i][j] = 0;
        }
    }
}

#endif