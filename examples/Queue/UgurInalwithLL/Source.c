#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct list {
	int data;
	struct list *next;
}QUEUE;

// GLOBAL VARIABLES

QUEUE *front = NULL;
QUEUE *rear = NULL;
int counter = 0;

int enqueue(int data);
int dequeue();
bool isEmpty();
int size();
void reset();
void display();


int main() {

	int choice, data;

	while (1) {
		printf("---------------------\n");
		printf("1.Enqueue\n2.Dequeue\n3.Display\n4.Size\n5.isEmpty\n6.Reset\n7.Exit\n");
		printf("---------------------\n");
		printf("Choose an option : ");
		scanf("%d", &choice);
		switch (choice) {
		case 1:
			printf("Enter a value to enqueue : ");
			scanf("%d", &data);
			enqueue(data);
			break;

		case 2:
			dequeue();
			break;

		case 3:
			display();
			break;

		case 4:
			size();
			break;

		case 5:
			isEmpty();
			break;

		case 6:
			reset();
			break;

		case 7:
			exit(0);
			break;

		default:
			printf("Plase enter a valid choice between 1-7\n");
			break;
		}

	}

	return 0;
}

int enqueue(int data) {

	QUEUE *temp = (QUEUE *)malloc(sizeof(QUEUE));


	if (temp == NULL) {
		printf("Error, Could not allocate memory.\n");
		return -1;
	}
	temp->data = data;
	temp->next = NULL;
	if (front == NULL) {		// If queue is empty insert at the beginning
		front = temp;
		rear = temp;
	}
	else {						// Insert at the end
		rear->next = temp;
		rear = temp;

	}

	counter++;
	printf("Data inserted to the Queue\n");
	return 1;

}

int dequeue() {

	if (front == NULL) {
		printf("The Queue is empty.\n");
		return -1;
	}

	QUEUE *temp;
	int data;
	temp = front;
	data = front->data;
	front = front->next;
	printf("Dequeued data is -> %d\n", data);

	if (front == NULL) {		// if front becomes NULL then change rear to NULL too.
		rear = NULL;
	}

	counter--;
	free(temp);
	return data;
}

bool isEmpty() {
	if (front == NULL) {
		printf("Queue is empty.\n");
		return true;
	}
	else {
		printf("Queue is not empty.\n");
		return false;
	}
}

int size() {
	printf("The Queue has %d element(s)\n", counter);
	return counter;
}

void reset() {
	QUEUE *temp;

	temp = front;
	while (temp) {
		front = front->next;
		free(temp);
		temp = front;
	}

	front == NULL;
	rear = NULL;

	counter = 0;
	printf("The Queue is empty now.\n");
}

void display() {

	if (front == NULL) {
		printf("The Queue is empty.\n");
	}

	else {
		QUEUE *temp;
		temp = front;
		printf("The Queue element(s)\n");
		while (temp) {
			printf("%d\t", temp->data);
			temp = temp->next;
		}
		printf("\n");
	}

}