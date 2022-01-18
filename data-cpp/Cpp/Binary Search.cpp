#include<stdio.h>

int ikiliArama(int D[],int N,int key)
{
	int left=0;
	int middle;
	int right=N-1;
	
	while(left<=right) {
		
		middle=(left+right)/2;
		
		if(key==D[middle])
			return middle;
		
		else if(key>D[middle])
			left=middle+1;
		
		else
			right=middle-1;
		
		}
		
		return -1;
}

int main()
{
	int indis,ara,B[]={1,2,3,4,5,6,7,8,9,10};
	
	printf("Aranan sayi:");
	scanf("%d",&ara);
	
	indis=ikiliArama(B,10,ara);
	
	if(indis==-1)
		printf("Aranan sayi bulunamadi!!");
	else
		printf("Aranan sayi %d indisli elemandir",indis);
	
	getchar();
	return 0;	
}
