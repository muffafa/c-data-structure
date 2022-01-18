//
//  main.c
//  Stack
//
//  Created by Buğra Tunçer on 4.12.2018.
//  Copyright © 2018 Buğra Tunçer. All rights reserved.
//
#include <stdlib.h>
#include <stdio.h>
typedef struct Stack
{
	int data;
	struct Stack *next;
}stack;
stack *head; // Stack head kısmını oluşturuyoruz.
int push(int data)
{
	stack *temp = (stack*)malloc(sizeof(stack)); //Temp değişkenine yer açıyoruz
	if (temp == NULL) // Yer açamadıysa hata mesajı
	{
		printf("Not enough memory\n");
		return -1;
	}
	else // Yer açtıysa stack e eleman ekliyoruz
	{
		temp->data = data;
		temp->next = head;
		head = temp;
		return 0;
	}
}
int pop()
{
	stack *temp;
	if (head == NULL)
	{
		printf("Stack is empty \n");
		return -1;
	}
	else
	{
		temp = head;
		head = head->next;
		printf("Popped %d \n", temp->data);
		free(temp);
		//free(head);
		return 1;
	}
}
void printStack()
{
	stack *temp = head;

	printf("Stack : ");
	if (temp == NULL)
	{
		printf("Stack is empty\n");
	}
	while (temp != NULL)
	{
		printf("%d  ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}
int topElement()
{
	return head->data;
}
void destroyStack()
{
	while (head != NULL)
	{
		head = head->next;
		free(head);
	}
}

int main() {
	push(10);
	printStack();
	push(30);
	printStack();
	push(40);
	printStack();
	push(50);
	printStack();
	pop();
	printStack();
	printf("Top Element : %d\n", topElement());
	//destroyStack();
	printStack();

}