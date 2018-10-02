#include <stdio.h>

#define maxLen 50
#define minLen 2

//int getString(char *buf);
//int checkString(char *buf);

typedef char element;
element stack[maxLen];

int NumofData;
int top = -1;

int main()
{
	int i;

	//puts("How many VPS?: ");
	scanf_s("%d", &NumofData);

	for (i = NumofData; i > 0; i--)
	{
		
	}

	puts("종료합니다.");
	scanf_s("%d", &NumofData);

	return 0;
}

void push(char item)
{

}

char pop(void)
{

	return 
}
/*
int getString(char *buf)
{
	char temp;
	int i;

	for (i = 0; i < maxLen; i++ )
	{
		temp = getchar();

		if (temp == '\n')
		{
			buf[i] = '\0';
			return 0;
		}
	}

	return 1;

}

int checkString(char *buf)
{
	char temp;
	int i;
	int j=0;

	for (i = 0; i < maxLen; i++ )
	{
		temp = buf[i];
		if (temp == 72)
		{
			i++;
		}
		else if (temp == 73)
		{
			i--;
			j++;
		}
		if (temp = '\n')
		{
			if (i == 0 && j!=0)
			{
			
				return 1;
			}
			else if(i != 0)
			{

				return 0;
			}
		}
	}

	return 0;
}*/