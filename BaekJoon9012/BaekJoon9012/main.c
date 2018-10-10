#include <stdio.h>
#include <stdint.h>
#include <assert.h>

#define __DEBUG__
#define maxLen 50
#define minLen 2

void push(char);
char pop(void);
int is_empty(void);
int is_full(void);
int CheckMatching(element* buf);
void ClearStack(void);

typedef char element;

element stack[maxLen];
int top = -1;

int main()
{
	int i, j;
	element string[maxLen];
	int NumOfTest;
	char tem = 0;

#ifdef __DEBUG__
	printf("How many VPS?: ");
#endif


#ifdef _WIN32
	scanf_s(" %d", &NumOfTest);
#elif __linux__
	scanf(" %d", &NumofData);
#endif
	for (i = 0; i < NumOfTest; i++)
	{
#ifdef __DEBUG__
		printf("NumOfTest : %d, i : %d\n", NumOfTest, i);
#endif

		for (j = 0; j < maxLen; j++)
		{
			//	fflush(stdout);
			scanf_s(" %s", string);
#ifdef __DEBUG__
			printf("sting is : %s", string);
#endif

			CheckMatching(string);

#ifdef __DEBUG__
			puts("One loop is done.");

#endif
			ClearStack();

		}//end of for(j<MaxLen)

	}//end of for(i<NumofTest)

	puts("종료합니다.");
	system("pause");

	return 0;
}


void push(char item)
{
	
	assert(!is_full());

	stack[++top] = item;

	return;
}

char pop(void)
{
	assert(!is_empty());

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

int CheckMatching(element* buf)
{



	return 1;
}

void ClearStack(void)
{
	top = -1;
	return;
}