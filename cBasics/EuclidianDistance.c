#include <stdio.h>
#include <math.h>
void getvalues(int p1[],int p2[]);
void euclidean(int p1[],int p2[]);
void printing (float dist);
int main(void) {
  int p1[2],p2[2];
  getvalues(p1, p2);
  euclidean(p1, p2);
  return 0;
}
void getvalues(int p1[],int p2[]){
    printf("Please enter a and b for P1:");
    scanf("%d %d",&p1[0],&p1[1]);
    printf("Please enter a and b for P2:");
    scanf("%d %d",&p2[0],&p2[1]);
}
void euclidean(int p1[],int p2[]){
    float dist;
    dist=sqrtf(pow(p1[0]-p2[0],2)+pow(p1[1]-p2[1], 2));
    printing(dist);
}
void printing (float dist){
    printf("the distance between P1 and P2 is %f\n",dist);
}
