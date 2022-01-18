#include <stdlib.h>
#include <stdio.h>

typedef struct linkedList {
	int info;
	//char data[5];
	struct linkedList *next;
}SIMPLE_LIST;

//This list has any number of elements
//Pointers to the first and last elements
// Initially, the list is empty
SIMPLE_LIST *first = NULL;
SIMPLE_LIST *last = NULL;

int insert(SIMPLE_LIST *p) {
	if (first != NULL) {
		last->next = p;
		p->next = NULL;
		last = p;
	}
	else {
		first = p;
		last = p;
		p->next = NULL;
	}
	return 0;
}

int displayList() {
	SIMPLE_LIST *p;
	p = first;
	if (p == NULL) {
		printf("List is empty\n");
		return -1;
	}
	while (p != NULL) {
		printf(" %d \n", 	p->info);
		p = p->next;
	}
	return 0;
}

SIMPLE_LIST *search(int key) {
	SIMPLE_LIST *p;
	p = first;
	while (p) {
		if (p->info == key)
			return p;
		p = p->next;
	}
	return NULL;
}

SIMPLE_LIST *delete(int key) {
	SIMPLE_LIST *p, *previous;
	p = first;
	previous = NULL;

	// search for the element to be deleted
	while (p) {
		if (key == p->info)
			break;
		previous = p;
		p = p->next;
	}
	if (p != NULL) { //if found
		if (previous == NULL){
			// if first element will be deleted
			if (first == last) {
				// if list has one element
				first = NULL;
				last = NULL;
			}
			else {
				first = first->next;
			}
		}
		else {
			//delete from middle or last
			previous->next = p->next;
			if (previous->next == NULL) {
				//last element is deleted
				last = previous;
			}
		}
		free(p);
		return(p);
	}
	else     //not found
		return NULL;
}

void main()
{
	SIMPLE_LIST *a1 = malloc(sizeof(SIMPLE_LIST));
	a1->info = 1;
	
	SIMPLE_LIST *a2 = malloc(sizeof(SIMPLE_LIST));
	a2->info = 2;

	SIMPLE_LIST *a3 = malloc(sizeof(SIMPLE_LIST));
	a3->info = 3;

	insert(a1);
	insert(a2);
	insert(a3);

	delete(2);
	displayList();
	
	a2->info = 2;
	insert(a2);
	displayList();
	
	system("pause");

}
