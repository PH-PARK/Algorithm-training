#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int i;
	int RandomNum[10];
	int Count[10];
	int CountSum[10];
	int Sort[10];

	for (i = 0; i < 10; i++)
	{
		RandomNum[i] = 0;
		Count[i] = 0;
		CountSum[i] = 0;
		Sort[i] = 0;
	}


	srand(time(NULL));
	printf("Random Numbers \n");
	for (i = 0; i < 10; i++)
	{
		RandomNum[i] = rand() % 10;
		printf("%d ", RandomNum[i]);
	}//Make Random Numbers
	puts("");

	for (i = 0; i < 10; i++)
	{
		Count[RandomNum[i]]++;
	}//Count numbers;

	CountSum[0] = Count[0];

	for (i = 1; i < 10; i++)
	{
		CountSum[i] = CountSum[i - 1] + Count[i];
	}//Accumulate Count

	for (i = 9; i > -1; i--)
	{
		Sort[CountSum[RandomNum[i]]] = RandomNum[i];
		CountSum[RandomNum[i]]--;
	}

	printf("Result\n");
	for (i = 0; i < 10; i++)
	{
		printf("%d ", Sort[i]);
	}
	puts("");
	puts("Pause");
	system("Pause");
}