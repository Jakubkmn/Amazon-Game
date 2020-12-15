#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct board {
	int game;
	int artif;
	int treas;

};
board tab[100][100];
void gen_board(board tab[100][100], int x, int y)
{
	int max_artif = 4;
	int max_treas = 9;
	int mini = 0;

	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
		{
			tab[i][j].game = 0;
			tab[i][j].artif = (rand() % (max_artif - mini));
			tab[i][j].treas = (rand() % (max_treas - mini));
		}
	}
}

void print_board(board tab[100][100], int x, int y)
{
	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
		{
			printf("%d ", tab[i][j].game);

		}
		printf("\n");
	}
	printf("\n");
	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
		{
			printf("%d ", tab[i][j].artif);

		}
		printf("\n");
	}
	printf("\n");
	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
		{
			printf("%d ", tab[i][j].treas);

		}
		printf("\n");
	}
}
/*void change_P(int player)
{
	if (player == 2)
	{
		player = 1;
		return player;
	}
	else if(player == 1)
	{
		player = 2;
		return player;
	}
}*/
int main()
{
	int player = 2;
	int x = 10;
	int y  = 10;
	time_t tt;
	int a;
	a = time(&tt);
	srand(a);
	int amazons = 5;
	printf(" Give board dimentions (x,y)");
	scanf_s("%d %d", &x, &y);
	
	gen_board(tab, x, y);
	print_board(tab, x, y);
	int c, b = 0;
	for (int i = 0; i < amazons; i++) 
	{

		printf("Where do you want to place amazon");
		scanf_s("%d %d", &c, &b);
			tab[c][b].game = 1;
			print_board(tab, x, y);
	}