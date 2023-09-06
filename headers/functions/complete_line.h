#ifndef COMPLETE_LINE_H
#define COMPLETE_LINE_H
#include "../variables/var.h"
#include "../variables/map.h"
#include "../functions.h"


void complete_line()
{
    int count_lines = 0;
    int combo = 0;
    for (int i = 1; i < 21; i++)
    {
        int line = 0;
        for (int j = 22; j < 42; j++)
        {
            if (map[i][j] == 8)
                line++;
        }

        if (line == 20)
        {

            count_lines++;
            lines++;
            for (int r = i; r > 1; r--)
            {
                for (int c = 22; c < 42; c++)
                {
                    map[r][c] = map[r - 1][c];
                }
            }
        }
    }
    if (count_lines > 0)
        combo = (count_lines - 1) * (100 * level);
    if (count_lines > 1)
        last_combo = combo;
    points = points + (100 * level * count_lines);
    points = points + combo;
    if (count_lines == 1)
        one_line++;
    if (count_lines == 2)
        two_lines++;
    if (count_lines == 3)
        three_lines++;
    if (count_lines == 4)
    {
        four_lines++;
        points = points + 400;
        print_tetris(windowWidth - 45, 20);
    }
}
#endif