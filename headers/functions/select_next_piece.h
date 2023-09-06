#ifndef SELECT_NEXT_PIECE_H
#define SELECT_NEXT_PIECE_H
#include "../variables/var.h"
#include "../variables/piece.h"


void select_next_piece(int _random_piece)
{

    switch (_random_piece)
    {
    case 1:
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                if (piece_1_a[i][j] == 1)
                {
                    next_piece[i][j] = 1;
                }
            }
        }
        break;
    case 2:
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                if (piece_2_a[i][j] == 2)
                {
                    next_piece[i][j] = 2;
                }
            }
        }
        break;
    case 3:
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                if (piece_3_b[i][j] == 3)
                {
                    next_piece[i][j] = 3;
                }
            }
        }
        break;
    case 4:
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                if (piece_4[i][j] == 4)
                {
                    next_piece[i][j] = 4;
                }
            }
        }
        break;
    case 5:
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                if (piece_5_a[i][j] == 5)
                {
                    next_piece[i][j] = 5;
                }
            }
        }
        break;
    case 6:
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                if (piece_6_a[i][j] == 6)
                {
                    next_piece[i][j] = 6;
                }
            }
        }
        break;
    case 7:
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                if (piece_7_a[i][j] == 7)
                {
                    next_piece[i][j] = 7;
                }
            }
        }
        break;
    }
}
#endif