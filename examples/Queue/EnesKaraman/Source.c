#include<stdio.h>
#include<stdbool.h>


int rear = -1, front = -1;
#define SIZE 50
int queue[SIZE];

bool isEmpty()
{
	if (front < 0)return true;
	else return false;
}

bool isFull()
{
	if (rear < SIZE)return false;
	else return true;
}

void add(int data)
{
	if (!isFull())
	{
		if (isEmpty())front++;
		rear++;
		queue[rear] = data;
	}
	else printf("\nQueue is Full\n");
}

int dadd()
{
	int frontdata;
	frontdata = queue[front];
	front++;
	if (front == rear + 1)front = -1;
	return frontdata;
}

void showAll()
{
	int i;
	for (i = front; i < rear + 1; i++)
	{
		printf("%d    ", queue[i]);
	}
}

int main()
{
	char menu = 'a';
	int data;
	printf("1-Queue\n2-Dequeue\n3-Show front\n4-Show rear\n5-Show all\n6-Reset\n0 to exit\n");

	do
	{
		if (menu != '\n')printf("\nChoice?   ");
		scanf_s("%c", &menu);
		switch (menu)
		{
		case '1':
			printf("\nInsert data : ");
			while (1)
			{
				if (scanf_s("%d", &data) != 1)
				{
					printf("Enter an integer: ");
					int c;
					while ((c = getchar()) != EOF && c != '\n');
				}
				else break;
			}
			add(data);
			//	printf("1-Queue\n2-Dequeue\n3-Show front\n4-Show rear\n5-Show all\n6-Reset\n0 to exit\n");
			break;
		case '2':
			if (!isEmpty()) printf("%d", dadd());
			else printf("Queue is empty\n");
			break;
		case '3':
			if (!isEmpty()) printf("Front--> %d", queue[front]);
			else printf("Queue is empty\n");
			break;
		case '4':
			if (!isEmpty()) printf("Rear--> %d", queue[rear]);
			else printf("Queue is empty\n");
			break;
		case '5':
			if (!isEmpty()) showAll();
			else printf("Queue is empty\n");
			break;
		case '6':
			rear = -1;
			front = -1;
			printf("\n\nReset\n\n\n\n\n");
			printf("1-Queue\n2-Dequeue\n3-Show front\n4-Show rear\n5-Show all\n6-Reset\n0 to exit\n");
			break;
		case '0':
			break;
		case '\n':
			break;
		default:
			printf("Wrong choice");
			break;
		}

	} while (menu != '0');
	return 0;
}