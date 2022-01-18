//ENES BERKE İNAL 2016555041

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdlib.h>
#define A 53

int Q[A];
int last = 0;

int enquee(int item) {
	printf("\n");
	if (last == A) {
		printf("Queue is full  \n");
		return -1;
	}
	else {
		Q[last] = item;
		last++;
		return 0;
	}
}

int dequeue() {
	int item, i;

	if (last == 0) {
		printf("Queue is empty\n");
		return -1;
	}
	else {
		item = Q[0];

		for (i = 0; i < last; i++)
			Q[i - 1] = Q[i];
		last--;
		printf("%d is dequeued\n\n", item);
		return item;
	}
}

void display() {
	int p;
	for (p = 0; p < last; p++)
		printf("%d  ", Q[p]);
	printf("\n");
}

void reset() {
	last = 0;
	printf("Queue is empty now \n");
}

void size() {
	printf("%d \n", last);
}

int main() {


	while (1) {

		printf(" 1-Enqueue \n 2-Dequeue \n 3-Display \n 4-Reset \n 5-Size \n 9-Exit    ");
		int a, s;
		scanf("%d", &s);

		switch (s) {

		case 1:
			scanf("   %d", &a);
			enquee(a);
			break;
		case 2:
			dequeue();
			break;
		case 3:
			display();
			break;
		case 4:
			reset();
			break;
		case 5:
			size();
			break;
		case 9:
			exit(0);
			break;
		default:
			printf("Error! operator is not correct\n");
		}
	}
	getchar(); getchar(); return 0;
}