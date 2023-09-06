#ifndef COLITION_RIGHT_H
#define COLITION_RIGHT_H
#include "../variables/var.h"
#include "../variables/map.h"
bool colition_right()
{
    for (int i = 0; i < size_x; i++)
    {
        for (int j = 0; j < size_y; j++)
        {
            if (current_piece[i][j] != 0)
            {
                if (map[center_y + i][center_x + j + 2] == 9 || map[center_y + i][center_x + j + 2] == 8)
                {
                    return true;
                }
            }
        }
    }
    return false;
};
#endif