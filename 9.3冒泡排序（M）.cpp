/*10¸öÕûÊıÃ°ÅİÅÅĞò*/
#include<stdio.h>
#include<stdlib.h>
int main ()
{
	int input[10] = { 23,3500,123,357,765,2,3,4,5,12},m, i, j;
	for (i = 1; i < 10; i++)
	{
		for (j = 0; j < i; j++)
		{
			if (input[i] < input[j])
			{
				m = input[i];
				input[i] = input[j];
				input[j] = m;
			}
		}
	}
	for (i = 0; i < 10; i++)
		printf("%d ", input[i]);
	system("pause");
}