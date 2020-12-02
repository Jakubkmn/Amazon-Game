#pragma once

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