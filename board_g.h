#include <stdio.h>

#define BOARD_S 10
int gen_board[BOARD_S][BOARD_S];
void generate_board()
{
    int i, j, number_amazon;

    for (i = 0; i <= BOARD_S - 1; i++) {
        for (j = 0; j <= BOARD_S - 1; j++) {
            gen_board[i][j] = 0;
        }
    }
    for (i = 0; i <= BOARD_S - 1; i++) {

        for (j = 0; j <= BOARD_S - 1; j++) {
            printf("%d", gen_board[i][j]);
            printf("\t");

        }
        printf("\n");
    } //llbvlbls
}
