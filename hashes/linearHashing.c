#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TableSize 11
typedef struct str{
  int number;
  char name[20];

} STUDENT;

STUDENT s[TableSize];
void display();
void insert(int,char *);
void delete(int);
void init_array();
int hash_function(int);

int main()
{
  init_array();
  int choice;
  int number;
  char name[20];
  STUDENT temp;
 do{

   printf("\n 1.insert item\n2.delete item\n3.display hash table\n other for exit\nEnter your choice: ");
   scanf("%d",&choice);
   switch(choice){
     case 1:
     printf("Enter student number: ");
     scanf("%d",&number);
     printf("\n Enter student name: ");
     scanf("%s",name);
     insert(number,name);
     break;
     case 2:
     printf("Enter student number for deletion: ");
     scanf("%d",&number);
      delete(number);
      break;
     case 3:
     display();
     break;
     default:
     return 0;

   }

 }while(1);

}
void display(){
  for(int i=0;i<TableSize;i++){
    if(s[i].number==0)
    {
      printf("Hashtable[%d] is empty.\n",i);
    }
    else
    printf("Hashtable[%d] | number: %d, name: %s\n",i,s[i].number,s[i].name);
  }

}
int hash_function(int number){
  return number % TableSize;
}
void insert(int number,char * name){
  int hashPosition=hash_function(number);
  if(s[hashPosition].number==0){
    s[hashPosition].number=number;
    strcpy(s[hashPosition].name,name);
  }
  else{
    printf("\n There is a coliision.");
    int counter=1;
    while(counter<TableSize){
    hashPosition++;
    hashPosition=hashPosition % TableSize;
    if(s[hashPosition].number==0){
    s[hashPosition].number=number;
    strcpy(s[hashPosition].name,name);
    return;
    }

    counter++;
    }
  }
}
void delete(int number){
int hashPosition=hash_function(number);

 if(s[hashPosition].number==number){
   s[hashPosition].number=0;
   strcpy(s[hashPosition].name,"");
 }
 else{
   int counter=1;
    while(counter<TableSize){
    hashPosition++;
    hashPosition=hashPosition % TableSize;
    if(s[hashPosition].number==number){
    s[hashPosition].number=0;
    strcpy(s[hashPosition].name,"");
    return;
    }

    counter++;
    }

 }
}
void init_array(){
  for(int i=0;i<TableSize;i++){
    s[i].number=0;
    strcpy(s[i].name,"");
  }
}

