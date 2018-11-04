#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

typedef struct node
{
	int key;
	struct node *leftChild, *rightChild;
} treeNode;

treeNode *gRoot = NULL;


treeNode* makeBTreeNode(int key);
void PreOrder(treeNode* root);
void InOrder(treeNode* root);
void PostOrder(treeNode* root);
void LevelOrder(treeNode *root);

void PreOrderIter(treeNode* root);
void InOrderIter(treeNode* root);
void PostOrderIter(treeNode* root);
void LevelOrderIter(treeNode* root);

treeNode* search_BST(treeNode* root, int targetKey);
void insert_BST(int key);
void delete_BST(int key);

int IsFull();
int IsEmpty();
treeNode* Dequeue();
void Enqueue(treeNode* item);
int front = MAX_SIZE -1;
int rear = MAX_SIZE - 1;
treeNode* queue[MAX_SIZE];

int main(void)
{
	
	treeNode *bt1 = makeBTreeNode(10);
	treeNode *bt2 = makeBTreeNode(8);
	treeNode *bt3 = makeBTreeNode(12);
	treeNode *bt4 = makeBTreeNode(9);
	treeNode *temp = NULL;
	bt1->leftChild = bt2;
	bt1->rightChild = bt4;
	bt2->rightChild = bt3;

	PreOrder(bt1);
	puts("");
	InOrder(bt1);
	puts("");
	PostOrder(bt1);
	puts("");
	LevelOrder(bt1);
	puts("");

	temp = search_BST(bt1, 4);
	printf("%d, %d ",temp->key, temp);


	system("pause");
	return 0;
}

treeNode *makeBTreeNode(int key)
{
	treeNode *ptr = (treeNode *)malloc(sizeof(treeNode));

	ptr->key = key;
	ptr->leftChild = ptr->rightChild = NULL;
	return ptr;
}

void PreOrder(treeNode *root) // root left right
{
	if (root)
	{
		printf("%d, %d ", root->key, root);
		PreOrder(root->leftChild);
		PreOrder(root->rightChild);
	}
}

void InOrder(treeNode *root) // left root right 
{
	if (root)
	{
		InOrder(root->leftChild);
		printf("%d, %d ", root ->key, root);
		InOrder(root->rightChild);
	}
}

void PostOrder(treeNode *root) // left right root 
{
	if (root)
	{
		PostOrder(root->leftChild);
		PostOrder(root->rightChild);
		printf("%d, %d ", root ->key,root);
	}
}


void LevelOrder(treeNode *root)
{

	if (!root)
	{
		return;
	}

	Enqueue(root);

	while (!IsEmpty())
	{
		root = Dequeue();
		printf("%d, %d ", root->key,root);
		if (root->leftChild)
		{
			Enqueue(root->leftChild);
		}
		if (root->rightChild)
		{
			Enqueue(root->rightChild);

		}		

	}

}

void PostOrderIter(treeNode* root)
{

}

void PreOrderIter(treeNode* root)
{

}

void InOrderIter(treeNode* root)
{

}

void LevelOrderIter(treeNode* root)
{

}

treeNode *search_BST(treeNode *root, int targetKey)
{
	if (!root)
	{
		return NULL;
	}

	if (targetKey == root->key)
	{
		return root;
	}
	if (targetKey < root->key)
	{
		return search_BST(root->leftChild, targetKey);
	}
	else
	{
		return search_BST(root->rightChild, targetKey);
	}

}

void insert_BST(int key)
{
	treeNode *pPre, *pLoc, *pNew;

	pPre = NULL;
	pLoc = gRoot;
	while (pLoc)
	{
		if (key == pLoc->key)
		{
			return;
		}
		if (key < pLoc->key)
		{
			pPre = pLoc;
			pLoc = pLoc->leftChild;
		}
		if (key > pLoc->rightChild)
		{
			pPre = pLoc;
			pLoc = pLoc->leftChild;
		}
	}

}

void delete_BST(int key)
{



}

int IsFull(void)
{
	return front == (rear + 1) % MAX_SIZE;
}

int IsEmpty(void)
{
	return front == rear;
}

void Enqueue(treeNode* item)
{
	rear = (rear + 1) % MAX_SIZE;
	queue[rear] = item;

	return;
}

treeNode* Dequeue(void)
{
	front = (front + 1) % MAX_SIZE;
	return queue[front];
}