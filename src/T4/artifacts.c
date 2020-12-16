void artifacts(struct board tab[15][15], int x, int y)
{
	int spear = 1;
	int arrow = 0;
	int horse = 2;
	int broken_arrow = 3;

	if(tab[x][y].artif == spear) {
		printf("spear \n");
	} else if(tab[x][y].artif == horse) {
		printf("horse \n");
	} else if(tab[x][y].artif == arrow) {
		printf("arrow \n");
	} else if(tab[x][y].artif == broken_arrow) {
		printf("broken arrow \n");
	} 
}
