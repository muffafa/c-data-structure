#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define SIZE 50

void push(int i);
int pop(void);
void yazdir();
void menuGoster();

int *enAlt,*enUst;
int yigin[SIZE];

int main()
{
	int secim;
	enAlt=yigin;
	enUst=yigin;
	
	while(1) {
		
		menuGoster();
		
		printf("Bir deger giriniz:");
		scanf("%d",&secim);
		int deger;
		
		switch(secim) {
			case 0:
				printf("Sistemden cikiliyor!\n");
				return 0;
				break;
			case 1:
				printf("\nYigina eklenecek degeri giriniz:");
				scanf("%d",&deger);
				push(deger);
				break;
			case 2:
				deger=pop();
				printf("\nYigindan alinan deger:%d",deger);
				break;
			case 3:
				yazdir();
				break;
			default:
				printf("Gecersiz secim.Gecerli bir sayi giriniz!");
				break;
				
		}
		
	}
	
	return 0;
}

void push(int i)
{
	if(enUst+1==(enAlt+SIZE)) {
		printf("Yigin dolu.Yeni eleman eklenemez!\n");
		exit(EXIT_FAILURE);
	
	}
	
	*enUst=i;
	enUst++;
}

int pop(void)
{
	if(enUst==enAlt) {
		printf("Yigin bos.Eleman cikaramazsiniz!\n");
		exit(EXIT_FAILURE);
	}
	
	enUst--;
	int deger=*enUst;
	return deger;
}

void yazdir() 
{
	printf("\n[EnAlt]\n");
	int* temp=yigin;
	
	while(temp<enUst) {
		printf("%d\n",*temp);
		temp++;
	}
	
	printf("[EnUst]");
}

void menuGoster()
{
	printf("\n----------\n   [MENU   \n----------\n]");
	printf("1.Ekle(Push) - 2.Cikar(Pop) - 3.Yazdir - 0.Cikis\n");
}
