#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "variables/var.h"
#include "variables/piece.h"
#include "variables/map.h"
#include "functions/resize.h"
#include "functions/title.h"
#include "functions/pause.h"
#include "functions/loose.h"
#include "functions/new_level.h"
#include "functions/clear_new_level.h"
#include "functions/tetris.h"
#include "functions/print_piece.h"
#include "functions/test_piece.h"
#include "functions/music_finished_callback.h"
#include "functions/select_piece.h"
#include "functions/select_next_piece.h"
#include "functions/insert_colision.h"
#include "functions/print_map.h"
#include "functions/colition_right.h"
#include "functions/colition_left.h"
#include "functions/colition_down.h"
#include "functions/insert_piece.h"
#include "functions/remove_piece.h"
#include "functions/clear_piece.h"
#include "functions/complete_line.h"
#include "functions/complete_line_transition.h"
#include "functions/game_over.h"
#include "functions/rotate_4.h"
#include "functions/rotate.h"
#include "functions/rotate_piece.h"
#include "functions/table.h"
#include "functions/print_next_piece.h"
#include "functions/clean_next_piece.h"
#include "functions/clean_next_piece_map.h"

void print_piece(int _x, int _y, int _type[4][8], int color, bool theme);
bool test_piece();
void print_tetris(int _x, int _y);
void clear_new_level(int _x, int _y);
void new_level(int _x, int _y);
void print_loose(int _x, int _y);
void print_pause(int _x, int _y);
void print_title(int _y);
void resize();
void select_piece(int _random_piece);
void select_next_piece(int _random_piece);
void insert_colition();
void print_map(int _random_piece);
bool colition_right();
bool colition_left();
bool colition_down();
void insert_piece();
void remove_piece();
void clear_piece();
void complete_line();
void complete_line_transition(int _current_piece, int put_num, int repeat_num);
void game_over(int _current_piece, int put_num, int repeat_num);
void rotate(int piece_a[4][8], int piece_b[4][8], int num);
void rotate_4(int piece_a[4][8], int piece_b[4][8], int piece_c[4][8], int piece_d[4][8], int num);
void rotate_piece(int _random_piece);
void table(int x, int y, int long_x, int long_y);
void print_next_piece(int x, int y);
void clean_next_piece(int x, int y);
void clean_next_piece_map();
void MusicFinishedCallback();

#endif