#include <stdio.h>
#include <assert.h>

#define MAX_STACK_SIZE 100
typedef int element;

element stack[MAX_STACK_SIZE];
int top = -1;

int main()
{
	int num;

	while (1)
	{
		scanf("%d", &num);
		if (num == -1)
			break;
		push(num);

	}

	while (!is_empty())
	{
		num = pop();
		printf("%d", num);
	}
	return 0;
}
void push(element item)
{
	assert(!is_full());

	stack[++top] = item;
}

int pop()
{
	assert(!is_empty());

	return stack[top--];
}

int is_empty()
{
	return (top == -1);
}
int is_full()
{
	return (top == (MAX_STACK_SIZE - 1));
}