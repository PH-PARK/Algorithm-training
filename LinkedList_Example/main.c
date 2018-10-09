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
			//pPre->next = pLoc->next; �������� ���� �ڵ��� �� ����.
					
			break;//�������� �ٷ� �������ͼ�
		}
		pPre = pLoc;
		pLoc = pLoc->next; //���� �ܰ�� �Ѿ
	}
	//�ۿ��� ������ �ϴ� �����/
	if (pPre)
		pPre->next = pLoc->next;
	else
		first = pLoc->next;

	free(pLoc);
}	