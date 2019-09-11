#include <stdlib.h>
#include<stdio.h>

void swap(int *a, int *b)
{
	int c;
	c = *a;
	*a = *b;
	*b = c;
	return;
};

int main()
{
	int a = 1, b = 2;
	swap(&a, &b);
	printf("%d  %d", a, b);
	system("pause");
}