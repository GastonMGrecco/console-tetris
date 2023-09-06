#ifndef COLITION_DOWN_H
#define COLITION_DOWN_H
#include "../variables/var.h"
#include "../variables/map.h"
bool colition_down()
{
    bool colition = false;
    for (int i = 0; i < size_x; i++)
    {
        for (int j = 0; j < size_y; j++)
        {
            if (current_piece[i][j] != 0)
            {
                if (map[center_y + i + 1][center_x + j] == 9 || map[center_y + i + 1][center_x + j] == 8)
                {
                    // printw("colition");
                    colition = true;
                }
            }
        }
    }
    return colition;
};
#endif