#include <stdio.h>

void revise(int a);

int main()
{
	int a = 10;
	printf("%d\n", a);
	revise(a);
	printf("%d\n", a);

	return 0;
}

void revise(int a)
{
	a = a++;
	return;
}
