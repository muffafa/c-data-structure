#include<stdio.h>

#include<stdlib.h>

#include<string.h>







typedef struct QUEUE {

	int element;

	struct  QUEUE *next;

}QUEUE;



QUEUE *first = NULL;

QUEUE *last = NULL;



int Enqueue(int element) {



	QUEUE *qp;

	qp = (QUEUE *)malloc(sizeof(QUEUE));

	if (qp == NULL) {

		printf("Not enough memory\n");

		return 0;

	}



	qp->element = element;

	qp->next = NULL;





	if (first == NULL) {

		first = qp;

		last = qp;



	}

	else {

		last->next = qp;

		last = qp;

	}



	return element;

}



int Dequeue() {

	QUEUE *qp;

	int element;



	if (first == NULL) {

		last = NULL;



		return -1;

	}



	qp = first;

	first = first->next;

	element = qp->element;

	//free(qp);

	return element;

}

void Reset() {

	QUEUE *temp;

	if (first == NULL) {

		printf("Queue already is empty\n");

	}

	else {

		do {

			temp = first;

			first = first->next;

			free(temp);







		} while (first != NULL);

		last = NULL;

		printf("reset all elements\n");

	}

}

void Display() {



	QUEUE *temp = NULL;

	temp = first;

	if (first == NULL) {

		printf("Queue is empty\n");

	}

	else {

		do {

			printf("%d  ", temp->element);

			temp = temp->next;



		} while (temp != NULL);

	}



}



int main()

{

	char choice;

	int item;

	while (1) {

		printf("\nMENU\n 1)Enqueue\n 2)Dequeue\n 3)Reset\n 4)Display\n 5)Exit\n");

		scanf_s(" %c", &choice);

		switch (choice) {

		case '1':

			printf("insert a new item:");

			scanf_s("%d", &item);



			item = Enqueue(item);

			printf("%d added to the queue\n", item);

			break;

		case '2':

			item = Dequeue();

			if (item == -1) {

				printf("Queue is empty\n");

			}

			else {

				printf("%d deleted from the front of the queue\n", item);

			}

			break;

		case '3':

			Reset();



			break;

		case '4':Display(); break;

		case '5':exit(-1); break;

		default:

			printf("you entered wrong character\n"); break;

		}

	}

	return 0;

}