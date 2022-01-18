#include <stdio.h>
#include <string.h>

#define STACKMAXSIZE 21
#define False 0
#define True 1

int Stack[STACKMAXSIZE];
int top_of_stack = 0;

void push(int data) {
	if (top_of_stack > STACKMAXSIZE) {
		printf("Stack is full!");
	}
	else {
		// we will write the data to the top and top will be increased
		Stack[top_of_stack] = data;
		top_of_stack = top_of_stack + 1;
	}
}

int pop() {
	if (!top_of_stack) {
		printf("Stack is empty!  ");
		return -1;
	}
	return Stack[--top_of_stack];
}

void reset() {
	top_of_stack = 0;
	memset(Stack, 0, sizeof(Stack));
}

int top() {
	if (top_of_stack == 0) {
		printf("Stack is empty!  ");
		return -1;
	}
	return Stack[top_of_stack - 1];
}

int sizeOf() {
	return top_of_stack;
}

int isEmpty() {
	if (top_of_stack != 0)
		return False;
	return True;
}

int main() {
	printf("top() %d\n", top());
	printf("pop() %d\n", pop());
	printf("isEmpty() %d\n", isEmpty());
	push(33);
	push(46);
	push(59);
	printf("sizeOf() %d\n", sizeOf());
	push(72);
	printf("isEmpty() %d\n", isEmpty());
	push(4);
	printf("top() %d\n", top());
	printf("pop() %d\n", pop());
	printf("top() %d\n", top());
	reset();
	printf("reset() -> pop() %d\n", pop());
	return 0;
}