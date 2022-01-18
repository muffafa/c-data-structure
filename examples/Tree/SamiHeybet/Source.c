#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct binary_tree{
	int info;
	char message[100];
	struct binary_tree *left;
	struct binary_tree *right;
}BIN_TREE;

BIN_TREE *root = NULL;

BIN_TREE *CreateNode(){
	BIN_TREE *newNode;
	newNode = (BIN_TREE *)malloc(sizeof(BIN_TREE));
	if (newNode == NULL) { printf("yer ayrılamadı"); return NULL; }
	printf("Enter info :");
	scanf("%d", &(newNode->info));
	printf("Enter message :");
	scanf("%s", newNode->message);
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
} // Create Node

void InsertNode(BIN_TREE *TreeRoot, BIN_TREE *newNode){
	if (TreeRoot == NULL)
	{
		root = newNode;
	}
	else
	{
		if (newNode->info < TreeRoot->info)
		{
			if (TreeRoot->left == NULL)
			{
				TreeRoot->left = newNode;
			}
			else
			{
				InsertNode(TreeRoot->left, newNode);
			}
		} //  insert left side

		if (newNode->info >= TreeRoot->info)
		{
			if (TreeRoot->right == NULL)
			{
				TreeRoot->right = newNode;
			}
			else
			{
				InsertNode(TreeRoot->right, newNode);
			}
		} //  insert right side
	} // else
} // InsertNode

void list(BIN_TREE *TR){
	if (TR != NULL)
	{
		printf("%d  %s\n", TR->info, TR->message);
		list(TR->left);
		list(TR->right);
	}
} // list

BIN_TREE *search(BIN_TREE *TR, int item){
	while ((TR != NULL) && (TR->info != item))
	{
		if (item < TR->info)
			TR = TR->left;
		else
			TR = TR->right;
	}  // while

	return TR;
} // search

int CountNodes(BIN_TREE *TR, int toplam){
	if (TR == NULL) return toplam;
	toplam++;
	toplam = CountNodes(TR->left, toplam);
	toplam = CountNodes(TR->right, toplam);
	return toplam;
} // count nodes

BIN_TREE *DeleteNode(BIN_TREE *treeRoot, int item){
	BIN_TREE *tmp, *tmp_root, *tmp2, *search_root, *search;
	if (treeRoot == NULL)
		return NULL;
	tmp = treeRoot;
	tmp_root = NULL;
	// find the item to be deleted
	while ((tmp != NULL) && (tmp->info != item))
	{
		tmp_root = tmp;
		if (item < tmp->info)
			tmp = tmp->left;
		else
			tmp = tmp->right;
	} // while 

	if (tmp == NULL) {
		printf("Item to be deleted is not found\n");
		return NULL;
	}

	// if q is found and it has 2 children
	if ((tmp->left != NULL) && (tmp->right != NULL))
	{
		search = tmp->left;
		search_root = tmp_root;
		// Find item having the max value in the left 
		// subtree. So, take the rightmost node
		// in the left subtree.
		while (search->right != NULL)
		{
			search_root = search;
			search = search->right;
		}
		tmp->info = search->info;  // copy s to q
		strcpy(tmp->message, search->message);
		tmp = search;
		tmp_root = search_root;
	}

	// now q has at most 1 child, and find it

	if (tmp->left != NULL)
		tmp2 = tmp->left;
	else
		tmp2 = tmp->right;

	// delete q

	if (tmp == treeRoot)
		root = tmp2;
	else {
		if (tmp == tmp_root->left)
			tmp_root->left = tmp2;
		else
			tmp_root->right = tmp2;
	}
	free(tmp);
	return tmp;
} // delete 

void main(){
	BIN_TREE *node, *tmp;
	int menu = 0;
	int search_value, node_count;

	while (1)
	{
		printf("1. Insert a node	\n");
		printf("2. Delete a node	\n");
		printf("3. List nodes		\n");
		printf("4. Search for a node \n");
		printf("5. Count number of nodes \n");
		printf("6. Exit	\n");
		printf("\n");
		printf("Enter your choice : ");
		scanf_s("%d", &menu);

		if (menu < 1 || menu>6)
		{
			printf("Wrong Selection !, please select again ...\n\n");
			while (getchar() == '\n'); // read all keyboard buffer(flush the buffer) until key=enter, so there is no key in the buffer 
		}

		if (menu == 1)
		{
			node = CreateNode();
			InsertNode(root, node);
		} // insert a node

		if (menu == 2)
		{
			if (root != NULL)
			{
				printf("Enter the nodes->info field value to be deleted... : ");
				scanf("%d", &search_value);
				tmp = DeleteNode(root, search_value);
				if (tmp != NULL) printf("Item was deleted!\n\n");
				else
					printf("Item to be deleted was not found.\n\n");
			}  // if not null
			else
			{
				printf("Tree is Empty!\n\n");
			} // if null
		} //  delete a node

		if (menu == 3)
		{
			if (root != NULL)
			{
				list(root);
			}
			else
			{
				printf("Tree is Empty!\n\n");
			}
		} //  print nodes

		if (menu == 4)
		{
			if (root != NULL)
			{
				printf("Enter the nodes->info field value to be search for ... : ");
				scanf("%d", &search_value);
				tmp = search(root, search_value);
				if (tmp == NULL) printf("Item was not found!\n\n");
				else
					printf("%d  %s\n", tmp->info, tmp->message);
			}
			else
			{
				printf("Tree is Empty!\n\n");
			}
		} // search node

		if (menu == 5)
		{
			if (root != NULL)
			{
				node_count = CountNodes(root, 0);
				printf("Number of Nodes in the tree = %d  \n\n", node_count);
			}
			else
			{
				printf("Tree is Empty!\n\n");
			}
		} //  count nodes

		if (menu == 6)
		{
			exit(0);
		} // exit
	} // while
} // main