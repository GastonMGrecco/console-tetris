#include <clocale>
#include <stdlib.h>
#include <time.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include "./headers/functions.h"
/*
compile with
g++ main.cpp -o consoletetris -lncursesw -lstdc++ -lSDL2 -lSDL2_mixer
*/

int main()
{

    setlocale(LC_ALL, "");
    struct timespec currentTime, start_time, current_time;
    clock_gettime(CLOCK_MONOTONIC, &currentTime);
    long long lastUpdateTime = currentTime.tv_sec * 1000000000LL + currentTime.tv_nsec;
    srand(time(NULL));

    initscr();

    SDL_Init(SDL_INIT_AUDIO);
    Mix_Init(MIX_INIT_MP3);
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);

    Mix_Music *music = Mix_LoadMUS(song.c_str());
    Mix_Music *game_over = Mix_LoadMUS("songs/Game Over.mp3");
    Mix_Music *celebration = Mix_LoadMUS("songs/Celebration.mp3");
    Mix_Music *level_up_song = Mix_LoadMUS("songs/Level Up.mp3");
    Mix_Music *title = Mix_LoadMUS("songs/Title Screen.mp3");
    Mix_Music *pause_sound = Mix_LoadMUS("songs/pause.mp3");
    Mix_PlayMusic(music, -1);
    Mix_VolumeMusic(MIX_MAX_VOLUME / 2);
    Mix_Chunk *collisionSound = Mix_LoadWAV("songs/colision.wav");
    Mix_Chunk *completeline = Mix_LoadWAV("songs/completeline.wav");
    Mix_Chunk *move_sound = Mix_LoadWAV("songs/MOVE.wav");
    Mix_Chunk *rotate = Mix_LoadWAV("songs/ROTATE.wav");
    Mix_HookMusicFinished(NULL);
    Mix_HookMusicFinished(MusicFinishedCallback);
    Mix_PauseMusic();
    Mix_PlayMusic(title, 0);

    start_color();
    init_pair(0, COLOR_WHITE, COLOR_BLACK);
    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_YELLOW, COLOR_BLACK);
    init_pair(3, COLOR_GREEN, COLOR_BLACK);
    init_pair(4, COLOR_BLUE, COLOR_BLACK);
    init_pair(5, COLOR_GREEN, COLOR_BLACK);
    init_pair(6, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(7, COLOR_CYAN, COLOR_BLACK);
    bkgd(COLOR_PAIR(0));
    noecho();
    curs_set(0);
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);

    while ((ch = getch()) != '\n')
    {
        getmaxyx(stdscr, windowHeight, windowWidth);
        resize();
        clock_gettime(CLOCK_MONOTONIC, &currentTime);
        long long updateTime = currentTime.tv_sec * 1000000000LL + currentTime.tv_nsec;
        if (updateTime - lastTransitionTime >= 100000000)
        {
            lastTransitionTime = updateTime;
            if (!color_transition)
            {

                attron(COLOR_PAIR(2));
                print_title(5);
                attroff(COLOR_PAIR(2));

                attron(COLOR_PAIR(0));
                move(25, windowWidth / 2 - 15);
                printw(" PRESIONA ENTER PARA COMENZAR ");
                move(30, windowWidth / 2 - 14);
                printw(" CREADO POR GASTON M GRECCO ");
                attroff(COLOR_PAIR(0));
                print_piece(10, 2, piece_1_a, 1, true);
                print_piece(38, 5, piece_2_a, 2, true);
                print_piece(20, 12, piece_3_a, 3, true);
                print_piece(18, 23, piece_4, 4, true);
                print_piece(70, 15, piece_5_a, 5, true);
                print_piece(90, 26, piece_6_a, 6, true);
                print_piece(100, 20, piece_7_a, 7, true);
                print_piece(120, 2, piece_1_b, 1, true);
                print_piece(115, 18, piece_2_b, 2, true);
                print_piece(53, 30, piece_3_b, 3, true);
                print_piece(114, 23, piece_4, 4, true);
                print_piece(55, 1, piece_5_b, 5, true);
                print_piece(130, 30, piece_6_b, 6, true);
                print_piece(135, 20, piece_7_b, 7, true);

                print_piece(5, 26, piece_6_c, 6, true);
                print_piece(10, 20, piece_7_c, 7, true);
                print_piece(37, 15, piece_6_d, 6, true);
                print_piece(80, 2, piece_7_d, 7, true);
                print_piece(55, 20, piece_3_c, 3, true);
                print_piece(120, 10, piece_3_d, 3, true);
            }
            if (color_transition)
            {

                attron(COLOR_PAIR(3));
                print_title(5);
                attroff(COLOR_PAIR(3));
                attron(COLOR_PAIR(0));
                move(25, windowWidth / 2 - 15);
                printw("                             ");
                move(30, windowWidth / 2 - 14);
                printw(" CREADO POR GASTON M GRECCO ");
                attroff(COLOR_PAIR(0));
                print_piece(10, 2, piece_1_a, 1, false);
                print_piece(38, 5, piece_2_a, 2, false);
                print_piece(20, 12, piece_3_a, 3, false);
                print_piece(18, 23, piece_4, 4, false);
                print_piece(70, 15, piece_5_a, 5, false);
                print_piece(90, 26, piece_6_a, 6, false);
                print_piece(100, 20, piece_7_a, 7, false);
                print_piece(120, 2, piece_1_b, 1, false);
                print_piece(115, 18, piece_2_b, 2, false);
                print_piece(53, 30, piece_3_b, 3, false);
                print_piece(114, 23, piece_4, 4, false);
                print_piece(55, 1, piece_5_b, 5, false);
                print_piece(130, 30, piece_6_b, 6, false);
                print_piece(135, 20, piece_7_b, 7, false);

                print_piece(5, 26, piece_6_c, 6, false);
                print_piece(10, 20, piece_7_c, 7, false);
                print_piece(37, 15, piece_6_d, 6, false);
                print_piece(80, 2, piece_7_d, 7, false);
                print_piece(55, 20, piece_3_c, 3, false);
                print_piece(120, 10, piece_3_d, 3, false);
            }
            refresh();
            color_transition = !color_transition;
        }
        clock_gettime(CLOCK_MONOTONIC, &current_time);
        long long updateTime_Word = current_time.tv_sec * 1000000000LL + current_time.tv_nsec;
        if (updateTime_Word - lastTransitionTime >= 900000000)
        {
            lastTransitionTime = updateTime_Word;
            if (!color_transition_word)
            {
                move(0, 0);

                attron(COLOR_PAIR(0));
                printw("COMENZAR JUEGO");
                attroff(COLOR_PAIR(0));
            }
            if (color_transition_word)
            {
                move(0, 0);

                attron(COLOR_PAIR(1));
                printw("COMENZAR JUEGO");
                attroff(COLOR_PAIR(1));
            }
            refresh();
            color_transition_word = !color_transition_word;
        }
    }
    clear();
    getmaxyx(stdscr, windowHeight, windowWidth);
    int startX = (windowWidth - 44) / 2;
    position_x = startX;
    random_piece = (rand() % 7) + 1;
    next_piece_num = (rand() % 7) + 1;
    select_next_piece(next_piece_num);
    print_next_piece(28, windowHeight - 9);
    select_piece(random_piece);
    insert_piece();
    print_map(random_piece);

    while ((ch = getch()) != 'q')
    {
        if (ch == 'P')
        {
            if (pause)
            {
                pause = false;
                Mix_PlayMusic(pause_sound, 0);
            }
            else
            {
                pause = true;
                print_pause(60, 15);
                Mix_PauseMusic();
                resume_music = true;
                Mix_PlayMusic(pause_sound, 0);
            }
        }
        if (!pause)
        {

            resize();
            if (level_up)
            {
                Mix_PauseMusic();

                Mix_PlayMusic(level_up_song, 0);
                level_up = false;
                music = Mix_LoadMUS(song.c_str());
            }
            if (initial_level < level)
            {
                Mix_FreeMusic(music);
                music = Mix_LoadMUS(song.c_str());
                Mix_PlayMusic(music, -1);
                print_new_level = true;
                level_up = true;

                initial_level = level;
                seconds = 0;
            }
            if (seconds == 5)
            {
                clear_new_level(windowWidth - 45, 20);
                print_new_level = false;
            }
            if (print_new_level)
                new_level(windowWidth - 45, 20);

            getmaxyx(stdscr, windowHeight, windowWidth);
            int startY = (windowHeight - 22) / 2;
            int startX = (windowWidth - 44) / 2;
            position_x = startX;

            attron(COLOR_PAIR(2));
            print_title(2);
            attroff(COLOR_PAIR(2));
            attroff(A_BOLD); // Desactivar negrita
            string song_played = song.c_str();
            if (song_played.length() >= 10)
            {
                song_played = song_played.substr(6, song_played.length() - 10);
            }
            move(position_y + 2, startX + 15);
            printw("%d", count_piece_1);
            move(position_y + 5, startX + 15);
            printw("%d", count_piece_2);
            move(position_y + 8, startX + 15);
            printw("%d", count_piece_3);
            move(position_y + 11, startX + 15);
            printw("%d", count_piece_4);
            move(position_y + 14, startX + 15);
            printw("%d", count_piece_5);
            move(position_y + 17, startX + 15);
            printw("%d", count_piece_6);
            move(position_y + 20, startX + 15);
            printw("%d", count_piece_7);
            clean_next_piece(28, windowHeight - 9);
            print_next_piece(28, windowHeight - 9);
            move(windowHeight - 6, windowWidth - 19);
            printw("NIVEL: %d", level);
            move(11, startX + 2);
            printw("LINEAS SIMPLES:%d", one_line);
            move(12, startX + 2);
            printw("LINEAS DOBLES:%d", two_lines);
            move(13, startX + 2);
            printw("LINEAS TRIPLES:%d", three_lines);
            move(11, startX + 22);
            printw("TETRIS: %d", four_lines);
            move(12, startX + 22);
            printw("LINEAS TOTALES: %d", lines);
            move(13, startX + 22);
            printw("PUNTOS: %d", points);
            move(windowHeight - 8, 7);
            printw("SIGUIENTE PIEZA: ");
            // move(12, startX + 26);
            // printw("ULTIMO COMBO: %d", last_combo);
            move(11, startX + 45);
            printw("NUMERO DE CANCION: %d  ", num_song);
            move(13, startX + 45);
            printw("                                                        ");
            move(13, startX + 45);
            printw("NOMBRE DE LA CANCION: %s  ", song_played.c_str());
            // Menu
            move(13, 4);
            printw("MENU:");
            move(14, 4);
            printw("- SALIR DEL JUEGO: 'q'");
            move(15, 4);
            printw("- PAUSAR EL JUEGO: 'P'");
            move(16, 4);
            printw("- Cambiar tema de la pieza: 'p'");
            move(17, 4);
            printw("- Cambiar tema de la colision: 'c'");
            move(18, 4);
            printw("- Cambiar fondo del mapa: 'm'");
            move(19, 4);
            printw("- Cambiar tema del mapa: 'f'");
            move(20, 4);
            printw("- Cambiar cancion: 's'");
            // Controls
            move(22, 4);
            printw("CONTROLES:");
            move(23, 4);
            printw("- Izquierda: \u2190");
            move(24, 4);
            printw("- Derecha: \u2192");
            move(25, 4);
            printw("- Abajo \u2193");
            move(26, 4);
            printw("- Rotar: [Barra Espaciadora]");
            table(startX, position_y - 5, 22, 5);
            table(startX + 20, position_y - 5, 24, 5);
            table(startX + 42, position_y - 5, 49, 5);
            table(windowWidth - 26, windowHeight - 8, 22, 5);
            table(0, 0, windowWidth, windowHeight);
            table(4, windowHeight - 11, 34, 8);
            if (resume_music)
            {
                if (!finished)
                {
                    Mix_PlayMusic(music, -1);
                    resume_music = false;
                }
            }
            clock_gettime(CLOCK_MONOTONIC, &currentTime);
            long long currentTimeNanos = currentTime.tv_sec * 1000000000LL + currentTime.tv_nsec;

            if (currentTimeNanos - lastTransitionTime >= transitionInterval)
            {

                if (delay)
                {
                    lastTransitionTime = currentTimeNanos;

                    if (!color_transition)
                    {
                        complete_line_transition(random_piece, 8, 9);
                        transition++;
                    }
                    else
                    {
                        complete_line_transition(random_piece, 9, 8);
                    }
                    if (transition == 10)
                    {
                        delay = false;
                    }

                    color_transition = !color_transition;
                    seconds = 0;
                }
            }

            if (delayed && !delay && transition == 0 && !finished)
            {
                if (colition_down())
                {

                    clock_gettime(CLOCK_MONOTONIC, &current_time);

                    if (currentTimeNanos - lastUpdateTime >= interval)
                    {

                        insert_colition();
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
                                clock_gettime(CLOCK_MONOTONIC, &start_time);
                                delay = true;
                            }
                        }

                        if (!delay)
                        {

                            if (!finished)
                            {
                                random_piece = next_piece_num;
                                clear_piece();
                                center_x = 30;
                                center_y = 0;
                                select_piece(random_piece);
                                insert_piece();
                                print_map(random_piece);
                                next_piece_num = (rand() % 7) + 1;
                                clean_next_piece_map();
                                select_next_piece(next_piece_num);
                            }
                            if (!colition_down())
                            {
                                nodelay(stdscr, TRUE);
                                delayed = false;
                                Mix_PlayChannel(1, collisionSound, 0);
                                transition = 0;
                            }
                            else
                            {
                                finished = true;
                                Mix_PauseMusic();
                                Mix_PlayMusic(game_over, 0);
                                print_loose(60, 15);
                            }
                        }
                    }
                }
            }

            if (transition == 10 && !finished)
            {

                complete_line();
                clear_piece();
                center_x = 30;
                center_y = 0;
                random_piece = next_piece_num;
                select_piece(random_piece);
                insert_piece();
                print_map(random_piece);
                next_piece_num = (rand() % 7) + 1;
                clean_next_piece_map();
                select_next_piece(next_piece_num);
                nodelay(stdscr, TRUE);
                delayed = false;
                Mix_PlayChannel(1, collisionSound, 0);
                Mix_PlayChannel(2, completeline, 0);
                transition = 0;
            }

            if (currentTimeNanos - lastUpdateTime >= interval)
            {

                if (!colition_down() && !finished)
                {
                    seconds++;
                    move(2, 4);
                    printw("   ");
                    move(2, 4);
                    remove_piece();
                    center_y++;
                    insert_piece();
                    print_map(random_piece);
                    lastUpdateTime = currentTimeNanos;
                }
            }
            if (ch == 'm')
                border_map = !border_map;
            if (ch == 'c')
                colision_map = !colision_map;
            if (ch == 'p')
                piece = !piece;
            if (ch == 'f')
                background_map = !background_map;
            if (ch == ' ')
            {
                remove_piece();
                clear_piece();
                rotate_piece(random_piece);
                insert_piece();
                print_map(random_piece);
                Mix_PlayChannel(4, rotate, 0);
            }
            if (ch == 's')
            {
                num_song++;
                if (num_song > 11)
                    num_song = 1;
                switch (num_song)
                {
                case 1:

                    Mix_FreeMusic(music);
                    song = "songs/Loginska.mp3";
                    music = Mix_LoadMUS(song.c_str());
                    Mix_PlayMusic(music, -1);

                    break;
                case 2:

                    Mix_FreeMusic(music);
                    song = "songs/Bradinsky.mp3";
                    music = Mix_LoadMUS(song.c_str());
                    Mix_PlayMusic(music, -1);

                    break;
                case 3:

                    Mix_FreeMusic(music);
                    song = "songs/Kalinka.mp3";
                    music = Mix_LoadMUS(song.c_str());
                    Mix_PlayMusic(music, -1);

                    break;
                case 4:
                    Mix_FreeMusic(music);
                    song = "songs/Troika.mp3";
                    music = Mix_LoadMUS(song.c_str());
                    Mix_PlayMusic(music, -1);
                    break;
                case 5:
                    Mix_FreeMusic(music);
                    song = "songs/Technotris.mp3";
                    music = Mix_LoadMUS(song.c_str());
                    Mix_PlayMusic(music, -1);

                    break;
                case 6:
                    Mix_FreeMusic(music);
                    song = "songs/Theme A.mp3";
                    music = Mix_LoadMUS(song.c_str());
                    Mix_PlayMusic(music, -1);

                    break;
                case 7:
                    Mix_FreeMusic(music);
                    song = "songs/MSX Goblin.mp3";
                    music = Mix_LoadMUS(song.c_str());
                    Mix_PlayMusic(music, -1);

                    break;
                case 8:
                    Mix_FreeMusic(music);
                    song = "songs/Hirokazu Tanaka.mp3";
                    music = Mix_LoadMUS(song.c_str());
                    Mix_PlayMusic(music, -1);

                    break;
                case 9:
                    Mix_FreeMusic(music);
                    song = "songs/Hirokazu Tanaka 2.mp3";
                    music = Mix_LoadMUS(song.c_str());
                    Mix_PlayMusic(music, -1);

                    break;
                case 10:
                    Mix_FreeMusic(music);
                    song = "songs/Amiga Spectrum Holobyte.mp3";
                    music = Mix_LoadMUS(song.c_str());
                    Mix_PlayMusic(music, -1);
                    break;
                case 11:
                    Mix_FreeMusic(music);
                    song = "songs/Mario Link and Yohsi.mp3";
                    music = Mix_LoadMUS(song.c_str());
                    Mix_PlayMusic(music, -1);
                    break;

                default:
                    break;
                }
            }

            if (ch == KEY_DOWN)
            {
                if (!colition_down())
                {
                    remove_piece();
                    center_y++;
                    insert_piece();
                    print_map(random_piece);
                    Mix_PlayChannel(1, move_sound, 0);
                }
            }
            if (ch == KEY_RIGHT)
            {
                if (!colition_right())
                {

                    remove_piece();
                    center_x = center_x + 2;
                    insert_piece();
                    print_map(random_piece);
                    Mix_PlayChannel(1, move_sound, 0);
                }
            }
            if (ch == KEY_LEFT)
            {

                if (!colition_left())
                {
                    remove_piece();
                    center_x = center_x - 2;
                    insert_piece();
                    print_map(random_piece);
                    Mix_PlayChannel(1, move_sound, 0);
                }
            }
            if (colition_down())
            {
                type = true;
                rotation = 0;
                clock_gettime(CLOCK_MONOTONIC, &start_time);
                delayed = true;
            }
            if (lines >= 20 && lines < 40)
            {

                level = 2;
                if (initial_level < level)
                    num_song = level;
                color_map = level;
                color_piece_colition = 1;
                interval = 800000000;
            }
            if (lines >= 40 && lines < 60)
            {
                level = 3;
                if (initial_level < level)
                    num_song = level;
                color_map = level;
                color_piece_colition = 2;
                interval = 700000000;
            }
            if (lines >= 60 && lines < 80)
            {
                level = 4;
                if (initial_level < level)
                    num_song = level;
                color_map = level;
                color_piece_colition = 3;
                interval = 600000000;
            }
            if (lines >= 80 && lines < 100)
            {
                level = 5;
                if (initial_level < level)
                    num_song = level;
                color_map = level;
                color_piece_colition = 4;
                interval = 500000000;
            }
            if (lines >= 100 && lines < 130)
            {
                level = 6;
                if (initial_level < level)
                    num_song = level;
                color_map = level;
                color_piece_colition = 5;
                interval = 400000000;
            }
            if (lines >= 130 && lines < 160)
            {
                level = 7;
                if (initial_level < level)
                    num_song = level;
                color_map = level;
                color_piece_colition = 6;
                interval = 300000000;
            }
            if (lines >= 160 && lines < 200)
            {
                level = 8;
                if (initial_level < level)
                    num_song = level;
                color_map = 1;
                color_piece_colition = 7;
                interval = 200000000;
            }
            if (lines >= 200 && lines < 250)
            {
                level = 9;
                if (initial_level < level)
                    num_song = level;
                color_map = 7;
                color_piece_colition = 0;
                interval = 100000000;
            }
            if (lines >= 250 && lines < 300)
            {
                level = 10;
                if (initial_level < level)
                    num_song = level;
                color_map = 6;
                color_piece_colition = 1;
                interval = 90000000;
            }
            if (lines >= 300 && lines < 400)
            {
                level = 11;
                if (initial_level < level)
                    num_song = 11;
                color_map = 5;
                color_piece_colition = 2;
                interval = 80000000;
            }
            if (lines >= 400 && lines < 500)
            {
                level = 12;
                if (initial_level < level)
                    num_song = 1;
                color_map = 4;
                color_piece_colition = 3;
                interval = 70000000;
            }
            if (lines >= 500 && lines < 600)
            {
                level = 13;
                if (initial_level < level)
                    num_song = 2;
                color_map = 3;
                color_piece_colition = 4;
                interval = 60000000;
            }
            if (lines >= 600 && lines < 700)
            {
                level = 14;
                if (initial_level < level)
                    num_song = 3;
                color_map = 2;
                color_piece_colition = 5;
                interval = 50000000;
            }
            if (lines >= 700 && lines < 800)
            {
                level = 15;
                if (initial_level < level)
                    num_song = 4;
                color_map = 1;
                color_piece_colition = 6;
                interval = 40000000;
            }
            if (lines >= 800 && lines < 900)
            {
                level = 16;
                if (initial_level < level)
                    num_song = 5;
                color_map = 0;
                color_piece_colition = 7;
                interval = 30000000;
            }
            if (lines >= 900 && lines < 1000)
            {
                level = 17;
                if (initial_level < level)
                    num_song = 6;
                color_map = 1;
                color_piece_colition = 0;
                interval = 20000000;
            }
            if (lines >= 1000)
            {
                level = 18;
                if (initial_level < level)
                    num_song = 7;
                color_map = 2;
                color_piece_colition = 1;
                interval = 10000000;
            }

            if (num_song)
            {
                switch (num_song)
                {
                case 1:
                    song = "songs/Loginska.mp3";
                    break;
                case 2:
                    song = "songs/Bradinsky.mp3";
                    break;
                case 3:
                    song = "songs/Kalinka.mp3";
                    break;
                case 4:
                    song = "songs/Troika.mp3";
                    break;
                case 5:
                    song = "songs/Technotris.mp3";
                    break;
                case 6:
                    song = "songs/Theme A.mp3";
                    break;
                case 7:
                    song = "songs/MSX Goblin.mp3";
                    break;
                case 8:
                    song = "songs/Hirokazu Tanaka.mp3";
                    break;
                case 9:
                    song = "songs/Hirokazu Tanaka 2.mp3";
                    break;
                case 10:
                    song = "songs/Amiga Spectrum Holobyte.mp3";
                    break;
                case 11:
                    song = "songs/Mario Link and Yohsi.mp3";
                    break;
                default:
                    break;
                }
            }
            refresh();
        }
    }

    Mix_FreeChunk(collisionSound);
    Mix_FreeMusic(music);
    Mix_Quit();
    endwin();
    return 0;
};
