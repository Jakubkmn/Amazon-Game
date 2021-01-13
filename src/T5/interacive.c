#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct board {
	int game;
	int artif;
	int treas;
};

struct board tab[15][15];
void gen_board(struct board tab[15][15], int x, int y)
{
	int max_artif = 4;
	int max_treas = 6;
	int mini = 0;

	for (int i=0; i<=x;i++)
	{
		tab[x][i+1].game = 9;
	}
	for (int i = 0; i < y; i++)
	{	
		for (int j = 0; j < x; j++)
		{	
			
			tab[i][j].game = 0;
			tab[i][j].artif = (rand() % (max_artif - mini));
			tab[i][j].treas = (rand() % (max_treas - mini));
		}
	}
	for(int i=0;i<=x;i++)
	{
		tab[i-1][y].game = 9;
	}
}

void print_board(struct board tab[15][15], int x, int y)
{
	for (int i=0; i<x; i++)
	{
	  printf("   %d", i);
	}
	printf("\n");
	for (int i = 0; i < y; i++)
	{

		printf(" %d ",i);
		for (int j = 0; j < x; j++)
		{
	
			printf("%d", tab[i][j].treas);
			printf("%d", tab[i][j].artif);
			printf("%d ", tab[i][j].game);

		}
		printf("\n");
	}
	
}

void change_P(int *player)
{
	if (*player == 1)
	{
		*player = 2;

	}
	else
	{
		*player = 1;
	}
}

int canAmazonMove(struct board tab[15][15], int x, int y) {
    // takes coordinates of amazon on the board
    // and returns whether it can move
    int can_move = 0;
    if (tab[x-1][y-1].game == 0) { can_move = 1; }
    if (tab[x-1][y].game   == 0)   { can_move = 1; }
    if (tab[x-1][y+1].game == 0) { can_move = 1; }
    if (tab[x][y-1].game   == 0)   { can_move = 1; }
    if (tab[x][y+1].game   == 0)   { can_move = 1; }
    if (tab[x+1][y-1].game == 0) { can_move = 1; }
    if (tab[x+1][y].game   == 0)   { can_move = 1; }
    if (tab[x+1][y+1].game == 0) { can_move = 1; }

    return can_move;
}


int taken(struct board tab[15][15], int x, int y)
{
	return tab[x][y].game != 0;
}

int ruch (struct board tab[15][15], int x, int y, int player)
{
return tab[x][y].game != player;
}
void place(struct board tab[15][15], int amazons, int x, int y, int player)
{
	int c, b = 0;
	int ok = 0;
	for (int i = 0; i < amazons * 2; i++)
	{
		do {
			printf("Where do you want to place amazon ");
			scanf("%d %d", &c, &b);
			ok=!taken(tab, c, b);
			//printf("Pick other place");
		} while (!ok);
		
			tab[c][b].game = player;
	
		tab[c][b].artif = 0;// change to zero when amazon is placed
		tab[c][b].treas = 0;//change to zero when amazon is placed

		print_board(tab, x, y);
		change_P(&player);
	}


}
void none(struct board tab[15][15])
{
	int vrt, hor = 0;
	int z = 0;
	
	do {
		printf("Where do you want to shoot arrow?");
		scanf("%d %d", &vrt, &hor);
		z = !taken(tab, vrt, hor);
		
	} while (!z);
	tab[vrt][hor].game = 9;
	//need to add chcecking obstacles(also for movement)

}

void SPEAR(struct board tab[15][15])
{
	int vrt, hor = 0;
	int z = 0;

	do {
		printf("where do you want to shoot spear? ");
		scanf("%d %d", &vrt, &hor);
		z = !taken(tab, vrt, hor);

	}while(!z);
	tab[vrt][hor].game = 9;// the number of spear is also 9
	
}




void move_H(struct board tab[15][15], int x, int y, int amazons, int player, int points[9])
{
	int c, b = 0;
	int ok = 0;
	int up = 1;
	
	do {
				printf("Where do you horse want to move it?\n");
				scanf("%d %d", &c, &b);
				
				ok = !taken(tab, c, b);
				

		}while (!ok);
			
		tab[c][b].game = player;
	
		
		points[player]+=tab[c][b].treas;
		printf("You have %d points\n", points[player]);
		tab[c][b].treas=0;
		
}


void HORSE(struct board tab[15][15], int x, int y, int amazons, int player, int points[9])
{
	none(tab);
	tab[x][y].game=0;
	move_H(tab, x,y,amazons,player,points);
	
}
void artifacts(struct board tab[15][15], int x, int y, int amazons, int player, int points[9])
{
	
	int spear = 3;
	int arrow = 0;
	int horse = 1;
	int broken_arrow = 2;

	if(tab[x][y].artif == spear) {
		printf("You picked up spear \n");
		SPEAR(tab);
	} else if(tab[x][y].artif == horse) {
		printf("You picked up horse \n");
		HORSE(tab, x, y, amazons, player, points);
	} else if(tab[x][y].artif == arrow) {
		printf("You picked up arrow \n");
		none(tab);
	} else if(tab[x][y].artif == broken_arrow) {
		printf("You picked up broken arrow \n");
	} 
	
}

void move(struct board tab[15][15], int x, int y, int amazons, int player, int points[9])
{
	int c, b = 0;
	int ok = 0;
	int up = 1;
	
	do {
				printf("Where do you want to move it?\n");
				scanf("%d %d", &c, &b);
				
				ok = !taken(tab, c, b);
				

		}while (!ok);
			
		tab[c][b].game = player;

		artifacts(tab, c, b, amazons, player, points);
		tab[c][b].artif = 0;
		points[player]+=tab[c][b].treas;
		printf("You have %d points\n", points[player]);
		tab[c][b].treas=0;

}
void pick(struct board tab[15][15], int x, int y, int amazons, int player, int points[9])
{
	int c, b = 0;
	int ok = 0;
	int up = 1;
	

		do {
			printf("Give coordinates of amazon you want to move\n");
			scanf("%d %d", &c, &b);
			up = !taken(tab, c, b);
		if(tab[c][b].game == player)
		{
			continue;
		}	
		else
		{
			printf("It is not yours!!\n");
			up = 1;
		}	
		} while (up);
			tab[c][b].game = 0;
}

void movement(struct board tab[15][15], int x, int y, int amazons, int player, int points[9])
{
	int c, b = 0;
	int ok = 0;
	int up = 1;
			printf("Player %d turn!\n", player);
			pick(tab,c,b,amazons,player,points);
		move(tab,c,b,amazons,player,points);
		print_board(tab, x, y);
		
		
		
			
}



int main()
{
	int player = 1;
	int x = 10;
	int y  = 10;
	time_t tt;
	int a;
	int points[9]={0,0,0,0,0,0,0,0,0};
	a = time(&tt);
	srand(a);
	int amazons = 5; 
	printf(" Give board dimentions (x,y) ");
	scanf("%d %d", &x, &y);
	printf("How many amazons do you want?: ");
	scanf("%d", &amazons);
	
	gen_board(tab, x, y);
	print_board(tab, x, y);
	place(tab, amazons, x, y, player);
	do
	{
			movement(tab, x, y, amazons, player, points);
			change_P(&player);
	} while (1);
}