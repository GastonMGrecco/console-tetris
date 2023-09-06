#ifndef ROTATE_H
#define ROTATE_H
#include "../variables/var.h"
#include "../variables/map.h"
#include "../functions.h"

void rotate(int piece_a[4][8], int piece_b[4][8], int num)
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (type)
            {

                if (piece_b[i][j] == num)
                {
                    current_piece[i][j] = num;
                }
            }
            else
            {
                if (piece_a[i][j] == num)
                {
                    current_piece[i][j] = num;
                }
            }
        }
    }
}
#endif