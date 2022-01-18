#include<stdio.h>
#include<stdlib.h>
#define QUEUESIZE 10
int Queue[QUEUESIZE - 1];
int frontElement = -1;
int backElement = -1;

void enQueue(int item) {
	if (backElement > 9) {
		printf("\n Your Queue is Full, please dequeue an element... ");
	}
	else {
		if (frontElement == -1) {
			frontElement = frontElement + 1;
		}

		backElement = backElement + 1;
		Queue[backElement] = item;
	}
}

void deQueue() {
	if (frontElement == -1 || frontElement > backElement) {
		printf("\n Your Queue is Already Empty, Please Enqueue an item");
	}
	else {
		frontElement = frontElement + 1;
	}

}
void reset() {
	backElement = 0;
}

void printQueue() {
	int i;
	if (frontElement == -1 || frontElement > backElement) {
		printf("\n Your Queue is Already Empty, Please Enqueue an item");
	}
	else {
		for (i = backElement; i >= frontElement; i--) {
			printf(" %d \n", Queue[i]);
		}
	}
}
int main() {
	int choice, item;
	while (1 == 1) {
		printf("\n 1- Enqueue element ...");
		printf("\n 2- Dequeue element ...");
		printf("\n 3- Reset queue ...");
		scanf_s("%d", &choice);

		switch (choice) {
		case 1:
			printf("\n Which number do you want to enqueue? ");
			scanf_s("%d", &item);
			enQueue(item);
			printQueue();
			break;
		case 2:
			deQueue();
			printQueue();
			break;
		case 3:
			reset();
			break;
		}
	}
	return 0;
}