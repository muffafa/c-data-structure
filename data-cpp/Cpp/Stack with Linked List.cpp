#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
typedef struct eleman {
	int deger;
	struct eleman *next;
}Eleman;

void push(int val,Eleman *head);
int pop(Eleman *head);

int main() {
	Eleman *baslangic,*bitis;
	int deger;
	
	baslangic=(Eleman *) malloc(sizeof(Eleman));
	bitis=(Eleman *) malloc(sizeof(Eleman));
	baslangic->next=bitis;
	
	do {
		printf("Tamsayi giriniz(cikis icin -1):");
		scanf("%d",&deger);
		
		if(deger!=-1)
			push(deger,baslangic);
			
	}while (deger!=-1);
	
	printf("Yiginin ustten alta durumu:");
	
	do {
		printf("%d\n",pop(baslangic));
		
	} while(baslangic->next!=bitis);
	
	getch();
	return 0;
	
}

void push(int val,Eleman *baslangic) {
	Eleman *eklenecek;
	eklenecek=(Eleman *) malloc(sizeof(Eleman));
	eklenecek->deger=val;
	eklenecek->next=baslangic->next;
	baslangic->next=eklenecek;
}

int pop(Eleman *baslangic) {
	Eleman *temp;
	int val=baslangic->next->deger;
	temp=baslangic->next;
	baslangic->next=baslangic->next->next;
	free(temp);
	return val;
}
