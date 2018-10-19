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
	scanf("%d", &NumOfPeople);
	scanf(" %d", &Order);

#ifdef __DEBUG__
	printf("%d\n", Order);
#endif

	if (NumOfPeople <= Order)
	{
		puts("Something Wrong...");
	}

	for (i = 0; i < NumOfPeople; i++)
	{
		Enqueue(i,Queue);
#ifdef __DEBUG__
		puts("Did Enqueue.");
		printf("front : %d, rear : %d\n", front, rear);
#endif
	}

	i = 0;
	j = 0;
	temp = IsEmpty();
#ifdef __DEBUG__
	printf("IsEmpty : %d", temp);
#endif
	while (IsEmpty() != 1)//(!IsEmpty)
	{
		j = i % Order;
#ifdef __DEBUG__
//		temp = IsEmpty();
//		printf("IsEmpty : %d", temp);
		printf("front : %d, rear : %d\n", front, rear);
		printf("j: %d", j);
#endif
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
		
		i++;
#ifdef __DEBUG__
		if (i == 50)
		{
			puts("what are you doing?");
			system("pause");
		}
#endif
	}

#ifdef __DEBUG__
	puts("Done.");
	system("pause");
#endif

		return;
}

int IsFull()
{
	return front == (rear + 1) % MAX_NUM;
}
int IsEmpty()
{
	return front == rear;
}
void Enqueue(int item, int* buf)
{
	rear = (rear + 1) % MAX_NUM;
	buf[rear] = item;
}

int Dequeue(int* buf)
{
	front = (front + 1) % MAX_NUM;
	return buf[front];
}