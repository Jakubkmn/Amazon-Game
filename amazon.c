#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define BOARD_S 10
//Global Variables
int gen_board[BOARD_S][BOARD_S];
int amazons = 7;
int PlayerNow = 1;

typedef enum
{
    none, broken_arrow, horse, arrow, spear
}artifacts;


void ARROW(int player, int gen_board[BOARD_S][BOARD_S])
{
// function shooting arrow
    printf("Player %d shot arrow\n", player);
}

void SPEAR(int player, int gen_board[BOARD_S][BOARD_S])
{
// function throwing spear
    printf("Player %d used spear\n", player);
}

void HORSE(int player, int gen_board[BOARD_S][BOARD_S])
{
// function using horse
    printf("Player %d used horse\n", player);
}

void showBoard1()
{
    //idea not completed yet
time_t tt;
    int a;
    a = time(&tt);
    srand(a);

    int b[3][10][10];
    int r = 0;
    int e = 4;
    int w = 8;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            for (int k = 0; k < 10; k++)
            {

             if (i == 0)
            {
                b[i][j][k] = 0;
            }
                if (i == 1)
            {
                b[i][j][k] = (rand() % (e - r));
            }
            if (i == 2)
            {
                b[i][j][k] = (rand() % (w - r) );
            }
        }
        }
    }
    for (int i = 0; i < 3; i++)
    {
        printf("\n");
        for (int j = 0; j < 10; j++)
        {
            printf("\n");
            for (int k = 0; k < 10; k++)
                printf("%d ", b[i][j][k]);
        }
    }

}

void showBoard(int gen_board[BOARD_S][BOARD_S])
{
 //function show board
}


void generate_board(){
    int i,j,number_amazon;

    for (i=0; i<=BOARD_S-1; i++) {
        for (j=0; j<=BOARD_S-1; j++) {
            gen_board[i][j]=0;
        }
    }
    for (i=0; i<=BOARD_S-1; i++) {

        for (j=0; j<=BOARD_S-1; j++) {
            printf("%d",gen_board[i][j]);
            printf("\t");

        }
        printf("\n");
    }
}
void place_Amazon(int player)
{
    int y, x;
    printf("Where do you want to place your amazon (y,x):\n ");
    if (scanf("%d %d", &y, &x))
    {
        while (gen_board[y][x] != 0)
        {
            printf("Invalid placement. The field is taken.\n");
            printf("Where do you want to place your amazon (y,x):\n ");
            scanf("%d %d", &y, &x);
        }
        gen_board[y][x] = player;
        printf("Player %d placed amazon\n", player);
    }
}

int MovePossible(int gen_board[BOARD_S][BOARD_S])
{
    // function checks if move is possible
    return 0;
}

void changePlaye(int *player)
{
    // function changes players
}

artifacts AmazonMove(int player, int gen_board[BOARD_S][BOARD_S])
{

   return none;
}


int main()
{
    printf("Welcome to Amazon game\n");
    generate_board(&gen_board[0]);
    printf("\n");
    printf("How many amazons do you want?: ");
    scanf("%d", &amazons);
    showBoard1();
    for (int i = 1; i<amazons; i++)
    {
        showBoard(gen_board);
        place_Amazon(1);
        showBoard(gen_board);
        place_Amazon(2);
    }
    while(1)
    {
        showBoard(gen_board);
        artifacts artifact = AmazonMove(PlayerNow, &gen_board[0]);
        switch(artifact)
        {
            case broken_arrow:
            changePlaye(&PlayerNow);
            break;
            case spear:
            SPEAR(PlayerNow, &gen_board[0]);
            changePlaye(&PlayerNow);
            break;
            case horse:
            HORSE(PlayerNow, &gen_board[0]);
            break;
            case none:
            changePlaye(&PlayerNow);
            break;
        }
    }
return 0;
}
