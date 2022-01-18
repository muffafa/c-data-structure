//
//  main.c
//  BinarySearchTree
//
//  Created by Buðra Tunçer on 18.12.2018.
//  Copyright © 2018 Buðra Tunçer. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int key;
	struct node *left, *right;
}node;
node *insert(node *root, int key)
{
	if (root == NULL)
	{
		node* new = malloc(sizeof(node));
		new->key = key;
		new->left = NULL;
		new->right = NULL;
		return new;
	}
	if (root->key > key)
	{
		root->left = insert(root->left, key);
	}
	else if (root->key < key)
	{
		root->right = insert(root->right, key);
	}
	return root;
}
node *delete(node *root, int key)
{
	node *current;
	if (root == NULL)
		return root;
	if (key < root->key)
	{
		root->left = delete(root->left, key);
	}
	else if (key > root->key)
	{
		root->right = delete(root->right, key);
	}
	else
	{
		if (root->left == NULL)
		{
			node *temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL)
		{
			node *temp = root->left;
			free(root);
			return temp;
		}
		current = root->right;
		while (current->left != NULL)
		{
			current = current->left;
		}
		root->key = current->key;
		root->right = delete(root->right, key);
	}
	return root;
}
void inorder(node* root) {
	if (root == NULL)
		return;
	inorder(root->left);
	printf(" %d ->", root->key);
	inorder(root->right);
}

int main() {
	int i;
	int data;
	node *root = NULL;
	while (1)
	{
		printf("Enter Choice \n 1-) Add \n 2-) Delete \n 3-) Display \n 4-) Exit \n");
		scanf("%d", &i);
		switch (i)
		{
		case 1: printf("Enter Value to add\n");
			scanf("%d", &data);
			root = insert(root, data);
			break;
		case 2: printf("Enter value to delete\n");
			scanf("%d", &data);
			root = delete(root, data);
			break;
		case 3: inorder(root);
			printf("\n");
			break;
		case 4: exit(1);
		default: printf("Wrong choice\n");
			break;

		}

	}
}