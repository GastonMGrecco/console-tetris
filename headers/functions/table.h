#ifndef TABLE_H
#define TABLE_H
#include "../variables/var.h"
#include "../variables/map.h"
#include "../functions.h"

void table(int x, int y, int long_x, int long_y)
{
    bool character_map = false;
    for (int i = 0; i < long_y; i++)
    {
        for (int j = 0; j < long_x; j++)
        {
            if (i == 0 || i == long_y - 1)
            {
                attron(COLOR_PAIR(color_map));
                move(y + i, x + j);

                if (border_map)
                {
                    if (character_map)
                        printw("[");
                    else
                        printw("]");
                }
                else
                    printw("%s", block.c_str());
                attroff(COLOR_PAIR(color_map));
            }
            if (j == 0 || j == 1 || j == long_x - 1 || j == long_x - 2)
            {
                attron(COLOR_PAIR(color_map));
                move(y + i, x + j);

                if (border_map)
                {
                    if (character_map)
                        printw("[");
                    else
                        printw("]");
                }
                else
                    printw("%s", block.c_str());
                attroff(COLOR_PAIR(color_map));
            }
            character_map = !character_map;
        }
    }
}
#endif