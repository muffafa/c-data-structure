#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct list {
	int data;
	struct list *next;
}STACK;


// GLOBAL VARIABLES
STACK *sp = NULL;  // stack pointer , shows the place for insertion and deletion
int counter = 0;	// Counter for inserted stack


void push(int data) {			// Insertion function

	STACK *temp = (STACK *)malloc(sizeof(STACK));	// Creating a new node and allocating memory to push stack
	if (temp == NULL) {
		printf("\nError, Could not allocate memory...\n");
	}
	else {
		temp->data = data;
		temp->next = sp;
		sp = temp;			// Stack pointer always shows the last inserted node
		counter++;
		printf("\nData inserted to the stack.\n\n");
	}

}

int pop() {  // Deletion function
	STACK *temp;			// temprorary stack pointer
	int data;				// to keep data
	if (sp == NULL) {  // Checks the stack
		printf("\nStack is empty.Could not retrieve the data.\n\n");
		return -1;
	}
	else {
		temp = sp;
		data = sp->data;
		sp = sp->next;		// Updates pointer
		free(temp);			// Deletes node from memory...
		counter--;			// Decreases counter
		printf("\nData --> %d\n", data);
		return data;
	}


}

void reset() {  // Reset function
	STACK *temp;		// temprorary pointer for free function
	while (sp != NULL) {
		temp = sp;
		sp = sp->next;
		free(temp);
	}
	counter = 0;		// Resets counter
	printf("\nStack is empty now.\n\n");
}

int top() { // Returns the last element inserted

	if (sp == NULL) {
		printf("\nStack is empty.\n");
	}
	else {
		printf("\nThe Last inserted data -> %d\n", sp->data);
		return (sp->data);
	}
	
}

int size() {		//Shows the number of elements stored

	return counter;
}

int isEmpty() {    // Checks the stack whether it is empty or not . If it is , it returns 1 other wise it returns 0.

	if (sp == NULL) {
		printf("\nStack is empty.\n");
		return 1;

	}
	else {
		printf("\nStack is not empty. %d elements are stored.\n\n", counter);
		return 0;
	}
	

}


int main() {

	int choice;
	int value;

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
			pop();

			break;
			case 3:
			reset();
			break;
			case 4:
			top();
			break;
			case 5:
			printf("\nThe number of elements stored -> %d \n\n\n", size());
			break;
			case 6:
			isEmpty();
			break;
			case 7:
			exit(0);
		}

	}
	return 0;
}