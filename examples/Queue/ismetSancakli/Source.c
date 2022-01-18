#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<process.h>

#define Max_Size 500

// GLOBAL VARIABLES
int Q[Max_Size];
int count = 0;
int front = 0;
int last = 0;

void enqueue(int item);
int dequeue();
bool isFull();
bool isEmpty();
int size();
void reset();
void display();

int main()
{
	int data, choice;
	while (1)
	{
		printf("\n");
		printf("MENU\n");
		printf("1_Enqueue\n 2_Dequeue\n 3_Size\n 4_Display\n 5_Reset\n 6_isFull\n 7_isEmpty\n 8_Exit\n");
		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
			printf("Enter a value : \n");
			scanf("%d", &data);
			enqueue(data);
			break;

		case 2:
			dequeue();
			break;

		case 3:
			size();
			break;

		case 4:
			display();
			break;

		case 5:
			reset();
			break;

		case 6:
			isFull();
			break;

		case 7:
			isEmpty();
			break;

		case 8:
			exit(0);
			break;

		default:
			printf("This is wrong choice. Please enter a valid value \n ");
			break;
		}

	}

	system("pause");
	return 0;
}

void enqueue(int item)
{
	if (count >= Max_Size)
		printf("Queue is full\n");

	else
	{
		Q[last] = item;
		last = (last + 1) % Max_Size;
		count++;
		printf("item is inserted to the Queue.\n");
	}
}

int dequeue()
{
	int item;
	if (count == 0)
	{
		printf("Queue is empty\n");
		return -1;
	}
	else
	{
		item = Q[0];
		front = (front + 1) % Max_Size;
		count--;
		return item;
	}
}

bool isFull()
{
	if (count >= Max_Size) {
		printf("Queue is full.\n");
		return true;
	}
	else {
		printf("Queue is not full.\n");
		return false;
	}
}

bool isEmpty()
{
	if (count <= 0) {
		printf("Queue is empty.\n");
		return true;
	}
	else {
		printf("Queue is not empty.\n");
		return false;
	}
}

int size()
{
	printf("The Queue has %d element(s)\n", count);
	return count;
}

void reset()
{
	count = 0;
	front = 0;
	last = 0;
	printf("Queue is empty now.\n");
}

void display()
{
	int item = front;

	if (count <= 0)
	{
		printf("The Queue is empty.\n");
	}
	else
	{
		printf("The Queue element(s).\n");
		while (item < last)
		{
			printf("%d\n", Q[item]);
			item++;
		}
	}
}