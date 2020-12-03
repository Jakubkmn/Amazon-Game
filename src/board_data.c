// ConsoleApplication9.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
void board()
{
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
                printf("%d ", b[0][j][k]);
        } 
    }
}
void show_game()
for(j=0;j<10;j++)
int main()
{
    //board();
}

