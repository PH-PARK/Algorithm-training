#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define MAX_NODE 26
#define MAX_QUEUE 10
#define __DEBUG__

typedef struct _STreeNode
{
	char item;
	struct _STreeNode* leftChild, *rightChild;
}STreeNode;
STreeNode* gRoot;

char queue[MAX_QUEUE];
int front, rear = 0;

void InsertBT(char, char, char);
void PreOrder(STreeNode*);
void InOrder(STreeNode*);
void PostOrder(STreeNode*);
STreeNode* SearchTarget(STreeNode*, char);
void enqueue(char);
char dequeue();
int IsEmpty();
int GetString(char*, int);
STreeNode* makeBTreeNode(char);

int main() 
{
	gRoot = makeBTreeNode('A');
	int nodeNum = 1;
	int i;
	char temp, tempRoot, tempLeft, tempRight;
	char buf[10];

#ifdef __DEBUG__
	puts("Number of Nodes.");
#endif
	scanf(" %d", &nodeNum);
	

	if (nodeNum < 1 || nodeNum>26)
	{
		puts("Wrong Num.");
		return 0;
	}

#ifdef __DEBUG__
		printf("nodeNum : %d\n", nodeNum);
#endif

		while (1 < nodeNum)
		{

			//		if (GetString(buf, 6) == 1)
			//		{
			//			return 1;
			//		}
			getchar();
			scanf("%[^\n]", buf);
#ifdef __DEBUG__
			puts("scanf");
#endif
			for (i = 0; i < 10; i++)
			{

				if (buf[i] == '\0')
				{
#ifdef __DEBUG__
					printf("1:%c 2:%c 3:%c 4:%c 5:%c %\n", buf[0], buf[1], buf[2], buf[3], buf[4]);
					printf("buf[%d] : '%c'\n", i, buf[i]);
					puts("break");
#endif
					break;
				}

				if (buf[i] != ' ')
				{
					enqueue(buf[i]);
#ifdef __DEBUG__
					puts("enqueue");
#endif
				}

			}
			tempRoot = dequeue();
#ifdef __DEBUG__
			puts("dequeue 1");
#endif
			temp = dequeue();
#ifdef __DEBUG__
			puts("dequeue 2");
#endif
			if (temp != '.')
			{
				tempLeft = temp;
				nodeNum--;
			}
			else
			{
#ifdef __DEBUG__
				puts("but was '.'");
#endif
				tempLeft = NULL;
			}

			temp = dequeue();
#ifdef __DEBUG__
			puts("dequeue 3");
#endif
			if (temp != '.')
			{
				tempRight = temp;
				nodeNum--;
			}
			else
			{
				tempRight = NULL;
#ifdef __DEBUG__
				puts("but was '.'");
#endif
			}

			while (!IsEmpty())
			{
				dequeue();
			}

			InsertBT(tempRoot, tempLeft, tempRight);
#ifdef __DEBUG__
			puts("Insert");
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

void InsertBT(char target, char left, char right)
{
	STreeNode* temp;

	if (target == gRoot->item)
	{
		if (left)
		{
			gRoot->leftChild = makeBTreeNode(left);
#ifdef __DEBUG__
			puts("left1");
#endif
		}
		if (right)
		{
			gRoot->rightChild = makeBTreeNode(right);
#ifdef __DEBUG__
			puts("right1");
#endif
		}
		return;
	}
	

	temp = SearchTarget(gRoot, target);

	if (left)
	{
		temp->leftChild = makeBTreeNode(left);
#ifdef __DEBUG__
		puts("left2");
#endif
	}
	if (right)
	{
		temp->rightChild = makeBTreeNode(right);
#ifdef __DEBUG__
		puts("right2");
#endif
	}

	return;
}


STreeNode* SearchTarget(STreeNode* root, char target)
{
	static STreeNode* returnptr;
	if (root->item == target)
	{
#ifdef __DEBUG__
		puts("found in %c's item",root->item);
#endif

		return root;

	}
	if (root->leftChild)
	{
		SearchTarget(root->leftChild, target);
#ifdef __DEBUG__
		puts("finding %c's left",root->item);
#endif

	}

	if (root->rightChild)
	{
		SearchTarget(root->rightChild, target);
#ifdef __DEBUG__
		puts("finding %c's right",root->item);
#endif
	}

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

void enqueue(char item)
{
	rear = (rear + 1) % MAX_QUEUE;
	queue[rear] = item;
	return;
}

char dequeue()
{
	front = (front + 1) % MAX_QUEUE;

	return queue[front];
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
	while (getchar());
	return	1;
}

int IsEmpty()
{
	return (rear == front);
}
