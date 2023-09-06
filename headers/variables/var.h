#ifndef VAR_H
#define VAR_H
#include <ncurses.h>
#include <iostream>
#include <string>
using namespace std;
bool pause = false;
// Songs
bool print_new_level=false;
int seconds=0;
string song = "songs/Loginska.mp3";
string block2 = "\u2592";
string block = "\u2593";
int one_line = 0;
int two_lines = 0;
int three_lines = 0;
int four_lines = 0;
int count_piece_1 = 0;
int count_piece_2 = 0;
int count_piece_3 = 0;
int count_piece_4 = 0;
int count_piece_5 = 0;
int count_piece_6 = 0;
int count_piece_7 = 0;

int random_piece;
int next_piece_num;
bool delay = false;
bool color_transition = false;
bool color_transition_word = false;
bool delayed = false;
int num_song = 1;
long long lastTransitionTime = 0;
const long long transitionInterval = 10000000;
int transition = 0;
bool finished = false;
int initial_level = 1;
long long interval = 900000000;
int ch;
int windowHeight, windowWidth;
int initial_width = windowWidth;
int initial_height = windowHeight;
int position_x = 30; // initial_map_position
int position_y = 15;

int center_x = 30; // initial_piece_position
int center_y = 0;

int current_piece[4][8];
int next_piece[4][8];

int size_x = 4;
int size_y = 8;

int color_map = 0;
int color_piece_colition = 2;
bool type = true;
int rotation = 0;

int lines = 0;
int points = 0;
int level = 1;
int last_combo = 0;
bool piece = false;
bool border_map = false;
bool colision_map = false;
bool background_map = false;
bool level_up = false;
bool resume_music = false;

#endif