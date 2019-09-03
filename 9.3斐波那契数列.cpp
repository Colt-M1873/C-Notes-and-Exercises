/*求斐波那契数列100位以内第n个数的值*/
#include<stdio.h>
#include <stdlib.h>
int main()
{
	long long int fibonacci[100], i;
	fibonacci[0] = 1;
	fibonacci[1] = 1;
	for (i = 2; i < 100; i++)
	{
		fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
		printf("%lld ", fibonacci[i]);
	}
	system("pause");
}