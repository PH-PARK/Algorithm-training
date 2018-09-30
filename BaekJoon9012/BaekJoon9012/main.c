#include <stdio.h>
#include <stdint.h>

#define maxLen 50
#define minLen 2

int getString(char *buf);
int checkSting(char *buf);

char string[maxLen];
uint8_t NumofData;

int main()
{
	int i;

	//puts("How many VPS?: ");
	scanf_s("%d", &NumofData);

	for (i = NumofData; i > 0 ; i--)
	{
		if (getSting(string) == 1)
		{
			puts("String input failed.");

			return 1;
		}

		if (checkString(string) == 1)
		{
			puts("YES");
		}
		else if (checkString(string) == 0)
		{
			puts("NO");
		}
		else
		{
			puts("Something wrong...");
			return 1;
		}
	}

	return 0;
}

int getString(char *buf)
{
	
}

int checkSting(char *buf)
{

}