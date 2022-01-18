#include <stdio.h>
#include<stdlib.h>


struct stack
{
	int data;
	struct stack *ptr;
};

typedef struct stack Stack;
typedef Stack *stackPtr;


void push(stackPtr *top, int x);
int pop(stackPtr *top);
int checkEmpty(stackPtr top);
void printValue(stackPtr showPtr);

int main()
{
	stackPtr stackNewPtr = NULL;
	int option;
	int value;


	printf("\nPlease choose following options:\n");
	printf("1. PUSH\n");
	printf("2. POP\n");
	printf("3. EXIT\n");

	scanf_s("%d", &option);

	while (option != 3)
	{
		switch (option)
		{
		case 1:
			printf("\nEnter value: ");
			scanf_s("%d", &value);
			push(&stackNewPtr, value);
			printValue(stackNewPtr);
			break;

		case 2:
			if (!checkEmpty(stackNewPtr))
			{
				printf("\nPopped Value: %d\n", pop(&stackNewPtr));
			}
			printValue(stackNewPtr);
			break;

		default:
			puts("\n**Invalid choice**");
			break;
		}

		printf("\nWhat do you want: ");
		scanf_s("%d", &option);
	}
}


void push(stackPtr *top, int x)
{
	stackPtr nodePtr;


	nodePtr = malloc(sizeof(Stack));


	if (nodePtr != NULL)
	{
		nodePtr->data = x;
		nodePtr->ptr = *top;
		*top = nodePtr;
	}

	else
		printf("\nERROR !!! (Not enough space)");
}


int pop(stackPtr *top)
{
	int pValue;
	stackPtr tempPtr;

	tempPtr = *top;
	pValue = (*top)->data;
	*top = (*top)->ptr;
	free(tempPtr);
	return pValue;
}


void printValue(stackPtr showPtr)
{
	if (showPtr == NULL)
	{
		printf("\n**No value found.**");
	}
	else
	{
		printf("\nData stored in stack:\n");

		while (showPtr != NULL)
		{
			printf("%d --> ", showPtr->data);
			showPtr = showPtr->ptr;
		}
		printf("NULL\n");
	}
}

int checkEmpty(stackPtr top)
{
	getch();
	return top == NULL;
}