#include <stdio.h>
#include <assert.h>

#define MAX_STACK_SIZE 100
typedef int element;

element stack[MAX_STACK_SIZE];
int top = -1;

void push(int item);
int pop(void);
int is_empty(void);
int is_full(void);

int main()
{
	int num;

	while (1)
	{
		puts("Enter Item.");
		scanf_s("%d", &num);

		if (num == -1) {
			
			puts("Out Items.");
			break;
		}

		push(num);

	}

	while (!is_empty())
	{

		num = pop();
		printf("%d\t", num);
	}

	system("pause");

	return 0;
}
void push(element item)
{
	assert(!is_full());

	stack[++top] = item;

	return;
}

int pop()
{
	assert(!is_empty());

	return stack[top--];
}

int is_empty(void )
{
	return (top == -1);
}
int is_full(void )
{
	return (top == (MAX_STACK_SIZE - 1));
}