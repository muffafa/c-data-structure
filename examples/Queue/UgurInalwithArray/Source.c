#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXSIZE 100  // Max size of Queue

// GLOBAL VARIABLES

int Queue[MAXSIZE];
int front = 0;
int rear = 0;
int counter = 0;

void enqueue(int data);
int dequeue();
bool isFull();
bool isEmpty();
int size();
void reset();
void display();


int main() {

	int choice, data;

	while (1) {
		printf("---------------------\n");
		printf("1.Enqueue\n2.Dequeue\n3.Display\n4.Size\n5.isFull\n6.isEmpty\n7.Reset\n8.Exit\n");
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
			isFull();
			break;

		case 6:
			isEmpty();
			break;

		case 7:
			reset();
			break;

		case 8:
			exit(0);
			break;

		default:
			printf("Plase enter a valid choice between 1-8\n");
			break;
		}

	}

	return 0;
}

void enqueue(int data) {

	if (counter >= MAXSIZE) {
		printf("Stack is full.Couldn't insert data to the queue.\n");
	}
	else {
		Queue[rear] = data;
		rear = (rear + 1) % MAXSIZE;		// Ensure The rear never crosses the bounds of array
		counter++;
		printf("%d is inserted to the Queue.\n", data);
	}
}

int dequeue() {

	if (counter <= 0) {
		printf("Stack is empty.\n");
		return -1;
	}
	else {
		int temp;
		temp = Queue[front];
		front = (front + 1) % MAXSIZE;		// Ensure The front never crosses the bounds of array
		counter--;
		printf("Data is --> %d\n", temp);
		return temp;
	}

}

bool isFull() {
	if (counter >= MAXSIZE) {
		printf("Stack is full.\n");
		return true;
	}
	else {
		printf("Stack is not full.\n");
		return false;
	}
}

bool isEmpty() {
	if (counter <= 0) {
		printf("Stack is empty.\n");
		return true;
	}
	else {
		printf("Stack is not empty.\n");
		return false;
	}
}

int size() {
	printf("The Queue has %d element(s)\n", counter);
	return counter;
}

void reset() {
	front = 0;
	rear = 0;
	counter = 0;
	printf("The Queue is empty now.\n");
}

void display() {

	if (counter <= 0) {
		printf("The Queue is empty.\n");
	}
	else {
		int temp = front;
		printf("The Queue element(s)\n");
		while (temp < rear) {
			printf("%d\t", Queue[temp]);
			temp++;
		}
		printf("\n");
	}

}