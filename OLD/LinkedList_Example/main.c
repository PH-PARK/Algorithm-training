#include <stdio.h>
#include <stdlib.h>

typedef struct listNode
{
	int data;
	struct listNode *next;
}listNode;

listNode *first = NULL;

void insert_head(int);
void remove_val(int);

int main()
{
	int num;
	int i;

	for (i = 0; i < 5; i++)
	{
		scanf("%d", &num);
		insert_head(num);
	}
	printList();

	for (i = 0; i < 5; i++)
	{
		scanf("%d", &num);
		remove_val(num);
		printList();
	}
	return 0;
}

void insert_head(int num)
{
	listNode *pNew = (listNode *)malloc(sizeof(listNode)); 
	pNew->data = num; 
	pNew->next = first; 
	first = pNew;
}
void printfList()
{

}
void remove_val(int num)
{
	listNode *pPre = NULL;
	listNode *pLoc = first;

	while (pLoc)
	{
		if (pLoc->data == num)
		{
			//pPre->next = pLoc->next; 교수님은 여기 코딩을 안 했음.
					
			break;//교수님은 바로 빠져나와서
		}
		pPre = pLoc;
		pLoc = pLoc->next; //다음 단계로 넘어감
	}
	//밖에서 저장을 하는 방식임/
	if (pPre)
		pPre->next = pLoc->next;
	else
		first = pLoc->next;

	free(pLoc);
}	