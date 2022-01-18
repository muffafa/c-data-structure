/*
 * Linked List kullanarak STACK  çalýþmasý
 * Sami HEYBET  2015556505
 */
#include <stdio.h>
#include <stdlib.h>

struct node
{
	int info;
	struct node *ptr;
}*llist, *temp;

void push(int data);
void pop();
int top();
void reset();
void display();
void stack_size();
void create();
int isEmpty();


int sp = 0;

void main()
{
	int no, ch;

	printf("\n 1 - Push To Stack");
	printf("\n 2 - Pop From Stack");
	printf("\n 3 - Top");
	printf("\n 4 - IsEmpty");
	printf("\n 5 - List of Stack");
	printf("\n 6 - Stack Element Count");
	printf("\n 7 - Clear Stack");
	printf("\n 8 - Exit");

	create();

	while (1)
	{
		printf("\n Enter choice : ");
		scanf("%d", &ch);

		switch (ch)
		{
		case 1:
			printf("Enter data : ");
			scanf("%d", &no);
			push(no);
			break;
		case 2:
			pop();
			break;
		case 3:
			if (sp == 0)
				printf("No elements in stack");
			else
			{
				printf("\n Top element : %d", top());
			}
			break;
		case 4:
			isEmpty();
			break;
		case 5:
			display();
			break;
		case 6:
			stack_size();
			break;
		case 7:
			reset();
			break;
		case 8:
			exit(0);
		default:
			printf(" Wrong choice, Please enter correct choice  ");
			break;
		}
	}
}




void create()
{
	sp = 0;
	llist = NULL;
}

void push(int data)
{
	if (llist == NULL)
	{
		llist = (struct node *)malloc(1 * sizeof(struct node));
		llist->ptr = NULL;
		llist->info = data;
	}
	else
	{
		temp = (struct node *)malloc(1 * sizeof(struct node));
		temp->ptr = llist;
		temp->info = data;
		llist = temp;
	}
	sp++;
}


void pop()
{
	temp = llist;

	if (temp == NULL)
	{
		printf("\n Error : Trying to pop from empty stack");
		return;
	}
	else
		temp = temp->ptr;
	printf("\n Popped value : %d", llist->info);
	free(llist);
	llist = temp;
	sp--;
}


int top()
{
	return(llist->info);
}


int isEmpty()
{
	if (llist == NULL)
	{
		printf("\n Stack is empty");
		return 1;
	}
	else
	{
		printf("\n Stack is not empty with %d elements", sp);
		return 0;
	}
}


void display()
{
	temp = llist;

	if (temp == NULL)
	{
		printf("Stack is empty");
		return;
	}

	while (temp != NULL)
	{
		printf("%d ", temp->info);
		temp = temp->ptr;
	}
}


void stack_size()
{
	printf("\n No. of elements in stack : %d", sp);
}


void reset()
{
	temp = llist;

	while (temp != NULL)
	{
		temp = llist->ptr;
		free(llist);
		llist = temp;
		temp = temp->ptr;
	}
	free(temp);
	llist = NULL;

	printf("\n All stack elements deleted");
	sp = 0;
}
