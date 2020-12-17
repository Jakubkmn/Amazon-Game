void artifacts(struct board tab[15][15], int x, int y)
{
	int spear = 1;
	int arrow = 0;
	int horse = 2;
	int broken_arrow = 3;

	if(tab[x][y].artif == spear) {
		printf("You have picked up spear \n");
	} else if(tab[x][y].artif == horse) {
		printf("You have picked up horse \n");
	} else if(tab[x][y].artif == arrow) {
		printf("You have picked up arrow \n");
	} else if(tab[x][y].artif == broken_arrow) {
		printf("You have picked up broken arrow \n");
	} 
}

void SPEAR(struct board tab[15][15])
{
	int vrt, hor = 0, diag = 0;
	int z = 0;

	do {
		printf("where do you wan to shoot spear? ");
		scanf("%d %d", &vrt, &hor, &diag);
		z = !taken(tab, vrt, hor);

	}while(!z);
	tab[vrt][hor].game = 5;
} // implement diagonally shooting
