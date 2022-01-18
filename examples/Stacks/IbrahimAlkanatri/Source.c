// Stack Implementation by Array.cpp : Defines the entry point for the console application.
//
// C program for array implementation of stack 
#include <stdio.h> 
#include <stdlib.h> 
#include <limits.h> 

// A structure to represent a stack 
struct Stack
{
	int top;
	unsigned capacity;
	int* array;
};

// function to create a stack of given capacity. It initializes size of 
// stack as 0 
struct Stack* createStack(unsigned capacity)
{
	struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
	stack->capacity = capacity;
	stack->top = -1;
	stack->array = (int*)malloc(stack->capacity * sizeof(int));
	return stack;
}

// Stack is full when top is equal to the last index 
int isFull(struct Stack* stack)
{
	return stack->top == stack->capacity - 1;
}



// Stack is empty when top is equal to -1 
int isEmpty(struct Stack* stack)
{
	return stack->top == -1;
}

// Function to add an item to stack. It increases top by 1 
void push(struct Stack* stack, int item)
{
	if (isFull(stack))
		return;
	stack->array[++stack->top] = item;

}

// Function to remove an item from stack. It decreases top by 1 
int pop(struct Stack* stack)
{
	if (isEmpty(stack))
		return INT_MIN;
	return stack->array[stack->top--];
}
// Function to print the items in the stack. 
void print(struct Stack* stack)
{
	printf("Elements in the stack \n");
	while ((stack->top) >= 0)
	{
		printf("%d\n", pop(stack));
		//stack->top--; We do not need for this step because the "pop" Function does the decrement for top.
	}


}

// Driver program to test above functions 
int main()
{
	struct Stack* stack = createStack(100);

	push(stack, 10);
	push(stack, 20);
	push(stack, 30);
	pop(stack);

	push(stack, 40);
	pop(stack);
	push(stack, 50);
	push(stack, 60);


	push(stack, 70);
	push(stack, 80);
	pop(stack);
	push(stack, 90);
	pop(stack);

	print(stack);



	return 0;
}