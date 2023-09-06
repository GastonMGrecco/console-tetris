#ifndef COMPLETE_LINETRANSITION_H
#define COMPLETE_LINETRANSITION_H
#include "../variables/var.h"
#include "../variables/map.h"
#include "../functions.h"

void complete_line_transition(int _current_piece, int put_num, int repeat_num)
{
    for (int i = 1; i < 21; i++)
    {
        int line = 0;
        for (int j = 22; j < 42; j++)
        {
            if (map[i][j] == repeat_num)
                line++;
        }
        if (line > 0)
            if (line == 20)
            {
                for (int c = 22; c < 42; c++)
                {
                    map[i][c] = put_num;
                }
                print_map(_current_piece);
            }
    }
}
#endif