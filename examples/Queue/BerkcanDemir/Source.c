#include<stdio.h>
#include<stdlib.h>

#define N 10


int Q[N];
int last;
int j;


int main()
{

	int choice;



	do {

		menu();
		if (scanf("%d", &choice) == 1)
		{


			switch (choice)
			{
			case 1:
				enqueue();
				break;
			case 2:
				dequeue();
				break;
			case 3:
				reset();
				break;
			case 4:
				display();
				break;
			case 0:
				exit(0);
				break;
			default:
				printf("Unknown operation\n");
				break;

			}
		}
		else {
			printf("wrong choice\n");
			return 0;
		}


	} while (1);

	return 0;
}






int enqueue(int item)
{
	if (last == N)
	{
		printf("Queue is full\n");
		return -1;
	}
	else
	{
		scanf("%d", &item);
		Q[last] = item;
		last++;
		return 0;
	}

}


int dequeue()
{
	int item, i;
	if (last == 0)
	{
		printf("Queue is empty\n");
		return -1;
	}
	else
	{
		item = Q[N];

		for (i = 1; i < last; i++)
		{
			Q[i - 1] = Q[i];

		}
		last--;
		return item;
	}
}


void reset()
{
	last = 0;
}

void menu()
{
	printf("1.Enqueue\n"),
		printf("2.Dequeue\n");
	printf("3.Reset\n");
	printf("4.Show the queue\n");
	printf("0.Exit\n");
	printf("Enter your choice:");
}

void display()
{
	if (last == 0)
	{
		printf("Queue is empty\n");
		return -1;
	}
	else
	{
		for (j = 0; j < last; j++)
		{
			printf("%d\n", Q[j]);
		}
	}
}