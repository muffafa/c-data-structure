#include <stdio.h>
#include <stdlib.h>

//Hash table size
#define max 10
int ht[max];

void insert();
void display();
void main()
{
    for (int i = 0; i < max; i++)
        ht[i] = -1;
    printf("1. Insert\n2, Display\n3. Exit");
    int n;
    while (1)
    {
        printf("\nEnter your choice: ");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            insert();
            break;
        case 2:
            display();
            break;
        case 3:
            exit(0);
        default:
            printf("Wrong choice\n");
        }
    }
}

void display(){
    for(int i=0;i<max;i++){
    if(ht[i]==-1)
    {
      printf("Hashtable[%d] is empty.\n",i);
    }
    else
    printf("Hashtable[%d] number: %d,\n",i,ht[i]);
  }
}

void insert(){
    int number;
    printf("\nEnter the number: ");
    scanf("%d",&number);

    int hashPosition = number%max;

    if(ht[hashPosition] == -1){ //position is empty
        ht[hashPosition] = number;
    }else{ //position is not empty
        if(ht[hashPosition] == number){
            printf("\nThis element already exist");
        }else{ //check is there any empty space?
            printf("\nThere is a coliision.");
            int counter = 1;
            while(counter < max){
            hashPosition++;
            hashPosition = hashPosition % max;
            if(ht[hashPosition] == -1){
                ht[hashPosition] = number;
                return;
            }
            counter++;
            }
        }
    }
}
