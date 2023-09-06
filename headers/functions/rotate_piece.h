#ifndef ROTATE_PIECE_H
#define ROTATE_PIECE_H
#include "../variables/var.h"
#include "../variables/map.h"
#include "../functions.h"

void rotate_piece(int _random_piece)
{

    switch (_random_piece)
    {
    case 1:
        rotate(piece_1_a, piece_1_b, 1);

        if (test_piece())
        {

            clear_piece();

            type = !type;
            rotate(piece_1_a, piece_1_b, 1);
        }
        type = !type;
        break;
    case 2:
        rotate(piece_2_a, piece_2_b, 2);

        if (test_piece())
        {

            clear_piece();

            type = !type;
            rotate(piece_2_a, piece_2_b, 2);
        }
        type = !type;
        break;
    case 3:
        rotate_4(piece_3_c, piece_3_d, piece_3_a, piece_3_b, 3);

        if (test_piece())
        {

            clear_piece();
            if (rotation == 0)
            {
                rotation = 3;
            }
            else
            {
                rotation--;
            }

            rotate_4(piece_3_c, piece_3_d, piece_3_a, piece_3_b, 3);
            rotation++;
        }
        else
        {
            rotation++;
        }
        if (rotation > 3)
            rotation = 0;
        break;
    case 4:
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
        rotate(piece_5_a, piece_5_b, 5);

        if (test_piece())
        {

            clear_piece();

            type = !type;
            rotate(piece_5_a, piece_5_b, 5);
        }
        type = !type;
        break;
    case 6:
        rotate_4(piece_6_b, piece_6_c, piece_6_d, piece_6_a, 6);

        if (test_piece())
        {

            clear_piece();

            if (rotation == 0)
            {
                rotation = 3;
            }
            else
            {
                rotation--;
            }

            rotate_4(piece_6_b, piece_6_c, piece_6_d, piece_6_a, 6);
            rotation++;
        }
        else
        {
            rotation++;
        }
        if (rotation > 3)
            rotation = 0;
        break;
    case 7:
        rotate_4(piece_7_b, piece_7_c, piece_7_d, piece_7_a, 7);

        if (test_piece())
        {

            clear_piece();

            if (rotation == 0)
            {
                rotation = 3;
            }
            else
            {
                rotation--;
            }
            rotate_4(piece_7_b, piece_7_c, piece_7_d, piece_7_a, 7);
            rotation++;
        }
        else
        {
            rotation++;
        }
        if (rotation > 3)
            rotation = 0;
        break;
        break;
    }
};

#endif