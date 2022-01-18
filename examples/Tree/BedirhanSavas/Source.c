#include <stdio.h>
#include <stdlib.h>
struct node
{
	int key;
	struct node *left, *right;
};

struct node *newNode(int item)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}

void inorder(struct node *root)
{
	if (root != NULL)
	{
		inorder(root->left);
		printf("%d ", root->key);
		inorder(root->right);
	}
}

struct node* insert(struct node* node, int key)
{
	if (node == NULL) return newNode(key);

	if (key < node->key)
		node->left = insert(node->left, key);
	else
		node->right = insert(node->right, key);

	return node;
}

struct node * minValueNode(struct node* node)
{
	struct node* current = node;


	while (current->left != NULL)
		current = current->left;

	return current;
}

struct node* deleteNode(struct node* root, int key)
{

	if (root == NULL) return root;

	if (key < root->key)
		root->left = deleteNode(root->left, key);

	else if (key > root->key)
		root->right = deleteNode(root->right, key);


	else
	{

		if (root->left == NULL)
		{
			struct node *temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL)
		{
			struct node *temp = root->left;
			free(root);
			return temp;
		}


		struct node* temp = minValueNode(root->right);
		root->key = temp->key;
		root->right = deleteNode(root->right, temp->key);
	}
	return root;
}

void main()
{
	struct node *root = NULL;
	int choice, data;
	while (1)
	{
		printf("Select a Choice \n 1-) Add a value \n 2-) Delete a value \n 3-) Display Tree \n");
		scanf_s("%d", &choice);
		switch (choice)
		{
		case 1: printf("Add a Value\n");
			scanf_s("%d", &data);
			root = insert(root, data);
			break;
		case 2: printf("Delete a Value\n");
			scanf_s("%d", &data);
			root = deleteNode(root, data);
			break;
		case 3: inorder(root);
			printf("\n");
			break;
		default: printf("Wrong choice\n");
			break;

		}

	}
	system("pause");
	return 0;
}