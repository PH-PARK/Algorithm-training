//studentroll
#include <stdio.h>
#include <stdint.h>
#include <assert.h>

//#define __DEBUG__
#define maxLen 50
#define minLen 2

void push(char);
char pop(void);
int is_empty(void);
int is_full(void);
void CheckMatching(char *buf);
void ClearStack(void);
//void ClearString();

typedef char element;

element stack[maxLen];
int top = -1;

int main()
{
	int i, j;
	char string[maxLen];
	int NumOfTest;

#ifdef __DEBUG__
	printf("How many VPS?: ");
#endif


#ifdef _WIN32
	scanf_s(" %d", &NumOfTest);
#elif __linux__
	scanf(" %d", &NumOfTest);
#endif
	for (i = 0; i < NumOfTest; i++)
	{
#ifdef __DEBUG__
		printf("NumOfTest : %d, i : %d\n", NumOfTest, i);
#endif

		//for (j = 0; j < maxLen; j++)
		//{
			while (getchar() != '\n'); //Clear Buffer
			scanf("%s",string);
#ifdef __DEBUG__
			printf("String is : %s\n", string);
			puts("Start Checking");
#endif

			CheckMatching(string);

#ifdef __DEBUG__
			puts("One loop is done.");
#endif
			ClearStack();

		//}//end of for(j<MaxLen)

	}//end of for(i<NumofTest)
#ifdef __DEBUG__
	puts("종료합니다.");
	system("pause");
#endif
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

void CheckMatching(char *buf)
{
	element tem = 0;
	uint8_t i = 0;
	uint8_t NumOfClose=0;

#ifdef __DEBUG__
	printf("buf is : %s\n", buf);
#endif

	while (buf[i] != '\0')
	{


		tem = buf[i];
#ifdef __DEBUG__
		printf("tem is %c\n", buf[i]);
#endif

		if (tem == 40)//"(")
		{
#ifdef __DEBUG__
			puts("This Char is (");
#endif
			push(tem);

		}
		else if (tem == 41)//")")
		{
#ifdef __DEBUG__
			puts("This Char is )");
#endif

			if (is_empty() == 1)
			{
				puts("NO");
				return;
				//break; //Failed this time.
			}
			else//if it is not empty;
			{
				pop();
				NumOfClose++;
			}
		}

		else//if(tem !=( && !=))
		{
			puts("Wrong Char");
			break;
		}
		i++;
	}
	if (is_empty() == 1 && NumOfClose>0) 
	{
		puts("YES");
		return;
	}
	else
	{
		puts("NO");
		return;
	}

	return;
}

void ClearStack(void)
{
	top = -1;
	return;
}