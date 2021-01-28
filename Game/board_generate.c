#include <stdio.h>
#include <stdlib.h>
#include "board.h"
#include "board_generate.h"

/**
 * @brief function generates board 
 * 
 * @param board_x_max 
 * @param board_y_max 
 */
void gen_board(int board_x_max, int board_y_max)
{
    int max_artif = 4;
    int max_treas = 6;
    int mini = 0;

    for (int i = 0; i < board_y_max; i++)
    {
        for (int j = 0; j < board_x_max; j++)
        {
            tab[i][j].game = 0;
            tab[i][j].artif = (rand() % (max_artif - mini));
            tab[i][j].treas = (rand() % (max_treas - mini));
        }
    }
}
/**
 * @brief function for printing board
 * 
 * @param board_x_max 
 * @param board_y_max 
 */
void print_board(int board_x_max, int board_y_max)
{
    printf("  ");
    for (int i = 0; i < board_x_max; i++)
    {
        printf(" ");
        if (i < 10)
            printf("  %d", i);
        else
            printf(" %d", i);
    }

    printf("\n");
    for (int i = 0; i < board_y_max; i++)
    {
        if (i < 10)
            printf("  %d ", i);
        else
            printf(" %d ", i);
        for (int j = 0; j < board_x_max; j++)
        {

            printf("%d", tab[i][j].treas);
            printf("%d", tab[i][j].artif);
            printf("%d ", tab[i][j].game);
        }
        printf("\n");
    }
}