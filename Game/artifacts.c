#include "board.h"
#include "board_move.h"
/**
 * @brief if player did not pick up any artifact
 * 
 */
void none()
{
    int vrt, hor = 0;
    int z = 0;

    do
    {
        printf("Where do you want to shoot arrow?");
        scanf("%d %d", &vrt, &hor);
        z = !taken(vrt, hor);

    } while (!z);
    tab[vrt][hor].game = 9;
}
/**
 * @brief function for shooting spear
 * 
 */
void SPEAR()
{
    int vrt, hor = 0;
    int z = 0;

    do
    {
        printf("where do you want to shoot spear? ");
        scanf("%d %d", &vrt, &hor);
        z = !taken(vrt, hor);

    } while (!z);
    tab[vrt][hor].game = 9; // the number of spear is also 9
}
/**
 * @brief function for moving horse
 * 
 * @param x current coordinate
 * @param y current coordinate
 * @param amazons number of amazons
 * @param player current player
 * @param points current points
 */
void move_H(int x, int y, int amazons, int player, int points[9])
{
    int c, b = 0;
    int ok = 0;
    int up = 1;

    do
    {
        printf("Where do you horse want to move it?\n");
        scanf("%d %d", &c, &b);

        ok = !taken(c, b);

    } while (!ok);

    tab[c][b].game = player;

    points[player] += tab[c][b].treas;
    printf("You have %d points\n", points[player]);
    tab[c][b].treas = 0;
}
/**
 * @brief function for horse
 * 
 * @param x current coordinate
 * @param y current coordinate
 * @param amazons number of amazons
 * @param player current player
 * @param points number of points
 */
void HORSE(int x, int y, int amazons, int player, int points[9])
{
    none();
    tab[x][y].game = 0;
    move_H(x, y, amazons, player, points);
}
/**
 * @brief function for artifacts
 * 
 * @param x 
 * @param y 
 * @param amazons 
 * @param player 
 * @param points 
 */
void artifacts(int x, int y, int amazons, int player, int points[9])
{

    int spear = 3;
    int arrow = 0;
    int horse = 1;
    int broken_arrow = 2;

    if (tab[x][y].artif == spear)
    {
        printf("You picked up spear \n");
        SPEAR(tab);
    }
    else if (tab[x][y].artif == horse)
    {
        printf("You picked up horse \n");
        HORSE(x, y, amazons, player, points);
    }
    else if (tab[x][y].artif == arrow)
    {
        printf("You picked up arrow \n");
        none(tab);
    }
    else if (tab[x][y].artif == broken_arrow)
    {
        printf("You picked up broken arrow \n");
    }
}