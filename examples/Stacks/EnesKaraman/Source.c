#include<stdio.h>
#include<stdbool.h>

int top = -1;
#define SIZE 50
int stack[SIZE];

bool isFull()
{
	if (top < SIZE)return false;
	else return true;
}

bool isEmpty()
{
	if (top < 0)return true;
	else return false;
}

void push(int data)
{
	if (!isFull())
	{
		top = top + 1;
		stack[top] = data;
	}
	else printf("Stack is full\n");
}

int pop()
{
	int data;
	data = stack[top];
	top--;
	return data;
}
int peek()
{
	return stack[top];
}

int main()
{
	int menu;
	int data = 1;
	do
	{
		printf("-----------------------------------------------------------------\n1-Add to stack(push)\n2-Remove and show element(pop)\n3-Show element without removing(peek) -1 to exit");
		scanf_s("%d", &menu);

		switch (menu)
		{
		case 1:
			printf("Insert data\n");
			scanf_s("%d", &data);
			push(data);
			//printf("\npushed data= %d \n",stack[top]);
			break;
		case 2:
			if (!isEmpty())printf("%d\n", pop());
			else printf("Stack is Empty\n");
			break;
		case 3:
			if (!isEmpty())printf("%d\n", peek());
			else printf("Stack is Empty\n");
			break;
		case -1:
			printf("out");
			break;
		}
	} while (menu != -1);
}