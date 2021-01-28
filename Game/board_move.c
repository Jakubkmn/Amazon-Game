#include <stdio.h>
#include <stdlib.h>
#include "board.h"
#include "artifacts.c"
#include "board_move.h"

int taken(int x, int y)
{
    return tab[x][y].game != 0;
}

void place(int amazons, int player, int max_player, int board_x_max, int board_y_max)
{
    int c, b = 0;
    int ok = 0;
    for (int i = 0; i < amazons * max_player; i++)
    {
        do
        {
            printf("Player %d turn!\n", player);
            printf("Where do you want to place amazon ");
            scanf("%d %d", &c, &b);

            if ((c >= 0 && b >= 0) && (c < board_x_max && b < board_y_max))
            {
                ok = !taken(c, b);
            }

            //printf("Pick other place");
        } while (!ok);

        tab[c][b].game = player;

        tab[c][b].artif = 0; // change to zero when amazon is placed
        tab[c][b].treas = 0; //change to zero when amazon is placed

        print_board(board_x_max, board_y_max);
        change_P(&player, max_player);
    }
}

int is_in_line(int a, int b, int c, int d)
{
    int mx = 0;
    int mn = 0;

    if (a == c || b == d)
    {
        if (b == d)
        {
            if (a > c)
            {
                mx = a;
                mn = c;
            }
            else
            {
                mx = c;
                mn = a;
            }

            for (int i = mn + 1; i <= mx; i++)
            {
                if (tab[i][b].game != 0)
                    return 0;
            }
        }
        else
        {
            if (b > d)
            {
                mx = b;
                mn = d;
            }
            else
            {
                mx = d;
                mn = b;
            }

            for (int i = mn + 1; i <= mx; i++)
            {
                if (taken(a, i) != 0)
                    return 0;
            }
        }
        return 1;
    }

    return 0;
}

int is_diagonal(int a, int b, int c, int d)
{
    if (c - a == d - b)
    {
        int xmax, xmin;
        int ymax, ymin;

        int mx2;

        if (c > a)
        {
            xmax = c;
            xmin = a;
        }
        else
        {
            xmax = a;
            xmin = c;
        }
        if (d > b)
        {
            ymax = d;
            ymin = b;
        }
        else
        {
            ymax = b;
            ymin = d;
        }

        for (int i = xmin + 1; i <= xmax; i++)
        {
            for (int j = ymin + 1; j <= ymax; j++)
            {
                if (taken(i, j))
                    return 0;
            }
        }

        return 1;
    }

    return 0;
}

int can_move(int from_x, int from_y, int to_x, int to_y)
{
    if (is_in_line(from_x, from_y, to_x, to_y) || is_diagonal(from_x, from_y, to_x, to_y))
        return 1;

    return 0;
}

void movement(int amazons, int player, int points[9], int board_x_max, int board_y_max)
{
    int up = 1;
    int start_x;
    int start_y;
    int end_x;
    int end_y;

    printf("Player %d turn!\n", player);
    do
    {
        printf("Give coordinates of amazon you want to move\n");
        scanf("%d %d", &start_x, &start_y);

        up = !taken(start_x, start_y);
        if (tab[start_x][start_y].game == player)
        {
            break;
        }
        else
        {
            printf("It is not yours!!\n");
            up = 1;
        }
    } while (1);

    do
    {
        printf("Where do you want to move it?\n");
        scanf("%d %d", &end_x, &end_y);

        int mozliwosc_ruchu = 0;

        if ((end_x >= 0 && end_x < board_x_max) && (end_y >= 0 && end_y < board_y_max))
        {
            mozliwosc_ruchu = can_move(start_x, start_y, end_x, end_y);
        }

        if (mozliwosc_ruchu == 1)
            break;
    } while (1);

    tab[start_x][start_y].game = 0;

    tab[end_x][end_y].game = player;
    artifacts(end_x, end_y, amazons, player, points);
    tab[end_x][end_y].artif = 0;
    points[player] += tab[end_x][end_y].treas;
    printf("You have %d points\n", points[player]);
    tab[end_x][end_y].treas = 0;
    print_board(board_x_max, board_y_max);
}

void change_P(int *player, int max_player)
{
    if (*player < max_player)
    {
        *player += 1;
    }
    else
    {
        *player = 1;
    }
}

int canAmazonMove(struct board tab[15][15], int x, int y)
{
    // takes coordinates of amazon on the board
    // and returns whether it can move
    int can_move = 0;
    if (tab[x - 1][y - 1].game == 0)
    {
        can_move = 1;
    }
    if (tab[x - 1][y].game == 0)
    {
        can_move = 1;
    }
    if (tab[x - 1][y + 1].game == 0)
    {
        can_move = 1;
    }
    if (tab[x][y - 1].game == 0)
    {
        can_move = 1;
    }
    if (tab[x][y + 1].game == 0)
    {
        can_move = 1;
    }
    if (tab[x + 1][y - 1].game == 0)
    {
        can_move = 1;
    }
    if (tab[x + 1][y].game == 0)
    {
        can_move = 1;
    }
    if (tab[x + 1][y + 1].game == 0)
    {
        can_move = 1;
    }

    return can_move;
}

int ruch(struct board tab[15][15], int x, int y, int player)
{
    return tab[x][y].game != player;
}