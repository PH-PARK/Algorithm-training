#include <stdio.h>

#define MAX_NUM 5000
//#define __DEBUG__
//#define __TEST__


typedef struct Queue {
		int array[MAX_NUM];
		int front;
		int rear;
}Queue;

int IsFull(Queue buf);
int IsEmpty(Queue buf);
void Enqueue(int item,Queue* buf);
int Dequeue(Queue* buf);

int main()
{
	Queue Data;
	Data.front = 0;
	Data.rear = 0;
	Queue Enswer;
	Enswer.front = 0;
	Enswer.rear = 0;
	int NumOfPeople =0 ;
	int Order = 0;
	int i, j = 0;
	int temp = 0;

#ifdef __DEBUG__
	puts("Enter num of People & Order");
#endif
	scanf("%d", &NumOfPeople);
	scanf(" %d", &Order);

#ifdef __DEBUG__
	printf("%%d\n", Order);
#endif

	if (NumOfPeople < Order)
	{
		puts("Something Wrong...");
		return 1;
	}

	for (i = 0; i < NumOfPeople; i++)
	{
		Enqueue(i+1,&Data);
#ifdef __DEBUG__
		puts("Did Enqueue.");
		printf("front : %d, rear : %d\n", Data.front, Data.rear);
#endif
	}
#ifdef __DEBUG__
	temp = IsEmpty(Data);
	printf("IsEmpty : %d", temp);
#endif
	i = 0;
	while (IsEmpty(Data) != 1)//(!IsEmpty)
	{
		j = i % Order;
#ifdef __DEBUG__
//		temp = IsEmpty();
//		printf("IsEmpty : %d", temp);
//		printf("i : %d, j : %d \nfront : %d, rear : %d\n", i, j, front, rear);
//		printf("j == Order-1 : %d", (j == (Order - 1)));

#endif
		if (j == (Order-1))
		{
			temp = Dequeue(&Data);
			Enqueue(temp, &Enswer);
		}
		else
		{
			temp = Dequeue(&Data);
			Enqueue(temp, &Data);
		}
		
		i++;
#ifdef __DEBUG__
		if (i == 50)
		{
			puts("what are you doing?");
			system("pause");
		}
#endif
	}
	
	temp = Dequeue(&Enswer);
	printf("<%d", temp);
	while (!IsEmpty(Enswer))//for(i = 1; i < NumOfPeople; i++)
	{
		temp = Dequeue(&Enswer);
		printf(", %d", temp);
	}
	printf(">\n");
#ifdef __DEBUG__
	puts("");
	puts("Done.");
	system("pause");
#endif
#ifdef __TEST__
	system("pause");
#endif 

	return 0;

}
int IsFull(Queue buf)
{
	return buf.front == (buf.rear + 1) % MAX_NUM;
}

int IsEmpty(Queue buf)
{
	return buf.front == buf.rear;

}
void Enqueue(int item, Queue* buf)
{
#ifdef __DEBUG__
	printf("rear = %d", buf->rear);
#endif
	buf->rear = (buf->rear + 1) % MAX_NUM;
	buf->array[buf->rear] = item;
}

int Dequeue(Queue* buf)
{
	buf->front = (buf->front + 1) % MAX_NUM;
	return buf->array[buf->front];
}