#include<stdio.h>

int ardisilArama(int A[],int N,int key)
{
	int k;
	
	for(k=0;k<N;k++) {
		if(A[k]==key)
			return k;
	}
	
	return -1;
}

int main()
{
	int indis,ara,B[]={13,12,15,11,26,5,47,10,27,34};
	
	

	
	
	printf("Aranan sayi:");
	scanf("%d",&ara);

	indis=ardisilArama(B,10,ara);
	
	if(indis==-1)
		printf("Aranan sayi bulunamadi!!");
	else
		printf("Aranan sayi bulundı-----> %d indisli elemandir",indis);
	
	getchar();
	return 0;	
}
