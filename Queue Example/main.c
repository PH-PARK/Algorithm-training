#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 100

typedef int element;

element queue[MAX_QUEUE_SIZE];

int front = MAX_QUEUE_SIZE - 1;
int rear = MAX_QUEUE_SIZE - 1;

int is_empty(void);
int is_full(void);
void enqueue(element item);
element dequeue(void);


int main()
{
	int i, num;

	for (i = 0; i < 5; i++) {
		scanf("%d", &num); 
		push(num); 
		enqueue(num);
	}
	printf("[Stack]: "); 
	for (i = 0; i < 5; i++) 
	{
		num = pop(); 
		printf("%d ", num);
	} 
	printf("\n");
	printf("[Queue]: "); 
	for (i = 0; i < 5; i++) 
	{
		num = dequeue(); 
		printf("%d ", num);
	}
	printf("\n"); return 0;
	
}

int is_empty()
{
	return front == rear;
}

int is_full()
{
	return front == (rear + 1) % MAX_QUEUE_SIZE;
}

void enqueue(element item)
{
	assert(!is_full());
	rear = (rear + 1 ) % MAX_QUEUE_SIZE;
	queue[rear] = item;
}

element dequeue()
{
	assert(!is_empty());
	front = (front + 1) % MAX_QUEUE_SIZE;
	return queue[front];
}