#ifndef SELECT_PIECE_H
#define SELECT_PIECE_H
#include "../variables/var.h"
#include "../variables/piece.h"


void select_piece(int _random_piece)
{

    switch (_random_piece)
    {
    case 1:
        count_piece_1++;
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                if (piece_1_a[i][j] == 1)
                {
                    current_piece[i][j] = 1;
                }
            }
        }
        break;
    case 2:
        count_piece_2++;
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                if (piece_2_a[i][j] == 2)
                {
                    current_piece[i][j] = 2;
                }
            }
        }
        break;
    case 3:
        count_piece_3++;
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                if (piece_3_b[i][j] == 3)
                {
                    current_piece[i][j] = 3;
                }
            }
        }
        break;
    case 4:
        count_piece_4++;
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                if (piece_4[i][j] == 4)
                {
                    current_piece[i][j] = 4;
                }
            }
        }
        break;
    case 5:
        count_piece_5++;
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                if (piece_5_a[i][j] == 5)
                {
                    current_piece[i][j] = 5;
                }
            }
        }
        break;
    case 6:
        count_piece_6++;
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                if (piece_6_a[i][j] == 6)
                {
                    current_piece[i][j] = 6;
                }
            }
        }
        break;
    case 7:
        count_piece_7++;
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                if (piece_7_a[i][j] == 7)
                {
                    current_piece[i][j] = 7;
                }
            }
        }
        break;
    }
}
#endif