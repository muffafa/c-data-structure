#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100  // Maximum size of stack


// GLOBAL VARIABLES
int Stack[MAXSIZE];
int sp = 0;  // stack index , shows the place for insertion and deletion


void push(int data) {   // Insertion function
	if (sp >= MAXSIZE) {   // Checks the stack whether it is full or not
		printf("Stack is full.Could not insert the data.\n");
	}
	else {
		Stack[sp] = data;
		sp++;
		printf("\nData inserted.\n\n");
	}

}

int pop() {  // Deletion function
	if (sp <= 0) {  // Checks the stack
		printf("\nStack is empty.Could not retrieve the data.\n\n");
		return -1;
	}
	else {
		sp--;  // Stack index shows the empty place for insertion so we have to decrease it once
		return Stack[sp];
	}

}

void reset() {  // Reset function
	sp = 0; // To reset the stack we just have to set stack index to 0.
	printf("\nStack is empty now.\n\n");
}

int top() { // Returns the index of last element

	return (sp - 1);
}

int size() {		//Shows the number of elements stored

	return sp;
}

int isEmpty() {    // Checks the stack whether it is empty or not . If it is , it returns 1 otherwise it returns 0.
	if (sp == 0) {
		return 1;
	}
	else
		return 0;

}


int main() {

	int choice;
	int value;
	int temp; // to keep poped data to display

	while (1) {
		printf("1-Push\n2-Pop\n3-Reset\n4-Top\n5-Size\n6-isEmpty\n7-Exit\n");
		scanf("%d", &choice);
		switch (choice) {
		case 1:
			printf("Enter the value for insertion : ");
			scanf("%d", &value);
			push(value);
			break;
		case 2:
			temp = pop();
			if (temp != -1) {
				printf("\nData -> %d \n\n", temp);
			}

			break;
		case 3:
			reset();
			break;
		case 4:
			if (top() < 0) {
				printf("\nStack is empty.\n\n");
			}
			else
				printf("\nThe last element inserted is %d \n\n", Stack[top()]);

			break;
		case 5:
			printf("\nThe number of elements stored -> %d \n\n\n", size());
			break;
		case 6:
			if (isEmpty() == 1) {
				printf("\nStack is empty\n\n");
			}
			else
				printf("\nStack is not empty. %d elements are stored\n\n", size());
			break;
		case 7:
			exit(0);
		}

	}

	return 0;
}