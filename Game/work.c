#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "board_generate.h"
#include "board_move.h"
#include "board.h"

int points[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};

int board_x_max = 10;
int board_y_max = 10;
/**
 * @brief main function which handles all the files
 * @note calls to functions change_P, gen_board, place, print_board, movement
 * 
 * @return int 
 */
int main()
{
    int player = 1;
    int amazons = 5;
    int max_player = 8;

    time_t tt;
    int a;

    a = time(&tt);
    srand(a);

    printf("How many players are going to play? ");
    scanf("%d", &max_player);
    printf("\nGive board dimentions (x,y) ");
    scanf("%d %d", &board_x_max, &board_y_max);

    printf("\nHow many amazons do you want? ");
    scanf("%d", &amazons);

    gen_board(board_x_max, board_y_max);
    print_board(board_x_max, board_y_max);
    place(amazons, player, max_player, board_x_max, board_y_max);
    do
    {
        movement(amazons, player, points, board_x_max, board_y_max);
        change_P(&player, max_player);
    } while (1);
}