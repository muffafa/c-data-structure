
/* Program to implement a queue using one user defined stack
and one Function Call Stack */
#include <stdio.h> 
#include <stdlib.h> 

/* structure of a stack node */
struct sNode {
	int data;
	struct sNode* next;
};

/* structure of queue having two stacks */
struct queue {
	struct sNode* stack1;
};

/* Function to push an item to stack*/
void push(struct sNode** top_ref, int new_data)
{
	/* allocate node */
	struct sNode* new_node = (struct sNode*)malloc(sizeof(struct sNode));

	/* put in the data */
	new_node->data = new_data;

	/* link the old list off the new node */
	new_node->next = (*top_ref);

	/* move the head to point to the new node */
	(*top_ref) = new_node;
}

/* Function to pop an item from stack*/
int pop(struct sNode** top_ref)
{
	int res;
	struct sNode* top;

	/*If stack is empty then error */
	if (*top_ref == NULL) {
		printf("Stack underflow \n");
		return -1;
	}
	else {
		top = *top_ref;
		res = top->data;
		*top_ref = top->next;
		free(top);
		return res;
	}
}

/* Function to enqueue an item to queue */
void enQueue(struct queue* q, int x)
{
	push(&q->stack1, x);
}

/* Function to deQueue an item from queue */
int deQueue(struct queue* q)
{
	int x, res;

	/* If both stacks are empty then error */
	if (q->stack1 == NULL) {
		printf("Q is empty");
		return -1;
	}/* only one element is present pop that one*/
	else if (q->stack1->next == NULL) {
		return pop(&q->stack1);
	}
	else {
		/* pop an item from the stack1 */
		x = pop(&q->stack1);

		/* store the last deQueued item */
		res = deQueue(q);

		/* push everything back to stack1 */
		push(&q->stack1, x);
		return res;
	}
}

/* Driver function to test above functions */
int main()
{
	/* Create a queue with items 1 2 3*/
	struct queue* q = (struct queue*)malloc(sizeof(struct queue));
	q->stack1 = NULL;

	enQueue(q, 1);
	enQueue(q, 2);
	enQueue(q, 3);
	enQueue(q, 4);


	/* Dequeue items */
	printf("%d ", deQueue(q));
	printf("%d ", deQueue(q));
	printf("%d ", deQueue(q));
	printf("%d ", deQueue(q));

	system("pause");
	return 0;
}
