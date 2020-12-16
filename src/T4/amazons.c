//program need division into libraries, however it is easier to work for me in main function (M.K.)
//scanf_s is used, because im using Visual Studio Community (M.K.)
//change player function needs work(M.K.)
// it does not distinct players yet (so every value is one)
//needs improvement and and changing loop in movement to the infinite one;
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct board {
	int game;
	int artif;
	int treas;

};
board tab[15][15];
void gen_board(board tab[15][15], int x, int y)
{
	int max_artif = 4;
	int max_treas = 6;
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

void print_board(board tab[15][15], int x, int y)
{
	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
		{
			printf("%d ", tab[i][j].game);

		}
		printf("\n");
	}
	/*printf("\n");
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
	}*/
	//we usually only need to see only first array with the game board.(M.K.)
}

void change_P(int player)
{
	if (player == 1)
	{
		player = 2;

	}
	else
	{
		player = 1;
	}
}


int taken(struct board tab[15][15], int x, int y)
{
	return tab[x][y].game != 0;
}

void place(struct board tab[15][15], int amazons, int x, int y, int player)
{
	int c, b = 0;
	int ok = 0;
	for (int i = 0; i < amazons * 2; i++)
	{
		do {
			printf("Where do you want to place amazon ");
			scanf_s("%d %d", &c, &b);
			ok=!taken(tab, c, b);
			//printf("Pick other place");
		} while (!ok);
		
			tab[c][b].game = player;
	
		tab[c][b].artif = 0;// change to zero when amazon is placed
		tab[c][b].treas = 0;//change to zero when amazon is placed

		print_board(tab, x, y);
		change_P(player);

		
	}


}

void artifacts(struct board tab[15][15], int x, int y)
{
	int spear = 1;
	int arrow = 0;
	int horse = 2;
	int broken_arrow = 3;

	if(tab[x][y].artif == spear) {
		printf("You picked up spear \n");
	} else if(tab[x][y].artif == horse) {
		printf("You picked up horse \n");
	} else if(tab[x][y].artif == arrow) {
		printf("You picked up arrow \n");
	} else if(tab[x][y].artif == broken_arrow) {
		printf("You picked up broken arrow \n");
	} 
}

void move(struct board tab[15][15],int x,int y,int amazons)
{
	int c, b = 0;
	int ok=0;
	int up = 1;
	for (int i = 0; i < amazons * 2; i++)
	{
		do {
			printf("Which give coordinates of amazon you want to move\n");
			scanf_s("%d %d", &c, &b);
			up = !taken(tab, c, b);
		} while (up);
			tab[c][b].game = 0;
		
		do {
			printf("Where do you want to move it?\n");
			scanf_s("%d %d", &c, &b);
			ok = !taken(tab, c, b);
		} while (!ok);
		tab[c][b].game = 1;
		print_board(tab, x, y);
		artifacts(tab, c, b);
		tab[c][b].artif = 0;
	}
}
int main()
{
	int player = 1;
	int x = 10;
	int y  = 10;
	time_t tt;
	int a;
	a = time(&tt);
	srand(a);
	int amazons = 5; 
	printf(" Give board dimentions (x,y) ");
	scanf_s("%d %d", &x, &y);
	printf("How many amazons do you want?: ");
	scanf_s("%d", &amazons);
	
	gen_board(tab, x, y);
	print_board(tab, x, y);
	place(tab, amazons, x, y, player);
	move(tab, x, y, amazons);

}