/*
 * Dizi kullanarak QUEUE (Kuyruk)  çalýþmasý
 * Sami HEYBET  2015556505
 */
#include <stdio.h>
#include <stdlib.h>

int Q[10];
int son = 0;


void sifirla()
{
	son = 0;
}


int enq(int veri)
{
	if (son == 10)
	{
		printf("Kuyruk Dolu, eleman eklenemez\n");
		return -1;
	}
	else
	{
		Q[son] = veri;
		son++;
		return 0;
	}

}

int deq()
{
	int veri;
	int i;

	if (son == 0)
	{
		printf("Kuyruk Bos, eleman cekilemez\n");
		return -1;
	}
	else
	{
		veri = Q[0];
		for (i = 1; i < son; i++)
		{
			Q[i - 1] = Q[i];
		}
		son--;
		return veri;
	}

}




void list()
{
	int i;
	if (son != 0)
	{

		printf("Kuyruktaki elemanlar\n");

		for (i = 0; i < son; i++)
		{
			printf("%d, ", Q[i]);
		}
		printf("\n");
	}
	else
	{
		printf("Kuyruk bos\n");
	}

}


int main()
{
	sifirla();
	enq(1);
	enq(3);
	enq(5);
	enq(7);
	enq(9);
	list();
	deq();
	list();
	deq();
	list();
	sifirla();
	list();
	return 0;
}




