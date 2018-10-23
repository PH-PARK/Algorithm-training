#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int key;
	struct node *leftChild, *rightChild;
} treeNode;

treeNode *makeBTreeNode(int key)
{
	treeNode *ptr = (treeNode *)malloc(sizeof(treeNode));

	ptr->key = key;
	ptr->leftChild = ptr->rightChild = NULL;
	return ptr;
}

void preorder(treeNode *root) // root left right
{
	if (root)
	{
		printf("%d ", root->key);
		preorder(root->leftChild);
		preorder(root->rightChild);
	}
}

void inorder(treeNode *root) // left root right 순서대로 출력
{
	if (root)
	{
		inorder(root->leftChild);
		printf("%d ", root ->key);
		inorder(root->rightChild);
	}
}

void postorder(treeNode *root) // left right root 순서 
{
	if (root)
	{
		postorder(root->leftChild);
		postorder(root->rightChild);
		printf("%d ", root ->key);
	}
}

int main(void)
{
	treeNode *bt1 = makeBTreeNode(1);
	treeNode *bt2 = makeBTreeNode(2);
	treeNode *bt3 = makeBTreeNode(3);
	treeNode *bt4 = makeBTreeNode(4);
	bt1->leftChild = bt2;
	bt1->rightChild = bt3;
	bt2->leftChild = bt4;

	preorder(bt1);
	puts("");
	inorder(bt1);
	puts("");
	postorder(bt1);
	puts("");
	system("pause");
	return 0;
}