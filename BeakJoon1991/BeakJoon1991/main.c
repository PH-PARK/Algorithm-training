//studentroll@gmail.com
//20141200 ¹ÚÆòÈ­

#include <stdio.h>
#include <stdlib.h>

#define MAX_NODE 30
#define BUFSIZE 30
//#define __DEBUG__

typedef struct _STreeNode
{
	char item;
	struct _STreeNode* leftChild, *rightChild;
}STreeNode;
STreeNode* gRoot;

STreeNode* queue[MAX_NODE];


void InsertBT(STreeNode*, char, char);
void PreOrder(STreeNode*);
void InOrder(STreeNode*);
void PostOrder(STreeNode*);
STreeNode* dequeue();
void enqueue(STreeNode* item);
int IsEmpty();
int GetString(char*, int);
STreeNode* makeBTreeNode(char);
int front = 0;
int rear = 0;

int main() 
{
	gRoot = makeBTreeNode('A');
	int nodeNum = 1;
	int i,j, k;
	char temp, tempRoot, tempLeft, tempRight;
	STreeNode* ptrRoot, *ptrLeft, *ptrRight;
	char buf[BUFSIZE];

	temp = 0;
	tempRoot = 0;
	tempLeft = 0;
	tempRight = 0;
	i = 0;
	j = 0;
	k = 0;
	ptrRoot = NULL;
	ptrLeft = NULL;
	ptrRight = NULL;

#ifdef __DEBUG__
	puts("Number of Nodes.");
#endif
	scanf(" %d", &nodeNum);
	

//	if (nodeNum < 1 || nodeNum>26)
//	{
//		puts("Wrong Num.");
//		return 0;
//	}

#ifdef __DEBUG__
	printf("nodeNum: %d\n", nodeNum);
#endif
	//getchar();
	while (getchar() != '\n');
#ifdef __DEBUG__
	puts("Nodes: ");
#endif

	//*************************
	//first enter
	//*************************

	if (GetString(buf, BUFSIZE) == 1)
	{
		return 0;
	}

	for (i = 0; buf[i] != '\0'; i++)
	{

		if (buf[i] != ' ')
		{
			if (j == 0)
			{
				tempRoot = buf[i];
				j++;
			}
			else if (j == 1)
			{
				if (buf[i] == '.')
				{
					tempLeft = 0;
				}
				else
				{
					tempLeft = buf[i];
					ptrLeft = makeBTreeNode(tempLeft);
					enqueue(ptrLeft);
					nodeNum--;
				}
				j++;
			}
			else if (j == 2)
			{
				if (buf[i] == '.')
				{
					tempRight = 0;
				}
				else
				{
					tempRight = buf[i];
					ptrRight = makeBTreeNode(tempRight);
					enqueue(ptrRight);
					nodeNum--;
				}
				j = 0;
			}
		}
#ifdef __DEBUG__
		printf("root: %c, left: %c, right: %c\n", tempRoot, tempLeft, tempRight);
#endif
	}

	if (tempLeft)
	{
		gRoot->leftChild = ptrLeft;
	}
	if (tempRight)
	{
		gRoot->rightChild = ptrRight;
	}

	if (nodeNum == 1 && IsEmpty())
	{
		PreOrder(gRoot);
		puts("");
		InOrder(gRoot);
		puts("");
		PostOrder(gRoot);
		puts("");
		return 0;
	}

#ifdef __DEBUG__
	puts("*****************");
	puts("After First Case");
	printf("front: %d, rear: %d\n", front, rear);
	puts("In the Queue:");
	for (k = front; k < rear; k++)
	{
		printf("%c", queue[k + 1]->item);
	}
	puts("");
	//		printf("In the Queue : %c, %c\n", queue[front + 1]->item, queue[front + 2]->item);
	puts("*****************");
#endif


	//***************************************
	//	LOOP
	//***************************************
#ifdef __DEBUG__
	puts("*******************");
	puts("LOOP");
	puts("*******************");
#endif
	while (!IsEmpty())
	{
	//	j = 0;

		if (GetString(buf, BUFSIZE) == 1)	//Get a String Line.
		{
			return 0;
		}

		for (i = 0; buf[i] != '\0'; i++)	//Distinguish a String, removing ' '.
		{
#ifdef __DEBUG__
			printf("buf[i]: %c, j: %d\n", buf[i],j);
#endif
			if (buf[i] != ' ')
			{
				if (j == 0)
				{
					tempRoot = buf[i];
					j++;
				}
				else if (j == 1)
				{
					if (buf[i] == '.')	//ignore '.'
					{
						tempLeft = 0;
					}
					else				//makeTreeNode and remember the pointer.
					{
						tempLeft = buf[i];
						ptrLeft = makeBTreeNode(tempLeft);
						enqueue(ptrLeft);
						nodeNum--;
					}
					j++;
				}
				else if (j == 2)
				{
					if (buf[i] == '.')
					{
						tempRight = 0;
					}
					else
					{
						tempRight = buf[i];
						ptrRight = makeBTreeNode(tempRight);
						enqueue(ptrRight);
						nodeNum--;
					}
					j = 0;
				}
			}
#ifdef __DEBUG__
			printf("root: %c, left: %c, right: %c\n", tempRoot, tempLeft, tempRight);
#endif
		}
#ifdef __DEBUG__
		puts("In the Queue:");
		for (k = front; k<rear; k++)
		{
			printf("%c", queue[k + 1]->item);
		}
		puts("");
//		printf("In the Queue : %c, %c\n", queue[front+1]->item, queue[front+2]->item);
#endif
		ptrRoot = dequeue();
#ifdef __DEBUG__
		printf("tempRoot : %c, ptrRoot->item: %c\n", tempRoot, ptrRoot->item);
#endif
		k = 0;
		while (tempRoot != ptrRoot->item)
		{
			enqueue(ptrRoot);
			ptrRoot = dequeue();
			k++;
			if (k > MAX_NODE)
			{
				puts("Can't find Root.");
				return 0;
			}
#ifdef __DEBUG__
			printf("tempRoot : %c, ptrRoot->item: %c\n", tempRoot, ptrRoot->item);
#endif
		}



		if (tempLeft)
		{
			ptrRoot->leftChild = ptrLeft;
		}
		if (tempRight)
		{
			ptrRoot->rightChild = ptrRight;
		}
#ifdef __DEBUG__
		puts("*****************");
		puts("Passed One LOOP");
		printf("front: %d, rear: %d\n", front, rear);
		puts("In the Queue:");
		for (k = front; k < rear; k++)
		{
			printf("%c", queue[k + 1]->item);
		}
		puts("");
//		printf("In the Queue : %c, %c\n", queue[front + 1]->item, queue[front + 2]->item);
		puts("*****************");
#endif

	}

	PreOrder(gRoot);
	puts("");
	InOrder(gRoot);
	puts("");
	PostOrder(gRoot);
	puts("");

	return 0;
}

void InsertBT(STreeNode* root, char leftkey, char rightkey)
{

	if (leftkey)
	{
		root->leftChild = makeBTreeNode(leftkey);
	}

	if (rightkey)
	{
		root->rightChild = makeBTreeNode(rightkey);
	}

	return;
}

STreeNode *makeBTreeNode(char key)
{
	STreeNode *ptr = (STreeNode *)malloc(sizeof(STreeNode));

	ptr->item = key;
	ptr->leftChild = ptr->rightChild = NULL;

	return ptr;
}	

void PreOrder(STreeNode *root) // root left right
{
	if (root)
	{
		printf("%c", root->item);
		PreOrder(root->leftChild);
		PreOrder(root->rightChild);
	}
}

void InOrder(STreeNode *root) // left root right 
{
	if (root)
	{
		InOrder(root->leftChild);
		printf("%c", root->item);
		InOrder(root->rightChild);
	}
}

void PostOrder(STreeNode *root) // left right root 
{
	if (root)
	{
		PostOrder(root->leftChild);
		PostOrder(root->rightChild);
		printf("%c", root->item);
	}
}

int GetString(char *buf, int maxLen)
{
	int i;
	char ch;

	for (i = 0; i < maxLen; i++)
	{
		ch = getchar();
		if (ch == '\n')
		{
			buf[i] = '\0';
			return 0;
		}
		buf[i] = ch;
	}
	puts("Too long string");
	printf("Maximum	input length is %d bytes.", maxLen - 1);
	while (getchar() != '\n');
	return	1;
}

int IsEmpty()
{
	return (front == rear);
}

void enqueue(STreeNode* item)
{
	rear = (rear + 1) % MAX_NODE;
	queue[rear] = item;
	return;
}

STreeNode* dequeue()
{
	front = (front + 1) % MAX_NODE;
	return queue[front];
}