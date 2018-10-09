#include <stdio.h>
	
#define __DEBUG__
#define maxLen 50
#define minLen 2

void push(char);
char pop(void);
int is_empty(void);
int is_full(void);
void ClearStack(void);

typedef char element;
element stack[maxLen];
int top = -1;

int main()
{
	int i;
	int NumOfTest;
	element tem;

#ifdef __DEBUG__
	puts("How many VPS?: ");
#endif


#ifdef _WIN32
	scanf_s("%d", &NumOfTest);
#elif __linux__
	scanf("%d", &NumofData);
#endif

	for (i = 0; i < NumOfTest; i++)
	{
		getchar(tem);

		if (tem == "(") {
#ifdef __DEBUG__
			puts("Passed if (tem == \"(\"");
#endif
			push(tem);

		}
		else if (tem == ")")
		{
#ifdef __DEBUG__
			puts("Passed if (tem == \")\"");
#endif
			if (is_empty == 1) 
			{

			}
			else
			{
				pop();
			}
		else if (tem == '\n')
		{

		}
		}
#ifdef __DEBUG__
	puts("Entering Finished.");
	puts("Start Checking.");
#endif
	if (is_empty() == 1) 
	{
		puts("YES");
	}
	else
	{
		puts("NO");
	}


	}//end of for


	

	puts("종료합니다.");
	system("pause");

	return 0;
}

void CheckMatching(void)
{
	char tem;

	tem = pop();


	return;
}

void push(char item)
{
	

	stack[++top] = item;

	return;
}

char pop(void)
{

	return stack[top--];
}

int is_full(void)
{
	return (top == maxLen -1);//return 1 if full; return 0 if not full
}

int is_empty(void)
{

	return (top == -1);// return 1 if empty; return 0 if not empty;
}

void ClearStack(void)
{
	top = -1;
	return;
}