#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define maxSize 5


int Queue[maxSize];
int front = 0;
int back = 0;
int counter = 0;
void enqueue() {
	int id;
	printf("Enter your id");
	scanf("%d", &id);
	if (counter == maxSize) {//dizinin dolu olup olmadigi kontrol ediliyor
		printf("\n***\nQueue is full Please wait for dequeue\n***\n");
	}
	else {
		Queue[back%maxSize] = id;//Diziden disari tasmamasi icin mod alindi
		back++;
		counter++;
		printf("%d is added to Queue\n", id);
	}

}
void dequeue() {
	if (Queue[front%maxSize] == NULL || counter == 0) {//Kuyrukta en onde kimse yoksa kuyrukta kimse yok demektir.
		printf("\n***\nThere is no element for dequeue\n***\n");
	}
	else {
		int a = front % maxSize;
		Queue[a] = NULL;//kuyrukta en onden silme islemi
		front++;
		counter--;
		printf("Dequeue is succesful\n");
	}
}


void list() {
	if (counter == 0) {
		printf("List is empty");
	}
	else {
		for (int i = front; i < (front + counter); i++) {//back ve front hic azalmiyor. Banka veya hastane sirasi gibi isliyor.
															 //counter ise sirada kac kisi oldugunu tutuyor.
			if (Queue[i] != NULL) {
				printf("	%d", Queue[i%maxSize]);
			}

		}
	}
}
void reset() {
	for (int i = 0; i < maxSize; i++) {
		Queue[i] = NULL;
	}
	back = 0;
	front = 0;
	counter = 0;

}


int main() {

	char select = ' ';
	bool menu = true;
	reset();
	while (menu) {
		printf("\n------------------------------------\n");
		printf("Select an operation:\n");
		printf("'+' for enqueue\n'-' for dequeue \n'l' for list\n'r' for reset\n'e' for EXIT\n");
		scanf(" %c", &select);

		switch (select)
		{
			case '+': enqueue(); break;
			case '-': dequeue(); break;
			case 'r': reset(); break;
			case 'l': list(); break;
			case 'e': menu = false; break;
			default: printf("Please enter a valid key\n"); break;
		}

		//KONTROL
		printf("\nBack=	%d Front=	%d Counter=		%d\n",back,front,counter);
		for (int i = 0; i < maxSize; i++) {
			printf("	%d",Queue[i]);
		}
	}

	system("pause");
	return 0;
}