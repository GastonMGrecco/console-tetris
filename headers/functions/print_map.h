#ifndef PRINT_MAP_H
#define PRINT_MAP_H
#include "../variables/var.h"
#include "../variables/map.h"

void print_map(int _random_piece)
{
    bool character_piece = true;
    bool character_map = true;
    bool character_colision = true;
    for (int i = 0; i < 22; i++)
    {
        for (int j = 0; j < 44; j++)
        {
            map[0][j] = 9;
            map[i][20] = 9;
            map[i][21] = 9;
            map[i][42] = 9;
            map[i][43] = 9;
            map[21][j] = 9;
            if (map[i][j] == _random_piece)
            {
                attron(COLOR_PAIR(_random_piece));
                move(position_y + i, position_x + j);

                if (piece)
                {
                    if (character_piece)
                        printw("[");
                    else
                        printw("]");
                    character_piece = !character_piece;
                }
                else
                    printw("%s", block.c_str());
                attroff(COLOR_PAIR(_random_piece));
            }
            else if (map[i][j] == 9)
            {
                attron(COLOR_PAIR(color_map));
                move(position_y + i, position_x + j);

                if (border_map)
                {
                    if (character_map)
                        printw("[");
                    else
                        printw("]");
                    character_map = !character_map;
                }
                else
                    printw("%s", block.c_str());
                attroff(COLOR_PAIR(color_map));
            }
            else if (map[i][j] == 8)
            {
                attron(COLOR_PAIR(color_piece_colition));
                move(position_y + i, position_x + j);
                if (colision_map)
                {
                    if (character_colision)
                        printw("[");
                    else
                        printw("]");
                    character_colision = !character_colision;
                }
                else
                    printw("%s", block2.c_str());
                attroff(COLOR_PAIR(color_piece_colition));
            }
            else if (map[i][j] == 7)
            {
                attron(COLOR_PAIR(7));
                move(position_y + i, position_x + j);
                if (piece)
                {
                    if (character_piece)
                        printw("[");
                    else
                        printw("]");
                    character_piece = !character_piece;
                }
                else
                    printw("%s", block2.c_str());
                attroff(COLOR_PAIR(7));
            }
            else if (map[i][j] == 6)
            {
                attron(COLOR_PAIR(6));
                move(position_y + i, position_x + j);
                if (piece)
                {
                    if (character_piece)
                        printw("[");
                    else
                        printw("]");
                    character_piece = !character_piece;
                }
                else
                    printw("%s", block2.c_str());
                attroff(COLOR_PAIR(6));
            }
            else if (map[i][j] == 5)
            {
                attron(COLOR_PAIR(5));
                move(position_y + i, position_x + j);
                if (piece)
                {
                    if (character_piece)
                        printw("[");
                    else
                        printw("]");
                    character_piece = !character_piece;
                }
                else
                    printw("%s", block2.c_str());
                attroff(COLOR_PAIR(5));
            }
            else if (map[i][j] == 4)
            {
                attron(COLOR_PAIR(4));
                move(position_y + i, position_x + j);
                if (piece)
                {
                    if (character_piece)
                        printw("[");
                    else
                        printw("]");
                    character_piece = !character_piece;
                }
                else
                    printw("%s", block2.c_str());
                attroff(COLOR_PAIR(4));
            }
            else if (map[i][j] == 3)
            {
                attron(COLOR_PAIR(3));
                move(position_y + i, position_x + j);
                if (piece)
                {
                    if (character_piece)
                        printw("[");
                    else
                        printw("]");
                    character_piece = !character_piece;
                }
                else
                    printw("%s", block2.c_str());
                attroff(COLOR_PAIR(3));
            }
            else if (map[i][j] == 2)
            {
                attron(COLOR_PAIR(2));
                move(position_y + i, position_x + j);
                if (piece)
                {
                    if (character_piece)
                        printw("[");
                    else
                        printw("]");
                    character_piece = !character_piece;
                }
                else
                    printw("%s", block2.c_str());
                attroff(COLOR_PAIR(2));
            }
            else if (map[i][j] == 1)
            {
                attron(COLOR_PAIR(1));
                move(position_y + i, position_x + j);
                if (piece)
                {
                    if (character_piece)
                        printw("[");
                    else
                        printw("]");
                    character_piece = !character_piece;
                }
                else
                    printw("%s", block2.c_str());
                attroff(COLOR_PAIR(1));
            }
            else
            {
                attron(COLOR_PAIR(color_map));
                move(position_y + i, position_x + j);
                if (background_map)
                    printw(" ");
                else
                    printw(".");
                attroff(COLOR_PAIR(color_map));
            }
        }
    }
};

#endif