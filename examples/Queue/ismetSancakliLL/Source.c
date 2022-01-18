#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<process.h>

struct Queue
{
	int item;
	Queue *next;
};


// GLOBAL VARIABLES.

Queue *front = NULL;
Queue *last = NULL;
int count = 0;

int enqueue(int item);
int dequeue();
int size();
bool isEmpty();
void reset();
void display();

int main()
{
	int item, choice;

	while (1)
	{
		printf("__MENU__\n");
		printf("1_Enqueue\n 2_Dequeue\n 3_Display\n 4_Size\n 5_isEmpty\n 6_Reset\n 7_Exit\n");
		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
			printf("Please Enter the data to Equeue : \n");
			scanf("%d", &item);
			enqueue(item);
			break;

		case 2:
			dequeue();
			break;

		case 3:
			display();
			break;

		case 4:
			size();
			break;

		case 5:
			isEmpty();
			break;

		case 6:
			reset();
			break;

		case 7:
			exit(0);
			break;

		default:
			printf("Enter The Number Between 1-7\n");
			break;

		}
	}
	system("pause");
	return 0;
}

int enqueue(int item)
{

	Queue *p;
	p = (Queue*)malloc(sizeof(Queue));

	if (p == NULL)
	{
		printf("Memory is full\n");
		return -1;
	}
	p->item = item;
	p->next = NULL;

	if (front == NULL) // QUEUE IS EMPTY.. INSERT THE FIRST ELEMENT. 
	{
		front = p;
		last = p;
	}
	else
	{                 // INSERT AT THE END:
		last->next = p;
		last = p;
	}
	count++;
	printf("Data succesfully added \n");
	return 0;
}

int dequeue()
{
	Queue *p;
	int data;

	if (front == NULL)
	{
		printf("Queue is empty.\n");
		return -1;
	}


	p = front;
	data = front->item;
	front = front->next;
	printf("This data is dequeded : %d\n", data);

	if (front == NULL)
	{
		last = NULL;
	}

	count--;
	free(p);
	return data;
}

int size()
{
	printf("Total element(s) in the Queue : %d\n", count);
	return count;
}

bool isEmpty()
{
	if (front == NULL)
	{
		printf("Queue is emoty \n");
		return true;
	}
	else
	{
		printf("Queue is not empty. \n");
		return false;
	}
}

void reset()
{
	Queue *p;
	p = front;

	while (p)
	{
		front = front->next;
		free(p);
		p = front;
	}
	front = NULL;
	last = NULL;
	count = 0;

	printf("The Queue is empty now.\n");
}

void display() {
	Queue *temp;
	temp = front;
	if (front == NULL) {
		printf("The Queue is empty.\n");
	}

	else {

		printf("Element(s)\n");
		while (temp) {
			printf("Data is = %d\n", temp->item);
			temp = temp->next;
		}
	}
}