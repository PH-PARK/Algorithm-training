#include <stdio.h>

#define MAX_NUM 5000
#define __DEBUG__

int IsFull();
int IsEmpty();
void Enqueue(int item, int* buf);
int Dequeue(int* buf);

int front=0;
int rear=0;


int main()
{
	int Queue[MAX_NUM];
	int NumOfPeople =0 ;
	int Order = 0;
	int i, j;
	int temp = 0;

#ifdef __DEBUG__
	puts("Enter num of People & Order");
#endif
	scanf("%d", NumOfPeople);
	scanf(" %d", Order);

	if (NumOfPeople <= Order)
	{
		puts("Something Wrong...");
	}

	for (i = 0; i < NumOfPeople; i++)
	{
		Enqueue(i,Queue);
	}

	while (!IsEmpty)
	{
		j = i % Order;
		if (j == Order-1)
		{
			temp = Dequeue(Queue);
			printf("%d", temp);
		}
		else
		{
			temp = Dequeue(Queue);
			Enqueue(temp, Queue);
		}
	}
}

int IsFull()
{

}
int IsEmpty()
{
	return front == (rear + 1) % MAX_NUM;
}
void Enqueue(int item, int* buf)
{
	rear = (rear + 1) & MAX_NUM;
	buf[rear] = item;
}

int Dequeue(int* buf)
{
	front = (front + 1) % MAX_NUM;
	return buf[front];
}