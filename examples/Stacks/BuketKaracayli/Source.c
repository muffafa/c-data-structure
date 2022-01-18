#include<stdio.h>
#define MAX_SIZE 101
int D[MAX_SIZE];
int top = -1;

void Push(int data) {
	if (top == MAX_SIZE - 1)
		printf("ERROR: Stack is owerflow\n");
	D[++top] = data;
}

void Pop() {
	if (top == 1)
		printf("ERROR: No element to pop.\n");
	top--;
}

void Top() {
	D[top];

}

void Print() {
	printf("Stack: ");
	for (int i = 0; i <= top; i++)
		printf("%d ", D[i]);
	printf("\n");
}
int main() {

	Push(19); Print();
	Push(8); Print();
	Push(33); Print();
	Pop(); Print();
	Push(2018); Print();
	Push(89); Print();

	getchar();
	return 0;
}