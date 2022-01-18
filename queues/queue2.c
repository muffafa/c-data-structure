/* C Program to implement a queue using two stacks 
Method 2 (By making deQueue operation costly)
In this method, in en-queue operation, the new element is entered at the top of stack1. 
In de-queue operation, all the elements are moved to stack2 and 
finally top of stack2 is returned.
*/
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
	struct sNode* stack2;
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
	int x;

	/* Move elements from stack1 to stack 2 */
	while (q->stack1 != NULL) {
		x = pop(&q->stack1);
		push(&q->stack2, x);
	}
	
	x = pop(&q->stack2);
	return x;
}

/* Driver program to test above functions */
int main()
{
	/* Create a queue with items 1 2 3*/
	struct queue* q = (struct queue*)malloc(sizeof(struct queue));
	q->stack1 = NULL;
	q->stack2 = NULL;
	enQueue(q, 1);
	enQueue(q, 2);
	enQueue(q, 3);

	/* Dequeue items */
	printf("%d ", deQueue(q));
	printf("%d ", deQueue(q));
	printf("%d ", deQueue(q));

	return 0;
}
