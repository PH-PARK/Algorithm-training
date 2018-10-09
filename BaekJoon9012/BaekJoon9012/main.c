#include <stdio.h>
#include <stdint.h>

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
	int i, j;
	uint8_t input_flag = 0;
	int NumOfTest;
	char tem = 0;

#ifdef __DEBUG__
	printf("How many VPS?: ");
#endif


#ifdef _WIN32
	scanf_s("%d", &NumOfTest);
#elif __linux__
	scanf("%d", &NumofData);
#endif
	for (i = 0; i < NumOfTest; i++)
	{
#ifdef __DEBUG__
		printf("NumOfTest : %d\n", NumOfTest);
#endif
		for (j = 0; j < maxLen; j++)
		{
			fflush(stdout);
			tem=getchar();
#ifdef __DEBUG__
			printf("tem : %c\n", tem);
#endif
			if (tem == "(") 
			{
#ifdef __DEBUG__
				puts("Passed if (tem == \"(\"");
#endif
				input_flag = 1;
				push(tem);

			}

			else if (tem == ")")
			{
#ifdef __DEBUG__
				puts("Passed if (tem == \")\"");
#endif
				if (is_empty == 1)
				{
					puts("NO");
					break; //Failed this time.
				}
				else
				{
					pop();
				}
			}

			else if (tem == '\n')
			{
				if (is_empty() == 1)
				{
					if (input_flag == 1)
					{
						puts("YES");
					}
					else
					{
						puts("NO");
						break;
					}
				}
				else
				{
					puts("NO");
					break;
				}
				break;
			}
			else
			{
				puts("Wrong Char");
				break;
			}

			}//end of for(j<maxLen)
#ifdef __DEBUG__
		puts("One loop is done.");
#endif
		ClearStack();
		input_flag = 0;
		}//end of for(i<NumOfTest)

	puts("종료합니다.");
	system("pause");

	return 0;

	}//end of main



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