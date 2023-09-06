#ifndef GAME_OVER_H
#define GAME_OVER_H
#include "../variables/var.h"
#include "../variables/map.h"
#include "../functions.h"

void game_over(int _current_piece, int put_num, int repeat_num)
{
    for (int i = 1; i < 21; i++)
    {
        int line = 0;
        for (int j = 2; j < 22; j++)
        {
            if (map[i][j] == repeat_num)
                line++;
        }

        if (line == 20)
        {
            for (int c = 2; c < 22; c++)
            {
                map[i][c] = put_num;
            }
            print_map(_current_piece);
        }
    }
}
#endif