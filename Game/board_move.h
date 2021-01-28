#ifndef BOARD_MOVE_H
#define BOARD_MOVE_H
#include "board_generate.h"
int taken(int x, int y);
void place(int amazons, int player, int max_player, int board_x_max, int board_y_max);
void change_P(int *player, int max_player);
void movement(int amazons, int player, int points[9], int board_x_max, int board_y_max);
#endif