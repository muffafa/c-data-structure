#include <stdio.h>
#include <stdlib.h>
#define N 5
int stack[N - 1];
int top = -1;

int checkFull() {
	if (top >= N - 1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


int checkEmpty() {
	if (top < 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


int push(int item) {
	int control = checkFull();
	if (control == 0)
	{
		top = top + 1;
		stack[top] = item;
		return 0;
	}

	else
	{
		printf("Stack is full ");
		return -1;
	}
}
int pop() {
	int control = checkEmpty();
	if (control == 0)
	{
		top = top - 1;
		return stack[top];
	}
	else
	{
		printf("\n Your Stack is already empty you cant pop anything");
		return -1;
	}
}

int peek()
{
	int control = checkEmpty();
	if (control == 1)
	{
		printf("\n There is no item here");
		return 0;
	}
	return stack[top];
}

int printStack()
{
	int i;
	for (i = 0; i < top + 1; i++)
	{
		printf("%d ", stack[i]);
	}
	return top;
}

void reset() {
	top = 0;
}


int main()
{
	int choice, item;
	int a;
	while (1)
	{
		printf("\n 1- Push an item");
		printf("\n 2- Pop an item");
		printf("\n 3- Peek ");
		printf("\n 4- Reset ");
		scanf_s("%d", &choice);

		switch (choice)
		{
		case 1:
			printf("Which number do you want to add?");
			scanf_s("%d", &item);
			push(item);
			printStack();
			break;
		case 2:
			pop();
			printStack();
			break;
		case 3:
			a = peek();
			printf("Your Stack's Top element is %d", a);
			break;
		case 4:
			reset();
			break;
		}
	}
}