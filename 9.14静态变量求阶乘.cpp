#include<stdlib.h>
#include<stdio.h>
int factorial(int a);
int main()
{
	int a, i;
	scanf_s("%d", &a);
	for (i = 1; i <= a; i++)
		printf("%d!=%ld\n", i, factorial(i));

}

int factorial(int i) {
	static int p = 1;
	if (i != 1 && i != 0)
	{
		p = p * i;
		return p;
	}
	else
		return 1;
}