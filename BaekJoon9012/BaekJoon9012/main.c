#include <stdio.h>
	
#define maxLen 50
#define minLen 2

typedef char element;
element stack[maxLen];

int NumofData;
int top = -1;

int main()
{
	int i;

	//puts("How many VPS?: ");
#ifdef _WIN32
	scanf_s("%d", &NumofData);
#elif __linux__
	scanf("%d", &NumofData);
#endif

	for (i = NumofData; i > 0; i--)
	{
		
	}

	puts("종료합니다.");
	system("pause");

	return 0;
}

void push(char item)
{

}

char pop(void)
{

	return;
}
