// Queue Implementation By Static Array.cpp : Defines the entry point for the console application.
// C program for  static array implementation of queue 
#include <stdio.h> 
#include <stdlib.h> 

#define capacity 5 

int Queue[capacity];

int front = 0;

int rear = 0;

// Function to insert an item to the queue.
void insert()
{
	if (capacity == rear)
	{
		printf("Queue is full \n");
	}
	else
	{

		int item;
		scanf_s("%d", &item);
		Queue[rear] = item;
		rear++;
	}
}
// Function to delete an item from the front of the queue.
void delet()
{
	if (front == rear)
	{
		printf("Queue is Empty \n");
	}
	else
	{
		printf("Deleted item is : %d", Queue[front]);
		for (int i = 0; i < rear; i++)
		{
			Queue[i] = Queue[i + 1];

		}
		rear = rear - 1;

	}
}
//Function to print the queue.
void display() {
	if (front == rear)
	{
		printf("Queue is Empty \n");
	}
	else
	{
		printf("The Items in Queue are:\n");
		for (int i = front; i < rear; i++)
		{
			printf("%d   ", Queue[i]);


		}
		printf("\n");
	}
}


int main()
{
	int s;
	while (1)
	{

		printf("1.insert \n");
		printf("2.delete \n");
		printf("3.show \n");
		printf("4.Quit \n");
		printf("Enter your choice :");
		scanf_s("%d", &s);
		switch (s)
		{
		case 1:
			printf("Enter the item. \n");

			insert();
			break;
		case 2:
			delet();
			break;
		case 3:
			display();
			break;
		case 4:
			exit(0);

		default: printf("Invalid input \n\n");


		}
	}


	return 0;

}
