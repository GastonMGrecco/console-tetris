#ifndef ROTATE_4_H
#define ROTATE_4_H
#include "../variables/var.h"
#include "../variables/map.h"
#include "../functions.h"

void rotate_4(int piece_a[4][8], int piece_b[4][8], int piece_c[4][8], int piece_d[4][8], int num)
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            switch (rotation)
            {
            case 0:
                if (piece_a[i][j] == num)
                {
                    current_piece[i][j] = num;
                }
                break;
            case 1:
                if (piece_b[i][j] == num)
                {
                    current_piece[i][j] = num;
                }
                break;
            case 2:
                if (piece_c[i][j] == num)
                {
                    current_piece[i][j] = num;
                }
                break;
            case 3:
                if (piece_d[i][j] == num)
                {
                    current_piece[i][j] = num;
                }
                break;
            }
        }
    }
}
#endif