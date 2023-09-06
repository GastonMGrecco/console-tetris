#ifndef TEST_PIECE_H
#define TEST_PIECE_H
#include "../variables/var.h"
#include "../variables/map.h"
bool test_piece(){
    for (int i = 0; i < size_x; i++)
    {
        for (int j = 0; j < size_y; j++)
        {
            if (current_piece[i][j] != 0)
            {
                if(map[center_y + i][center_x + j]==8||map[center_y + i][center_x + j]==9)return true;
                 
            }
        }
    }
    return false;
}

#endif