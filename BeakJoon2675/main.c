#include <stdio.h>

#define MAX_NUM 20

int GetString(char* buf);

int main()
{
	int i, j;
	int ExecutionTime = 0;
	int RepeatTime = 0;
	char String[MAX_NUM];



	scanf("%d", &ExecutionTime);

	while (ExecutionTime)
	{
		scanf("%d", &RepeatTime);
		GetString(String);
		
		while (String[i])
		{
			for (j = 0; j = RepeatTime; j++)
			{
				printf("%c", String[i]);
			}

			i++;
		}
	}

	return 0;
}

int GetString(char* buf)
{
	char c = 0;
	int i;

	for(i = 0; i < MAX_NUM; i++)
	{
		c= getchar();
		buf[i] = c;
		if (c != '\n')
		{
			buf[i] = NULL;
			return 0;
		}

	}
	puts("Too long String");

	return 1;
}