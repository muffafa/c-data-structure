#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

typedef struct binaryT {
	int info;
	char message[100];
	struct binaryT *left;
	struct binaryT *right;
}btree;

btree *root=NULL;


int depth(btree* node) 
{
   if (node==NULL) 
       return 0;
   else
   {
       
       int leftdepth = depth(node->left);
       int rightdepth = depth(node->right);
 
       
       if (leftdepth>rightdepth) 
           return(leftdepth);
           
       else 
	   	return (rightdepth+1);
   }
} 





void insert(btree *treeRoot,btree *newNode) {
	
	if(treeRoot==NULL) 
		root=newNode;
	else {
		if(newNode->info < treeRoot->info) {
			if(treeRoot->left==NULL)
				treeRoot->left=newNode;
			else
				insert(treeRoot->left,newNode);
		}
		else {
			if(treeRoot->right==NULL)
				treeRoot->right=newNode;
			else
				insert(treeRoot->right,newNode);
		}
	}
}

//in-order traversal
void traverse (btree *treeRoot) {
	if(treeRoot!=NULL) {
		
	
		traverse(treeRoot->left);
			printf("%d\n",treeRoot->info);
				
		traverse(treeRoot->right);
	}
}

btree *search(btree *treeRoot,int item) {
	while((treeRoot!=NULL) && (treeRoot->info!=item)) {
		if(item<treeRoot->info)
			treeRoot=treeRoot->left;
		else
			treeRoot=treeRoot->right;
	}
	return treeRoot;
}


btree *deletee(btree *treeRoot,int item) {
	btree *qa,*q,*qc,*sa,*s;
	if(treeRoot==NULL) 
		return NULL;
	q=treeRoot;
	qa=NULL;
	//find the item to be deleted
	while((q!=NULL) && (q->info!=item)) {
		qa=q;
		if(item<q->info)
			q=q->left;
		else
			q=q->right;
	}
	if(q==NULL) {
		printf("Item to be deleted is not found\n");
		return NULL;
	}
	//if q is found and it has 2 children
	if((q->left!=NULL) && (q->right!=NULL))  {
		s=q->left;
		sa=q;
		//Find item having the max value in the left
		//subtree.So,take the rightmost node
		//in the left subtree.
		while(s->right!=NULL) {
			sa=s;
			s=s->right;
		}
		q->info=s->info;  // copy s to q
		strcpy(q->message,s->message);
		q=s;
		qa=sa;
	}
	//now q has at most 1 child,and find it
	if((q->left!=NULL))
		qc=q->left;
	else
		qc=q->right;
	
	//delete q
	
	if(q==treeRoot)
		root=qc;
	else {
		if(q==qa->left)
			qa->left=qc;
		else
			qa->right=qc;
	}
	free(q);
	return q;
}

btree *readNode() {
	btree *newNode;
	newNode=(btree *)malloc(sizeof(btree));
	if(newNode==NULL)
		return NULL;
	printf("Enter info:");
	scanf("%d",&(newNode->info));
	
	newNode->left=NULL;
	newNode->right=NULL;
	return newNode;
}

int countNodes(btree *treeRoot,int sum) {
	if(treeRoot==NULL)
		return sum;
	sum++;
	sum=countNodes(treeRoot->left,sum);
	sum=countNodes(treeRoot->right,sum);
	return sum;
}

int main() {
	btree *n , *a;
	int i,choice,count;
	
	while(1) {
		printf("1.Insert a node\n2.Delete a node\n3.List nodes\n4.Search for a node\n5.Count number of nodes\n6.Find depth\n7.Exit\nEnter your choice:");			
		scanf("%d",&choice);
		
		if(choice==1) {
			n=readNode();
			insert(root,n);
		}
		else if (choice==2) {
			printf("Enter node to be deleted...");
			scanf("%d",&i);
			a=deletee(root,i);
			if(a!=NULL)
				printf("Deleted\n");
			else
				printf("Item to be deleted is not found\n");
		}
		else if(choice==3) {
			if(root!=NULL) 
				traverse(root);
			else
				printf("Tree is empty\n");
			
		}
		else if(choice==4) {
			printf("Enter node to be searched for...");
			scanf("%d",&i);
			a=search(root,i);
			if(a==NULL)
				printf("Item is not found\n");
			else
				printf("%d \n",a->info);
		}
		else if(choice==5) {
			count=countNodes(root,0);
			printf("Number of node in the tree= %d\n",count);
		}
		
		else if(choice==6) {
			printf("Depth=%d",depth(root))	;
		}
		
		
		else
			break;
			
		printf("\n***********************\n");
		}
	}



