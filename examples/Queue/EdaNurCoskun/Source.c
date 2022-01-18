#include <stdio.h>
#include <process.h>
#define N 500
int Q[N];
int front = 0, last = 0, count = 0;

int enqueue(int item) {
	if (count >= N) {
		printf("Queue is full\n");
		return -1;
	}
	else {
		Q[last] = item;
		last = (last + 1) % N;
		count++;
		return 0;
	}
}
int dequeue() {
	int item;
	if (count == 0) {
		printf("Queue is empty\n");
		return -1;
	}
	else {
		item = Q[front];
		front = (front + 1) % N;
		count--;
		return item;
	}
}
int main() {

	enqueue(1);
	enqueue(2);
	enqueue(10);
	enqueue(8);
	enqueue(15);
	enqueue(3);
	enqueue(24);
	enqueue(16);
	enqueue(35);

	if (count == 0) {
		printf("Queue is empty\n");
	}

	while (count > 0) {
		printf("%d\n", dequeue());
	}


	system("pause");
	return 0;
}