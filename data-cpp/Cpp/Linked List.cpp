#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct list{

		int id;
		char name[10];
		struct list *next;

}List;

List *first = NULL;
List *last = NULL;


//**************************
void insert(List *p){

	if(first!=NULL){
		last->next = p;
		p->next = NULL;
		last = p;

	}
	else {

		first = p;
		last = p;
		p->next = NULL;
	}

}


//**************************
int  displayList(){
	List *p;
	p=first;
	if(p==NULL){

		printf("No element to search!\n");
		return -1;
	}

	while(p){
		printf("%d \n",p->id);
		p = p->next;


	}
	return 0;
}	

//**************************
List *search(int key){
	List *p;
	p=first;
	while(p){

		if(p->id==key){
			return p;
		}
		else{

			p = p->next;
		}
	}

	return NULL;
}



int main(){
   
    List *A;
    A=(List *)malloc(sizeof(List));
		   
     char selection;
     printf("1-Insert\n2-Display\n3-Seach\n");
        while((selection=getchar())!='q'){
            printf("-------------------------\n");
        
            switch(selection){
                case '1':{
                    printf("Please enter an number:\n");
                    scanf("%d",&A->id);
                    insert(A);
                  
                    break;
                }

                case '2':{
                    	int result = displayList();

                    
                    break;
                }


                case '3':{
                	int key;
                	printf("Please enter number for search : \n");
                	scanf("%d",&key);
					List *result2=search(key);
					if(result2==NULL){
							printf("%d is not found!\n",key);
					}else{

						printf("%d found! ----->%d \n",key,result2->id);
							}

                 break;	
                }
                 
                default:
                    printf("Errror!\n");
                    break;
                    
            }
            printf("-----------------------\n");
            printf("1-Insert\n2-Display\n3-Seach\n");
             selection = getchar();
             A++;

        }
        
        
   
    
   

	getchar();
	return 0;
}
