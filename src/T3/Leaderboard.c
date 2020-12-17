#include <stdio.h>
#define SIZE 2

typedef struct
{
  char name[20];
  int score;
}player;

int main()
{
  int i, j, sorted;
  player temp;
  player p[SIZE]={
  {"player1", 25, 80},
  {"player2", 55, 21}};

  printf("\n\n");

  //simple bubble sort
  sorted=0;        //set up the while loop to start and to
  while(!sorted) {
    sorted = 1;    //detect when no more swaps are being made
    for(i=0;i<SIZE-1;i++) {
      if(p[i].score < p[i+1].score) {
        sorted = 0;
        temp=p[i];
        p[i] = p[i+1];
        p[i+1] = temp;
      }
    }
  }
  //show the order of the actual data:
  printf("Players in sorted order: \n\n");
  for(i=0;i<SIZE;i++) {
    printf("%20s  %3d  %2d\n", p[i].name,p[i].score);
  }
  printf("\n\n\t\t\t     Press enter to exit");
  (void) getchar();
  return 0;
}
